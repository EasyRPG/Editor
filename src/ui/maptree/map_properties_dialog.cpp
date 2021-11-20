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

#include "map_properties_dialog.h"
#include "ui_map_properties_dialog.h"
#include "core.h"
#include "common/dbstring.h"
#include "ui/picker/picker_audio_widget.h"
#include "ui/picker/picker_dialog.h"

MapPropertiesDialog::MapPropertiesDialog(ProjectData& project, lcf::rpg::MapInfo &info, lcf::rpg::Map &map, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MapPropertiesDialog),
	m_info(info),
	m_map(map),
	m_project(project)
{
	ui->setupUi(this);
	connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(ok()));

	auto& database = project.database();

	for (int terrain = 0; terrain < 162; terrain++)
		m_generatorLowerLayer.push_back(core().translate(terrain, UP+DOWN+LEFT+RIGHT));
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

	ui->lineName->setText(ToQString(info.name));
	ui->lineBGMname->setText(ToQString(info.music.name));
	ui->lineBackdropName->setText(ToQString(info.background_name));
	for (int i = 0; i < static_cast<int>(database.chipsets.size()); i++)
		ui->comboTileset->addItem(ToQString(database.chipsets[static_cast<size_t>(i)].name), i+1);
	ui->comboTileset->setCurrentIndex(map.chipset_id-1);
	ui->comboWrapping->setCurrentIndex(map.scroll_type);
	ui->spinDungeonRoomHeight->setValue(map.generator_height);
	ui->spinDungeonRoomWidth->setValue(map.generator_width);
	ui->spinEncounterRate->setValue(info.encounter_steps);
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
	for (int i = static_cast<int>(info.encounters.size()) - 1; i >= 0; i--)
	{
		QTableWidgetItem * item = new QTableWidgetItem();
		item->setData(Qt::DisplayRole, ToQString(database.troops[static_cast<size_t>(info.encounters[static_cast<size_t>(i)].troop_id)-1].name));
		item->setData(Qt::UserRole, info.encounters[static_cast<size_t>(i)].troop_id);
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
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[0], QRect(0,0,32,32));
	core().endPainting();
	m_ceilingItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[1], QRect(0,0,32,32));
	core().endPainting();
	m_lowerWallItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[2], QRect(0,0,32,32));
	core().endPainting();
	m_upperWallItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[3], QRect(0,0,32,32));
	core().endPainting();
	m_floorAItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[4], QRect(0,0,32,32));
	core().endPainting();
	m_floorBItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[5], QRect(0,0,32,32));
	core().endPainting();
	m_floorCItem->setPixmap(pix);

	pix = QPixmap(64, 64);
	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[6], QRect(0,0,32,32));
	core().renderTile(map.generator_tile_ids[7], QRect(32,0,32,32));
	core().renderTile(map.generator_tile_ids[8], QRect(0,32,32,32));
	core().renderTile(map.generator_tile_ids[9], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleAItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[10], QRect(0,0,32,32));
	core().renderTile(map.generator_tile_ids[11], QRect(32,0,32,32));
	core().renderTile(map.generator_tile_ids[12], QRect(0,32,32,32));
	core().renderTile(map.generator_tile_ids[13], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleBItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(map.generator_tile_ids[14], QRect(0,0,32,32));
	core().renderTile(map.generator_tile_ids[15], QRect(32,0,32,32));
	core().renderTile(map.generator_tile_ids[16], QRect(0,32,32,32));
	core().renderTile(map.generator_tile_ids[17], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleCItem->setPixmap(pix);
	}
	if (map.parallax_flag)
	{
		pix = QPixmap(m_project.project().findFile(PANORAMA, ToQString(map.parallax_name), FileFinder::FileType::Image));
		if (!pix)
			pix = QPixmap(core().rtpPath(PANORAMA,ToQString(map.parallax_name)));
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

	new_music = info.music;
}

MapPropertiesDialog::~MapPropertiesDialog()
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

void MapPropertiesDialog::ok() {
	m_info.name = ToDBString(ui->lineName->text());
	m_map.chipset_id = ui->comboTileset->currentIndex() + 1;
	m_map.width = ui->spinWidth->value();
	m_map.height = ui->spinHeight->value();
	m_map.scroll_type = ui->comboWrapping->currentIndex();
	if (ui->radioBGMparent->isChecked()) {
		m_info.music_type = 0;
	} else if (ui->radioBGMevent->isChecked()) {
		m_info.music_type = 1;
	} else {
		m_info.music_type = 2;
	}
	new_music.name = ui->lineBGMname->text().toStdString();
	m_info.music = new_music;
	if (ui->radioTeleportParent->isChecked()) {
		m_info.teleport = 0;
	} else if (ui->radioTeleportAllow->isChecked()) {
		m_info.teleport = 1;
	} else {
		m_info.teleport = 2;
	}
	if (ui->radioEscapeParent->isChecked()) {
		m_info.escape = 0;
	} else if (ui->radioEscapeAllow->isChecked()) {
		m_info.escape = 1;
	} else {
		m_info.escape = 2;
	}
	if (ui->radioSaveParent->isChecked()) {
		m_info.save = 0;
	} else if (ui->radioSaveAllow->isChecked()) {
		m_info.save = 1;
	} else {
		m_info.save = 2;
	}
}

void MapPropertiesDialog::on_groupPanorama_toggled(bool arg1)
{
	m_panoramaItem->setVisible(arg1);
}

void MapPropertiesDialog::on_groupUseGenerator_toggled(bool arg1)
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

void MapPropertiesDialog::on_groupUpperWall_toggled(bool arg1)
{
	m_upperWallItem->setVisible(arg1);
}

void MapPropertiesDialog::on_groupFloorB_toggled(bool arg1)
{
	m_floorBItem->setVisible(arg1);
}

void MapPropertiesDialog::on_groupFloorC_toggled(bool arg1)
{
	m_floorCItem->setVisible(arg1);
}

void MapPropertiesDialog::on_groupObstacleB_toggled(bool arg1)
{
	m_ObstacleBItem->setVisible(arg1);
}

void MapPropertiesDialog::on_groupObstacleC_toggled(bool arg1)
{
	m_ObstacleCItem->setVisible(arg1);
}

void MapPropertiesDialog::on_tableEncounters_itemChanged(QTableWidgetItem *item)
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

void MapPropertiesDialog::on_toolSetBGM_clicked() {
	auto* widget = new PickerAudioWidget(new_music, this);
	PickerDialog dialog(m_project, FileFinder::FileType::Music, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		ui->lineBGMname->setText(baseName);
		new_music.name = baseName.toStdString();
		new_music.fadein = widget->fadeInTime();
		new_music.volume = widget->volume();
		new_music.tempo = widget->tempo();
		new_music.balance = widget->balance();
	});
	dialog.setDirectoryAndFile(MUSIC, ui->lineBGMname->text());
	dialog.exec();
}
