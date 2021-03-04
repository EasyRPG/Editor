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
#include "ui/database/actor_widget.h"
#include "common/dbstring.h"
#include "common/sortfilter_proxy_models.h"

ActorModel::ActorModel(ProjectData& project, lcf::rpg::Actor& data) :
	RpgBase(project), m_data(data) {
}

lcf::rpg::Actor& ActorModel::data() {
	return m_data;
}

QPixmap ActorModel::preview() {
	QPixmap faceSet = ImageLoader::Load(m_project.project().findFile("FaceSet", ToQString(m_data.face_name), FileFinder::FileType::Image));

	int x = (m_data.face_index % 4) * 48;
	int y = (m_data.face_index / 4) * 48;

	return faceSet.copy(x, y, 48, 48);
}

const lcf::rpg::Actor& ActorModel::data() const {
        return m_data;
}

bool ActorModel::IsItemUsable(const lcf::rpg::Item& item) const {
	int query_idx = m_data.ID - 1;
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

	return (*query_set)[query_idx];
}

QSortFilterProxyModel* ActorModel::CreateEquipmentFilter(lcf::rpg::Item::Type type) {
	std::vector<int> indices;

	for (const auto& item : m_project.database().items) {
		if (item.type != type || !IsItemUsable(item)) {
			continue;
		}

		indices.push_back(item.ID);
	}

	return new SortFilterProxyModelIdFilter(indices);
}
