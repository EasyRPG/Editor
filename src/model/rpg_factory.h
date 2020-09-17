/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "actor.h"
#include "skill.h"
#include "enemy.h"
#include "item.h"
#include "troop.h"
#include "terrain.h"
#include "attribute.h"
#include "state.h"
#include "animation.h"
#include "chipset.h"
#include "commonevent.h"
#include "class.h"
#include "battleranimation.h"
#include "switch.h"
#include "variable.h"

namespace RpgFactory {
	template<typename T>
	static auto Create(T& data, lcf::rpg::Database& database) {
		if constexpr (std::is_same_v<lcf::rpg::Actor, T>) {
			return Actor(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Skill, T>) {
			return Skill(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Enemy, T>) {
			return Enemy(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Item, T>) {
			return Item(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Troop, T>) {
			return Troop(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Terrain, T>) {
			return Terrain(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Attribute, T>) {
			return Attribute(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::State, T>) {
			return State(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Animation, T>) {
			return Animation(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Chipset, T>) {
			return Chipset(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::CommonEvent, T>) {
			return CommonEvent(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Class, T>) {
			return Class(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::BattlerAnimation, T>) {
			return BattlerAnimation(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Switch, T>) {
			return Switch(data, database);
		} else if constexpr (std::is_same_v<lcf::rpg::Variable, T>) {
			return Variable(data, database);
		}

		assert(false);
	}
}