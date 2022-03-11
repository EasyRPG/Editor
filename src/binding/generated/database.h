/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
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

// Headers
#include <lcf/rpg/database.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/actor.h"
#include "binding/animation.h"
#include "binding/attribute.h"
#include "binding/battlecommands.h"
#include "binding/battleranimation.h"
#include "binding/chipset.h"
#include "binding/class.h"
#include "binding/commonevent.h"
#include "binding/enemy.h"
#include "binding/item.h"
#include "binding/skill.h"
#include "binding/state.h"
#include "binding/switch.h"
#include "binding/system.h"
#include "binding/terms.h"
#include "binding/terrain.h"
#include "binding/troop.h"
#include "binding/variable.h"

class ProjectData;

/**
 * Binding::Generated::Database class.
 * Exposes lcf::rpg::Database to QML.
 */
namespace Binding::Generated {
class Database : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(ArrayAdapter* actors READ actors CONSTANT)
	Q_PROPERTY(ArrayAdapter* skills READ skills CONSTANT)
	Q_PROPERTY(ArrayAdapter* items READ items CONSTANT)
	Q_PROPERTY(ArrayAdapter* enemies READ enemies CONSTANT)
	Q_PROPERTY(ArrayAdapter* troops READ troops CONSTANT)
	Q_PROPERTY(ArrayAdapter* terrains READ terrains CONSTANT)
	Q_PROPERTY(ArrayAdapter* attributes READ attributes CONSTANT)
	Q_PROPERTY(ArrayAdapter* states READ states CONSTANT)
	Q_PROPERTY(ArrayAdapter* animations READ animations CONSTANT)
	Q_PROPERTY(ArrayAdapter* chipsets READ chipsets CONSTANT)
	Q_PROPERTY(Binding::Terms* terms READ terms CONSTANT)
	Q_PROPERTY(Binding::System* system READ system CONSTANT)
	Q_PROPERTY(ArrayAdapter* switches READ switches CONSTANT)
	Q_PROPERTY(ArrayAdapter* variables READ variables CONSTANT)
	Q_PROPERTY(ArrayAdapter* commonevents READ commonevents CONSTANT)
	Q_PROPERTY(int version READ version WRITE set_version NOTIFY version_changed)
	Q_PROPERTY(Binding::BattleCommands* battlecommands READ battlecommands CONSTANT)
	Q_PROPERTY(ArrayAdapter* classes READ classes CONSTANT)
	Q_PROPERTY(ArrayAdapter* battleranimations READ battleranimations CONSTANT)

public:
	Database(ProjectData& project, lcf::rpg::Database& data, QObject* parent = nullptr);

	lcf::rpg::Database& data();
	ArrayAdapter* actors();
	ArrayAdapter* skills();
	ArrayAdapter* items();
	ArrayAdapter* enemies();
	ArrayAdapter* troops();
	ArrayAdapter* terrains();
	ArrayAdapter* attributes();
	ArrayAdapter* states();
	ArrayAdapter* animations();
	ArrayAdapter* chipsets();
	Binding::Terms* terms();
	Binding::System* system();
	ArrayAdapter* switches();
	ArrayAdapter* variables();
	ArrayAdapter* commonevents();
	int version();
	void set_version(const int& new_version);
	Binding::BattleCommands* battlecommands();
	ArrayAdapter* classes();
	ArrayAdapter* battleranimations();

signals:
	void version_changed();

protected:
	lcf::rpg::Database& m_data;
	ArrayAdapter* m_actors;
	ArrayAdapter* m_skills;
	ArrayAdapter* m_items;
	ArrayAdapter* m_enemies;
	ArrayAdapter* m_troops;
	ArrayAdapter* m_terrains;
	ArrayAdapter* m_attributes;
	ArrayAdapter* m_states;
	ArrayAdapter* m_animations;
	ArrayAdapter* m_chipsets;
	Binding::Terms* m_terms;
	Binding::System* m_system;
	ArrayAdapter* m_switches;
	ArrayAdapter* m_variables;
	ArrayAdapter* m_commonevents;
	Binding::BattleCommands* m_battlecommands;
	ArrayAdapter* m_classes;
	ArrayAdapter* m_battleranimations;
};
} // namespace Binding::Generated
