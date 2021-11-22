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

#include "map_scene.h"
#include <QAction>
#include <QDialogButtonBox>
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QScrollBar>
#include <QStatusBar>
#include <lcf/rpg/event.h>
#include <iomanip>
#include <sstream>
#include "core.h"
#include "common/dbstring.h"
#include "ui/event/event_dialog.h"
#include "ui/other/run_game_dialog.h"
#include "ui/maptree/map_properties_dialog.h"
#include "ui/main_window.h"
#include "undo_draw.h"
#include "undo_event.h"
#include <lcf/lmu/reader.h>
#include <lcf/lmt/reader.h>

MapScene::MapScene(ProjectData& project, int id, QGraphicsView *view, QObject *parent) :
	QGraphicsScene(parent), m_project(project)
{
	m_init = false;
	m_view = view;
	m_view->setMouseTracking(true);
	m_undoStack = new QUndoStack(this);
	m_selectionTile = new QGraphicsRectItem(QRectF(QRect(0,32,32,32)));
	m_selecting = false;
	const auto& treeMap = project.treeMap();
	for (unsigned int i = 1; i < treeMap.maps.size(); i++)
		if (treeMap.maps[i].ID == id)
		{
			n_mapInfo = treeMap.maps[i];
			break;
		}
	m_eventMenu = new QMenu(m_view);
	QList<QAction*> actions;
	actions << new QAction(QIcon(":/icons/share/old_playtest.png"),
						   "Start Game Here",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_edit.png"),
						   "Set Start Position",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "New Event",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "Edit Event",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "Copy Event",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "Cut Event",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "Paste Event",
						   this);
	actions << new QAction(QIcon(":/icons/share/old_event_layer.png"),
						   "Delete Event",
						   this);
	connect(actions[0],SIGNAL(triggered()),this,SLOT(on_actionRunHere()));
	connect(actions[1],SIGNAL(triggered()),this,SLOT(on_actionSetStartPosition()));
	connect(actions[2],SIGNAL(triggered()),this,SLOT(on_actionNewEvent()));
	connect(actions[3],SIGNAL(triggered()),this,SLOT(on_actionEditEvent()));
	connect(actions[4],SIGNAL(triggered()),this,SLOT(on_actionCopyEvent()));
	connect(actions[5],SIGNAL(triggered()),this,SLOT(on_actionCutEvent()));
	connect(actions[6],SIGNAL(triggered()),this,SLOT(on_actionPasteEvent()));
	connect(actions[7],SIGNAL(triggered()),this,SLOT(on_actionDeleteEvent()));

	m_eventMenu->addActions(actions);
	m_lowerpix = new QGraphicsPixmapItem();
	m_upperpix = new QGraphicsPixmapItem();
	addItem(m_lowerpix);
	addItem(m_upperpix);
	Load();
	QPen selPen(Qt::yellow);
	selPen.setWidth(2);
	m_selectionTile->setPen(selPen);
	m_selectionTile->setVisible(false);
	this->addItem(m_selectionTile);
	m_drawing = false;
	m_cancelled = false;
	m_selecting = false;
	QGraphicsBlurEffect * effect = new QGraphicsBlurEffect(this);
	effect->setBlurRadius(2.0);
	effect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
	m_lowerpix->setGraphicsEffect(effect);
	m_upperpix->setGraphicsEffect(new QGraphicsOpacityEffect(this));
	onLayerChanged();
	onToolChanged();
}

MapScene::~MapScene()
{
	delete m_lowerpix;
	delete m_upperpix;
	delete m_lines;
	delete m_selectionTile;
	delete m_undoStack;
}

