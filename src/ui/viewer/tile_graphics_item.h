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

#pragma once

#include <QGraphicsPixmapItem>
#include "chipset_graphics_view.h"

namespace lcf::rpg {
	class Chipset;
}

class ProjectData;

class TileGraphicsItem : public QGraphicsItem {
public:
	explicit TileGraphicsItem(ProjectData& project, lcf::rpg::Chipset* chipset = nullptr, const QPixmap pix = QPixmap(16,16));

	QRectF boundingRect() const override;
	QRectF tileRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	void refresh(const lcf::rpg::Chipset& chipset);
	void refresh(const QString& filename);

	void clicked();

	int tileIndex() const;
	void setTileIndex(int index);

	int animType() const;
	void setAnimType(int anim_type);

	int animSpeed() const;
	void setAnimSpeed(int anim_speed);

	ChipsetGraphicsView::Layer layer() const;
	void setLayer(ChipsetGraphicsView::Layer layer);

	ChipsetGraphicsView::EditMode editMode() const;
	void setEditMode(ChipsetGraphicsView::EditMode edit_mode);

protected:
	void advance(int phase) override;

private:
	ProjectData& m_project;
	int m_tile_index = 0;
	int m_anim_type = -1;
	int m_anim_speed = 12;
	int m_anim_step = 0;
	ChipsetGraphicsView::Layer m_layer = ChipsetGraphicsView::Layer::None;
	ChipsetGraphicsView::EditMode m_editmode = ChipsetGraphicsView::EditMode::None;
	QString m_filename;
	lcf::rpg::Chipset* m_chipset = nullptr;
	QPixmap m_image;
	int frames = 0;
};
