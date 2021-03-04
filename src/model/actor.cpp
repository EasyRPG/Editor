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

class FaceSetGraphicsItem : public QGraphicsItem {
public:
	FaceSetGraphicsItem(const ActorModel& actor) : m_actor(actor.data()), m_project(actor.project().project()) {}

	QRect faceRect() const {
		return {
				(m_actor.face_index % 4) * 48,
				m_actor.face_index / 4 * 48,
				48,
				48
		};
	}

	QRectF boundingRect() const override {
		return {0., 0., 48., 48.};
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override {
		if (ToQString(m_actor.face_name) != face_name) {
			face_name = ToQString(m_actor.face_name);
			graphic = ImageLoader::Load(m_project.findFile(FACESET, ToQString(m_actor.face_name), FileFinder::FileType::Image));
		}
		painter->drawPixmap(boundingRect(), graphic, faceRect());
	}

private:
	const lcf::rpg::Actor& m_actor;
	const Project& m_project;
	QPixmap graphic;
	QString face_name;
};

QGraphicsItem* ActorModel::face() const {
	return new FaceSetGraphicsItem(*this);
}

class CharSetGraphicsItem : public QGraphicsItem {
public:
	enum Direction {
		Direction_up = 0,
		Direction_right = 1,
		Direction_down = 2,
		Direction_left = 3
	};

	enum Frame {
		Frame_left = 0,
		Frame_middle = 1,
		Frame_right = 2
	};

	explicit CharSetGraphicsItem(const ActorModel& actor) : m_actor(actor.data()), m_project(actor.project().project()) {}

	void setBasePix(const QString &n_pixName);

	QRectF boundingRect() const override {
		return {0., 0., 24., 32.};
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override {
		if (ToQString(m_actor.character_name) != charset_name) {
			charset_name = ToQString(m_actor.character_name);
			graphic = ImageLoader::Load(m_project.findFile(CHARSET, ToQString(m_actor.character_name), FileFinder::FileType::Image));
		}

		int x = (m_actor.character_index % 4) * 72 + m_frame * 24;
		int y = (m_actor.character_index / 4) * 128 + m_facing * 32;
		painter->drawPixmap(boundingRect(), graphic, QRect(x, y, 24, 32));
	}

	int facing() const {
		return m_facing;
	}

	void setFacing(int facing) {
		m_facing = facing;
	}

	int frame() const {
		return m_frame;
	}

	void setFrame(int frame) {
		m_frame = frame;
	}

	bool spin() const {
		return m_spin;
	}

	void setSpin(bool spin) {
		m_spin = spin;
	}

	bool walk() const {
		return m_walk;
	}

	void setWalk(bool walk) {
		m_walk = walk;
	}

protected:
	void advance(int phase) override {
		static int patterns[4] = {Frame_middle, Frame_right, Frame_middle,Frame_left};
		if (!phase)	{
			frame_count++;
			if (frame_count == 90) {
				frame_count = 0;
				if (m_spin)	{
					m_facing++;
					if (m_facing > Direction_left)
						m_facing = Direction_up;
				}
			}
			if (m_walk) {
				m_frame = patterns[m_pattern];

				if (frame_count % 6 == 0) {
					m_pattern = (m_pattern + 1) % 4;
				}
			}
		} else {
			update();
		}
	}

private:
	QPixmap m_pix;
	int frame_count = 0;
	int m_facing = Direction_down;
	int m_frame = Frame_middle;
	bool m_spin = true;
	bool m_walk = true;
	int m_pattern = 0;

private:
	const lcf::rpg::Actor& m_actor;
	const Project& m_project;
	QPixmap graphic;
	QString charset_name;
};

QGraphicsItem* ActorModel::character() const {
	return new CharSetGraphicsItem(*this);
}
