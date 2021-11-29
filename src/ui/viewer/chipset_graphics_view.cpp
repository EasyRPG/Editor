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

#include "chipset_graphics_view.h"
#include "model/project.h"
#include "common/dbstring.h"
#include "common/image_loader.h"
#include "defines.h"
#include "tile_graphics_item.h"
#include <QMouseEvent>

ChipsetGraphicsView::ChipsetGraphicsView(QWidget* parent) : QGraphicsView(parent) {
	setScene(new QGraphicsScene(this));
	scale(2, 2);
}

void ChipsetGraphicsView::setProjectData(ProjectData& project) {
	m_project = &project;
}

void ChipsetGraphicsView::setChipset(lcf::rpg::Chipset& chipset) {
	if (m_chipset == &chipset) {
		return;
	}

	m_chipset = &chipset;
	m_chipset_pix = ImageLoader::Load(m_project->project().findFile(CHIPSET, ToQString(chipset.chipset_name), FileFinder::FileType::Image));
}

void ChipsetGraphicsView::enableTimer() {
	/*m_timer.reset(new QTimer());
	QObject::connect(m_timer.get(), &QTimer::timeout, scene(), &QGraphicsScene::advance);
	m_timer->start(1000 / 33);*/
}

void ChipsetGraphicsView::mousePressEvent(QMouseEvent* event) {
	/*if (event->button() == Qt::LeftButton && m_item) {
		const auto& p = mapToScene(event->pos());
		if (m_item->boundingRect().contains(p)) {
			emit clicked(p);
		}
	}
	QGraphicsView::mousePressEvent(event);*/
}

bool ChipsetGraphicsView::drawGrid() const {
	return m_draw_grid;
}

void ChipsetGraphicsView::setDrawGrid(bool draw_grid) {
	m_draw_grid = draw_grid;
}

int ChipsetGraphicsView::tilesPerCol() const {
	return m_tiles_per_col;
}

void ChipsetGraphicsView::setTilesPerCol(int tiles_per_col) {
	m_tiles_per_col = tiles_per_col;
}

ChipsetGraphicsView::Layer ChipsetGraphicsView::layer() const {
	return m_layer;
}

void ChipsetGraphicsView::setLayer(ChipsetGraphicsView::Layer layer) {
	m_layer = layer;
}

ChipsetGraphicsView::EditMode ChipsetGraphicsView::editMode() const {
	return m_editmode;
}

void ChipsetGraphicsView::setEditMode(ChipsetGraphicsView::EditMode edit_mode) {
	m_editmode = edit_mode;
}

void ChipsetGraphicsView::refresh() {
	assert(m_project);
	assert(m_chipset);

	const int TILE_SIZE = 16;

	if (layer() == Layer::Lower) {
		scene()->clear();
		for (int terrain_id = 0; terrain_id < 162; terrain_id++) {
			auto* tile = new TileGraphicsItem(*m_project, *m_chipset, m_chipset_pix);
			tile->setTileIndex(terrain_id);
			tile->setLayer(Layer::Lower);
			tile->setEditMode(m_editmode);
			tile->setPos(QPointF(terrain_id * TILE_SIZE % (TILE_SIZE * m_tiles_per_col), terrain_id / m_tiles_per_col * TILE_SIZE));
			scene()->addItem(tile);
		}
	} else if (layer() == Layer::Upper) {
		scene()->clear();
		for (int terrain_id = 0; terrain_id < 144; terrain_id++) {
			auto* tile = new TileGraphicsItem(*m_project, *m_chipset, m_chipset_pix);
			tile->setTileIndex(terrain_id);
			tile->setLayer(Layer::Upper);
			tile->setEditMode(m_editmode);
			tile->setPos(QPointF(terrain_id * TILE_SIZE % (TILE_SIZE * m_tiles_per_col), terrain_id / m_tiles_per_col * TILE_SIZE));
			scene()->addItem(tile);
		}
	}
}
