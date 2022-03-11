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

// Headers
#include "database.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Database::Database(ProjectData& project, lcf::rpg::Database& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		for (auto& var: m_data.actors) {
			m_actors.push_back(new Binding::Actor(m_project, var, this));
		}
		for (auto& var: m_data.skills) {
			m_skills.push_back(new Binding::Skill(m_project, var, this));
		}
		for (auto& var: m_data.items) {
			m_items.push_back(new Binding::Item(m_project, var, this));
		}
		for (auto& var: m_data.enemies) {
			m_enemies.push_back(new Binding::Enemy(m_project, var, this));
		}
		for (auto& var: m_data.troops) {
			m_troops.push_back(new Binding::Troop(m_project, var, this));
		}
		for (auto& var: m_data.terrains) {
			m_terrains.push_back(new Binding::Terrain(m_project, var, this));
		}
		for (auto& var: m_data.attributes) {
			m_attributes.push_back(new Binding::Attribute(m_project, var, this));
		}
		for (auto& var: m_data.states) {
			m_states.push_back(new Binding::State(m_project, var, this));
		}
		for (auto& var: m_data.animations) {
			m_animations.push_back(new Binding::Animation(m_project, var, this));
		}
		for (auto& var: m_data.chipsets) {
			m_chipsets.push_back(new Binding::Chipset(m_project, var, this));
		}
		m_terms = new Binding::Terms(m_project, m_data.terms, this);
		m_system = new Binding::System(m_project, m_data.system, this);
		for (auto& var: m_data.switches) {
			m_switches.push_back(new Binding::Switch(m_project, var, this));
		}
		for (auto& var: m_data.variables) {
			m_variables.push_back(new Binding::Variable(m_project, var, this));
		}
		for (auto& var: m_data.commonevents) {
			m_commonevents.push_back(new Binding::CommonEvent(m_project, var, this));
		}
		m_battlecommands = new Binding::BattleCommands(m_project, m_data.battlecommands, this);
		for (auto& var: m_data.classes) {
			m_classes.push_back(new Binding::Class(m_project, var, this));
		}
		for (auto& var: m_data.battleranimations) {
			m_battleranimations.push_back(new Binding::BattlerAnimation(m_project, var, this));
		}
	}
	QVector<Binding::Actor*>& Database::actors() {
		return m_actors;
	}

	QVector<Binding::Skill*>& Database::skills() {
		return m_skills;
	}

	QVector<Binding::Item*>& Database::items() {
		return m_items;
	}

	QVector<Binding::Enemy*>& Database::enemies() {
		return m_enemies;
	}

	QVector<Binding::Troop*>& Database::troops() {
		return m_troops;
	}

	QVector<Binding::Terrain*>& Database::terrains() {
		return m_terrains;
	}

	QVector<Binding::Attribute*>& Database::attributes() {
		return m_attributes;
	}

	QVector<Binding::State*>& Database::states() {
		return m_states;
	}

	QVector<Binding::Animation*>& Database::animations() {
		return m_animations;
	}

	QVector<Binding::Chipset*>& Database::chipsets() {
		return m_chipsets;
	}

	Binding::Terms* Database::terms() {
		return m_terms;
	}

	Binding::System* Database::system() {
		return m_system;
	}

	QVector<Binding::Switch*>& Database::switches() {
		return m_switches;
	}

	QVector<Binding::Variable*>& Database::variables() {
		return m_variables;
	}

	QVector<Binding::CommonEvent*>& Database::commonevents() {
		return m_commonevents;
	}

	int32_t Database::version() {
		return m_data.version;
	}

	Binding::BattleCommands* Database::battlecommands() {
		return m_battlecommands;
	}

	QVector<Binding::Class*>& Database::classes() {
		return m_classes;
	}

	QVector<Binding::BattlerAnimation*>& Database::battleranimations() {
		return m_battleranimations;
	}

} // namespace Binding::Generated
