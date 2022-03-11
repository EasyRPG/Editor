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
#include <lcf/rpg/savetitle.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveTitle class.
 * Exposes lcf::rpg::SaveTitle to QML.
 */
namespace Binding::Generated {
class SaveTitle : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(double timestamp READ timestamp WRITE set_timestamp NOTIFY timestamp_changed)
	Q_PROPERTY(QString hero_name READ hero_name WRITE set_hero_name NOTIFY hero_name_changed)
	Q_PROPERTY(int hero_level READ hero_level WRITE set_hero_level NOTIFY hero_level_changed)
	Q_PROPERTY(int hero_hp READ hero_hp WRITE set_hero_hp NOTIFY hero_hp_changed)
	Q_PROPERTY(QString face1_name READ face1_name WRITE set_face1_name NOTIFY face1_name_changed)
	Q_PROPERTY(int face1_id READ face1_id WRITE set_face1_id NOTIFY face1_id_changed)
	Q_PROPERTY(QString face2_name READ face2_name WRITE set_face2_name NOTIFY face2_name_changed)
	Q_PROPERTY(int face2_id READ face2_id WRITE set_face2_id NOTIFY face2_id_changed)
	Q_PROPERTY(QString face3_name READ face3_name WRITE set_face3_name NOTIFY face3_name_changed)
	Q_PROPERTY(int face3_id READ face3_id WRITE set_face3_id NOTIFY face3_id_changed)
	Q_PROPERTY(QString face4_name READ face4_name WRITE set_face4_name NOTIFY face4_name_changed)
	Q_PROPERTY(int face4_id READ face4_id WRITE set_face4_id NOTIFY face4_id_changed)

public:
	SaveTitle(ProjectData& project, lcf::rpg::SaveTitle& data, QObject* parent = nullptr);

	lcf::rpg::SaveTitle& data();
	double timestamp();
	void set_timestamp(const double& new_timestamp);
	QString hero_name();
	void set_hero_name(const QString& new_hero_name);
	int hero_level();
	void set_hero_level(const int& new_hero_level);
	int hero_hp();
	void set_hero_hp(const int& new_hero_hp);
	QString face1_name();
	void set_face1_name(const QString& new_face1_name);
	int face1_id();
	void set_face1_id(const int& new_face1_id);
	QString face2_name();
	void set_face2_name(const QString& new_face2_name);
	int face2_id();
	void set_face2_id(const int& new_face2_id);
	QString face3_name();
	void set_face3_name(const QString& new_face3_name);
	int face3_id();
	void set_face3_id(const int& new_face3_id);
	QString face4_name();
	void set_face4_name(const QString& new_face4_name);
	int face4_id();
	void set_face4_id(const int& new_face4_id);

signals:
	void timestamp_changed();
	void hero_name_changed();
	void hero_level_changed();
	void hero_hp_changed();
	void face1_name_changed();
	void face1_id_changed();
	void face2_name_changed();
	void face2_id_changed();
	void face3_name_changed();
	void face3_id_changed();
	void face4_name_changed();
	void face4_id_changed();

protected:
	lcf::rpg::SaveTitle& m_data;
};
} // namespace Binding::Generated
