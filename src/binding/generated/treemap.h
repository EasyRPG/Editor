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
#include <lcf/rpg/treemap.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/mapinfo.h"
#include "binding/start.h"

class ProjectData;

/**
 * Binding::Generated::TreeMap class.
 * Exposes lcf::rpg::TreeMap to QML.
 */
namespace Binding::Generated {
class TreeMap : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(ArrayAdapter* maps READ maps CONSTANT)
	Q_PROPERTY(QVector<int32_t> tree_order READ tree_order WRITE set_tree_order NOTIFY tree_order_changed)
	Q_PROPERTY(int active_node READ active_node WRITE set_active_node NOTIFY active_node_changed)
	Q_PROPERTY(Binding::Start* start READ start CONSTANT)

public:
	TreeMap(ProjectData& project, lcf::rpg::TreeMap& data, QObject* parent = nullptr);

	lcf::rpg::TreeMap& data();
	ArrayAdapter* maps();
	QVector<int32_t> tree_order();
	void set_tree_order(const QVector<int32_t>& new_tree_order);
	int active_node();
	void set_active_node(const int& new_active_node);
	Binding::Start* start();

signals:
	void tree_order_changed();
	void active_node_changed();

protected:
	lcf::rpg::TreeMap& m_data;
	ArrayAdapter* m_maps;
	Binding::Start* m_start;
};
} // namespace Binding::Generated