void MapScene::Init()
{
	connect(m_view->verticalScrollBar(),
			SIGNAL(actionTriggered(int)),
			this,
			SLOT(on_user_interaction()));
	connect(m_view->horizontalScrollBar(),
			SIGNAL(actionTriggered(int)),
			this,
			SLOT(on_user_interaction()));
	connect(m_view->verticalScrollBar(),
			SIGNAL(valueChanged(int)),
			this,
			SLOT(redrawMap()));
	connect(m_view->horizontalScrollBar(),
			SIGNAL(valueChanged(int)),
			this,
			SLOT(redrawMap()));
	connect(m_view->verticalScrollBar(),
			SIGNAL(rangeChanged(int,int)),
			this,
			SLOT(redrawMap()));
	connect(m_view->horizontalScrollBar(),
			SIGNAL(rangeChanged(int,int)),
			this,
			SLOT(redrawMap()));
	connect(m_view->verticalScrollBar(),
			SIGNAL(valueChanged(int)),
			this,
			SLOT(on_view_V_Scroll()));
	connect(m_view->horizontalScrollBar(),
			SIGNAL(valueChanged(int)),
			this,
			SLOT(on_view_H_Scroll()));
	connect(&core(),
			SIGNAL(toolChanged()),
			this,
			SLOT(onToolChanged()));
	connect(&core(),
			SIGNAL(layerChanged()),
			this,
			SLOT(onLayerChanged()));
	m_view->verticalScrollBar()->setValue(n_mapInfo.scrollbar_y *static_cast<int>(m_scale));
	m_view->horizontalScrollBar()->setValue(n_mapInfo.scrollbar_x * static_cast<int>(m_scale));
	m_init = true;
	redrawMap();
}

float MapScene::scale() const
{
	return m_scale;
}

QString MapScene::mapName() const
{
	return ToQString(n_mapInfo.name);
}

bool MapScene::isModified() const
{
	return (m_undoStack->count() > 0);
}

int MapScene::id() const
{
	return n_mapInfo.ID;
}

int MapScene::chipsetId() const
{
	return m_map->chipset_id;
}

void MapScene::setLayerData(Core::Layer layer, std::vector<short> data)
{
	if (layer == Core::LOWER)
	{
		m_lower = data;
		m_map->lower_layer = data;
	}
	else
	{
		m_upper = data;
		m_map->upper_layer = data;
	}
	redrawLayer(layer);
}

void MapScene::setEventData(int id, const lcf::rpg::Event &data)
{
	for (unsigned int i = 0; i < m_map->events.size(); i++) {
		if (m_map->events[i].ID == id) {
			if (m_map->events[i] == data) {
				m_map->events.erase(m_map->events.begin() + i);
				redrawMap();
				return;
			} else {
				m_map->events[i] = data;
				return;
			}
		}
	}

	m_map->events.push_back(data);
	redrawMap();
}

QMap<int, lcf::rpg::Event*> *MapScene::mapEvents()
{
	QMap<int, lcf::rpg::Event*> *events = new QMap<int, lcf::rpg::Event*>();
	for (unsigned int i = 0; i < m_map->events.size(); i++)
		events->insert(m_map->events[i].ID, &m_map->events[i]);
	return events;
}

void MapScene::editMapProperties()
{
	int old_width = m_map->width;
	int old_height = m_map->height;

	MapPropertiesDialog dlg(m_project, n_mapInfo, *m_map, m_view);
	if (dlg.exec() == QDialog::Accepted) {
		if (m_map->width != old_width || m_map->height != old_height) {
			setLayerData(Core::LOWER, m_map->lower_layer);
			setLayerData(Core::UPPER, m_map->upper_layer);
			redrawGrid();
		}

		Save(true);
		redrawPanorama();
		redrawMap();
		setScale(m_scale);
	}
}

void MapScene::redrawMap()
{
	if (!m_init)
		return;
	core().LoadChipset(m_map->chipset_id);
	core().setCurrentMapEvents(mapEvents());
	s_tileSize = core().tileSize() * static_cast<double>(m_scale);
	redrawLayer(Core::LOWER);
	redrawLayer(Core::UPPER);
}

void MapScene::setScale(float scale)
{
	float old_scale = m_scale;
	int map_x = m_view->horizontalScrollBar()->value();
	int map_y = m_view->verticalScrollBar()->value();

	m_scale = scale;
	m_lines->setScale(static_cast<double>(m_scale));
	m_selectionTile->setScale(static_cast<double>(m_scale));
	this->setSceneRect(0,
		0,
		m_map->width * core().tileSize() * static_cast<double>(m_scale),
		m_map->height * core().tileSize() * static_cast<double>(m_scale));

	if (m_view->horizontalScrollBar()->isVisible()) {
		m_view->horizontalScrollBar()->setValue((map_x + m_view->horizontalScrollBar()->pageStep() / 2.0) * m_scale / old_scale - m_view->horizontalScrollBar()->pageStep() / 2.0);
	} else {
		m_view->horizontalScrollBar()->setValue(m_view->horizontalScrollBar()->maximum() / 2.0);
	}
	if (m_view->verticalScrollBar()->isVisible()) {
		m_view->verticalScrollBar()->setValue((map_y + m_view->verticalScrollBar()->pageStep() / 2.0) * m_scale / old_scale - m_view->verticalScrollBar()->pageStep() / 2.0);
	} else {
		m_view->verticalScrollBar()->setValue(m_view->verticalScrollBar()->maximum() / 2.0);
	}
	redrawMap();
}

