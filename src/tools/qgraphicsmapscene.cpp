#include "qgraphicsmapscene.h"
#include <QAction>
#include <QDialogButtonBox>
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QScrollBar>
#include <iomanip>
#include <sstream>
#include "../core.h"
#include "../dialogEvent.h"
#include "../dialogrungame.h"
#include "../dialogmapproperties.h"
#include "../mainwindow.h"
#include "qundodraw.h"
#include "qundoevent.h"
#include <data.h>
#include <lmu_reader.h>
#include <lmt_reader.h>

QGraphicsMapScene::QGraphicsMapScene(int id, QGraphicsView *view, QObject *parent) :
    QGraphicsScene(parent)
{
    m_init = false;
    m_view = view;
    m_view->setMouseTracking(true);
    m_undoStack = new QUndoStack(this);
    for (unsigned int i = 1; i < Data::treemap.maps.size(); i++)
        if (Data::treemap.maps[i].ID == id)
        {
            m_mapInfo = &(Data::treemap.maps[i]);
            n_mapInfo = Data::treemap.maps[i];
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
    connect(actions[1],SIGNAL(triggered()),this, SLOT(on_actionSetStartPosition()));
    connect(actions[2],SIGNAL(triggered()),this,SLOT(on_actionNewEvent()));

    m_eventMenu->addActions(actions);
    m_lowerpix = new QGraphicsPixmapItem();
    m_upperpix = new QGraphicsPixmapItem();
    addItem(m_lowerpix);
    addItem(m_upperpix);
    Load();
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

QGraphicsMapScene::~QGraphicsMapScene()
{
    delete m_lowerpix;
    delete m_upperpix;
    m_eventpixs.clear();
}

void QGraphicsMapScene::Init()
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
    connect(mCore,
            SIGNAL(toolChanged()),
            this,
            SLOT(onToolChanged()));
    connect(mCore,
            SIGNAL(layerChanged()),
            this,
            SLOT(onLayerChanged()));
    m_view->verticalScrollBar()->setValue(m_mapInfo->scrollbar_y*m_scale);
    m_view->horizontalScrollBar()->setValue(m_mapInfo->scrollbar_x*m_scale);
    m_init = true;
    redrawMap();
}

float QGraphicsMapScene::scale() const
{
    return m_scale;
}

QString QGraphicsMapScene::mapName() const
{
    return QString::fromStdString(n_mapInfo.name);
}

bool QGraphicsMapScene::isModified() const
{
    return (m_undoStack->count() > 0);
}

int QGraphicsMapScene::id() const
{
    return m_mapInfo->ID;
}

int QGraphicsMapScene::chipsetId() const
{
    return m_map.get()->chipset_id;
}

void QGraphicsMapScene::setLayerData(Layer layer, std::vector<short> data)
{
    if (layer == LOWER)
    {
        m_lower = data;
        m_map.get()->lower_layer = data;
    }
    else
    {
        m_upper = data;
        m_map.get()->upper_layer = data;
    }
    redrawLayer(layer);
}

void QGraphicsMapScene::setEventData(int id, const RPG::Event &data)
{
    for (unsigned int i = 0; i < m_map.get()->events.size(); i++)
        if (m_map.get()->events[i].ID == id)
            m_map.get()->events[i] = data;
}

QMap<int, RPG::Event*> *QGraphicsMapScene::mapEvents()
{
    QMap<int, RPG::Event*> *events = new QMap<int, RPG::Event*>();
    for (unsigned int i = 0; i < m_map.get()->events.size(); i++)
        events->insert(m_map.get()->events[i].ID, &m_map.get()->events[i]);
    return events;
}

void QGraphicsMapScene::editMapProperties()
{
    DialogMapProperties dlg(n_mapInfo, *m_map, m_view);
    dlg.exec();
}

void QGraphicsMapScene::redrawMap()
{
    if (!m_init)
        return;
    mCore->LoadChipset(m_map.get()->chipset_id);
    s_tileSize = mCore->tileSize()*m_scale;
    redrawLayer(LOWER);
    redrawLayer(UPPER);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    for (int i = 0; i < m_lines.count(); i++)
        m_lines[i]->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       m_map.get()->width* mCore->tileSize()*m_scale,
                       m_map.get()->height* mCore->tileSize()*m_scale);
    redrawMap();
}

