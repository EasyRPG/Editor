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
#include <lcf/rpg/battleranimationpose.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::BattlerAnimationPose class.
 * Exposes lcf::rpg::BattlerAnimationPose to QML.
 */
namespace Binding::Generated {
class BattlerAnimationPose : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString battler_name READ battler_name WRITE set_battler_name NOTIFY battler_name_changed)
	Q_PROPERTY(int battler_index READ battler_index WRITE set_battler_index NOTIFY battler_index_changed)
	Q_PROPERTY(int animation_type READ animation_type WRITE set_animation_type NOTIFY animation_type_changed)
	Q_PROPERTY(int battle_animation_id READ battle_animation_id WRITE set_battle_animation_id NOTIFY battle_animation_id_changed)

public:
	BattlerAnimationPose(ProjectData& project, lcf::rpg::BattlerAnimationPose& data, QObject* parent = nullptr);

	lcf::rpg::BattlerAnimationPose& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString battler_name();
	void set_battler_name(const QString& new_battler_name);
	int battler_index();
	void set_battler_index(const int& new_battler_index);
	int animation_type();
	void set_animation_type(const int& new_animation_type);
	int battle_animation_id();
	void set_battle_animation_id(const int& new_battle_animation_id);

signals:
	void name_changed();
	void battler_name_changed();
	void battler_index_changed();
	void animation_type_changed();
	void battle_animation_id_changed();

protected:
	lcf::rpg::BattlerAnimationPose& m_data;
};
} // namespace Binding::Generated
