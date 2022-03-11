#!/usr/bin/env python3

import pandas as pd
import numpy as np
import sys
import os
import re
import shutil
import filecmp
from collections import namedtuple, OrderedDict
from itertools import groupby
import operator

from jinja2 import Environment, PackageLoader, select_autoescape
env = Environment(
    loader=PackageLoader('templates', ''),
    autoescape=select_autoescape([]),
    keep_trailing_newline=True,
    lstrip_blocks=True
)

gen_dir = os.path.dirname(os.path.abspath(__file__))
csv_dir = sys.argv[1]
dest_dir = os.path.abspath(os.path.join(gen_dir, "..", "src", "binding", "generated"))
tmp_dir = os.path.join(dest_dir, "tmp")

qt_types = {
    'Boolean': 'bool',
    'Double': 'double',
    'UInt8': 'int',
    'UInt16': 'int',
    'UInt32': 'int',
    'Int8': 'int',
    'Int16': 'int',
    'Int32': 'int',
    'String': 'QString',
    'DBString': 'QString',
    'DBBitArray': 'QVector<bool>',
}

# Additional Jinja 2 functions
def qt_type(ty, prefix=True):
    if ty in qt_types:
        return qt_types[ty]

    if ty == "DatabaseVersion":
        return 'int'

    if ty == "EmptyBlock":
        return 'void'

    m = re.match(r'Count<(.*)>', ty)
    if m:
        return qt_type(m.group(1), prefix)

    m = re.match(r'Array<(.*):(.*)>', ty)
    if m:
        return 'ArrayAdapter*'

    m = re.match(r'(Vector|Array)<(.*)>', ty)
    if m:
        if type_is_struct(m.group(2)):
            return 'ArrayAdapter*'
        return 'QVector<%s>' % qt_type(m.group(2), prefix)

    m = re.match(r'DBArray<(.*)>', ty)
    if m:
        return 'QVector<%s>' % qt_type(m.group(1), prefix)

    m = re.match(r'Ref<(.*):(.*)>', ty)
    if m:
        return qt_type(m.group(2), prefix)

    m = re.match(r'Ref<(.*)>', ty)
    if m:
        return 'int'

    m = re.match(r'Enum<(.*)>', ty)
    if m:
        return 'int'

    m = re.match(r'(.*)_Flags$', ty)
    if m:
        ty = m.expand(r'\1::Flags')
        if prefix:
            ty = "Binding::" + ty + "*"
        return ty

    if prefix:
        ty = "Binding::" + ty + "*"

    return ty

def inner_type(ty):
    m = re.match(r'.*?<([^:]+).*>', ty)
    if m:
        return m.group(1)
    return ty

def num_flags(flag):
    return len(flag)

def filter_structs_without_codes(structs):
    for struct in structs:
        if all(f.code for f in sfields[struct.name]):
            yield struct
# End of Jinja 2 functions

int_types = {
    'UInt8': 'uint8_t',
    'UInt16': 'uint16_t',
    'UInt32': 'uint32_t',
    'Int16': 'int16_t',
    'Int32': 'int32_t'
}

def struct_headers(ty, header_map):
    m = re.match(r'Ref<(.*):(.*)>', ty)
    if m:
        return struct_headers(m.group(2), header_map)

    m = re.match(r'Array<(.*):(.*)>', ty)
    if m:
        return struct_headers(m.group(1), header_map)

    m = re.match(r'(Vector|Array)<(.*)>', ty)
    if m:
        return struct_headers(m.group(2), header_map)

    header = header_map.get(ty)
    if header is not None:
        return ['"%s.h"' % header]

    if ty in ['Parameters', 'Equipment', 'EventCommand', 'MoveCommand', 'Rect', 'TreeMap']:
        return ['"%s.h"' % ty.lower()]

    return []

def merge_dicts(dicts):
    # Merges multiple dicts into one
    out_dict = dicts[0]

    for d in dicts[1:]:
        for k,v in d.items():
            if k in out_dict:
                # Append new values
                for vv in v:
                    out_dict[k].append(vv)
            else:
                # Insert whole key
                out_dict[k] = v

    return out_dict

def process_file(filename, namedtup):
    # Mapping is: All elements of the line grouped by the first column

    path = os.path.join(csv_dir, filename)
    df = pd.read_csv(path, comment='#', dtype=str)
    df = df.fillna("")

    lines = [ list(r) for _i, r in df.iterrows() ]

    result = OrderedDict()
    for k, g in groupby(lines, operator.itemgetter(0)):
        result[k] = list(map(lambda x: namedtup(*x[1:]), list(g)))

    return result

def get_structs(*filenames):
    Struct = namedtuple("Struct", "name base hasid")

    results = list(map(lambda x: process_file(x, Struct), filenames))

    processed_result = OrderedDict()

    for k, struct in merge_dicts(results).items():
        processed_result[k] = []

        for elem in struct:
            elem = Struct(elem.name, elem.base, bool(int(elem.hasid)) if elem.hasid else None)
            processed_result[k].append(elem)

    processed_flat = []
    for filetype, struct in processed_result.items():
        for elem in struct:
            processed_flat.append(elem)

    return processed_result, processed_flat

def get_fields(*filenames):
    Field = namedtuple("Field", "name size type code default presentifdefault is2k3 comment")

    results = list(map(lambda x: process_file(x, Field), filenames))

    processed_result = OrderedDict()

    for k, field in merge_dicts(results).items():
        processed_result[k] = []
        for elem in field:
            if elem.size == 't':
                continue
            if not elem.type or elem.type == "EmptyBlock":
                continue
            elem = Field(
                elem.name,
                True if elem.size == 't' else False,
                elem.type,
                0 if elem.code == '' else int(elem.code, 0),
                elem.default,
                elem.presentifdefault,
                elem.is2k3,
                elem.comment)
            processed_result[k].append(elem)

    return processed_result

