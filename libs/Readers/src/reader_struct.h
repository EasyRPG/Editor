/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _EASYRPG_READER_STRUCT_H_
#define _EASYRPG_READER_STRUCT_H_

// Headers
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cstring>
#include <cstdlib>
#include "boost/preprocessor/cat.hpp"
#include "boost/preprocessor/stringize.hpp"
#include "reader_lcf.h"
#include "writer_lcf.h"
#include "reader_xml.h"
#include "writer_xml.h"
#include "rpg_eventpagecondition.h"
#include "rpg_trooppagecondition.h"
#include "rpg_terrain.h"
#include "rpg_equipment.h"
#include "rpg_parameters.h"
#include "rpg_eventcommand.h"
#include "rpg_movecommand.h"
#include "rpg_treemap.h"
#include "rpg_rect.h"

// Forward declarations

template <class T>
class Struct;

// Type categories

struct Category {
	enum Index {
		Primitive,
		Struct,
		Flags,
		RawStruct
	};
};

template <class T>
struct TypeCategory {
	static const Category::Index value = Category::Struct;
};

template <> struct TypeCategory<RPG::TroopPageCondition::Flags>	{ static const Category::Index value = Category::Flags; };
template <> struct TypeCategory<RPG::EventPageCondition::Flags>	{ static const Category::Index value = Category::Flags; };
template <> struct TypeCategory<RPG::Terrain::Flags>			{ static const Category::Index value = Category::Flags; };

template <> struct TypeCategory<RPG::Equipment>					{ static const Category::Index value = Category::RawStruct; };
template <> struct TypeCategory<RPG::EventCommand>				{ static const Category::Index value = Category::RawStruct; };
template <> struct TypeCategory<RPG::MoveCommand>				{ static const Category::Index value = Category::RawStruct; };
template <> struct TypeCategory<RPG::Parameters>				{ static const Category::Index value = Category::RawStruct; };
template <> struct TypeCategory<RPG::TreeMap>					{ static const Category::Index value = Category::RawStruct; };
template <> struct TypeCategory<RPG::Rect>						{ static const Category::Index value = Category::RawStruct; };

