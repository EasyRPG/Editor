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
#include <lcf/rpg/animation.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/animationframe.h"
#include "binding/animationtiming.h"

class ProjectData;

/**
 * Binding::Generated::Animation class.
 * Exposes lcf::rpg::Animation to QML.
 */
namespace Binding::Generated {
class Animation : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString animation_name READ animation_name WRITE set_animation_name NOTIFY animation_name_changed)
	Q_PROPERTY(bool large READ large WRITE set_large NOTIFY large_changed)
	Q_PROPERTY(ArrayAdapter* timings READ timings CONSTANT)
	Q_PROPERTY(int scope READ scope WRITE set_scope NOTIFY scope_changed)
	Q_PROPERTY(int position READ position WRITE set_position NOTIFY position_changed)
	Q_PROPERTY(ArrayAdapter* frames READ frames CONSTANT)

public:
	Animation(ProjectData& project, lcf::rpg::Animation& data, QObject* parent = nullptr);

	lcf::rpg::Animation& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString animation_name();
	void set_animation_name(const QString& new_animation_name);
	bool large();
	void set_large(const bool& new_large);
	ArrayAdapter* timings();
	int scope();
	void set_scope(const int& new_scope);
	int position();
	void set_position(const int& new_position);
	ArrayAdapter* frames();

signals:
	void name_changed();
	void animation_name_changed();
	void large_changed();
	void scope_changed();
	void position_changed();

protected:
	lcf::rpg::Animation& m_data;
	ArrayAdapter* m_timings;
	ArrayAdapter* m_frames;
};
} // namespace Binding::Generated