void MapScene::onLayerChanged()
{
	if (m_drawing)
		stopDrawing();
	if (m_selecting)
		stopSelecting();
	switch (core().layer())
	{
	case Core::LOWER:
		m_lowerpix->graphicsEffect()->setEnabled(false);
		m_upperpix->graphicsEffect()->setEnabled(true);
		m_lines->setVisible(false);
		break;
	case Core::UPPER:
		m_lowerpix->graphicsEffect()->setEnabled(true);
		m_upperpix->graphicsEffect()->setEnabled(false);
		m_lines->setVisible(false);
		break;
	case Core::EVENT:
		m_lowerpix->graphicsEffect()->setEnabled(false);
		m_upperpix->graphicsEffect()->setEnabled(false);
		m_lines->setVisible(true);
		break;
//	  default:
//		  Q_ASSERT(false);
	}
}

void MapScene::onToolChanged()
{
	if (m_drawing)
		stopDrawing();
	if (m_selecting)
		stopSelecting();
	switch (core().tool())
	{
	case (Core::ZOOM):
		m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_zoom.png"),1,1));
		break;
	case (Core::PENCIL):
		m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_pen.png"),1,1));
		break;
	case (Core::RECTANGLE):
		m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_rectangle.png"),1,1));
		break;
	case (Core::CIRCLE):
		m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_circle.png"),1,1));
		break;
	case (Core::FILL):
		m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_fill.png"),1,1));
		break;
	}
}

void MapScene::Save(bool properties_changed)
{
	if (!isModified() && !properties_changed)
		return;

	auto& treeMap = m_project.treeMap();
	for (unsigned int i = 1; i < treeMap.maps.size(); i++)
		if (treeMap.maps[i].ID == n_mapInfo.ID)
		{
			treeMap.maps[i] = n_mapInfo; //Apply info changes
			break;
		}
	// FIXME: ProjectData.Project is Const
	core().project()->saveTreeMap();
	QString file = QString("Map%1.emu")
			.arg(QString::number(n_mapInfo.ID), 4, QLatin1Char('0'));
	lcf::LMU_Reader::PrepareSave(*m_map);
	// FIXME: ProjectData.Project is Const
	core().project()->saveMap(*m_map, n_mapInfo.ID);
	m_undoStack->clear();
	emit mapSaved();
}

void MapScene::Load(bool revert)
{
	// FIXME: Many calls to core()
	const auto& treeMap = m_project.treeMap();
	for (unsigned int i = 1; i < treeMap.maps.size(); i++)
		if (treeMap.maps[i].ID == n_mapInfo.ID)
		{
			n_mapInfo = treeMap.maps[i]; //Revert info changes
			break;
		}

	m_map = m_project.project().loadMap(n_mapInfo.ID);
	m_lower =  m_map->lower_layer;
	m_upper =  m_map->upper_layer;

	redrawPanorama();

	if (!revert) {
		redrawGrid();
	}

	redrawMap();
	m_undoStack->clear();
	emit mapReverted();
}

void MapScene::undo()
{
	m_undoStack->undo();
	if (m_undoStack->index() == 0)
	{
		m_undoStack->clear();
		emit mapReverted();
	}
}

void MapScene::on_actionNewEvent()
{
	// Find first free id
	int id = getFirstFreeId();

	lcf::rpg::Event event;
	event.ID = id;
	event.name = ToDBString(QString("EV%1").arg(QString::number(id), 4, QLatin1Char('0')));
	event.x = cur_x;
	event.y = cur_y;
	event.pages.push_back(lcf::rpg::EventPage());

	int result = EventDialog::edit(m_view, event, m_project);
	if (result != QDialogButtonBox::Cancel)
	{
		m_map->events.push_back(event);
		m_undoStack->push(new UndoEvent(event, this));
		redrawMap();
		emit mapChanged();
	}
}