template <>	struct TypeCategory<uint8_t>						{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<int16_t>						{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<uint32_t>						{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<int>							{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<bool>							{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<double>							{ static const Category::Index value = Category::Primitive; };
template <>	struct TypeCategory<std::string>					{ static const Category::Index value = Category::Primitive; };

template <class T>
struct TypeCategory<std::vector<T> > {
	static const Category::Index value = TypeCategory<T>::value;
};

/**
 * Typed data readers.
 */
template <class T, Category::Index cat = TypeCategory<T>::value>
struct TypeReader {};

/**
 * Raw structure reader template.
 */
template <class T>
struct RawStruct {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const T& ref, LcfWriter& stream);
	static int LcfSize(const T& ref, LcfWriter& stream);
	static void WriteXml(const T& ref, XmlWriter& stream);
	static void BeginXml(T& ref, XmlReader& stream);
};

template <class T>
struct TypeReader<T, Category::RawStruct> {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t length) {
		RawStruct<T>::ReadLcf(ref, stream, length);
	}
	static void WriteLcf(const T& ref, LcfWriter& stream) {
		RawStruct<T>::WriteLcf(ref, stream);
	}
	static int LcfSize(const T& ref, LcfWriter& stream) {
		return RawStruct<T>::LcfSize(ref, stream);
	}
	static void WriteXml(const T& ref, XmlWriter& stream) {
		RawStruct<T>::WriteXml(ref, stream);
	}
	static void BeginXml(T& ref, XmlReader& stream) {
		RawStruct<T>::BeginXml(ref, stream);
	}
	static void ParseXml(T& /* ref */, const std::string& /* data */) {
		//no-op
	}
};

/**
 * Type Lcf size.
 */
template <class T>
struct LcfSizeT {
	static const uint32_t value = sizeof(T);
};

/**
 * Type Lcf bool size.
 */
template <>
struct LcfSizeT<bool> {
	static const uint32_t value = 1;
};

/**
 * Primitive type reader template.
 */
template <class T>
struct Primitive {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t length) {
		assert(length == LcfSizeT<T>::value);
		stream.Read(ref);
	}
	static void WriteLcf(const T& ref, LcfWriter& stream) {
		stream.Write(ref);
	}
	static int LcfSize(const T& /* ref */, LcfWriter& /* stream */) {
		return LcfSizeT<T>::value;
	}
	static void WriteXml(const T& ref, XmlWriter& stream) {
		stream.Write(ref);
	}
	static void ParseXml(T& ref, const std::string& data) {
		XmlReader::Read(ref, data);
	}
};

/**
 * Vector specialization.
 */
template <class T>
struct Primitive<std::vector<T> > {
	static void ReadLcf(std::vector<T>& ref, LcfReader& stream, uint32_t length) {
		stream.Read(ref, length);
	}
	static void WriteLcf(const std::vector<T>& ref, LcfWriter& stream) {
		stream.Write(ref);
	}
	static int LcfSize(const std::vector<T>& ref, LcfWriter& /* stream */) {
		return LcfSizeT<T>::value * ref.size();
	}
	static void WriteXml(const std::vector<T>& ref, XmlWriter& stream) {
		stream.Write(ref);
	}
	static void ParseXml(std::vector<T>& ref, const std::string& data) {
		XmlReader::Read(ref, data);
	}
};

/**
 * Int specialization.
 */
template <>
struct Primitive<int> {
	static void ReadLcf(int& ref, LcfReader& stream, uint32_t length) {
		assert(length >= 1 && length <= 5);
		ref = stream.ReadInt();
	}
	static void WriteLcf(const int& ref, LcfWriter& stream) {
		stream.WriteInt(ref);
	}
	static int LcfSize(const int& ref, LcfWriter& /* stream */) {
		return LcfReader::IntSize(ref);
	}
	static void WriteXml(const int& ref, XmlWriter& stream) {
		stream.WriteInt(ref);
	}
	static void ParseXml(int& ref, const std::string& data) {
		XmlReader::Read(ref, data);
	}
};

/**
 * String specialization.
 */
template <>
struct Primitive<std::string> {
	static void ReadLcf(std::string& ref, LcfReader& stream, uint32_t length) {
		stream.ReadString(ref, length);
	}
	static void WriteLcf(const std::string& ref, LcfWriter& stream) {
		stream.Write(ref);
	}
	static int LcfSize(const std::string& ref, LcfWriter& stream) {
		return stream.Decode(ref).size();
	}
	static void WriteXml(const std::string& ref, XmlWriter& stream) {
		stream.Write(ref);
	}
	static void ParseXml(std::string& ref, const std::string& data) {
		XmlReader::Read(ref, data);
	}
};

/**
 * Primitive Reader.
 */
template <class T>
struct TypeReader<T, Category::Primitive> {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t length) {
		Primitive<T>::ReadLcf(ref, stream, length);
	}
	static void WriteLcf(const T& ref, LcfWriter& stream) {
		Primitive<T>::WriteLcf(ref, stream);
	}
	static int LcfSize(const T& ref, LcfWriter& stream) {
		return Primitive<T>::LcfSize(ref, stream);
	}
	static void WriteXml(const T& ref, XmlWriter& stream) {
		Primitive<T>::WriteXml(ref, stream);
	}
	static void BeginXml(T& /* ref */, XmlReader& /* stream */) {
		// no-op
	}
	static void ParseXml(T& ref, const std::string& data) {
		Primitive<T>::ParseXml(ref, data);
	}
};

/**
 * Structure field reader.
 */
template <class S, class T>
struct FieldReader {
	static void ReadLcf(S& obj, T S::*ref, LcfReader& stream, uint32_t length) {
		TypeReader<T>::ReadLcf(obj.*ref, stream, length);
	}
	static void WriteLcf(const S& obj, const T S::*ref, LcfWriter& stream) {
		TypeReader<T>::WriteLcf(obj.*ref, stream);
	}
	static int LcfSize(const S& obj, const T S::*ref, LcfWriter& stream) {
		return TypeReader<T>::LcfSize(obj.*ref, stream);
	}
	static void WriteXml(const S& obj, const T S::*ref, XmlWriter& stream) {
		TypeReader<T>::WriteXml(obj.*ref, stream);
	}
	static void BeginXml(S& obj, T S::*ref, XmlReader& stream) {
		TypeReader<T>::BeginXml(obj.*ref, stream);
	}
	static void ParseXml(S& obj, T S::*ref, const std::string& data) {
		TypeReader<T>::ParseXml(obj.*ref, data);
	}
};

/**
 * Field abstract base class template.
 */
template <class S>
struct Field {
	typedef S struct_type;

	int id;
	const char* const name;

	virtual void ReadLcf(S& obj, LcfReader& stream, uint32_t length) const = 0;
	virtual void WriteLcf(const S& obj, LcfWriter& stream) const = 0;
	virtual int LcfSize(const S& obj, LcfWriter& stream) const = 0;
	virtual bool IsDefault(const S& obj, const S& ref) const = 0;
	virtual void WriteXml(const S& obj, XmlWriter& stream) const = 0;
	virtual void BeginXml(S& obj, XmlReader& stream) const = 0;
	virtual void ParseXml(S& obj, const std::string& data) const = 0;

	Field(int id, const char* name) :
		id(id), name(name) {}
};

// Equivalence traits

template <class T>
struct Class_Test {
	typedef char yes;
	typedef int no;

	template <class C>
	static yes& check(void(C::*)(void));
	template <class C>
	static no&  check(...);

	static const bool value = sizeof(check<T>(0)) == sizeof(yes);
};

template <class T>
struct Compare_Test {
	static const bool value = !Class_Test<T>::value;
};

template <class T>
struct Compare_Test<std::vector<T> > {
	static const bool value = Compare_Test<T>::value;
};

template <>
struct Compare_Test<std::string> {
	static const bool value = true;
};

template <class T, bool comparable>
struct Compare_Traits_Impl {};

template <class T>
struct Compare_Traits_Impl<T, true> {
	static bool IsEqual(const T& a, const T& b) {
		return a == b;
	}
};

template <class T>
struct Compare_Traits_Impl<T, false> {
	static bool IsEqual(const T& /* a */, const T& /* b */) {
		return false;
	}
};

template <class T>
struct Compare_Traits_Impl<std::vector<T>, false> {
	static bool IsEqual(const std::vector<T>& a, const std::vector<T>& b) {
		return a.empty() && b.empty();
	}
};

template <class T>
struct Compare_Traits {
	typedef Compare_Traits_Impl<T, Compare_Test<T>::value> impl_type;
	static bool IsEqual(const T& a, const T& b) {
		return impl_type::IsEqual(a, b);
	}
};

/**
 * TypedField class template.
 */
template <class S, class T>
struct TypedField : public Field<S> {
	T S::*ref;

	void ReadLcf(S& obj, LcfReader& stream, uint32_t length) const {
		FieldReader<S, T>::ReadLcf(obj, ref, stream, length);
	}
	void WriteLcf(const S& obj, LcfWriter& stream) const {
		FieldReader<S, T>::WriteLcf(obj, ref, stream);
	}
	int LcfSize(const S& obj, LcfWriter& stream) const {
		return FieldReader<S, T>::LcfSize(obj, ref, stream);
	}
	void WriteXml(const S& obj, XmlWriter& stream) const {
		stream.BeginElement(this->name);
		FieldReader<S, T>::WriteXml(obj, ref, stream);
		stream.EndElement(this->name);
	}
	void BeginXml(S& obj, XmlReader& stream) const {
		FieldReader<S, T>::BeginXml(obj, ref, stream);
	}
	void ParseXml(S& obj, const std::string& data) const {
		FieldReader<S, T>::ParseXml(obj, ref, data);
	}
	bool IsDefault(const S& a, const S& b) const {
		return Compare_Traits<T>::IsEqual(a.*ref, b.*ref);
	}

	TypedField(T S::*ref, int id, const char* name) :
		Field<S>(id, name), ref(ref) {}
};

/**
 * SizeField class template.
 */
template <class S, class T>
struct SizeField : public Field<S> {
	const std::vector<T> S::*ref;

	void ReadLcf(S& /* obj */, LcfReader& stream, uint32_t length) const {
		int dummy;
		TypeReader<int>::ReadLcf(dummy, stream, length);
	}
	void WriteLcf(const S& obj, LcfWriter& stream) const {
		int size = TypeReader<std::vector<T> >::LcfSize(obj.*ref, stream);
		TypeReader<int>::WriteLcf(size, stream);
	}
	int LcfSize(const S& obj, LcfWriter& stream) const {
		int size = TypeReader<std::vector<T> >::LcfSize(obj.*ref, stream);
		return LcfReader::IntSize(size);
	}
	void WriteXml(const S& /* obj */, XmlWriter& /* stream */) const {
		// no-op
	}
	void BeginXml(S& /* obj */, XmlReader& /* stream */) const {
		// no-op
	}
	void ParseXml(S& /* obj */, const std::string& /* data */) const {
		// no-op
	}
	bool IsDefault(const S& a, const S& b) const {
		return (a.*ref).empty() && (b.*ref).empty();
	}

	SizeField(const std::vector<T> S::*ref, int id) :
		Field<S>(id, ""), ref(ref) {}
};

/**
 * ID handling for Struct class.
 */
template <class T>
struct IDChecker {
	typedef char no;
	typedef int yes;

	template <typename U, U> struct type_check;
	template <class C>
	static yes check(type_check<int C::*, &C::ID> *);
	template <class C>
	static no  check(...);

	static const bool value = sizeof(check<T>(0)) == sizeof(yes);
};

// ID reader for Struct class

template <class S, bool T>
struct IDReaderT {
};

template <class S>
struct IDReaderT<S, true> {
	static void ReadID(S& obj, LcfReader& stream) {
		obj.ID = stream.ReadInt();
	}
	static void WriteID(const S& obj, LcfWriter& stream) {
		stream.WriteInt(obj.ID);
	}
	static int IDSize(const S& obj) {
		return LcfReader::IntSize(obj.ID);
	}
	static void WriteXmlTag(const S& obj, const std::string& name, XmlWriter& stream) {
		stream.BeginElement(name, obj.ID);
	}
	static void ReadIDXml(S& obj, const char** atts) {
		for (int i = 0; atts[i] != NULL && atts[i + 1] != NULL; i += 2) {
			if (strcmp(atts[i], "id") == 0)
				obj.ID = atoi(atts[i + 1]);
		}
	}
};

template <class S>
struct IDReaderT<S, false> {
	static void ReadID(S& /* obj */, LcfReader& /* stream */) {}
	static void WriteID(const S& /* obj */, LcfWriter& /* stream */) {}
	static int IDSize(const S& /* obj */) { return 0; }
	static void WriteXmlTag(const S& /* obj */, const std::string& name, XmlWriter& stream) {
		stream.BeginElement(name);
	}
	static void ReadIDXml(S& /* obj */, const char** /* atts */) {}
};

struct StringComparator {
	bool operator() (const char* const& lhs, const char* const& rhs) const {
		return strcmp(lhs, rhs) < 0;
	}
};

// Struct class template

template <class S>
class Struct {
private:
	typedef std::map<int, const Field<S>* > field_map_type;
	typedef std::map<const char* const, const Field<S>*, StringComparator> tag_map_type;
	typedef IDReaderT<S, IDChecker<S>::value > IDReader;
	static const Field<S>* fields[];
	static field_map_type field_map;
	static tag_map_type tag_map;
	static const char* const name;

	static void MakeFieldMap();
	static void MakeTagMap();

	template <class T> friend class StructXmlHandler;
	template <class T> friend class StructVectorXmlHandler;
	template <class T> friend class StructFieldXmlHandler;

public:
	static void ReadLcf(S& obj, LcfReader& stream);
	static void WriteLcf(const S& obj, LcfWriter& stream);
	static int LcfSize(const S& obj, LcfWriter& stream);
	static void WriteXml(const S& obj, XmlWriter& stream);
	static void BeginXml(S& obj, XmlReader& stream);

	static void ReadLcf(std::vector<S>& obj, LcfReader& stream);
	static void WriteLcf(const std::vector<S>& obj, LcfWriter& stream);
	static int LcfSize(const std::vector<S>& obj, LcfWriter& stream);
	static void WriteXml(const std::vector<S>& obj, XmlWriter& stream);
	static void BeginXml(std::vector<S>& obj, XmlReader& stream);
};

template <class S>
std::map<int, const Field<S>* > Struct<S>::field_map;

template <class S>
std::map<const char* const, const Field<S>*, StringComparator> Struct<S>::tag_map;

/**
 * Struct reader.
*/
template <class T>
struct TypeReader<T, Category::Struct> {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t /* length */) {
		Struct<T>::ReadLcf(ref, stream);
	}
	static void WriteLcf(const T& ref, LcfWriter& stream) {
		Struct<T>::WriteLcf(ref, stream);
	}
	static int LcfSize(const T& ref, LcfWriter& stream) {
		return Struct<T>::LcfSize(ref, stream);
	}
	static void WriteXml(const T& ref, XmlWriter& stream) {
		Struct<T>::WriteXml(ref, stream);
	}
	static void BeginXml(T& ref, XmlReader& stream) {
		Struct<T>::BeginXml(ref, stream);
	}
	static void ParseXml(T& /* ref */, const std::string& /* data */) {
		// no-op
	}
};

