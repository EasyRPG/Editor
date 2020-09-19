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

namespace RpgFactory {
	inline ActorModel Create(ProjectData &project, lcf::rpg::Actor &data) {
		return ActorModel(project, data);
	}

	inline SkillModel Create(ProjectData &project, lcf::rpg::Skill &data) {
		return SkillModel(project, data);
	}

	inline EnemyModel Create(ProjectData &project, lcf::rpg::Enemy &data) {
		return EnemyModel(project, data);
	}

	inline ItemModel Create(ProjectData &project, lcf::rpg::Item &data) {
		return ItemModel(project, data);
	}

	inline TroopModel Create(ProjectData &project, lcf::rpg::Troop &data) {
		return TroopModel(project, data);
	}

	inline TerrainModel Create(ProjectData &project, lcf::rpg::Terrain &data) {
		return TerrainModel(project, data);
	}

	inline AttributeModel Create(ProjectData &project, lcf::rpg::Attribute &data) {
		return AttributeModel(project, data);
	}

	inline StateModel Create(ProjectData &project, lcf::rpg::State &data) {
		return StateModel(project, data);
	}

	inline AnimationModel Create(ProjectData &project, lcf::rpg::Animation &data) {
		return AnimationModel(project, data);
	}

	inline ChipsetModel Create(ProjectData &project, lcf::rpg::Chipset &data) {
		return ChipsetModel(project, data);
	}

	inline CommonEventModel Create(ProjectData &project, lcf::rpg::CommonEvent &data) {
		return CommonEventModel(project, data);
	}

	inline ClassModel Create(ProjectData &project, lcf::rpg::Class &data) {
		return ClassModel(project, data);
	}

	inline BattlerAnimationModel Create(ProjectData &project, lcf::rpg::BattlerAnimation &data) {
		return BattlerAnimationModel(project, data);
	}

	inline SwitchModel Create(ProjectData &project, lcf::rpg::Switch &data) {
		return SwitchModel(project, data);
	}

	inline VariableModel Create(ProjectData &project, lcf::rpg::Variable &data) {
		return VariableModel(project, data);
	}
}