void QGraphicsMapScene::onLayerChanged()
{
    if (m_drawing)
        stopDrawing();
    if (m_selecting)
        stopSelecting();
    switch (mCore->layer())
    {
    case (LOWER):
        m_lowerpix->graphicsEffect()->setEnabled(false);
        m_upperpix->graphicsEffect()->setEnabled(true);
        break;
    case (UPPER):
        m_lowerpix->graphicsEffect()->setEnabled(true);
        m_upperpix->graphicsEffect()->setEnabled(false);
        break;
    default:
        m_lowerpix->graphicsEffect()->setEnabled(false);
        m_upperpix->graphicsEffect()->setEnabled(false);
        break;
    }
    for (int i = 0; i < m_lines.count(); i++)
        m_lines[i]->setVisible(mCore->layer() == EVENT);
}

void QGraphicsMapScene::onToolChanged()
{
    if (m_drawing)
        stopDrawing();
    if (m_selecting)
        stopSelecting();
    switch (mCore->tool())
    {
    case (ZOOM):
        m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_zoom.png"),1,1));
        break;
    case (PENCIL):
        m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_pen.png"),1,1));
        break;
    case (RECTANGLE):
        m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_rectangle.png"),1,1));
        break;
    case (CIRCLE):
        m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_circle.png"),1,1));
        break;
    case (FILL):
        m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_fill.png"),1,1));
        break;
    }
}

void QGraphicsMapScene::Save()
{
    if (!isModified())
        return;

    *m_mapInfo = n_mapInfo;
    LMT_Reader::SaveXml(mCore->filePath(ROOT,EASY_MT).toStdString());
    QString file = QString("Map%1.emu")
            .arg(QString::number(m_mapInfo->ID), 4, QLatin1Char('0'));
    LMU_Reader::SaveXml(mCore->filePath(ROOT, file).toStdString(), *m_map);
    m_undoStack->clear();
    emit mapSaved();
}

void QGraphicsMapScene::Load()
{
    n_mapInfo = *m_mapInfo; //Revert info changes
    QString file = QString("Map%1.emu")
            .arg(QString::number(m_mapInfo->ID), 4, QLatin1Char('0'));
    m_map = LMU_Reader::LoadXml(mCore->filePath(ROOT, file).toStdString());
    m_lower =  m_map.get()->lower_layer;
    m_upper =  m_map.get()->upper_layer;
    if(m_map.get()->parallax_flag)
        mCore->LoadBackground(m_map.get()->parallax_name.c_str());
    else
        mCore->LoadBackground(QString());
    for (int i = 0; i < m_lines.count(); i++)
        removeItem(m_lines[i]);
    m_lines.clear();
    for (int x = 0; x <= m_map.get()->width; x++)
    {
        QGraphicsLineItem* line = new QGraphicsLineItem(x*mCore->tileSize(),
                                                        0,
                                                        x*mCore->tileSize(),
                                                        m_map.get()->height*mCore->tileSize());
        m_lines.append(line);
        line->setScale(m_scale);
        line->setVisible(mCore->layer() == EVENT);
        addItem(line);
    }
    for (int y = 0; y <= m_map.get()->height; y++)
    {
        QGraphicsLineItem* line = new QGraphicsLineItem(0,
                                                        y*mCore->tileSize(),
                                                        m_map.get()->width*mCore->tileSize(),
                                                        y*mCore->tileSize());
        m_lines.append(line);
        line->setScale(m_scale);
        line->setVisible(mCore->layer() == EVENT);
        addItem(line);
    }
    redrawMap();
    m_undoStack->clear();
    emit mapReverted();
}

void QGraphicsMapScene::undo()
{
    m_undoStack->undo();
    if (m_undoStack->index() == 0)
    {
        m_undoStack->clear();
        emit mapReverted();
    }
}