template <class T>
struct TypeReader<std::vector<T>, Category::Struct> {
	static void ReadLcf(std::vector<T>& ref, LcfReader& stream, uint32_t /* length */) {
		Struct<T>::ReadLcf(ref, stream);
	}
	static void WriteLcf(const std::vector<T>& ref, LcfWriter& stream) {
		Struct<T>::WriteLcf(ref, stream);
	}
	static int LcfSize(const std::vector<T>& ref, LcfWriter& stream) {
		return Struct<T>::LcfSize(ref, stream);
	}
	static void WriteXml(const std::vector<T>& ref, XmlWriter& stream) {
		Struct<T>::WriteXml(ref, stream);
	}
	static void BeginXml(std::vector<T>& ref, XmlReader& stream) {
		Struct<T>::BeginXml(ref, stream);
	}
	static void ParseXml(std::vector<T>& /* ref */, const std::string& /* data */) {
		// no-op
	}
};

/**
 * Flags class template.
 */
template <class S>
class Flags {
public:
	struct Flag {
		Flag(bool S::*ref, const char* const name) : ref(ref), name(name) {}
		bool S::*ref;
		const char* const name;
	};

private:
	static const uint32_t max_size;
	typedef std::map<const char* const, const Flag*, StringComparator> tag_map_type;
	static const Flag* flags[];
	static tag_map_type tag_map;
	static const char* const name;

