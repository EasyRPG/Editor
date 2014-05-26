#include "dialogmapproperties.h"
#include "ui_dialogmapproperties.h"
#include <data.h>
#include "core.h"

DialogMapProperties::DialogMapProperties(RPG::MapInfo &info, RPG::Map &map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMapProperties),
    m_info(info),
    m_map(map)
{
    ui->setupUi(this);

    for (int terrain = 0; terrain < 162; terrain++)
        m_generatorLowerLayer.push_back(mCore->translate(terrain, UP+DOWN+LEFT+RIGHT));
    for (short tile_id = 10000; tile_id < 10144; tile_id++)
        m_generatorUpperLayer.push_back(tile_id);

    m_panoramaItem = new QGraphicsPixmapItem();
    m_ceilingItem = new QGraphicsPixmapItem();
    m_lowerWallItem = new QGraphicsPixmapItem();
    m_upperWallItem = new QGraphicsPixmapItem();
    m_floorAItem = new QGraphicsPixmapItem();
    m_floorBItem = new QGraphicsPixmapItem();
    m_floorCItem = new QGraphicsPixmapItem();
    m_ObstacleAItem = new QGraphicsPixmapItem();
    m_ObstacleBItem = new QGraphicsPixmapItem();
    m_ObstacleCItem = new QGraphicsPixmapItem();

    ui->lineName->setText(QString::fromStdString(info.name));
    ui->lineBGMname->setText(QString::fromStdString(info.music.name));
    ui->lineBackdropName->setText(QString::fromStdString(info.background_name));
    for (int i = 0; i < (int)Data::chipsets.size(); i++)
        ui->comboTileset->addItem(QString::fromStdString(Data::chipsets[i].name), i+1);
    ui->comboTileset->setCurrentIndex(map.chipset_id-1);
    ui->comboWrapping->setCurrentIndex(map.scroll_type);
    ui->spinDungeonRoomHeight->setValue(map.generator_height);
    ui->spinDungeonRoomWidth->setValue(map.generator_width);
    ui->spinEncontrerRate->setValue(info.encounter_steps);
    ui->spinHeight->setValue(map.height);
    ui->spinWidth->setValue(map.width);
    ui->spinHorizontalScrollSpeed->setValue(map.parallax_sx);
    ui->spinVerticalScrollSpeed->setValue(map.parallax_sy);
    ui->checkHorizontalAutoscroll->setChecked(map.parallax_auto_loop_x);
    ui->checkVerticalAutoscroll->setChecked(map.parallax_auto_loop_y);
    ui->checkDungeonSurroundWithWalls->setChecked(map.generator_surround);
    ui->groupHorizontalScroll->setChecked(map.parallax_loop_x);
    ui->groupVerticalScroll->setChecked(map.parallax_loop_y);
    ui->groupPanorama->setChecked(map.parallax_flag);
    ui->groupUseGenerator->setChecked(map.generator_flag);
    ui->radioBackdropParent->setChecked(info.background_type == 0);
    ui->radioBackdropTerrain->setChecked(info.background_type == 1);
    ui->radioBackdropSpecify->setChecked(info.background_type == 2);
    ui->radioBGMparent->setChecked(info.music_type == 0);
    ui->radioBGMevent->setChecked(info.music_type == 1);
    ui->radioBGMspecify->setChecked(info.music_type == 2);
    ui->radioTeleportParent->setChecked(info.teleport == 0);
    ui->radioTeleportAllow->setChecked(info.teleport == 1);
    ui->radioTeleportForbid->setChecked(info.teleport == 2);
    ui->radioEscapeParent->setChecked(info.escape == 0);
    ui->radioEscapeAllow->setChecked(info.escape == 1);
    ui->radioEscapeForbid->setChecked(info.escape == 2);
    ui->radioSaveParent->setChecked(info.save == 0);
    ui->radioSaveAllow->setChecked(info.save == 1);
    ui->radioSaveForbid->setChecked(info.save == 2);
    ui->radioDungeonSinglePassage->setChecked(map.generator_mode == 0);
    ui->radioDungeonLinkedRooms->setChecked(map.generator_mode == 1);
    ui->radioDungeonMaze->setChecked(map.generator_mode == 2);
    ui->radioDungeonOpenRoom->setChecked(map.generator_mode == 3);
    ui->radioDungeonPassage1_1->setChecked(map.generator_tiles == 0);
    ui->radioDungeonPassage2_2->setChecked(map.generator_tiles == 1);
    for (int i = (int)info.encounters.size() - 1; i >= 0; i--)
    {
        QTableWidgetItem * item = new QTableWidgetItem();
        item->setData(Qt::DisplayRole, QString::fromStdString(Data::troops[info.encounters[i].troop_id-1].name));
        item->setData(Qt::UserRole, info.encounters[i].troop_id);
        ui->tableEncounters->insertRow(0);
        ui->tableEncounters->setItem(0,0,item);
    }
    m_encounterDelegate = new QEncounterDelegate(this);
    ui->tableEncounters->setItemDelegate(m_encounterDelegate);

    ui->graphicsPanorama->setScene(new QGraphicsScene(this));
    ui->graphicsCeiling->setScene(new QGraphicsScene(this));
    ui->graphicsFloorA->setScene(new QGraphicsScene(this));
    ui->graphicsFloorB->setScene(new QGraphicsScene(this));
    ui->graphicsFloorC->setScene(new QGraphicsScene(this));
    ui->graphicsLowerWall->setScene(new QGraphicsScene(this));
    ui->graphicsObstacleA->setScene(new QGraphicsScene(this));
    ui->graphicsObstacleB->setScene(new QGraphicsScene(this));
    ui->graphicsObstacleC->setScene(new QGraphicsScene(this));
    ui->graphicsUpperWall->setScene(new QGraphicsScene(this));

    ui->graphicsPanorama->scene()->addItem(m_panoramaItem);
    ui->graphicsCeiling->scene()->addItem(m_ceilingItem);
    ui->graphicsFloorA->scene()->addItem(m_floorAItem);
    ui->graphicsFloorB->scene()->addItem(m_floorBItem);
    ui->graphicsFloorC->scene()->addItem(m_floorCItem);
    ui->graphicsLowerWall->scene()->addItem(m_lowerWallItem);
    ui->graphicsObstacleA->scene()->addItem(m_ObstacleAItem);
    ui->graphicsObstacleB->scene()->addItem(m_ObstacleBItem);
    ui->graphicsObstacleC->scene()->addItem(m_ObstacleCItem);
    ui->graphicsUpperWall->scene()->addItem(m_upperWallItem);
    QPixmap pix(32, 32);
    if(map.generator_tile_ids.size()>0)
    {

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[0], QRect(0,0,32,32));
    mCore->endPainting();
    m_ceilingItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[1], QRect(0,0,32,32));
    mCore->endPainting();
    m_lowerWallItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[2], QRect(0,0,32,32));
    mCore->endPainting();
    m_upperWallItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[3], QRect(0,0,32,32));
    mCore->endPainting();
    m_floorAItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[4], QRect(0,0,32,32));
    mCore->endPainting();
    m_floorBItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[5], QRect(0,0,32,32));
    mCore->endPainting();
    m_floorCItem->setPixmap(pix);

    pix = QPixmap(64, 64);
    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[6], QRect(0,0,32,32));
    mCore->renderTile(map.generator_tile_ids[7], QRect(32,0,32,32));
    mCore->renderTile(map.generator_tile_ids[8], QRect(0,32,32,32));
    mCore->renderTile(map.generator_tile_ids[9], QRect(32,32,32,32));
    mCore->endPainting();
    m_ObstacleAItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[10], QRect(0,0,32,32));
    mCore->renderTile(map.generator_tile_ids[11], QRect(32,0,32,32));
    mCore->renderTile(map.generator_tile_ids[12], QRect(0,32,32,32));
    mCore->renderTile(map.generator_tile_ids[13], QRect(32,32,32,32));
    mCore->endPainting();
    m_ObstacleBItem->setPixmap(pix);

    pix.fill();
    mCore->beginPainting(pix);
    mCore->renderTile(map.generator_tile_ids[14], QRect(0,0,32,32));
    mCore->renderTile(map.generator_tile_ids[15], QRect(32,0,32,32));
    mCore->renderTile(map.generator_tile_ids[16], QRect(0,32,32,32));
    mCore->renderTile(map.generator_tile_ids[17], QRect(32,32,32,32));
    mCore->endPainting();
    m_ObstacleCItem->setPixmap(pix);
    }
    if (map.parallax_flag)
    {
        pix = QPixmap(mCore->filePath(PANORAMA,QString::fromStdString(map.parallax_name)));
        if (pix.isNull())
            pix = QPixmap(mCore->rtpPath(PANORAMA,QString::fromStdString(map.parallax_name)));
        m_panoramaItem->setPixmap(pix);
    }

    //TODO: Show generator tiles.
    if (info.parent_map == 0)
    {
        ui->radioBackdropParent->setEnabled(false);
        ui->radioBGMparent->setEnabled(false);
        ui->radioTeleportParent->setEnabled(false);
        ui->radioSaveParent->setEnabled(false);
        ui->radioEscapeParent->setEnabled(false);
    }
}

