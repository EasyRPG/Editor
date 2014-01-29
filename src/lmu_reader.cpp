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
#include "lmu_reader.h"
#include "lmu_chunks.h"
#include "reader_lcf.h"
#include "reader_util.h"
#include "reader_struct.h"

/**
 * Loads Map.
 */
std::auto_ptr<RPG::Map> LMU_Reader::Load(const std::string& filename) {
	LcfReader reader(filename, ReaderUtil::GetEncoding());
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s map file.\n", filename.c_str());
		return std::auto_ptr<RPG::Map>(NULL);
	}
	std::string header;
	reader.ReadString(header, reader.ReadInt());
	if (header != "LcfMapUnit") {
		LcfReader::SetError("%s is not a valid RPG2000 map.\n", filename.c_str());
		return std::auto_ptr<RPG::Map>(NULL);
	}

	RPG::Map* map = new RPG::Map();
	Struct<RPG::Map>::ReadLcf(*map, reader);
	return std::auto_ptr<RPG::Map>(map);
}

/**
 * Saves Map.
 */
bool LMU_Reader::Save(const std::string& filename, const RPG::Map& map) {
	LcfWriter writer(filename, ReaderUtil::GetEncoding());
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s map file.\n", filename.c_str());
		return false;
	}
	const std::string header("LcfMapUnit");
	writer.WriteInt(header.size());
	writer.Write(header);

	Struct<RPG::Map>::WriteLcf(map, writer);
	return true;
}

/**
 * Save Map as XML.
 */
bool LMU_Reader::SaveXml(const std::string& filename, const RPG::Map& map) {
	XmlWriter writer(filename);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s map file.\n", filename.c_str());
		return false;
	}
	writer.BeginElement("LMU");
	Struct<RPG::Map>::WriteXml(map, writer);
	writer.EndElement("LMU");
	return true;
}

/**
 * Loads Map as XML.
 */
std::auto_ptr<RPG::Map> LMU_Reader::LoadXml(const std::string& filename) {
	XmlReader reader(filename);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s map file.\n", filename.c_str());
		return std::auto_ptr<RPG::Map>(NULL);
	}

	RPG::Map* map = new RPG::Map();
	reader.SetHandler(new RootXmlHandler<RPG::Map>(*map, "LMU"));
	reader.Parse();
	return std::auto_ptr<RPG::Map>(map);
}

