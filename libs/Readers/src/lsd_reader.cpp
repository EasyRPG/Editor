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
#include <cmath>
#include "lsd_reader.h"
#include "lsd_chunks.h"
#include "ldb_reader.h"
#include "rpg_save.h"
#include "reader_util.h"
#include "reader_struct.h"

/**
 * Timestamp.
 */
namespace {
double const DIFF_DAYS = std::floor(365.2422 * 70) + 3;
double const SECOND_PER_HOUR = 60 * 60 * 24;
}

double LSD_Reader::ToMicrosoftAccessTime(std::time_t const t) {
	return(t / SECOND_PER_HOUR + DIFF_DAYS);
}
std::time_t LSD_Reader::ToUnixTime(double const ms) {
	return(std::time_t(ms * SECOND_PER_HOUR - DIFF_DAYS * SECOND_PER_HOUR));
}

double LSD_Reader::GenerateTimeStamp(std::time_t const t) {
	return ToMicrosoftAccessTime(t);
}

/**
 * Loads Savegame.
 */
std::auto_ptr<RPG::Save> LSD_Reader::Load(const std::string& filename, const std::string &encoding) {
	LcfReader reader(filename, encoding);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s save file.\n", filename.c_str());
		return std::auto_ptr<RPG::Save>(NULL);
	}
	std::string header;
	reader.ReadString(header, reader.ReadInt());
	if (header.length() != 11) {
		LcfReader::SetError("%s is not a valid RPG2000 save.\n", filename.c_str());
		return std::auto_ptr<RPG::Save>(NULL);
	}
	if (header != "LcfSaveData") {
		fprintf(stderr, "Warning: %s header is not LcfSaveData and might not be a valid RPG2000 save.\n", filename.c_str());
	}
	RPG::Save* save = new RPG::Save();
	Struct<RPG::Save>::ReadLcf(*save, reader);
	return std::auto_ptr<RPG::Save>(save);
}

/**
 * Saves Savegame.
 */
bool LSD_Reader::Save(const std::string& filename, const RPG::Save& save, const std::string &encoding) {
	LcfWriter writer(filename, encoding);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s save file.\n", filename.c_str());
		return false;
	}
	const std::string header("LcfSaveData");
	writer.WriteInt(header.size());
	writer.Write(header);

	const_cast<RPG::Save&>(save).title.timestamp = GenerateTimeStamp();

	Struct<RPG::Save>::WriteLcf(save, writer);
	return true;
}

/*
 * Saves Savegame as XML.
 */
bool LSD_Reader::SaveXml(const std::string& filename, const RPG::Save& save) {
	XmlWriter writer(filename);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't find %s save file.\n", filename.c_str());
		return false;
	}

	writer.BeginElement("LSD");
	Struct<RPG::Save>::WriteXml(save, writer);
	writer.EndElement("LSD");
	return true;
}

/**
 * Loads Savegame as XML.
 */
std::auto_ptr<RPG::Save> LSD_Reader::LoadXml(const std::string& filename) {
	XmlReader reader(filename);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't find %s save file.\n", filename.c_str());
		return std::auto_ptr<RPG::Save>(NULL);
	}

	RPG::Save* save = new RPG::Save();
	reader.SetHandler(new RootXmlHandler<RPG::Save>(*save, "LSD"));
	reader.Parse();
	return std::auto_ptr<RPG::Save>(save);
}

