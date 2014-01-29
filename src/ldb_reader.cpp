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

// Headers
#include "ldb_reader.h"
#include "ldb_chunks.h"
#include "data.h"
#include "reader_util.h"
#include "reader_struct.h"

/**
 * Loads Database.
 */
bool LDB_Reader::Load(const std::string& filename) {
	LcfReader reader(filename, ReaderUtil::GetEncoding());
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s database file.\n", filename.c_str());
		return false;
	}
	std::string header;
	reader.ReadString(header, reader.ReadInt());
	if (header != "LcfDataBase") {
		LcfReader::SetError("%s is not a valid RPG2000 database.\n", filename.c_str());
		return false;
	}
	TypeReader<RPG::Database>::ReadLcf(Data::data, reader, 0);
	return true;
}

/**
 * Saves Database.
 */
bool LDB_Reader::Save(const std::string& filename) {
	LcfWriter writer(filename, ReaderUtil::GetEncoding());
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't open %s database file.\n", filename.c_str());
		return false;
	}
	const std::string header("LcfDataBase");
	writer.WriteInt(header.size());
	writer.Write(header);
	TypeReader<RPG::Database>::WriteLcf(Data::data, writer);
	return true;
}

/**
 * Saves Database as XML.
 */
bool LDB_Reader::SaveXml(const std::string& filename) {
	XmlWriter writer(filename);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't open %s database file.\n", filename.c_str());
		return false;
	}
	writer.BeginElement("LDB");
	TypeReader<RPG::Database>::WriteXml(Data::data, writer);
	writer.EndElement("LDB");
	return true;
}

/**
 * Load Database as XML.
 */
bool LDB_Reader::LoadXml(const std::string& filename) {
	XmlReader reader(filename);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't open %s database file.\n", filename.c_str());
		return false;
	}
	reader.SetHandler(new RootXmlHandler<RPG::Database>(Data::data, "LDB"));
	reader.Parse();
	return true;
}
