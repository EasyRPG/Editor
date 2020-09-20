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
#include "project_data.h"

Q_DECLARE_METATYPE(lcf::rpg::Actor*)
Q_DECLARE_METATYPE(lcf::rpg::Skill*)
Q_DECLARE_METATYPE(lcf::rpg::Enemy*)
Q_DECLARE_METATYPE(lcf::rpg::Item*)
Q_DECLARE_METATYPE(lcf::rpg::Troop*)
Q_DECLARE_METATYPE(lcf::rpg::Terrain*)
Q_DECLARE_METATYPE(lcf::rpg::Attribute*)
Q_DECLARE_METATYPE(lcf::rpg::State*)
Q_DECLARE_METATYPE(lcf::rpg::Animation*)
Q_DECLARE_METATYPE(lcf::rpg::Chipset*)
Q_DECLARE_METATYPE(lcf::rpg::CommonEvent*)
Q_DECLARE_METATYPE(lcf::rpg::Class*)
Q_DECLARE_METATYPE(lcf::rpg::BattlerAnimation*)
Q_DECLARE_METATYPE(lcf::rpg::Switch*)
Q_DECLARE_METATYPE(lcf::rpg::Variable*)

class ActorWidget;
class SkillWidget;
class EnemyWidget;
class ItemWidget;
class EnemyGroupWidget;
class TerrainWidget;
class AttributeWidget;
class StateWidget;
class BattleAnimationWidget;
class ChipsetWidget;
class ClassWidget;
class BattleAnimation2Widget;
class CommonEventWidget;
class SwitchWidget;
class VariableWidget;

template<typename T>
class RpgReflect {};

template<>
class RpgReflect<lcf::rpg::Actor> {
public:
	using widget_type = ActorWidget;
	using model_type = ActorModel;

	static std::vector<lcf::rpg::Actor>& items(lcf::rpg::Database& database) {
		return database.actors;
	}
};

template<>
class RpgReflect<lcf::rpg::Skill> {
public:
	using widget_type = SkillWidget;
	using model_type = SkillModel;

	static std::vector<lcf::rpg::Skill>& items(lcf::rpg::Database& database) {
		return database.skills;
	}
};

template<>
class RpgReflect<lcf::rpg::Enemy> {
public:
	using widget_type = EnemyWidget;
	using model_type = EnemyModel;

	static std::vector<lcf::rpg::Enemy>& items(lcf::rpg::Database& database) {
		return database.enemies;
	}
};

template<>
class RpgReflect<lcf::rpg::Item> {
public:
	using widget_type = ItemWidget;
	using model_type = ItemModel;

	static std::vector<lcf::rpg::Item>& items(lcf::rpg::Database& database) {
		return database.items;
	}
};

template<>
class RpgReflect<lcf::rpg::Troop> {
public:
	using widget_type = EnemyGroupWidget;
	using model_type = TroopModel;

	static std::vector<lcf::rpg::Troop>& items(lcf::rpg::Database& database) {
		return database.troops;
	}
};

template<>
class RpgReflect<lcf::rpg::Terrain> {
public:
	using widget_type = TerrainWidget;
	using model_type = TerrainModel;

	static std::vector<lcf::rpg::Terrain>& items(lcf::rpg::Database& database) {
		return database.terrains;
	}
};

template<>
class RpgReflect<lcf::rpg::Attribute> {
public:
	using widget_type = AttributeWidget;
	using model_type = AttributeModel;

	static std::vector<lcf::rpg::Attribute>& items(lcf::rpg::Database& database) {
		return database.attributes;
	}
};

template<>
class RpgReflect<lcf::rpg::State> {
public:
	using widget_type = StateWidget;
	using model_type = StateModel;

	static std::vector<lcf::rpg::State>& items(lcf::rpg::Database& database) {
		return database.states;
	}
};

template<>
class RpgReflect<lcf::rpg::Animation> {
public:
	using widget_type = BattleAnimationWidget;
	using model_type = AnimationModel;

	static std::vector<lcf::rpg::Animation>& items(lcf::rpg::Database& database) {
		return database.animations;
	}
};

template<>
class RpgReflect<lcf::rpg::Chipset> {
public:
	using widget_type = ChipsetWidget;
	using model_type = ChipsetModel;

	static std::vector<lcf::rpg::Chipset>& items(lcf::rpg::Database& database) {
		return database.chipsets;
	}
};

template<>
class RpgReflect<lcf::rpg::CommonEvent> {
public:
	using widget_type = CommonEventWidget;
	using model_type = CommonEventModel;

	static std::vector<lcf::rpg::CommonEvent>& items(lcf::rpg::Database& database) {
		return database.commonevents;
	}
};

template<>
class RpgReflect<lcf::rpg::Class> {
public:
	using widget_type = ClassWidget;
	using model_type = ClassModel;

	static std::vector<lcf::rpg::Class>& items(lcf::rpg::Database& database) {
		return database.classes;
	}
};

template<>
class RpgReflect<lcf::rpg::BattlerAnimation> {
public:
	using widget_type = BattleAnimation2Widget;
	using model_type = BattlerAnimationModel;

	static std::vector<lcf::rpg::BattlerAnimation>& items(lcf::rpg::Database& database) {
		return database.battleranimations;
	}
};

template<>
class RpgReflect<lcf::rpg::Switch> {
public:
	using widget_type = SwitchWidget;
	using model_type = SwitchModel;

	static std::vector<lcf::rpg::Switch>& items(lcf::rpg::Database& database) {
		return database.switches;
	}
};

template<>
class RpgReflect<lcf::rpg::Variable> {
public:
	using widget_type = VariableWidget;
	using model_type = VariableModel;

	static std::vector<lcf::rpg::Variable>& items(lcf::rpg::Database& database) {
		return database.variables;
	}
};
