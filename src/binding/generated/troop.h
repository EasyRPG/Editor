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
#include <lcf/rpg/troop.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/troopmember.h"
#include "binding/trooppage.h"

class ProjectData;

/**
 * Binding::Generated::Troop class.
 * Exposes lcf::rpg::Troop to QML.
 */
namespace Binding::Generated {
class Troop : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(ArrayAdapter* members READ members CONSTANT)
	Q_PROPERTY(bool auto_alignment READ auto_alignment WRITE set_auto_alignment NOTIFY auto_alignment_changed)
	Q_PROPERTY(QVector<bool> terrain_set READ terrain_set WRITE set_terrain_set NOTIFY terrain_set_changed)
	Q_PROPERTY(bool appear_randomly READ appear_randomly WRITE set_appear_randomly NOTIFY appear_randomly_changed)
	Q_PROPERTY(ArrayAdapter* pages READ pages CONSTANT)

public:
	Troop(ProjectData& project, lcf::rpg::Troop& data, QObject* parent = nullptr);

	lcf::rpg::Troop& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	ArrayAdapter* members();
	bool auto_alignment();
	void set_auto_alignment(const bool& new_auto_alignment);
	QVector<bool> terrain_set();
	void set_terrain_set(const QVector<bool>& new_terrain_set);
	bool appear_randomly();
	void set_appear_randomly(const bool& new_appear_randomly);
	ArrayAdapter* pages();

signals:
	void name_changed();
	void auto_alignment_changed();
	void terrain_set_changed();
	void appear_randomly_changed();

protected:
	lcf::rpg::Troop& m_data;
	ArrayAdapter* m_members;
	ArrayAdapter* m_pages;
};
} // namespace Binding::Generated