	static void MakeTagMap();

	template <class T> friend class FlagsXmlHandler;

public:
	static void ReadLcf(S& obj, LcfReader& stream, uint32_t length);
	static void WriteLcf(const S& obj, LcfWriter& stream);
	static int LcfSize(const S& obj, LcfWriter& stream);
	static void WriteXml(const S& obj, XmlWriter& stream);
	static void BeginXml(S& obj, XmlReader& stream);
};

template <class S>
std::map<const char* const, const typename Flags<S>::Flag*, StringComparator> Flags<S>::tag_map;

/**
 * Wrapper XML handler struct.
 */
template <class T>
struct TypeReader<T, Category::Flags> {
	static void ReadLcf(T& ref, LcfReader& stream, uint32_t length) {
		Flags<T>::ReadLcf(ref, stream, length);
	}
	static void WriteLcf(const T& ref, LcfWriter& stream) {
		Flags<T>::WriteLcf(ref, stream);
	}
	static int LcfSize(const T& ref, LcfWriter& stream) {
		return Flags<T>::LcfSize(ref, stream);
	}
	static void WriteXml(const T& ref, XmlWriter& stream) {
		Flags<T>::WriteXml(ref, stream);
	}
	static void BeginXml(T& ref, XmlReader& stream) {
		Flags<T>::BeginXml(ref, stream);
	}
	static void ParseXml(T& /* ref */, const std::string& /* data */) {
		// no-op
	}
};

