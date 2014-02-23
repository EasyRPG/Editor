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

#ifndef _LSD_READER_H_
#define _LSD_READER_H_

// Headers
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "rpg_save.h"

/**
 * LSD Reader namespace.
 */
namespace LSD_Reader {
	double ToMicrosoftAccessTime(std::time_t const t);
	std::time_t ToUnixTime(double const ms);
	double GenerateTimeStamp(std::time_t const t = std::time(NULL));

	std::auto_ptr<RPG::Save> Load(const std::string &filename, const std::string &encoding);
	bool Save(const std::string& filename, const RPG::Save& save, const std::string &encoding);
	bool SaveXml(const std::string& filename, const RPG::Save& save);
	std::auto_ptr<RPG::Save> LoadXml(const std::string &filename);
}

#endif
