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
	Q_PROPERTY(int parent_map READ parent_map WRITE set_parent_map NOTIFY parent_map_changed)
	Q_PROPERTY(int indentation READ indentation WRITE set_indentation NOTIFY indentation_changed)
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)
	Q_PROPERTY(int scrollbar_x READ scrollbar_x WRITE set_scrollbar_x NOTIFY scrollbar_x_changed)
	Q_PROPERTY(int scrollbar_y READ scrollbar_y WRITE set_scrollbar_y NOTIFY scrollbar_y_changed)
	Q_PROPERTY(bool expanded_node READ expanded_node WRITE set_expanded_node NOTIFY expanded_node_changed)
	Q_PROPERTY(int music_type READ music_type WRITE set_music_type NOTIFY music_type_changed)
	Q_PROPERTY(Binding::Music* music READ music CONSTANT)
	Q_PROPERTY(int background_type READ background_type WRITE set_background_type NOTIFY background_type_changed)
	Q_PROPERTY(QString background_name READ background_name WRITE set_background_name NOTIFY background_name_changed)
	Q_PROPERTY(int teleport READ teleport WRITE set_teleport NOTIFY teleport_changed)
	Q_PROPERTY(int escape READ escape WRITE set_escape NOTIFY escape_changed)
	Q_PROPERTY(int save READ save WRITE set_save NOTIFY save_changed)
	Q_PROPERTY(ArrayAdapter* encounters READ encounters CONSTANT)
	Q_PROPERTY(int encounter_steps READ encounter_steps WRITE set_encounter_steps NOTIFY encounter_steps_changed)
	Q_PROPERTY(Binding::Rect* area_rect READ area_rect CONSTANT)

public:
	MapInfo(ProjectData& project, lcf::rpg::MapInfo& data, QObject* parent = nullptr);

	lcf::rpg::MapInfo& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int parent_map();
	void set_parent_map(const int& new_parent_map);
	int indentation();
	void set_indentation(const int& new_indentation);
	int type();
	void set_type(const int& new_type);
	int scrollbar_x();
	void set_scrollbar_x(const int& new_scrollbar_x);
	int scrollbar_y();
	void set_scrollbar_y(const int& new_scrollbar_y);
	bool expanded_node();
	void set_expanded_node(const bool& new_expanded_node);
	int music_type();
	void set_music_type(const int& new_music_type);
	Binding::Music* music();
	int background_type();
	void set_background_type(const int& new_background_type);
	QString background_name();
	void set_background_name(const QString& new_background_name);
	int teleport();
	void set_teleport(const int& new_teleport);
	int escape();
	void set_escape(const int& new_escape);
	int save();
	void set_save(const int& new_save);
	ArrayAdapter* encounters();
	int encounter_steps();
	void set_encounter_steps(const int& new_encounter_steps);
	Binding::Rect* area_rect();

signals:
	void name_changed();
	void parent_map_changed();
	void indentation_changed();
	void type_changed();
	void scrollbar_x_changed();
	void scrollbar_y_changed();
	void expanded_node_changed();
	void music_type_changed();
	void background_type_changed();
	void background_name_changed();
	void teleport_changed();
	void escape_changed();
	void save_changed();
	void encounter_steps_changed();

protected:
	lcf::rpg::MapInfo& m_data;
	Binding::Music* m_music;
	ArrayAdapter* m_encounters;
	Binding::Rect* m_area_rect;
};
} // namespace Binding::Generated
