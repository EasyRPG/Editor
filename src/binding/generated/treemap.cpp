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

// Headers
#include "treemap.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	TreeMap::TreeMap(ProjectData& project, lcf::rpg::TreeMap& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_maps = new ArrayAdapter(this);
			auto& arr = m_maps->data();
			for (auto& var: m_data.maps)
				arr.push_back(new Binding::MapInfo(m_project, var, this));
		}
		m_start = new Binding::Start(m_project, m_data.start, this);
	}
	ArrayAdapter* TreeMap::maps() {
		return m_maps;
	}

	QVector<int> TreeMap::tree_order() {
		return QVector<int>(m_data.tree_order.begin(), m_data.tree_order.end());
	}
	void TreeMap::set_tree_order(const QVector<int>& new_tree_order) {
		if (QVector<int>(m_data.tree_order.begin(), m_data.tree_order.end()) == new_tree_order)
			return;
		m_data.tree_order = decltype(m_data.tree_order)(new_tree_order.begin(), new_tree_order.end());
		emit tree_order_changed();
	}

	int TreeMap::active_node() {
		return m_data.active_node;
	}
	void TreeMap::set_active_node(const int& new_active_node) {
		if (m_data.active_node == new_active_node)
			return;
		m_data.active_node = new_active_node;
		emit active_node_changed();
	}

	Binding::Start* TreeMap::start() {
		return m_start;
	}

} // namespace Binding::Generated
