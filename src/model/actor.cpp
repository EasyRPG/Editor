/*
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

#include "actor.h"
#include <lcf/rpg/item.h>
#include <lcf/reader_util.h>

#include "common/sortfilter_proxy_models.h"

#include <QSortFilterProxyModel>

Actor::Actor(lcf::rpg::Actor& actor, Project& project) :
	actor(actor), project(project) {

}

bool Actor::IsItemUsable(const lcf::rpg::Item& item) const {
	int query_idx = actor.ID - 1;
	auto* query_set = &item.actor_set;
	/*TODO if (Player::IsRPG2k3() && Data::system.equipment_setting == lcf::rpg::System::EquipmentSetting_class) {
		auto* cls = GetClass();

		// Class index. If there's no class, in the "class_set" it's equal to 0. The first class is 1, not 0
		query_idx = cls ? cls->ID : 0;
		query_set = &item->class_set;
	}*/

	// If the actor or class ID is out of range this is an optimization in the ldb file
	// (all actors or classes missing can equip the item)
	if (query_set->size() <= (unsigned)(query_idx)) {
		return true;
	}

	return query_set->at(query_idx);
}

QSortFilterProxyModel* Actor::CreateEquipmentFilter(lcf::rpg::Item::Type type) {
	std::vector<int> indices;

	for (size_t i = 0; i < project.database().items.size(); ++i) {
		const lcf::rpg::Item& item = *lcf::ReaderUtil::GetElement(project.database().items, i + 1);

		if (item.type != type || !IsItemUsable(item)) {
			continue;
		}

		indices.push_back(i + 1);
	}

	return new SortFilterProxyModelIndexFilter(indices);
}

lcf::rpg::Actor& Actor::data() {
	return actor;
}
