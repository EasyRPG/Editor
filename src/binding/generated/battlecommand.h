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
#include <lcf/rpg/battlecommand.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::BattleCommand class.
 * Exposes lcf::rpg::BattleCommand to QML.
 */
namespace Binding::Generated {
class BattleCommand : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)

public:
	BattleCommand(ProjectData& project, lcf::rpg::BattleCommand& data, QObject* parent = nullptr);

	lcf::rpg::BattleCommand& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int type();
	void set_type(const int& new_type);

signals:
	void name_changed();
	void type_changed();

protected:
	lcf::rpg::BattleCommand& m_data;
};
} // namespace Binding::Generated