void MapScene::on_actionEditEvent() {
	std::vector<lcf::rpg::Event>::iterator ev;
	for (ev = m_map->events.begin(); ev != m_map->events.end(); ++ev) {
		if (_index(cur_x, cur_y) == _index(ev->x, ev->y)) {
			lcf::rpg::Event backup = *ev;
			int result = EventDialog::edit(m_view, *ev, m_project);
			if (result != QDialogButtonBox::Cancel) {
				m_undoStack->push(new UndoEvent(backup, this));
				emit mapChanged();
			}
			redrawMap();
			return;
		}
	}
}

void MapScene::on_actionCopyEvent() {
	event_clipboard = *getEventAt(cur_x, cur_y);
	event_clipboard_set = true;
}

void MapScene::on_actionCutEvent() {
	on_actionCopyEvent();
	on_actionDeleteEvent();
}

void MapScene::on_actionPasteEvent() {
	// Find first free id
	int id = getFirstFreeId();

	lcf::rpg::Event event = event_clipboard;
	event.ID = id;
	event.name = ToDBString(QString("EV%1").arg(QString::number(id), 4, QLatin1Char('0')));
	event.x = cur_x;
	event.y = cur_y;

	m_map->events.push_back(event);
	m_undoStack->push(new UndoEvent(event, this));
	redrawMap();
	emit mapChanged();
}

void MapScene::on_actionDeleteEvent()
{
	std::vector<lcf::rpg::Event>::iterator ev;
	for (ev = m_map->events.begin(); ev != m_map->events.end(); ++ev)
		if (_index(cur_x,cur_y) == _index(ev->x,ev->y))
			break;

	if (ev != m_map->events.end())
	{
		lcf::rpg::Event backup = *ev;
		m_undoStack->push(new UndoEvent(backup, this));

		m_map->events.erase(ev);
		redrawMap();
		emit mapChanged();
	}
}

void MapScene::on_actionRunHere()
{
	core().runGameHere(id(), lst_x, lst_y);
}

void MapScene::on_actionSetStartPosition()
{
	auto& treeMap = m_project.treeMap();
	treeMap.start.party_map_id = this->id();
	treeMap.start.party_x = lst_x;
	treeMap.start.party_y = lst_y;
}

void MapScene::on_user_interaction()
{
	m_userInteraction = true;
}

void MapScene::on_view_V_Scroll()
{
	if (!m_userInteraction || !m_init)
		return;
	if (m_view->verticalScrollBar()->isVisible())
	{
		n_mapInfo.scrollbar_y = m_view->verticalScrollBar()->value() / static_cast<double>(m_scale);
	}
	m_userInteraction = false;
}

void MapScene::on_view_H_Scroll()
{
	if (!m_userInteraction || !m_init)
		return;
	if (m_view->horizontalScrollBar()->isVisible())
	{
		n_mapInfo.scrollbar_x = m_view->horizontalScrollBar()->value() / static_cast<double>(m_scale);
	}
	m_userInteraction = false;
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		if (m_drawing)
		{
			stopDrawing();
			return;
		}
		if (sceneRect().contains(event->scenePos()) && core().layer() == Core::EVENT)
		{
			m_eventMenu->actions()[2]->setEnabled(!getEventAt(cur_x, cur_y));
			m_eventMenu->actions()[3]->setEnabled(getEventAt(cur_x, cur_y));
			m_eventMenu->actions()[4]->setEnabled(getEventAt(cur_x, cur_y));
			m_eventMenu->actions()[5]->setEnabled(getEventAt(cur_x, cur_y));
			m_eventMenu->actions()[6]->setEnabled(!getEventAt(cur_x, cur_y) && event_clipboard_set);
			m_eventMenu->actions()[7]->setEnabled(getEventAt(cur_x, cur_y));

			lst_x = cur_x;
			lst_y = cur_y;
			m_eventMenu->popup(event->screenPos());
		}
		if (core().tool() == Core::ZOOM && static_cast<double>(m_scale) > 0.125)
			setScale(m_scale/2);
	}
	if (event->button() == Qt::LeftButton)
	{
		if (core().tool() == Core::ZOOM && static_cast<double>(m_scale) < 8.0) // Zoom
			setScale(m_scale*2);
		else if (core().layer() == Core::EVENT) // Select tile
		{
			// Do not allow selecting the (-1, -1) spot
			if (cur_x == -1 || cur_y == -1) {
				return;
			}

			m_selecting = true;
			m_selectionTile->setVisible(true);
			m_selectionTile->setRect(QRectF(QRect(cur_x*core().tileSize(),cur_y*core().tileSize(),
												  core().tileSize(),core().tileSize())));
		}
		else // Start drawing
		{
			// Do not draw on invalid coordinates
			if (cur_x == -1 || cur_y == -1) {
				return;
			}

			fst_x = cur_x;
			fst_y = cur_y;
			switch(core().tool())
			{
			case Core::PENCIL:
				m_drawing = true;
				drawPen();
				break;
			case Core::RECTANGLE:
				m_drawing = true;
				drawRect();
				break;
			case Core::FILL:
				m_drawing = true;
				if (core().layer() == Core::LOWER)
					drawFill(core().translate(m_lower[static_cast<size_t>(_index(fst_x,fst_y))]),fst_x,fst_y);
				else if (core().layer() == Core::UPPER)
					drawFill(core().translate(m_upper[static_cast<size_t>(_index(fst_x,fst_y))]),fst_x,fst_y);
				updateArea(0, 0, m_map->width-1 ,m_map->height-1);
				break;
			default:
				break;
			}
		}
	}
}

void MapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (!sceneRect().contains(event->scenePos())) {
		cur_x = -1;
		cur_y = -1;
		return;
	}
	if (cur_x == static_cast<int>(event->scenePos().x() / s_tileSize) && cur_y == static_cast<int>(event->scenePos().y() / s_tileSize))
		return;
	cur_x = std::max(0, std::min(m_map->width - 1, static_cast<int>(event->scenePos().x() / s_tileSize)));
	cur_y = std::max(0, std::min(m_map->height - 1, static_cast<int>(event->scenePos().y() / s_tileSize)));
	if (m_drawing)
	{
		switch (core().tool())
		{
		case (Core::PENCIL):
			drawPen();
			break;
		case (Core::RECTANGLE):
			drawRect();
			break;
		default:
			break;
		}
	}

	// Update status bar
	QMainWindow* mw = qobject_cast<QMainWindow*>(parent());

	// Show coordinates of current tile
	QString status_msg = QString("(%0, %1)").arg(cur_x).arg(cur_y);

	if (core().layer() == Core::EVENT)
	{
		// Show events on current tile
		for (const lcf::rpg::Event& evt : m_map->events)
		{
			if (_index(cur_x,cur_y) == _index(evt.x,evt.y))
			{
				status_msg.append(QString(" - Event %0: %1").arg(evt.ID).arg(evt.name.c_str()));
			}
		}
	}

	mw->statusBar()->showMessage(status_msg);
}

void MapScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_cancelled && !event->buttons())
	{
		m_cancelled = false;
		return;
	}
	if (m_drawing && !m_cancelled)
	{
		m_drawing = false;
		if (core().layer() == Core::LOWER)
		{
			m_undoStack->push(new UndoDraw(Core::LOWER,
											m_map->lower_layer,
											this));
			m_map->lower_layer = m_lower;
		}
		else
		{
			m_undoStack->push(new UndoDraw(Core::UPPER,
											m_map->upper_layer,
											this));
			m_map->upper_layer = m_upper;
		}
		emit mapChanged();
	}
}

void MapScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	Q_UNUSED(event)
	if (core().layer() != Core::EVENT)
		return;

	// Do not allow putting events on invalid coordinates
	if (cur_x == -1 || cur_y == -1) {
		return;
	}

	if (getEventAt(cur_x, cur_y)) {
		on_actionEditEvent();
	} else {
		on_actionNewEvent();
	}
}

int MapScene::_x(int index)
{
	return (index%m_map->width);
}

int MapScene::_y(int index)
{
	return (index/m_map->width);
}

int MapScene::_index(int x, int y)
{
	return (m_map->width*y+x);
}

void MapScene::redrawTile(const Core::Layer &layer,
								   const int &x,
								   const int &y,
								   const QRect &dest_rec)
{
	switch (layer)
	{
	case (Core::LOWER):
		core().renderTile(m_lower[static_cast<size_t>(_index(x,y))],dest_rec);
		break;
	case (Core::UPPER):
		core().renderTile(m_upper[static_cast<size_t>(_index(x,y))],dest_rec);
		break;
	default:
		break;
	}
}

