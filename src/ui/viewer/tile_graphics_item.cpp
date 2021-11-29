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

#include "tile_graphics_item.h"
#include "core.h"
#include "common/image_loader.h"
#include "common/dbstring.h"
#include "model/project_data.h"

#include <lcf/rpg/actor.h>

TileGraphicsItem::TileGraphicsItem(ProjectData& project, lcf::rpg::Chipset* chipset, const QPixmap pix) :
	QGraphicsItem(), m_project(project), m_chipset(chipset), m_image(pix) {
}

QRectF TileGraphicsItem::tileRect() const {
	const int TILE_SIZE = 16;

	int sub_tile_id = 0;
	int x;
	int y;

	if (layer() == ChipsetGraphicsView::Layer::Lower) {
		if (m_tile_index > 0 && m_tile_index < 3) {
			x = m_tile_index % 2 * TILE_SIZE * 3;
			y = m_tile_index / 2 * TILE_SIZE * 4;
		} else if (m_tile_index >= 3 && m_tile_index < 6) {
			sub_tile_id = m_tile_index - 3;
			x = 3 * TILE_SIZE;
			y = 4 * TILE_SIZE;
		} else if (m_tile_index >= 6 && m_tile_index < 10) {
			x = m_tile_index % 2 * TILE_SIZE * 3;
			y = 128 + (m_tile_index - 6) / 2 * TILE_SIZE * 4;
		} else if (m_tile_index >= 10 && m_tile_index < 18) {
			x = m_tile_index % 2 * TILE_SIZE * 3 + 6 * TILE_SIZE;
			y = (m_tile_index - 10) / 2 * TILE_SIZE * 4;
		} else if (m_tile_index >= 18 && m_tile_index < 114) {
			sub_tile_id = m_tile_index - 18;
			x = 192;
			y = 0;
		} else if (m_tile_index >= 114 && m_tile_index < 170) {
			sub_tile_id = m_tile_index - 114;
			x = 288;
			y = 0;
		} else { // Invalid -> Use water tile (first one)
			x = 0;
			y = 0;
		}

		x += sub_tile_id % 6 * 16 + (m_anim_step * TILE_SIZE);
		y += sub_tile_id / 6 * 16;

		return QRectF(x, y, TILE_SIZE, TILE_SIZE);
	} else if (layer() == ChipsetGraphicsView::Layer::Upper) {
		if (m_tile_index > 0 && m_tile_index < 48) {
			sub_tile_id = m_tile_index;
			x = 288;
			y = 128;
		} else if (m_tile_index >= 48 && m_tile_index < 96) {
			sub_tile_id = m_tile_index - 48;
			x = 384;
			y = 0;
		} else if (m_tile_index >= 96 && m_tile_index < 144) {
			sub_tile_id = m_tile_index - 96;
			x = 384;
			y = 128;
		} else { // Invalid -> Use empty tile (first one)
			x = 288;
			y = 128;
		}

		x += sub_tile_id % 6 * 16 + (m_anim_step * TILE_SIZE);
		y += sub_tile_id / 6 * 16;

		return QRectF(x, y, TILE_SIZE, TILE_SIZE);
	} else {
		assert(false);
	}

	return QRectF();
}

QRectF TileGraphicsItem::boundingRect() const {
	return {0., 0., 16., 16.};
}

void TileGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
	painter->drawPixmap(boundingRect(), m_image, tileRect());
}

void TileGraphicsItem::refresh(const lcf::rpg::Chipset& chipset) {
	refresh(ToQString(chipset.chipset_name));
}

void TileGraphicsItem::refresh(const QString& filename) {
	if (m_filename != filename) {
		m_filename = filename;
		m_image = ImageLoader::Load(m_project.project().findFile(CHIPSET, filename, FileFinder::FileType::Image));
	}
	update();
}

void TileGraphicsItem::clicked() {
	// todo
}

int TileGraphicsItem::tileIndex() const {
	return m_tile_index;
}

void TileGraphicsItem::setTileIndex(int index) {
	m_tile_index = index;
}

int TileGraphicsItem::animType() const {
	return m_anim_type;
}

void TileGraphicsItem::setAnimType(int anim_type) {
	m_anim_type = anim_type;
}

int TileGraphicsItem::animSpeed() const {
	return m_anim_speed;
}

void TileGraphicsItem::setAnimSpeed(int anim_speed) {
	m_anim_speed = (anim_speed + 1) * 12;
}

ChipsetGraphicsView::Layer TileGraphicsItem::layer() const {
	return m_layer;
}

void TileGraphicsItem::setLayer(ChipsetGraphicsView::Layer layer) {
	m_layer = layer;
}

ChipsetGraphicsView::EditMode TileGraphicsItem::editMode() const {
	return m_editmode;
}

void TileGraphicsItem::setEditMode(ChipsetGraphicsView::EditMode edit_mode) {
	m_editmode = edit_mode;
}

void TileGraphicsItem::advance(int phase) {
	if (!phase)	{
		m_anim_step = frames / animSpeed();
		if (animType() == lcf::rpg::Chipset::AnimType_reciprocating) {
			m_anim_step %= 3;
		} else if (animType() == lcf::rpg::Chipset::AnimType_cyclic) {
			m_anim_step %= 4;
			if (m_anim_step == 3) {
				m_anim_step = 1;
			}
		} else {
			return;
		}
		++frames;
	} else {
		update();
	}
}