/**
 * Wrapper XML handler class.
 */
class WrapperXmlHandler : public XmlHandler {
public:
	WrapperXmlHandler(const char* const name, XmlHandler* handler) :
		name(name), handler(handler) {}

	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		if (strcmp(name, this->name) != 0)
			stream.Error("Expecting %s but got %s", this->name, name);
		stream.SetHandler(handler);
	}

private:
	const char* const name;
	XmlHandler* handler;
};

/**
 * Root node XML handler.
 */
template <class S>
class RootXmlHandler : public XmlHandler {

public:
	RootXmlHandler(S& ref, const char* const name) : ref(ref), name(name) {}

	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		if (strcmp(name, this->name) != 0)
			stream.Error("Expecting %s but got %s", this->name, name);
		TypeReader<S>::BeginXml(ref, stream);
	}

private:
	S& ref;
	const char* const name;

};

// Macros

// needs define of
// - EASYRPG_CHUNK_SUFFIX
// - EASYRPG_CURRENT_STRUCT

#define EASYRPG_STRUCT_FIELDS_BEGIN() \
	template <> \
	char const* const Struct<RPG::EASYRPG_CURRENT_STRUCT>::name = BOOST_PP_STRINGIZE(EASYRPG_CURRENT_STRUCT); \
	template <> \
	Field<RPG::EASYRPG_CURRENT_STRUCT> const* Struct<RPG::EASYRPG_CURRENT_STRUCT>::fields[] = { \

#define EASYRPG_STRUCT_FIELDS_END() \
	NULL }; \

#define EASYRPG_STRUCT_TYPED_FIELD(T, REF) \
	new TypedField<RPG::EASYRPG_CURRENT_STRUCT, T>( \
		  &RPG::EASYRPG_CURRENT_STRUCT::REF \
		, EASYRPG_CHUNK_SUFFIX::BOOST_PP_CAT(Chunk, EASYRPG_CURRENT_STRUCT)::REF \
		, BOOST_PP_STRINGIZE(REF) \
	) \

#define EASYRPG_STRUCT_SIZE_FIELD(T, REF) \
	new SizeField<RPG::EASYRPG_CURRENT_STRUCT, T>( \
		  &RPG::EASYRPG_CURRENT_STRUCT::REF \
		, EASYRPG_CHUNK_SUFFIX::BOOST_PP_CAT(Chunk, EASYRPG_CURRENT_STRUCT)::BOOST_PP_CAT(REF, _size) \
	) \

#endif