def get_enums(*filenames):
    results = list(map(lambda x: process_file(x, namedtuple("Enum", "entry value index")), filenames))
    new_result = OrderedDict()

    # Additional processing to group by the Enum Entry
    # Results in e.g. EventCommand -> Code -> List of (Name, Index)
    for k, v in merge_dicts(results).items():
        new_result[k] = OrderedDict()
        for kk, gg in groupby(v, operator.attrgetter("entry")):
            new_result[k][kk] = list(map(lambda x: (x.value, x.index), gg))

    return new_result

def get_flags(*filenames):
    results = list(map(lambda x: process_file(x, namedtuple("Flag", "field is2k3")), filenames))
    return merge_dicts(results)

def get_functions(*filenames):
    Function = namedtuple("Function", "method static headers")

    results = list(map(lambda x: process_file(x, Function), filenames))

    processed_result = OrderedDict()

    for k, field in merge_dicts(results).items():
        processed_result[k] = []
        for elem in field:
            elem = Function(
                elem.method,
                elem.static == 't',
                elem.headers)
            processed_result[k].append(elem)

    return processed_result

def get_constants(filename='constants.csv'):
    return process_file(filename, namedtuple("Constant", "name type value comment"))

def type_is_db_string(ty):
    return ty == 'DBString'

def type_is_string(ty):
    return ty == 'String'

def type_is_array(ty):
    return re.match(r'(Vector|Array|DBArray)<(.*)>', ty) or ty == "DBBitArray"

def type_is_struct(ty):
    return ty in [ x.name for x in structs_flat ]

def type_can_write(ty):
    if qt_type(ty) in ["bool", "int", "double", "QString"]:
        return True
    return type_is_array(ty) and not type_is_array_of_struct(ty)

def type_is_array_of_struct(ty):
    m = re.match(r'(Vector|Array|DBArray)<(.*)>', ty)
    return m and type_is_struct(m.group(2).split(":")[0])

def openToRender(path):
    subdir = os.path.dirname(path)
    if not os.path.exists(subdir):
        os.makedirs(subdir)
    return open(path, 'w')

def generate():
    if not os.path.exists(tmp_dir):
        os.mkdir(tmp_dir)

    for filetype, structlist in structs.items():
        for struct in structlist:
            filename = struct.name.lower()

            filepath = os.path.join(tmp_dir, '%s.h' % filename)
            with openToRender(filepath) as f:
                f.write(rpg_header_tmpl.render(
                    struct_name=struct.name,
                    struct_base=struct.base,
                    has_id=struct.hasid
                ))

            filepath = os.path.join(tmp_dir, '%s.cpp' % filename)
            with openToRender(filepath) as f:
                f.write(rpg_source_tmpl.render(
                    struct_name=struct.name,
                    struct_base=struct.base,
                    has_id=struct.hasid,
                    filename=filename
                ))

    for dirname, subdirlist, filelist in os.walk(tmp_dir, topdown=False):
        subdir = os.path.relpath(dirname, tmp_dir)

        for tmp_file in filelist:
            tmp_path = os.path.join(tmp_dir, subdir, tmp_file)
            dest_path = os.path.join(dest_dir, subdir, tmp_file)
            dest_subdir = os.path.dirname(dest_path)
            if not os.path.exists(dest_subdir):
                os.mkdir(dest_subdir)
            if not (os.path.exists(dest_path) and filecmp.cmp(tmp_path, dest_path)):
                shutil.copyfile(tmp_path, dest_path)
            os.remove(tmp_path)
        os.rmdir(os.path.join(dirname))

def main(argv):
    if not os.path.exists(dest_dir):
        os.mkdir(dest_dir)

    global structs, structs_flat, sfields, enums, flags, functions, constants
    global chunk_tmpl, lcf_struct_tmpl, rpg_header_tmpl, rpg_source_tmpl, flags_tmpl, enums_tmpl, fwd_tmpl, fwd_struct_tmpl

    structs, structs_flat = get_structs('structs.csv','structs_easyrpg.csv')
    sfields = get_fields('fields.csv','fields_easyrpg.csv')
    enums = get_enums('enums.csv','enums_easyrpg.csv')
    flags = get_flags('flags.csv')
    functions = get_functions('functions.csv')
    constants = get_constants()

    # Setup Jinja
    env.filters["qt_type"] = qt_type
    env.filters["inner_type"] = inner_type
    env.filters["struct_has_code"] = filter_structs_without_codes
    env.filters["num_flags"] = num_flags
    env.tests['is_db_string'] = type_is_db_string
    env.tests['is_string'] = type_is_string
    env.tests['is_array'] = type_is_array
    env.tests['is_array_of_struct'] = type_is_array_of_struct
    env.tests['is_struct'] = type_is_struct
    env.tests['can_write'] = type_can_write

    globals = dict(
        structs=structs,
        structs_flat=structs_flat,
        fields=sfields,
        flags=flags,
        enums=enums,
        functions=functions,
        constants=constants,
    )

    rpg_header_tmpl = env.get_template('rpg_header.tmpl', globals=globals)
    rpg_source_tmpl = env.get_template('rpg_source.tmpl', globals=globals)

    generate()

if __name__ == '__main__':
    main(sys.argv)