void MapScene::stopDrawing()
{
	m_cancelled = true;
	m_drawing = false;
	m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_cancel.png"),1,1));
	m_lower = m_map->lower_layer;
	m_upper = m_map->upper_layer;
	redrawLayer(Core::LOWER);
	redrawLayer(Core::UPPER);
}

void MapScene::stopSelecting()
{
	m_cancelled = true;
	m_selecting = false;
	m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_cancel.png"),1,1));
	m_selectionTile->setVisible(false);
	//cancel selection...
}

void MapScene::updateArea(int x1, int y1, int x2, int y2)
{
	//Normalize
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x2 >= m_map->width)
		x2 = m_map->width - 1;
	if (y2 >= m_map->height)
		y2 = m_map->height - 1;

	for (int x = x1; x <= x2; x++)
		for (int y = y1; y <= y2; y++)
		{
			if (core().layer() == Core::LOWER)
			{
				if (!core().isEblock(core().translate(m_lower[static_cast<size_t>(_index(x, y))])))
					m_lower[static_cast<size_t>(_index(x,y))] = bind(x, y);
			}

		}
	redrawLayer(core().layer());
}

void MapScene::redrawLayer(Core::Layer layer)
{
	QSize size = m_view->size();
	if (size.width() > m_map->width*s_tileSize)
		size.setWidth(m_map->width*s_tileSize);
	else
		size.setWidth(size.width()+s_tileSize);
	if (size.height() > m_map->height*s_tileSize)
		size.setHeight(m_map->height*s_tileSize);
	else
		size.setHeight(size.height()+s_tileSize);
	int start_x = m_view->horizontalScrollBar()->value()/s_tileSize;
	int start_y = m_view->verticalScrollBar()->value()/s_tileSize;
	int end_x = start_x+(size.width()-1)/s_tileSize;
	int end_y = start_y+(size.height()-1)/s_tileSize;
	QPixmap pix(size);
	pix.fill(QColor(0,0,0,0));
	core().beginPainting(pix);
	for (int x = start_x; x <= end_x; x++)
		for (int y = start_y; y <= end_y; y++)
		{
			if (x >= m_map->width || y >= m_map->height)
				continue;
			QRect dest_rect((x-start_x)* s_tileSize,
					   (y-start_y)* s_tileSize,
					   s_tileSize,
					   s_tileSize);
			redrawTile(layer, x, y, dest_rect);
		}
	if (layer == Core::UPPER)
	{
		for (unsigned int i = 0; i <  m_map->events.size(); i++)
		{
			QRect rect((m_map->events[i].x-start_x)* s_tileSize,
					   (m_map->events[i].y-start_y)* s_tileSize,
					   s_tileSize,
					   s_tileSize);
			core().renderEvent(m_map->events[i], rect);
		}
	}
	core().endPainting();
	if (layer == Core::LOWER)
	{
		m_lowerpix->setPixmap(pix);
		m_lowerpix->setPos(start_x*s_tileSize,start_y*s_tileSize);
	}
	else
	{
		m_upperpix->setPixmap(pix);
		m_upperpix->setPos(start_x*s_tileSize,start_y*s_tileSize);
	}
}

