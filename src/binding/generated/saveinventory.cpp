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
#include "saveinventory.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveInventory::SaveInventory(ProjectData& project, lcf::rpg::SaveInventory& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	QVector<int> SaveInventory::party() {
		return QVector<int>(m_data.party.begin(), m_data.party.end());
	}
	void SaveInventory::set_party(const QVector<int>& new_party) {
		if (QVector<int>(m_data.party.begin(), m_data.party.end()) == new_party)
			return;
		m_data.party = decltype(m_data.party)(new_party.begin(), new_party.end());
		emit party_changed();
	}

	QVector<int> SaveInventory::item_ids() {
		return QVector<int>(m_data.item_ids.begin(), m_data.item_ids.end());
	}
	void SaveInventory::set_item_ids(const QVector<int>& new_item_ids) {
		if (QVector<int>(m_data.item_ids.begin(), m_data.item_ids.end()) == new_item_ids)
			return;
		m_data.item_ids = decltype(m_data.item_ids)(new_item_ids.begin(), new_item_ids.end());
		emit item_ids_changed();
	}

	QVector<int> SaveInventory::item_counts() {
		return QVector<int>(m_data.item_counts.begin(), m_data.item_counts.end());
	}
	void SaveInventory::set_item_counts(const QVector<int>& new_item_counts) {
		if (QVector<int>(m_data.item_counts.begin(), m_data.item_counts.end()) == new_item_counts)
			return;
		m_data.item_counts = decltype(m_data.item_counts)(new_item_counts.begin(), new_item_counts.end());
		emit item_counts_changed();
	}

	QVector<int> SaveInventory::item_usage() {
		return QVector<int>(m_data.item_usage.begin(), m_data.item_usage.end());
	}
	void SaveInventory::set_item_usage(const QVector<int>& new_item_usage) {
		if (QVector<int>(m_data.item_usage.begin(), m_data.item_usage.end()) == new_item_usage)
			return;
		m_data.item_usage = decltype(m_data.item_usage)(new_item_usage.begin(), new_item_usage.end());
		emit item_usage_changed();
	}

	int SaveInventory::gold() {
		return m_data.gold;
	}
	void SaveInventory::set_gold(const int& new_gold) {
		if (m_data.gold == new_gold)
			return;
		m_data.gold = new_gold;
		emit gold_changed();
	}

	int SaveInventory::timer1_frames() {
		return m_data.timer1_frames;
	}
	void SaveInventory::set_timer1_frames(const int& new_timer1_frames) {
		if (m_data.timer1_frames == new_timer1_frames)
			return;
		m_data.timer1_frames = new_timer1_frames;
		emit timer1_frames_changed();
	}

	bool SaveInventory::timer1_active() {
		return m_data.timer1_active;
	}
	void SaveInventory::set_timer1_active(const bool& new_timer1_active) {
		if (m_data.timer1_active == new_timer1_active)
			return;
		m_data.timer1_active = new_timer1_active;
		emit timer1_active_changed();
	}

	bool SaveInventory::timer1_visible() {
		return m_data.timer1_visible;
	}
	void SaveInventory::set_timer1_visible(const bool& new_timer1_visible) {
		if (m_data.timer1_visible == new_timer1_visible)
			return;
		m_data.timer1_visible = new_timer1_visible;
		emit timer1_visible_changed();
	}

	bool SaveInventory::timer1_battle() {
		return m_data.timer1_battle;
	}
	void SaveInventory::set_timer1_battle(const bool& new_timer1_battle) {
		if (m_data.timer1_battle == new_timer1_battle)
			return;
		m_data.timer1_battle = new_timer1_battle;
		emit timer1_battle_changed();
	}

	int SaveInventory::timer2_frames() {
		return m_data.timer2_frames;
	}
	void SaveInventory::set_timer2_frames(const int& new_timer2_frames) {
		if (m_data.timer2_frames == new_timer2_frames)
			return;
		m_data.timer2_frames = new_timer2_frames;
		emit timer2_frames_changed();
	}

	bool SaveInventory::timer2_active() {
		return m_data.timer2_active;
	}
	void SaveInventory::set_timer2_active(const bool& new_timer2_active) {
		if (m_data.timer2_active == new_timer2_active)
			return;
		m_data.timer2_active = new_timer2_active;
		emit timer2_active_changed();
	}

	bool SaveInventory::timer2_visible() {
		return m_data.timer2_visible;
	}
	void SaveInventory::set_timer2_visible(const bool& new_timer2_visible) {
		if (m_data.timer2_visible == new_timer2_visible)
			return;
		m_data.timer2_visible = new_timer2_visible;
		emit timer2_visible_changed();
	}

	bool SaveInventory::timer2_battle() {
		return m_data.timer2_battle;
	}
	void SaveInventory::set_timer2_battle(const bool& new_timer2_battle) {
		if (m_data.timer2_battle == new_timer2_battle)
			return;
		m_data.timer2_battle = new_timer2_battle;
		emit timer2_battle_changed();
	}

	int SaveInventory::battles() {
		return m_data.battles;
	}
	void SaveInventory::set_battles(const int& new_battles) {
		if (m_data.battles == new_battles)
			return;
		m_data.battles = new_battles;
		emit battles_changed();
	}

	int SaveInventory::defeats() {
		return m_data.defeats;
	}
	void SaveInventory::set_defeats(const int& new_defeats) {
		if (m_data.defeats == new_defeats)
			return;
		m_data.defeats = new_defeats;
		emit defeats_changed();
	}

	int SaveInventory::escapes() {
		return m_data.escapes;
	}
	void SaveInventory::set_escapes(const int& new_escapes) {
		if (m_data.escapes == new_escapes)
			return;
		m_data.escapes = new_escapes;
		emit escapes_changed();
	}

	int SaveInventory::victories() {
		return m_data.victories;
	}
	void SaveInventory::set_victories(const int& new_victories) {
		if (m_data.victories == new_victories)
			return;
		m_data.victories = new_victories;
		emit victories_changed();
	}

	int SaveInventory::turns() {
		return m_data.turns;
	}
	void SaveInventory::set_turns(const int& new_turns) {
		if (m_data.turns == new_turns)
			return;
		m_data.turns = new_turns;
		emit turns_changed();
	}

	int SaveInventory::steps() {
		return m_data.steps;
	}
	void SaveInventory::set_steps(const int& new_steps) {
		if (m_data.steps == new_steps)
			return;
		m_data.steps = new_steps;
		emit steps_changed();
	}

} // namespace Binding::Generated
