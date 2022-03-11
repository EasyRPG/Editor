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
#include <lcf/rpg/chipset.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Chipset class.
 * Exposes lcf::rpg::Chipset to QML.
 */
namespace Binding::Generated {
class Chipset : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString chipset_name READ chipset_name WRITE set_chipset_name NOTIFY chipset_name_changed)
	Q_PROPERTY(QVector<int> terrain_data READ terrain_data WRITE set_terrain_data NOTIFY terrain_data_changed)
	Q_PROPERTY(QVector<int> passable_data_lower READ passable_data_lower WRITE set_passable_data_lower NOTIFY passable_data_lower_changed)
	Q_PROPERTY(QVector<int> passable_data_upper READ passable_data_upper WRITE set_passable_data_upper NOTIFY passable_data_upper_changed)
	Q_PROPERTY(int animation_type READ animation_type WRITE set_animation_type NOTIFY animation_type_changed)
	Q_PROPERTY(int animation_speed READ animation_speed WRITE set_animation_speed NOTIFY animation_speed_changed)

public:
	Chipset(ProjectData& project, lcf::rpg::Chipset& data, QObject* parent = nullptr);

	lcf::rpg::Chipset& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString chipset_name();
	void set_chipset_name(const QString& new_chipset_name);
	QVector<int> terrain_data();
	void set_terrain_data(const QVector<int>& new_terrain_data);
	QVector<int> passable_data_lower();
	void set_passable_data_lower(const QVector<int>& new_passable_data_lower);
	QVector<int> passable_data_upper();
	void set_passable_data_upper(const QVector<int>& new_passable_data_upper);
	int animation_type();
	void set_animation_type(const int& new_animation_type);
	int animation_speed();
	void set_animation_speed(const int& new_animation_speed);

signals:
	void name_changed();
	void chipset_name_changed();
	void terrain_data_changed();
	void passable_data_lower_changed();
	void passable_data_upper_changed();
	void animation_type_changed();
	void animation_speed_changed();

protected:
	lcf::rpg::Chipset& m_data;
};
} // namespace Binding::Generated
