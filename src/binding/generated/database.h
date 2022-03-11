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
	Q_PROPERTY(QVector<Binding::Actor*> actors READ actors CONSTANT)
	Q_PROPERTY(QVector<Binding::Skill*> skills READ skills CONSTANT)
	Q_PROPERTY(QVector<Binding::Item*> items READ items CONSTANT)
	Q_PROPERTY(QVector<Binding::Enemy*> enemies READ enemies CONSTANT)
	Q_PROPERTY(QVector<Binding::Troop*> troops READ troops CONSTANT)
	Q_PROPERTY(QVector<Binding::Terrain*> terrains READ terrains CONSTANT)
	Q_PROPERTY(QVector<Binding::Attribute*> attributes READ attributes CONSTANT)
	Q_PROPERTY(QVector<Binding::State*> states READ states CONSTANT)
	Q_PROPERTY(QVector<Binding::Animation*> animations READ animations CONSTANT)
	Q_PROPERTY(QVector<Binding::Chipset*> chipsets READ chipsets CONSTANT)
	Q_PROPERTY(Binding::Terms* terms READ terms CONSTANT)
	Q_PROPERTY(Binding::System* system READ system CONSTANT)
	Q_PROPERTY(QVector<Binding::Switch*> switches READ switches CONSTANT)
	Q_PROPERTY(QVector<Binding::Variable*> variables READ variables CONSTANT)
	Q_PROPERTY(QVector<Binding::CommonEvent*> commonevents READ commonevents CONSTANT)
	Q_PROPERTY(int32_t version READ version CONSTANT)
	Q_PROPERTY(Binding::BattleCommands* battlecommands READ battlecommands CONSTANT)
	Q_PROPERTY(QVector<Binding::Class*> classes READ classes CONSTANT)
	Q_PROPERTY(QVector<Binding::BattlerAnimation*> battleranimations READ battleranimations CONSTANT)

public:
	Database(ProjectData& project, lcf::rpg::Database& data, QObject* parent = nullptr);

	lcf::rpg::Database& data();
	QVector<Binding::Actor*>& actors();
	QVector<Binding::Skill*>& skills();
	QVector<Binding::Item*>& items();
	QVector<Binding::Enemy*>& enemies();
	QVector<Binding::Troop*>& troops();
	QVector<Binding::Terrain*>& terrains();
	QVector<Binding::Attribute*>& attributes();
	QVector<Binding::State*>& states();
	QVector<Binding::Animation*>& animations();
	QVector<Binding::Chipset*>& chipsets();
	Binding::Terms* terms();
	Binding::System* system();
	QVector<Binding::Switch*>& switches();
	QVector<Binding::Variable*>& variables();
	QVector<Binding::CommonEvent*>& commonevents();
	int32_t version();
	Binding::BattleCommands* battlecommands();
	QVector<Binding::Class*>& classes();
	QVector<Binding::BattlerAnimation*>& battleranimations();

signals:

protected:
	lcf::rpg::Database& m_data;
	QVector<Binding::Actor*> m_actors;
	QVector<Binding::Skill*> m_skills;
	QVector<Binding::Item*> m_items;
	QVector<Binding::Enemy*> m_enemies;
	QVector<Binding::Troop*> m_troops;
	QVector<Binding::Terrain*> m_terrains;
	QVector<Binding::Attribute*> m_attributes;
	QVector<Binding::State*> m_states;
	QVector<Binding::Animation*> m_animations;
	QVector<Binding::Chipset*> m_chipsets;
	Binding::Terms* m_terms;
	Binding::System* m_system;
	QVector<Binding::Switch*> m_switches;
	QVector<Binding::Variable*> m_variables;
	QVector<Binding::CommonEvent*> m_commonevents;
	Binding::BattleCommands* m_battlecommands;
	QVector<Binding::Class*> m_classes;
	QVector<Binding::BattlerAnimation*> m_battleranimations;
};
} // namespace Binding::Generated