DialogMapProperties::~DialogMapProperties()
{
    delete m_panoramaItem;
    delete m_ceilingItem;
    delete m_lowerWallItem;
    delete m_upperWallItem;
    delete m_floorAItem;
    delete m_floorBItem;
    delete m_floorCItem;
    delete m_ObstacleAItem;
    delete m_ObstacleBItem;
    delete m_ObstacleCItem;

    delete ui;
}

void DialogMapProperties::on_groupPanorama_toggled(bool arg1)
{
    m_panoramaItem->setVisible(arg1);
}

void DialogMapProperties::on_groupUseGenerator_toggled(bool arg1)
{
    m_ceilingItem->setVisible(arg1);
    m_lowerWallItem->setVisible(arg1);
    m_floorAItem->setVisible(arg1);
    m_ObstacleAItem->setVisible(arg1);
    if (arg1)
    {
        m_upperWallItem->setVisible(ui->groupUpperWall->isChecked());
        m_floorBItem->setVisible(ui->groupFloorB->isChecked());
        m_floorCItem->setVisible(ui->groupFloorC->isChecked());
        m_ObstacleBItem->setVisible(ui->groupObstacleB->isChecked());
        m_ObstacleCItem->setVisible(ui->groupObstacleC->isChecked());
    }
    else
    {
        m_upperWallItem->setVisible(false);
        m_floorBItem->setVisible(false);
        m_floorCItem->setVisible(false);
        m_ObstacleBItem->setVisible(false);
        m_ObstacleCItem->setVisible(false);
    }
}

