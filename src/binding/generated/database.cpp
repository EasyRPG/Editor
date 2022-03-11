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
		{
			m_actors = new ArrayAdapter(this);
			auto& arr = m_actors->data();
			for (auto& var: m_data.actors)
				arr.push_back(new Binding::Actor(m_project, var, this));
		}
		{
			m_skills = new ArrayAdapter(this);
			auto& arr = m_skills->data();
			for (auto& var: m_data.skills)
				arr.push_back(new Binding::Skill(m_project, var, this));
		}
		{
			m_items = new ArrayAdapter(this);
			auto& arr = m_items->data();
			for (auto& var: m_data.items)
				arr.push_back(new Binding::Item(m_project, var, this));
		}
		{
			m_enemies = new ArrayAdapter(this);
			auto& arr = m_enemies->data();
			for (auto& var: m_data.enemies)
				arr.push_back(new Binding::Enemy(m_project, var, this));
		}
		{
			m_troops = new ArrayAdapter(this);
			auto& arr = m_troops->data();
			for (auto& var: m_data.troops)
				arr.push_back(new Binding::Troop(m_project, var, this));
		}
		{
			m_terrains = new ArrayAdapter(this);
			auto& arr = m_terrains->data();
			for (auto& var: m_data.terrains)
				arr.push_back(new Binding::Terrain(m_project, var, this));
		}
		{
			m_attributes = new ArrayAdapter(this);
			auto& arr = m_attributes->data();
			for (auto& var: m_data.attributes)
				arr.push_back(new Binding::Attribute(m_project, var, this));
		}
		{
			m_states = new ArrayAdapter(this);
			auto& arr = m_states->data();
			for (auto& var: m_data.states)
				arr.push_back(new Binding::State(m_project, var, this));
		}
		{
			m_animations = new ArrayAdapter(this);
			auto& arr = m_animations->data();
			for (auto& var: m_data.animations)
				arr.push_back(new Binding::Animation(m_project, var, this));
		}
		{
			m_chipsets = new ArrayAdapter(this);
			auto& arr = m_chipsets->data();
			for (auto& var: m_data.chipsets)
				arr.push_back(new Binding::Chipset(m_project, var, this));
		}
		m_terms = new Binding::Terms(m_project, m_data.terms, this);
		m_system = new Binding::System(m_project, m_data.system, this);
		{
			m_switches = new ArrayAdapter(this);
			auto& arr = m_switches->data();
			for (auto& var: m_data.switches)
				arr.push_back(new Binding::Switch(m_project, var, this));
		}
		{
			m_variables = new ArrayAdapter(this);
			auto& arr = m_variables->data();
			for (auto& var: m_data.variables)
				arr.push_back(new Binding::Variable(m_project, var, this));
		}
		{
			m_commonevents = new ArrayAdapter(this);
			auto& arr = m_commonevents->data();
			for (auto& var: m_data.commonevents)
				arr.push_back(new Binding::CommonEvent(m_project, var, this));
		}
		m_battlecommands = new Binding::BattleCommands(m_project, m_data.battlecommands, this);
		{
			m_classes = new ArrayAdapter(this);
			auto& arr = m_classes->data();
			for (auto& var: m_data.classes)
				arr.push_back(new Binding::Class(m_project, var, this));
		}
		{
			m_battleranimations = new ArrayAdapter(this);
			auto& arr = m_battleranimations->data();
			for (auto& var: m_data.battleranimations)
				arr.push_back(new Binding::BattlerAnimation(m_project, var, this));
		}
	}
	ArrayAdapter* Database::actors() {
		return m_actors;
	}

	ArrayAdapter* Database::skills() {
		return m_skills;
	}

	ArrayAdapter* Database::items() {
		return m_items;
	}

	ArrayAdapter* Database::enemies() {
		return m_enemies;
	}

	ArrayAdapter* Database::troops() {
		return m_troops;
	}

	ArrayAdapter* Database::terrains() {
		return m_terrains;
	}

	ArrayAdapter* Database::attributes() {
		return m_attributes;
	}

	ArrayAdapter* Database::states() {
		return m_states;
	}

	ArrayAdapter* Database::animations() {
		return m_animations;
	}

	ArrayAdapter* Database::chipsets() {
		return m_chipsets;
	}

	Binding::Terms* Database::terms() {
		return m_terms;
	}

	Binding::System* Database::system() {
		return m_system;
	}

	ArrayAdapter* Database::switches() {
		return m_switches;
	}

	ArrayAdapter* Database::variables() {
		return m_variables;
	}

	ArrayAdapter* Database::commonevents() {
		return m_commonevents;
	}

	int Database::version() {
		return m_data.version;
	}
	void Database::set_version(const int& new_version) {
		if (m_data.version == new_version)
			return;
		m_data.version = new_version;
		emit version_changed();
	}

	Binding::BattleCommands* Database::battlecommands() {
		return m_battlecommands;
	}

	ArrayAdapter* Database::classes() {
		return m_classes;
	}

	ArrayAdapter* Database::battleranimations() {
		return m_battleranimations;
	}

} // namespace Binding::Generated
