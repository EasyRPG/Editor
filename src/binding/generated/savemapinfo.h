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
#include <lcf/rpg/savemapinfo.h>
#include "binding/binding_base.h"
#include "binding/savemapevent.h"

class ProjectData;

/**
 * Binding::Generated::SaveMapInfo class.
 * Exposes lcf::rpg::SaveMapInfo to QML.
 */
namespace Binding::Generated {
class SaveMapInfo : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int position_x READ position_x WRITE set_position_x NOTIFY position_x_changed)
	Q_PROPERTY(int position_y READ position_y WRITE set_position_y NOTIFY position_y_changed)
	Q_PROPERTY(int encounter_rate READ encounter_rate WRITE set_encounter_rate NOTIFY encounter_rate_changed)
	Q_PROPERTY(int chipset_id READ chipset_id WRITE set_chipset_id NOTIFY chipset_id_changed)
	Q_PROPERTY(QVector<Binding::SaveMapEvent*> events READ events CONSTANT)
	Q_PROPERTY(QVector<int> lower_tiles READ lower_tiles WRITE set_lower_tiles NOTIFY lower_tiles_changed)
	Q_PROPERTY(QVector<int> upper_tiles READ upper_tiles WRITE set_upper_tiles NOTIFY upper_tiles_changed)
	Q_PROPERTY(QString parallax_name READ parallax_name WRITE set_parallax_name NOTIFY parallax_name_changed)
	Q_PROPERTY(bool parallax_horz READ parallax_horz WRITE set_parallax_horz NOTIFY parallax_horz_changed)
	Q_PROPERTY(bool parallax_vert READ parallax_vert WRITE set_parallax_vert NOTIFY parallax_vert_changed)
	Q_PROPERTY(bool parallax_horz_auto READ parallax_horz_auto WRITE set_parallax_horz_auto NOTIFY parallax_horz_auto_changed)
	Q_PROPERTY(int parallax_horz_speed READ parallax_horz_speed WRITE set_parallax_horz_speed NOTIFY parallax_horz_speed_changed)
	Q_PROPERTY(bool parallax_vert_auto READ parallax_vert_auto WRITE set_parallax_vert_auto NOTIFY parallax_vert_auto_changed)
	Q_PROPERTY(int parallax_vert_speed READ parallax_vert_speed WRITE set_parallax_vert_speed NOTIFY parallax_vert_speed_changed)

public:
	SaveMapInfo(ProjectData& project, lcf::rpg::SaveMapInfo& data, QObject* parent = nullptr);

	lcf::rpg::SaveMapInfo& data();
	int position_x();
	void set_position_x(const int& new_position_x);
	int position_y();
	void set_position_y(const int& new_position_y);
	int encounter_rate();
	void set_encounter_rate(const int& new_encounter_rate);
	int chipset_id();
	void set_chipset_id(const int& new_chipset_id);
	QVector<Binding::SaveMapEvent*>& events();
	QVector<int> lower_tiles();
	void set_lower_tiles(const QVector<int>& new_lower_tiles);
	QVector<int> upper_tiles();
	void set_upper_tiles(const QVector<int>& new_upper_tiles);
	QString parallax_name();
	void set_parallax_name(const QString& new_parallax_name);
	bool parallax_horz();
	void set_parallax_horz(const bool& new_parallax_horz);
	bool parallax_vert();
	void set_parallax_vert(const bool& new_parallax_vert);
	bool parallax_horz_auto();
	void set_parallax_horz_auto(const bool& new_parallax_horz_auto);
	int parallax_horz_speed();
	void set_parallax_horz_speed(const int& new_parallax_horz_speed);
	bool parallax_vert_auto();
	void set_parallax_vert_auto(const bool& new_parallax_vert_auto);
	int parallax_vert_speed();
	void set_parallax_vert_speed(const int& new_parallax_vert_speed);

signals:
	void position_x_changed();
	void position_y_changed();
	void encounter_rate_changed();
	void chipset_id_changed();
	void lower_tiles_changed();
	void upper_tiles_changed();
	void parallax_name_changed();
	void parallax_horz_changed();
	void parallax_vert_changed();
	void parallax_horz_auto_changed();
	void parallax_horz_speed_changed();
	void parallax_vert_auto_changed();
	void parallax_vert_speed_changed();

protected:
	lcf::rpg::SaveMapInfo& m_data;
	QVector<Binding::SaveMapEvent*> m_events;
};
} // namespace Binding::Generated
