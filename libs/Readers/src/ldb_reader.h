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

#ifndef _LDB_READER_H_
#define _LDB_READER_H_

// Headers
#include <string>
#include <vector>
#include "rpg_actor.h"
#include "rpg_skill.h"
#include "rpg_item.h"
#include "rpg_enemy.h"
#include "rpg_troop.h"
#include "rpg_attribute.h"
#include "rpg_state.h"
#include "rpg_terrain.h"
#include "rpg_chipset.h"
#include "rpg_animation.h"
#include "rpg_terms.h"
#include "rpg_system.h"
#include "rpg_commonevent.h"
#include "rpg_music.h"
#include "rpg_sound.h"
#include "rpg_class.h"
#include "rpg_battlecommand.h"
#include "rpg_battleranimation.h"
#include "rpg_battleranimationdata.h"
#include "rpg_itemanimation.h"
#include "rpg_parameters.h"
#include "rpg_equipment.h"
#include "rpg_database.h"

/**
 * LDB Reader namespace.
 */
namespace LDB_Reader {
	bool Load(const std::string &filename, const std::string &encoding);
	bool Save(const std::string &filename, const std::string &encoding);
	bool SaveXml(const std::string &filename);
	bool LoadXml(const std::string &filename);
}

#endif
