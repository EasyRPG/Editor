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
#include <lcf/rpg/mapinfo.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/rect.h"
#include "binding/encounter.h"
#include "binding/music.h"

class ProjectData;

/**
 * Binding::Generated::MapInfo class.
 * Exposes lcf::rpg::MapInfo to QML.
 */
namespace Binding::Generated {
class MapInfo : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int32_t parent_map READ parent_map CONSTANT)
	Q_PROPERTY(int indentation READ indentation WRITE set_indentation NOTIFY indentation_changed)
	Q_PROPERTY(int32_t type READ type CONSTANT)
	Q_PROPERTY(int scrollbar_x READ scrollbar_x WRITE set_scrollbar_x NOTIFY scrollbar_x_changed)
	Q_PROPERTY(int scrollbar_y READ scrollbar_y WRITE set_scrollbar_y NOTIFY scrollbar_y_changed)
	Q_PROPERTY(bool expanded_node READ expanded_node WRITE set_expanded_node NOTIFY expanded_node_changed)
	Q_PROPERTY(int32_t music_type READ music_type CONSTANT)
	Q_PROPERTY(Binding::Music* music READ music CONSTANT)
	Q_PROPERTY(int32_t background_type READ background_type CONSTANT)
	Q_PROPERTY(QString background_name READ background_name WRITE set_background_name NOTIFY background_name_changed)
	Q_PROPERTY(int32_t teleport READ teleport CONSTANT)
	Q_PROPERTY(int32_t escape READ escape CONSTANT)
	Q_PROPERTY(int32_t save READ save CONSTANT)
	Q_PROPERTY(ArrayAdapter* encounters READ encounters CONSTANT)
	Q_PROPERTY(int encounter_steps READ encounter_steps WRITE set_encounter_steps NOTIFY encounter_steps_changed)
	Q_PROPERTY(Binding::Rect* area_rect READ area_rect CONSTANT)

public:
	MapInfo(ProjectData& project, lcf::rpg::MapInfo& data, QObject* parent = nullptr);

	lcf::rpg::MapInfo& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int32_t parent_map();
	int indentation();
	void set_indentation(const int& new_indentation);
	int32_t type();
	int scrollbar_x();
	void set_scrollbar_x(const int& new_scrollbar_x);
	int scrollbar_y();
	void set_scrollbar_y(const int& new_scrollbar_y);
	bool expanded_node();
	void set_expanded_node(const bool& new_expanded_node);
	int32_t music_type();
	Binding::Music* music();
	int32_t background_type();
	QString background_name();
	void set_background_name(const QString& new_background_name);
	int32_t teleport();
	int32_t escape();
	int32_t save();
	ArrayAdapter* encounters();
	int encounter_steps();
	void set_encounter_steps(const int& new_encounter_steps);
	Binding::Rect* area_rect();

signals:
	void name_changed();
	void indentation_changed();
	void scrollbar_x_changed();
	void scrollbar_y_changed();
	void expanded_node_changed();
	void background_name_changed();
	void encounter_steps_changed();

protected:
	lcf::rpg::MapInfo& m_data;
	Binding::Music* m_music;
	ArrayAdapter* m_encounters;
	Binding::Rect* m_area_rect;
};
} // namespace Binding::Generated
