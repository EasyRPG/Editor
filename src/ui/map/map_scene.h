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
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMap>
#include <QMenu>
#include <QUndoStack>
#include <memory>
#include <rpg_map.h>
#include <rpg_mapinfo.h>
#include "core.h"

class MapScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit MapScene(int id,QGraphicsView *view, QObject *parent = nullptr);
	~MapScene();

	void Init();
	float scale() const;
	void selectTile(int x, int y);
	void centerOnTile(int x, int y);
	void setScale(float scale);
	QString mapName() const;
	bool isModified() const;
	int id() const;
	int chipsetId() const;
	void setLayerData(Core::Layer layer, std::vector<short> data);
	void setEventData(int id, const RPG::Event &data);
	QMap<int, RPG::Event *> *mapEvents();
	void editMapProperties();

signals:

	void mapChanged();

	void mapSaved();

	void mapReverted();

public slots:
	void redrawMap();

	void onLayerChanged();

	void onToolChanged();

	void Save();

	void Load();

	void undo();

private slots:
	void on_actionRunHere();

	void on_actionSetStartPosition();

	void on_actionNewEvent();

	void on_actionDeleteEvent();

	void on_user_interaction();

	void on_view_V_Scroll();

	void on_view_H_Scroll();

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
	int _x(int index);
	int _y(int index);
	int _index(int x, int y);
	void redrawTile(const Core::Layer &layer,
					const int &x,
					const int &y,
					const QRect &dest_rec);
	void stopDrawing();
	void stopSelecting();
	void updateArea(int x1, int y1, int x2, int y2);
	void redrawLayer(Core::Layer layer);
	void drawPen();
	void drawRect();
	void drawFill(int terrain_id, int x, int y);
	short bind(int x, int y);


	QMenu *m_eventMenu;
	QGraphicsPixmapItem *m_lowerpix;
	QGraphicsPixmapItem *m_upperpix;
	QGraphicsItemGroup* m_lines;
	QGraphicsRectItem* m_selectionTile;
	QUndoStack *m_undoStack;
	std::unique_ptr<RPG::Map> m_map;
	RPG::MapInfo n_mapInfo; //To store unsaved changes
	std::vector<short> m_lower;
	std::vector<short> m_upper;
	float m_scale;
	bool m_init;
	int s_tileSize;
	int cur_x;
	int cur_y;
	int fst_x;
	int fst_y;
	int lst_x;
	int lst_y;
	QGraphicsView* m_view;
	bool m_drawing;
	bool m_cancelled;
	bool m_selecting;
	bool m_userInteraction;
};