void MapScene::drawPen()
{
	for (int x = cur_x; x < cur_x + core().selWidth(); x++)
		for (int y = cur_y; y < cur_y + core().selHeight(); y++)
		{
			if (core().layer() == Core::LOWER)
				m_lower[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
			else if (core().layer() == Core::UPPER)
				m_upper[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
		}
	updateArea(cur_x-1,cur_y-1,cur_x+core().selWidth()+1,cur_y+core().selHeight()+1);
}

void MapScene::drawRect()
{
	switch (core().layer())
	{
	case (Core::LOWER):
		m_lower = m_map->lower_layer;
		break;
	case (Core::UPPER):
		m_upper = m_map->upper_layer;
		break;
	default:
		break;
	}

	int x1 = fst_x > cur_x ? cur_x : fst_x;
	int x2 = fst_x > cur_x ? fst_x : cur_x;
	int y1 = fst_y > cur_y ? cur_y : fst_y;
	int y2 = fst_y > cur_y ? fst_y : cur_y;
	for (int x = x1; x <= x2; x++)
		for (int y = y1; y <= y2; y++)
		{
			if (core().layer() == Core::LOWER)
				m_lower[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
			else if (core().layer() == Core::UPPER)
				m_upper[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
		}
	updateArea(x1-2, y1-2, x2+2, y2+2);
}

void MapScene::drawFill(int terrain_id, int x, int y)
{
	if (x < 0 || x >= m_map->width || y < 0 || y >= m_map->height)
		return;
	if (terrain_id == core().selection(x-fst_x,y-fst_y))
		return;
	switch (core().layer())
	{
	case (Core::LOWER):
		if (core().translate(m_lower[static_cast<size_t>(_index(x,y))]) != terrain_id)
			return;
		m_lower[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
		break;
	case (Core::UPPER):
		if (core().translate(m_upper[static_cast<size_t>(_index(x,y))]) != terrain_id)
			return;
		m_upper[static_cast<size_t>(_index(x,y))] = core().selection(x-fst_x,y-fst_y);
		break;
	default:
		break;
	}
	drawFill(terrain_id, x, y-1);
	drawFill(terrain_id, x-1, y);
	drawFill(terrain_id, x+1, y);
	drawFill(terrain_id, x, y+1);
}

short MapScene::bind(int x, int y)
{
#define tile_u core().translate(m_lower[static_cast<size_t>(_index(x, y-1))])
#define tile_d core().translate(m_lower[static_cast<size_t>(_index(x, y+1))])
#define tile_l core().translate(m_lower[static_cast<size_t>(_index(x-1, y))])
#define tile_r core().translate(m_lower[static_cast<size_t>(_index(x+1, y))])
#define tile_ul core().translate(m_lower[static_cast<size_t>(_index(x-1, y-1))])
#define tile_ur core().translate(m_lower[static_cast<size_t>(_index(x+1, y-1))])
#define tile_dl core().translate(m_lower[static_cast<size_t>(_index(x-1, y+1))])
#define tile_dr core().translate(m_lower[static_cast<size_t>(_index(x+1, y+1))])
	int _code = 0, _scode = 0;
	int terrain_id = core().translate(m_lower[static_cast<size_t>(_index(x, y))]);
	int u=0,d=0,l=0,r=0,ul=0,ur=0,dl=0,dr=0,sul=0,sur=0,sdl=0,sdr=0;
	if (core().isDblock(terrain_id))
	{
		if (y > 0 && terrain_id != tile_u)
			u = UP;
		if (y < m_map->height-1 && terrain_id != tile_d)
			d = DOWN;
		if (x > 0 && terrain_id != tile_l)
			l = LEFT;
		if (x < m_map->width-1 && terrain_id != tile_r)
			r = RIGHT;
		if (u+l == 0 && x > 0 && y > 0 && terrain_id != tile_ul)
			ul = UPLEFT;
		if (u+r == 0 && x < m_map->width-1 && y > 0 && terrain_id != tile_ur)
			ur = UPRIGHT;
		if (d+l == 0 && x > 0 && y < m_map->height-1 && terrain_id != tile_dl)
			dl = DOWNLEFT;
		if (d+r == 0 && x < m_map->width-1 &&
				y < m_map->height-1 && terrain_id != tile_dr)
			dr = DOWNRIGHT;
		_code = u+d+l+r+ul+ur+dl+dr;
	}
	else if (core().isWater(terrain_id) || core().isAnimation(terrain_id))
	{
		if (y > 0 && (!core().isWater(tile_u) &&
					  !core().isAnimation(tile_u)))
			u = UP;
		if (y < m_map->height-1 && (!core().isWater(tile_d) &&
										  !core().isAnimation(tile_d)))
			d = DOWN;
		if (x > 0 && (!core().isWater(tile_l) &&
					  !core().isAnimation(tile_l)))
			l = LEFT;
		if (x < m_map->width-1 && (!core().isWater(tile_r) &&
										 !core().isAnimation(tile_r)))
			r = RIGHT;
		if ((u+l) == 0 && x > 0 && y > 0 && !core().isWater(tile_ul) && !core().isAnimation(tile_ul))
			ul = UPLEFT;
		if ((u+r) == 0 && x < m_map->width-1 && y > 0 && !core().isWater(tile_ur) && !core().isAnimation(tile_ur))
			ur = UPRIGHT;
		if ((d+l) == 0 && x > 0 && y < m_map->height-1 && !core().isWater(tile_dl) && !core().isAnimation(tile_dl))
			dl = DOWNLEFT;
		if ((d+r) == 0 && x < m_map->width-1 &&
				y < m_map->height-1 && !core().isWater(tile_dr) && !core().isAnimation(tile_dr))
			dr = DOWNRIGHT;
		_code = u+d+l+r+ul+ur+dl+dr;
		// DeepWater Special Corners
		if (core().isDWater(terrain_id))
		{
			if (x > 0 && y > 0 && core().isABWater(tile_u) && core().isABWater (tile_l) && core().isABWater (tile_ul))
				sul = UPLEFT;
			if (x < m_map->width-1 && y > 0 && core().isABWater(tile_u) && core().isABWater (tile_r) && core().isABWater (tile_ur))
				sur = UPRIGHT;
			if (x > 0 && y < m_map->height-1 && core().isABWater(tile_d) && core().isABWater (tile_l) && core().isABWater (tile_dl))
				sdl = DOWNRIGHT;
			if (x < m_map->width-1 && y < m_map->height-1 &&
					core().isABWater(tile_d) && core().isABWater (tile_r) && core().isABWater (tile_dr))
				sdr = DOWNLEFT;
		}
		else
		{
			if (x > 0 && y > 0 && core().isDWater (tile_u) && core().isDWater (tile_l) && core().isWater(tile_ul))
				sul = UPLEFT;
			if (x < m_map->width-1 && y > 0 && core().isDWater (tile_u) && core().isDWater (tile_r) && core().isWater(tile_ur))
				sur = UPRIGHT;
			if (x > 0 && y < m_map->height-1 && core().isDWater (tile_d) && core().isDWater (tile_l) && core().isWater(tile_dl))
				sdl = DOWNRIGHT;
			if (x < m_map->width-1 && y < m_map->height-1 &&
					core().isDWater (tile_d) && core().isDWater (tile_r) && core().isWater(tile_dr))
				sdr = DOWNLEFT;
		}
		_scode = sul+sur+sdl+sdr;
	}
	return core().translate(terrain_id, _code, _scode);
#undef tile_u
#undef tile_d
#undef tile_l
#undef tile_r
#undef tile_ul
#undef tile_ur
#undef tile_dl
#undef tile_dr
}

void MapScene::selectTile(int x, int y)
{
	cur_x = x;
	cur_y = y;
	std::unique_ptr<QGraphicsSceneMouseEvent> mpe{new QGraphicsSceneMouseEvent()};
	mpe->setButton(Qt::LeftButton);
	mousePressEvent(mpe.get());
}

void MapScene::centerOnTile(int x, int y)
{
	m_view->centerOn(x * s_tileSize, y * s_tileSize);
}

lcf::rpg::Event* MapScene::getEventAt(int x, int y) {
	std::vector<lcf::rpg::Event>::iterator ev;
	for (ev = m_map->events.begin(); ev != m_map->events.end(); ++ev) {
		if (_index(x, y) == _index(ev->x, ev->y)) {
			break;
		}
	}

	if (ev != m_map->events.end()) {
		return &(*ev);
	}

	return nullptr;
}

int MapScene::getFirstFreeId() {
	std::vector<lcf::rpg::Event>::iterator ev;
	int id = 1;
	for (;;++id) {
		bool valid = true;
		for (ev = m_map->events.begin(); ev != m_map->events.end(); ++ev) {
			if (ev->ID == id) {
				valid = false;
				break;
			}
		}
		if (valid) {
			break;
		}
	}

	return id;
}

void MapScene::redrawPanorama() {
	if (m_map->parallax_flag) {
		core().LoadBackground(m_map->parallax_name.c_str());
	} else {
		core().LoadBackground(QString());
	}
}

void MapScene::redrawGrid() {
	if (!grid_lines.empty()) {
		while (!grid_lines.empty()) {
			QGraphicsItem* line = grid_lines.takeLast();
			delete line;
		}
		destroyItemGroup(m_lines);
	}

	for (int x = 0; x <= m_map->width; x++) {
		grid_lines.append(new QGraphicsLineItem(x*core().tileSize(),
			0,
			x*core().tileSize(),
			m_map->height*core().tileSize()));
	}

	for (int y = 0; y <= m_map->height; y++) {
		grid_lines.append(new QGraphicsLineItem(0,
			y*core().tileSize(),
			m_map->width*core().tileSize(),
			y*core().tileSize()));
	}

	m_lines = createItemGroup(grid_lines);

	m_lines->setVisible(core().layer() == Core::EVENT);
}
