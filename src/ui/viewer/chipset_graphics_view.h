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

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QTimer>
#include <memory>
#include <type_traits>

class ProjectData;

namespace lcf::rpg {
	class Chipset;
}

class ChipsetGraphicsView : public QGraphicsView {
Q_OBJECT

public:
	enum class Layer {
		None,
		Lower,
		Upper
	};

	enum class EditMode {
		None,
		Terrain,
		Passability,
		Passage,
		Counter
	};

	explicit ChipsetGraphicsView(QWidget* parent);

	void setProjectData(ProjectData& project);

	void setChipset(lcf::rpg::Chipset& chipset);

	void enableTimer();

	bool drawGrid() const;
	void setDrawGrid(bool draw_grid);

	int tilesPerCol() const;
	void setTilesPerCol(int tiles_per_col);

	Layer layer() const;
	void setLayer(Layer layer);

	EditMode editMode() const;
	void setEditMode(EditMode edit_mode);

	void refresh();

signals:
	void clicked(const QPointF&);

protected:
	void mousePressEvent(QMouseEvent* event) override;

	ProjectData* m_project = nullptr;
	lcf::rpg::Chipset* m_chipset = nullptr;
	std::unique_ptr<QTimer> m_timer;
	QPixmap m_chipset_pix;

	bool m_draw_grid = false;
	int m_tiles_per_col = 6;
	EditMode m_editmode = EditMode::Terrain;
	Layer m_layer = Layer::None;
};
