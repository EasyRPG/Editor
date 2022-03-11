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
#include "troop.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Troop::Troop(ProjectData& project, lcf::rpg::Troop& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		for (auto& var: m_data.members) {
			m_members.push_back(new Binding::TroopMember(m_project, var, this));
		}
		for (auto& var: m_data.pages) {
			m_pages.push_back(new Binding::TroopPage(m_project, var, this));
		}
	}
	int Troop::id() {
		return m_data.ID;
	}
	QString Troop::name() {
		return ToQString(m_data.name);
	}
	void Troop::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QVector<Binding::TroopMember*>& Troop::members() {
		return m_members;
	}

	bool Troop::auto_alignment() {
		return m_data.auto_alignment;
	}
	void Troop::set_auto_alignment(const bool& new_auto_alignment) {
		if (m_data.auto_alignment == new_auto_alignment)
			return;
		m_data.auto_alignment = new_auto_alignment;
		emit auto_alignment_changed();
	}

	QVector<bool> Troop::terrain_set() {
		return QVector<bool>(m_data.terrain_set.begin(), m_data.terrain_set.end());
	}
	void Troop::set_terrain_set(const QVector<bool>& new_terrain_set) {
		if (QVector<bool>(m_data.terrain_set.begin(), m_data.terrain_set.end()) == new_terrain_set)
			return;
		m_data.terrain_set = decltype(m_data.terrain_set)(new_terrain_set.begin(), new_terrain_set.end());
		emit terrain_set_changed();
	}

	bool Troop::appear_randomly() {
		return m_data.appear_randomly;
	}
	void Troop::set_appear_randomly(const bool& new_appear_randomly) {
		if (m_data.appear_randomly == new_appear_randomly)
			return;
		m_data.appear_randomly = new_appear_randomly;
		emit appear_randomly_changed();
	}

	QVector<Binding::TroopPage*>& Troop::pages() {
		return m_pages;
	}

} // namespace Binding::Generated