void QGraphicsMapScene::on_actionNewEvent()
{

}

void QGraphicsMapScene::on_actionRunHere()
{
    mCore->runGameHere(id(), lst_x, lst_y);
}

void QGraphicsMapScene::on_actionSetStartPosition()
{
    Data::treemap.start.party_map_id = this->id();
    Data::treemap.start.party_x = lst_x;
    Data::treemap.start.party_y = lst_y;
    LMT_Reader::SaveXml(mCore->filePath(ROOT,EASY_MT).toStdString());
}

void QGraphicsMapScene::on_user_interaction()
{
    m_userInteraction = true;
}

void QGraphicsMapScene::on_view_V_Scroll()
{
    if (!m_userInteraction || !m_init)
        return;
    if (m_view->verticalScrollBar()->isVisible())
    {
        m_mapInfo->scrollbar_y = m_view->verticalScrollBar()->value()/m_scale;
        n_mapInfo.scrollbar_y = m_view->verticalScrollBar()->value()/m_scale;
    }
    m_userInteraction = false;
    LMT_Reader::SaveXml(mCore->filePath(ROOT,EASY_MT).toStdString());
}

void QGraphicsMapScene::on_view_H_Scroll()
{
    if (!m_userInteraction || !m_init)
        return;
    if (m_view->horizontalScrollBar()->isVisible())
    {
        m_mapInfo->scrollbar_x = m_view->horizontalScrollBar()->value()/m_scale;
        n_mapInfo.scrollbar_x = m_view->horizontalScrollBar()->value()/m_scale;
    }
    m_userInteraction = false;
    LMT_Reader::SaveXml(mCore->filePath(ROOT,EASY_MT).toStdString());
}

void QGraphicsMapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        if (m_drawing)
        {
            stopDrawing();
            return;
        }
        if (sceneRect().contains(event->scenePos()) && mCore->layer() == EVENT)
        {
            lst_x = cur_x;
            lst_y = cur_y;
            m_eventMenu->popup(event->screenPos());
        }
        if (mCore->tool() == ZOOM && m_scale > 0.25)
            setScale(m_scale/2);
    }
    if (event->button() == Qt::LeftButton)
    {
        if (m_selecting)
        {
            stopSelecting();
            return;
        }
        if (mCore->tool() == ZOOM && m_scale < 2.0)
            setScale(m_scale*2);
    }
    if(event->button() == Qt::LeftButton && mCore->layer() != EVENT) //Start drawing
    {
        fst_x = cur_x;
        fst_y = cur_y;
        switch(mCore->tool())
        {
        case (PENCIL):
            m_drawing = true;
            drawPen();
            break;
        case (RECTANGLE):
            m_drawing = true;
            drawRect();
            break;
        case (FILL):
            m_drawing = true;
            if (mCore->layer() == LOWER)
                drawFill(mCore->translate(m_lower[_index(fst_x,fst_y)]),fst_x,fst_y);
            else if (mCore->layer() == UPPER)
                drawFill(mCore->translate(m_upper[_index(fst_x,fst_y)]),fst_x,fst_y);
            updateArea(0, 0, m_map.get()->width-1 ,m_map.get()->height-1);
        default:
            break;
        }
    }
    if(event->button() == Qt::RightButton) //StartSelecting
    {

    }
}

void QGraphicsMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!sceneRect().contains(event->scenePos()))
        return;
    if (cur_x == event->scenePos().x()/s_tileSize && cur_y == event->scenePos().y()/s_tileSize)
        return;
    cur_x = event->scenePos().x()/s_tileSize;
    cur_y = event->scenePos().y()/s_tileSize;
    if (m_drawing)
    {
        switch (mCore->tool())
        {
        case (PENCIL):
            drawPen();
            break;
        case (RECTANGLE):
            drawRect();
            break;
        default:
            break;
        }
    }
}

void QGraphicsMapScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (m_cancelled && !event->buttons())
    {
        m_cancelled = false;
        onToolChanged();
        return;
    }
    if (m_drawing && !m_cancelled)
    {
        m_drawing = false;
        if (mCore->layer() == LOWER)
        {
            m_undoStack->push(new QUndoDraw(LOWER,
                                            m_map.get()->lower_layer,
                                            this));
            m_map.get()->lower_layer = m_lower;
        }
        else
        {
            m_undoStack->push(new QUndoDraw(UPPER,
                                            m_map.get()->upper_layer,
                                            this));
            m_map.get()->upper_layer = m_upper;
        }
        emit mapChanged();
    }
}

void QGraphicsMapScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (mCore->layer() != EVENT)
        return;
    for (unsigned int i = 0; i < m_map.get()->events.size(); i++)
        if (_index(cur_x,cur_y) == _index(m_map.get()->events[i].x,m_map.get()->events[i].y))
        {
            RPG::Event backup = m_map.get()->events[i];
            int result = DialogEvent::edit(m_view, &m_map.get()->events[i]);
            if (result != QDialogButtonBox::Cancel)
            {
                m_undoStack->push(new QUndoEvent(backup,
                                                 this));
                emit mapChanged();
            }
        }
}

int QGraphicsMapScene::_x(int index)
{
    return (index%m_map.get()->width);
}

int QGraphicsMapScene::_y(int index)
{
    return (index/m_map.get()->width);
}

int QGraphicsMapScene::_index(int x, int y)
{
    return (m_map.get()->width*y+x);
}

void QGraphicsMapScene::redrawTile(const Layer &layer,
                                   const int &x,
                                   const int &y,
                                   const QRect &dest_rec)
{
    switch (layer)
    {
    case (LOWER):
        mCore->renderTile(m_lower[_index(x,y)],dest_rec);
        break;
    case (UPPER):
        mCore->renderTile(m_upper[_index(x,y)],dest_rec);
        break;
    default:
        break;
    }
}

void QGraphicsMapScene::stopDrawing()
{
    m_cancelled = true;
    m_drawing = false;
    m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_cancel.png"),1,1));
    m_lower = m_map.get()->lower_layer;
    m_upper = m_map.get()->upper_layer;
    redrawLayer(LOWER);
    redrawLayer(UPPER);
}

void QGraphicsMapScene::stopSelecting()
{
    m_cancelled = true;
    m_selecting = false;
    m_lowerpix->setCursor(QCursor(QPixmap(":/icons/share/cur_cancel.png"),1,1));
    //cancel selection...
}

void QGraphicsMapScene::updateArea(int x1, int y1, int x2, int y2)
{
    //Normalize
    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= m_map.get()->width)
        x2 = m_map.get()->width - 1;
    if (y2 >= m_map.get()->height)
        y2 = m_map.get()->height - 1;

    for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y++)
        {
            if (mCore->layer() == LOWER)
            {
                if (!mCore->isEblock(mCore->translate(m_lower[_index(x, y)])) &&
                    !mCore->isAnimation(mCore->translate(m_lower[_index(x, y)])))
                    m_lower[_index(x,y)] = bind(x, y);
            }

        }
    redrawLayer(mCore->layer());
}

