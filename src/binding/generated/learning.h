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
#include <lcf/rpg/learning.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Learning class.
 * Exposes lcf::rpg::Learning to QML.
 */
namespace Binding::Generated {
class Learning : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int level READ level WRITE set_level NOTIFY level_changed)
	Q_PROPERTY(int skill_id READ skill_id WRITE set_skill_id NOTIFY skill_id_changed)

public:
	Learning(ProjectData& project, lcf::rpg::Learning& data, QObject* parent = nullptr);

	lcf::rpg::Learning& data();
	int id();
	int level();
	void set_level(const int& new_level);
	int skill_id();
	void set_skill_id(const int& new_skill_id);

signals:
	void level_changed();
	void skill_id_changed();

protected:
	lcf::rpg::Learning& m_data;
};
} // namespace Binding::Generated