void DialogMapProperties::on_groupUpperWall_toggled(bool arg1)
{
    m_upperWallItem->setVisible(arg1);
}

void DialogMapProperties::on_groupFloorB_toggled(bool arg1)
{
    m_floorBItem->setVisible(arg1);
}

void DialogMapProperties::on_groupFloorC_toggled(bool arg1)
{
    m_floorCItem->setVisible(arg1);
}

void DialogMapProperties::on_groupObstacleB_toggled(bool arg1)
{
    m_ObstacleBItem->setVisible(arg1);
}

void DialogMapProperties::on_groupObstacleC_toggled(bool arg1)
{
    m_ObstacleCItem->setVisible(arg1);
}

void DialogMapProperties::on_tableEncounters_itemChanged(QTableWidgetItem *item)
{
    if (item->row() == ui->tableEncounters->rowCount()-1)
    {
        QTableWidgetItem *n_item = new QTableWidgetItem();
        n_item->setData(Qt::DisplayRole, item->data(Qt::DisplayRole));
        n_item->setData(Qt::UserRole, item->data(Qt::UserRole));
        ui->tableEncounters->insertRow(ui->tableEncounters->rowCount()-1);
        ui->tableEncounters->setItem(ui->tableEncounters->rowCount()-2, 0, n_item);
        item->setData(Qt::DisplayRole, "<Add Encounter>");
    }
}