void QGraphicsMapScene::redrawLayer(Layer layer)
{
    QSize size = m_view->size();
    if (size.width() > m_map.get()->width*s_tileSize)
        size.setWidth(m_map.get()->width*s_tileSize);
    else
        size.setWidth(size.width()+s_tileSize);
    if (size.height() > m_map.get()->height*s_tileSize)
        size.setHeight(m_map.get()->height*s_tileSize);
    else
        size.setHeight(size.height()+s_tileSize);
    int start_x = m_view->horizontalScrollBar()->value()/s_tileSize;
    int start_y = m_view->verticalScrollBar()->value()/s_tileSize;
    int end_x = start_x+(size.width()-1)/s_tileSize;
    int end_y = start_y+(size.height()-1)/s_tileSize;
    QPixmap pix(size);
    pix.fill(QColor(0,0,0,0));
    mCore->beginPainting(pix);
    for (int x = start_x; x <= end_x; x++)
        for (int y = start_y; y <= end_y; y++)
        {
            if (x >= m_map.get()->width || y >= m_map.get()->height)
                continue;
            QRect dest_rect((x-start_x)* s_tileSize,
                       (y-start_y)* s_tileSize,
                       s_tileSize,
                       s_tileSize);
            redrawTile(layer, x, y, dest_rect);
        }
    if (layer == UPPER)
    {
        for (unsigned int i = 0; i <  m_map.get()->events.size(); i++)
        {
            QRect rect((m_map.get()->events[i].x-start_x)* s_tileSize,
                       (m_map.get()->events[i].y-start_y)* s_tileSize,
                       s_tileSize,
                       s_tileSize);
            mCore->renderTile(EV, rect);
        }
    }
    mCore->endPainting();
    if (layer == LOWER)
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

void QGraphicsMapScene::drawPen()
{
    for (int x = cur_x; x < cur_x + mCore->selWidth(); x++)
        for (int y = cur_y; y < cur_y + mCore->selHeight(); y++)
        {
            if (mCore->layer() == LOWER)
                m_lower[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
            else if (mCore->layer() == UPPER)
                m_upper[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
        }
    updateArea(cur_x-1,cur_y-1,cur_x+mCore->selWidth()+1,cur_y+mCore->selHeight()+1);
}

void QGraphicsMapScene::drawRect()
{
    switch (mCore->layer())
    {
    case (LOWER):
        m_lower = m_map.get()->lower_layer;
        break;
    case (UPPER):
        m_upper = m_map.get()->upper_layer;
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
            if (mCore->layer() == LOWER)
                m_lower[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
            else if (mCore->layer() == UPPER)
                m_upper[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
        }
    updateArea(x1-2, y1-2, x2+2, y2+2);
}

void QGraphicsMapScene::drawFill(int terrain_id, int x, int y)
{
    if (x < 0 || x >= m_map.get()->width || y < 0 || y >= m_map.get()->height)
        return;
    if (terrain_id == mCore->selection(x-fst_x,y-fst_y))
        return;
    switch (mCore->layer())
    {
    case (LOWER):
        if (mCore->translate(m_lower[_index(x,y)]) != terrain_id)
            return;
        m_lower[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
        break;
    case (UPPER):
        if (mCore->translate(m_upper[_index(x,y)]) != terrain_id)
            return;
        m_upper[_index(x,y)] = mCore->selection(x-fst_x,y-fst_y);
        break;
    default:
        break;
    }
    drawFill(terrain_id, x, y-1);
    drawFill(terrain_id, x-1, y);
    drawFill(terrain_id, x+1, y);
    drawFill(terrain_id, x, y+1);
}

short QGraphicsMapScene::bind(int x, int y)
{
#define tile_u mCore->translate(m_lower[_index(x, y-1)])
#define tile_d mCore->translate(m_lower[_index(x, y+1)])
#define tile_l mCore->translate(m_lower[_index(x-1, y)])
#define tile_r mCore->translate(m_lower[_index(x+1, y)])
#define tile_ul mCore->translate(m_lower[_index(x-1, y-1)])
#define tile_ur mCore->translate(m_lower[_index(x+1, y-1)])
#define tile_dl mCore->translate(m_lower[_index(x-1, y+1)])
#define tile_dr mCore->translate(m_lower[_index(x+1, y+1)])
    int _code = 0, _scode = 0;
    int terrain_id = mCore->translate(m_lower[_index(x, y)]);
    int u=0,d=0,l=0,r=0,ul=0,ur=0,dl=0,dr=0,sul=0,sur=0,sdl=0,sdr=0;
    if (mCore->isDblock(terrain_id))
    {
        if (y > 0 && terrain_id != tile_u)
            u = UP;
        if (y < m_map.get()->height-1 && terrain_id != tile_d)
            d = DOWN;
        if (x > 0 && terrain_id != tile_l)
            l = LEFT;
        if (x < m_map.get()->width-1 && terrain_id != tile_r)
            r = RIGHT;
        if (u+l == 0 && x > 0 && y > 0 && terrain_id != tile_ul)
            ul = UPLEFT;
        if (u+r == 0 && x < m_map.get()->width-1 && y > 0 && terrain_id != tile_ur)
            ur = UPRIGHT;
        if (d+l == 0 && x > 0 && y < m_map.get()->height-1 && terrain_id != tile_dl)
            dl = DOWNLEFT;
        if (d+r == 0 && x < m_map.get()->width-1 &&
                y < m_map.get()->height-1 && terrain_id != tile_dr)
            dr = DOWNRIGHT;
        _code = u+d+l+r+ul+ur+dl+dr;
    }
    else if (mCore->isWater(terrain_id))
    {
        if (y > 0 && (!mCore->isWater(tile_u) &&
                      !mCore->isAnimation(tile_u)))
            u = UP;
        if (y < m_map.get()->height-1 && (!mCore->isWater(tile_d) &&
                                          !mCore->isAnimation(tile_d)))
            d = DOWN;
        if (x > 0 && (!mCore->isWater(tile_l) &&
                      !mCore->isAnimation(tile_l)))
            l = LEFT;
        if (x < m_map.get()->width-1 && (!mCore->isWater(tile_r) &&
                                         !mCore->isAnimation(tile_r)))
            r = RIGHT;
        if ((u+l) == 0 && x > 0 && y > 0 && !mCore->isWater(tile_ul))
            ul = UPLEFT;
        if ((u+r) == 0 && x < m_map.get()->width-1 && y > 0 && !mCore->isWater(tile_ur))
            ur = UPRIGHT;
        if ((d+l) == 0 && x > 0 && y < m_map.get()->height-1 && !mCore->isWater(tile_dl))
            dl = DOWNLEFT;
        if ((d+r) == 0 && x < m_map.get()->width-1 &&
                y < m_map.get()->height-1 && !mCore->isWater(tile_dr))
            dr = DOWNRIGHT;
        _code = u+d+l+r+ul+ur+dl+dr;
        // DeepWater Special Corners
        if (mCore->isDWater(terrain_id))
        {
            if (x > 0 && y > 0 && mCore->isABWater(tile_u) && mCore->isABWater (tile_l) && mCore->isABWater (tile_ul))
                sul = UPLEFT;
            if (x < m_map.get()->width-1 && y > 0 && mCore->isABWater(tile_u) && mCore->isABWater (tile_r) && mCore->isABWater (tile_ur))
                sur = UPRIGHT;
            if (x > 0 && y < m_map.get()->height-1 && mCore->isABWater(tile_d) && mCore->isABWater (tile_l) && mCore->isABWater (tile_dl))
                sdl = DOWNLEFT;
            if (x < m_map.get()->width-1 && y < m_map.get()->height-1 &&
                    mCore->isABWater(tile_d) && mCore->isABWater (tile_r) && mCore->isABWater (tile_dr))
                sdr = DOWNRIGHT;
        }
        else
        {
            if (x > 0 && y > 0 && mCore->isDWater (tile_u) && mCore->isDWater (tile_l) && mCore->isWater(tile_ul))
                sul = UPLEFT;
            if (x < m_map.get()->width-1 && y > 0 && mCore->isDWater (tile_u) && mCore->isDWater (tile_r) && mCore->isWater(tile_ur))
                sur = UPRIGHT;
            if (x > 0 && y < m_map.get()->height-1 && mCore->isDWater (tile_d) && mCore->isDWater (tile_l) && mCore->isWater(tile_dl))
                sdl = DOWNLEFT;
            if (x < m_map.get()->width-1 && y < m_map.get()->height-1 &&
                    mCore->isDWater (tile_d) && mCore->isDWater (tile_r) && mCore->isWater(tile_dr))
                sdr = DOWNRIGHT;
        }
        _scode = sul+sur+sdl+sdr;
    }
    return mCore->translate(terrain_id, _code, _scode);
#undef tile_u
#undef tile_d
#undef tile_l
#undef tile_r
#undef tile_ul
#undef tile_ur
#undef tile_dl
#undef tile_dr
}
