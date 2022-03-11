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
#include <lcf/rpg/saveinventory.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveInventory class.
 * Exposes lcf::rpg::SaveInventory to QML.
 */
namespace Binding::Generated {
class SaveInventory : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(QVector<int> party READ party WRITE set_party NOTIFY party_changed)
	Q_PROPERTY(QVector<int> item_ids READ item_ids WRITE set_item_ids NOTIFY item_ids_changed)
	Q_PROPERTY(QVector<int> item_counts READ item_counts WRITE set_item_counts NOTIFY item_counts_changed)
	Q_PROPERTY(QVector<int> item_usage READ item_usage WRITE set_item_usage NOTIFY item_usage_changed)
	Q_PROPERTY(int gold READ gold WRITE set_gold NOTIFY gold_changed)
	Q_PROPERTY(int timer1_frames READ timer1_frames WRITE set_timer1_frames NOTIFY timer1_frames_changed)
	Q_PROPERTY(bool timer1_active READ timer1_active WRITE set_timer1_active NOTIFY timer1_active_changed)
	Q_PROPERTY(bool timer1_visible READ timer1_visible WRITE set_timer1_visible NOTIFY timer1_visible_changed)
	Q_PROPERTY(bool timer1_battle READ timer1_battle WRITE set_timer1_battle NOTIFY timer1_battle_changed)
	Q_PROPERTY(int timer2_frames READ timer2_frames WRITE set_timer2_frames NOTIFY timer2_frames_changed)
	Q_PROPERTY(bool timer2_active READ timer2_active WRITE set_timer2_active NOTIFY timer2_active_changed)
	Q_PROPERTY(bool timer2_visible READ timer2_visible WRITE set_timer2_visible NOTIFY timer2_visible_changed)
	Q_PROPERTY(bool timer2_battle READ timer2_battle WRITE set_timer2_battle NOTIFY timer2_battle_changed)
	Q_PROPERTY(int battles READ battles WRITE set_battles NOTIFY battles_changed)
	Q_PROPERTY(int defeats READ defeats WRITE set_defeats NOTIFY defeats_changed)
	Q_PROPERTY(int escapes READ escapes WRITE set_escapes NOTIFY escapes_changed)
	Q_PROPERTY(int victories READ victories WRITE set_victories NOTIFY victories_changed)
	Q_PROPERTY(int turns READ turns WRITE set_turns NOTIFY turns_changed)
	Q_PROPERTY(int steps READ steps WRITE set_steps NOTIFY steps_changed)

public:
	SaveInventory(ProjectData& project, lcf::rpg::SaveInventory& data, QObject* parent = nullptr);

	lcf::rpg::SaveInventory& data();
	QVector<int> party();
	void set_party(const QVector<int>& new_party);
	QVector<int> item_ids();
	void set_item_ids(const QVector<int>& new_item_ids);
	QVector<int> item_counts();
	void set_item_counts(const QVector<int>& new_item_counts);
	QVector<int> item_usage();
	void set_item_usage(const QVector<int>& new_item_usage);
	int gold();
	void set_gold(const int& new_gold);
	int timer1_frames();
	void set_timer1_frames(const int& new_timer1_frames);
	bool timer1_active();
	void set_timer1_active(const bool& new_timer1_active);
	bool timer1_visible();
	void set_timer1_visible(const bool& new_timer1_visible);
	bool timer1_battle();
	void set_timer1_battle(const bool& new_timer1_battle);
	int timer2_frames();
	void set_timer2_frames(const int& new_timer2_frames);
	bool timer2_active();
	void set_timer2_active(const bool& new_timer2_active);
	bool timer2_visible();
	void set_timer2_visible(const bool& new_timer2_visible);
	bool timer2_battle();
	void set_timer2_battle(const bool& new_timer2_battle);
	int battles();
	void set_battles(const int& new_battles);
	int defeats();
	void set_defeats(const int& new_defeats);
	int escapes();
	void set_escapes(const int& new_escapes);
	int victories();
	void set_victories(const int& new_victories);
	int turns();
	void set_turns(const int& new_turns);
	int steps();
	void set_steps(const int& new_steps);

signals:
	void party_changed();
	void item_ids_changed();
	void item_counts_changed();
	void item_usage_changed();
	void gold_changed();
	void timer1_frames_changed();
	void timer1_active_changed();
	void timer1_visible_changed();
	void timer1_battle_changed();
	void timer2_frames_changed();
	void timer2_active_changed();
	void timer2_visible_changed();
	void timer2_battle_changed();
	void battles_changed();
	void defeats_changed();
	void escapes_changed();
	void victories_changed();
	void turns_changed();
	void steps_changed();

protected:
	lcf::rpg::SaveInventory& m_data;
};
} // namespace Binding::Generated
