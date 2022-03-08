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
#include "ui/picker/picker_backdrop_widget.h"
#include "ui/picker/picker_panorama_widget.h"
#include "ui/picker/picker_dialog.h"
#include <QMessageBox>
#include "common/lcf_widget_binding.h"

MapPropertiesDialog::MapPropertiesDialog(ProjectData& project, lcf::rpg::MapInfo &info, lcf::rpg::Map &map, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MapPropertiesDialog),
	m_info(info),
	m_map(map),
	m_project(project)
{
	ui->setupUi(this);

	m_info_copy = m_info;
	m_map_copy = m_map;

	auto& database = project.database();

	for (int i = 0; i < static_cast<int>(database.chipsets.size()); i++) {
		ui->comboTileset->addItem(ToQString(database.chipsets[static_cast<size_t>(i)].name), i + 1);
	}

	ui->comboWrapping->addItem("None", lcf::rpg::Map::ScrollType_none);
	ui->comboWrapping->addItem("Vertical", lcf::rpg::Map::ScrollType_vertical);
	ui->comboWrapping->addItem("Horizontal", lcf::rpg::Map::ScrollType_horizontal);
	ui->comboWrapping->addItem("Both", lcf::rpg::Map::ScrollType_both);

	m_buttonGroupBGM = new QButtonGroup(this);
	m_buttonGroupBGM->addButton(ui->radioBGMparent);
	m_buttonGroupBGM->setId(ui->radioBGMparent, lcf::rpg::MapInfo::MusicType_parent);
	m_buttonGroupBGM->addButton(ui->radioBGMevent);
	m_buttonGroupBGM->setId(ui->radioBGMevent, lcf::rpg::MapInfo::MusicType_event);
	m_buttonGroupBGM->addButton(ui->radioBGMspecify);
	m_buttonGroupBGM->setId(ui->radioBGMspecify, lcf::rpg::MapInfo::MusicType_specific);

	m_buttonGroupBackdrop = new QButtonGroup(this);
	m_buttonGroupBackdrop->addButton(ui->radioBackdropParent);
	m_buttonGroupBackdrop->setId(ui->radioBackdropParent, lcf::rpg::MapInfo::BGMType_parent);
	m_buttonGroupBackdrop->addButton(ui->radioBackdropTerrain);
	m_buttonGroupBackdrop->setId(ui->radioBackdropTerrain, lcf::rpg::MapInfo::BGMType_terrain);
	m_buttonGroupBackdrop->addButton(ui->radioBackdropSpecify);
	m_buttonGroupBackdrop->setId(ui->radioBackdropSpecify, lcf::rpg::MapInfo::BGMType_specific);

	m_buttonGroupTeleport = new QButtonGroup(this);
	m_buttonGroupTeleport->addButton(ui->radioTeleportParent);
	m_buttonGroupTeleport->setId(ui->radioTeleportParent, lcf::rpg::MapInfo::TriState_parent);
	m_buttonGroupTeleport->addButton(ui->radioTeleportAllow);
	m_buttonGroupTeleport->setId(ui->radioTeleportAllow, lcf::rpg::MapInfo::TriState_allow);
	m_buttonGroupTeleport->addButton(ui->radioTeleportForbid);
	m_buttonGroupTeleport->setId(ui->radioTeleportForbid, lcf::rpg::MapInfo::TriState_forbid);

	m_buttonGroupEscape = new QButtonGroup(this);
	m_buttonGroupEscape->addButton(ui->radioEscapeParent);
	m_buttonGroupEscape->setId(ui->radioEscapeParent, lcf::rpg::MapInfo::TriState_parent);
	m_buttonGroupEscape->addButton(ui->radioEscapeAllow);
	m_buttonGroupEscape->setId(ui->radioEscapeAllow, lcf::rpg::MapInfo::TriState_allow);
	m_buttonGroupEscape->addButton(ui->radioEscapeForbid);
	m_buttonGroupEscape->setId(ui->radioEscapeForbid, lcf::rpg::MapInfo::TriState_forbid);

	m_buttonGroupSave = new QButtonGroup(this);
	m_buttonGroupSave->addButton(ui->radioSaveParent);
	m_buttonGroupSave->setId(ui->radioSaveParent, lcf::rpg::MapInfo::TriState_parent);
	m_buttonGroupSave->addButton(ui->radioSaveAllow);
	m_buttonGroupSave->setId(ui->radioSaveAllow, lcf::rpg::MapInfo::TriState_allow);
	m_buttonGroupSave->addButton(ui->radioSaveForbid);
	m_buttonGroupSave->setId(ui->radioSaveForbid, lcf::rpg::MapInfo::TriState_forbid);

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

	ui->spinDungeonRoomHeight->setValue(m_map_copy.generator_height);
	ui->spinDungeonRoomWidth->setValue(m_map_copy.generator_width);
	ui->spinEncounterRate->setValue(m_info_copy.encounter_steps);
	ui->checkDungeonSurroundWithWalls->setChecked(m_map_copy.generator_surround);
	ui->groupUseGenerator->setChecked(m_map_copy.generator_flag);
	ui->radioDungeonSinglePassage->setChecked(m_map_copy.generator_mode == 0);
	ui->radioDungeonLinkedRooms->setChecked(m_map_copy.generator_mode == 1);
	ui->radioDungeonMaze->setChecked(m_map_copy.generator_mode == 2);
	ui->radioDungeonOpenRoom->setChecked(m_map_copy.generator_mode == 3);
	ui->radioDungeonPassage1_1->setChecked(m_map_copy.generator_tiles == 0);
	ui->radioDungeonPassage2_2->setChecked(m_map_copy.generator_tiles == 1);
	for (int i = 0; i < static_cast<int>(m_info_copy.encounters.size()); i++) {
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setData(Qt::DisplayRole, ToQString(database.troops[static_cast<size_t>(m_info_copy.encounters[static_cast<size_t>(i)].troop_id)-1].name));
		item->setData(Qt::UserRole, m_info_copy.encounters[static_cast<size_t>(i)].troop_id);
		ui->tableEncounters->insertRow(i);
		ui->tableEncounters->setItem(i, 0, item);
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
	if(m_map_copy.generator_tile_ids.size()>0)
	{

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[0], QRect(0,0,32,32));
	core().endPainting();
	m_ceilingItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[1], QRect(0,0,32,32));
	core().endPainting();
	m_lowerWallItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[2], QRect(0,0,32,32));
	core().endPainting();
	m_upperWallItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[3], QRect(0,0,32,32));
	core().endPainting();
	m_floorAItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[4], QRect(0,0,32,32));
	core().endPainting();
	m_floorBItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[5], QRect(0,0,32,32));
	core().endPainting();
	m_floorCItem->setPixmap(pix);

	pix = QPixmap(64, 64);
	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[6], QRect(0,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[7], QRect(32,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[8], QRect(0,32,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[9], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleAItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[10], QRect(0,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[11], QRect(32,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[12], QRect(0,32,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[13], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleBItem->setPixmap(pix);

	pix.fill();
	core().beginPainting(pix);
	core().renderTile(m_map_copy.generator_tile_ids[14], QRect(0,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[15], QRect(32,0,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[16], QRect(0,32,32,32));
	core().renderTile(m_map_copy.generator_tile_ids[17], QRect(32,32,32,32));
	core().endPainting();
	m_ObstacleCItem->setPixmap(pix);
	}
	if (m_map_copy.parallax_flag)
	{
		pix = QPixmap(m_project.project().findFile(PANORAMA, ToQString(m_map_copy.parallax_name), FileFinder::FileType::Image));
		if (!pix)
			pix = QPixmap(core().rtpPath(PANORAMA,ToQString(m_map_copy.parallax_name)));
		m_panoramaItem->setPixmap(pix);
	}

	//TODO: Show generator tiles.
	if (m_info_copy.parent_map == 0)
	{
		ui->radioBackdropParent->setEnabled(false);
		ui->radioBGMparent->setEnabled(false);
		ui->radioTeleportParent->setEnabled(false);
		ui->radioSaveParent->setEnabled(false);
		ui->radioEscapeParent->setEnabled(false);
	}

	new_panorama = m_map_copy.parallax_name;
	new_music = m_info_copy.music;

	old_width = m_map_copy.width;
	old_height = m_map_copy.height;

	ui->lineBGMname->setText(ToQString(m_info_copy.music.name));

	LcfWidgetBinding::connect(this, ui->lineName);
	LcfWidgetBinding::connect(this, ui->lineBackdropName);
	LcfWidgetBinding::connect<int32_t>(this, ui->comboTileset);
	LcfWidgetBinding::connect<int32_t>(this, ui->comboWrapping);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinWidth);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinHeight);
	LcfWidgetBinding::connect<bool>(this, ui->groupPanorama);
	LcfWidgetBinding::connect<bool>(this, ui->groupHorizontalScroll);
	LcfWidgetBinding::connect<bool>(this, ui->groupVerticalScroll);
	LcfWidgetBinding::connect<bool>(this, ui->checkHorizontalAutoscroll);
	LcfWidgetBinding::connect<bool>(this, ui->checkVerticalAutoscroll);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinHorizontalScrollSpeed);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinVerticalScrollSpeed);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupBGM);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupBackdrop);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupTeleport);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupEscape);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupSave);

	LcfWidgetBinding::bind(ui->lineName, m_info_copy.name);
	LcfWidgetBinding::bind(ui->lineBackdropName, m_info_copy.background_name);
	LcfWidgetBinding::bind(ui->comboTileset, m_map_copy.chipset_id);
	LcfWidgetBinding::bind(ui->comboWrapping, m_map_copy.scroll_type);
	LcfWidgetBinding::bind(ui->spinWidth, m_map_copy.width);
	LcfWidgetBinding::bind(ui->spinHeight, m_map_copy.height);
	LcfWidgetBinding::bind(ui->groupPanorama, m_map_copy.parallax_flag);
	LcfWidgetBinding::bind(ui->groupHorizontalScroll, m_map_copy.parallax_loop_x);
	LcfWidgetBinding::bind(ui->groupVerticalScroll, m_map_copy.parallax_loop_y);
	LcfWidgetBinding::bind(ui->checkHorizontalAutoscroll, m_map_copy.parallax_auto_loop_x);
	LcfWidgetBinding::bind(ui->checkVerticalAutoscroll, m_map_copy.parallax_auto_loop_y);
	LcfWidgetBinding::bind(ui->spinHorizontalScrollSpeed, m_map_copy.parallax_sx);
	LcfWidgetBinding::bind(ui->spinVerticalScrollSpeed, m_map_copy.parallax_sy);
	LcfWidgetBinding::bind(m_buttonGroupBGM, m_info_copy.music_type);
	LcfWidgetBinding::bind(m_buttonGroupBackdrop, m_info_copy.background_type);
	LcfWidgetBinding::bind(m_buttonGroupTeleport, m_info_copy.teleport);
	LcfWidgetBinding::bind(m_buttonGroupEscape, m_info_copy.escape);
	LcfWidgetBinding::bind(m_buttonGroupSave, m_info_copy.save);

	ui->spinHorizontalScrollSpeed->setEnabled(m_map_copy.parallax_auto_loop_x);
	ui->spinVerticalScrollSpeed->setEnabled(m_map_copy.parallax_auto_loop_y);
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

void MapPropertiesDialog::accept() {
	int width = m_map_copy.width;
	int height = m_map_copy.height;
	if (width < old_width || height < old_height) {
		int result = QMessageBox::question(this,
			"Shrink map",
			QString("You are about to shrink the current map. All out of bounds map data and events will be deleted. This cannot be undone. Do you want to continue?"),
			QMessageBox::Yes | QMessageBox::No);

		if (result != QMessageBox::Yes) {
			return;
		}
	}

	if (ui->groupPanorama->isChecked()) {
		m_map_copy.parallax_name = new_panorama;
	} else {
		m_map_copy.parallax_flag = false;
		m_map_copy.parallax_name = ToDBString("");
		m_map_copy.parallax_loop_x = false;
		m_map_copy.parallax_loop_y = false;
		m_map_copy.parallax_auto_loop_x = false;
		m_map_copy.parallax_auto_loop_y = false;
		m_map_copy.parallax_sx = 0;
		m_map_copy.parallax_sy = 0;
	}

	new_music.name = ui->lineBGMname->text().toStdString();
	m_info_copy.music = new_music;

	m_info_copy.encounters.clear();
	for (int i = 0; i < ui->tableEncounters->rowCount(); i++) {
		QTableWidgetItem *item = ui->tableEncounters->item(i, 0);
		lcf::rpg::Encounter enc;
		enc.troop_id = item->data(Qt::UserRole).toInt();
		m_info_copy.encounters.push_back(enc);
	}
	m_info_copy.encounter_steps = ui->spinEncounterRate->value();

	// Resize map if map bounds have been changed
	if (width != old_width || height != old_height) {
		auto old_lower_layer = m_map_copy.lower_layer;
		auto old_upper_layer = m_map_copy.upper_layer;
		int old_tile_counter = 0;

		m_map_copy.lower_layer.clear();
		m_map_copy.upper_layer.clear();
		for (int y = 0; y < height; y++) {
			if (y < old_height) {
				for (int x = 0; x < width; x++) {
					if (x < old_width) {
						m_map_copy.lower_layer.push_back(old_lower_layer[old_tile_counter]);
						m_map_copy.upper_layer.push_back(old_upper_layer[old_tile_counter]);
						old_tile_counter++;
					} else {
						m_map_copy.lower_layer.push_back(0);
						m_map_copy.upper_layer.push_back(10000);
					}
				}
				if (width < old_width) {
					old_tile_counter += (old_width - width);
				}
			} else {
				for (int x = 0; x < width; x++) {
					m_map_copy.lower_layer.push_back(0);
					m_map_copy.upper_layer.push_back(10000);
				}
			}
		}

		// Delete out of bounds events
		if (width < old_width || height < old_height) {
			std::vector<lcf::rpg::Event>::iterator ev = m_map_copy.events.begin();
			while (ev != m_map_copy.events.end()) {
				if (ev->x >= width || ev->y >= height) {
					ev = m_map_copy.events.erase(ev);
				} else {
					++ev;
				}
			}
		}
	}

	m_info = m_info_copy;
	m_map = m_map_copy;

	QDialog::accept();
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

void MapPropertiesDialog::on_pushAddEncounter_clicked() {
	QTableWidgetItem* item = new QTableWidgetItem();
	item->setData(Qt::DisplayRole, ToQString(m_project.database().troops[0].name));
	item->setData(Qt::UserRole, 1);
	ui->tableEncounters->insertRow(ui->tableEncounters->rowCount());
	ui->tableEncounters->setItem(ui->tableEncounters->rowCount() - 1, 0, item);
}

void MapPropertiesDialog::on_pushRemoveEncounter_clicked() {
	QTableWidgetItem *item = ui->tableEncounters->currentItem();
	if (item) {
		ui->tableEncounters->removeRow(item->row());
	}
}

void MapPropertiesDialog::on_pushSetPanorama_clicked() {
	auto* widget = new PickerPanoramaWidget(this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		new_panorama = ToDBString(baseName);
	});
	dialog.setDirectoryAndFile(PANORAMA, ToQString(new_panorama));
	dialog.exec();

	if (!new_panorama.empty()) {
		QPixmap pix = QPixmap(m_project.project().findFile(PANORAMA, ToQString(new_panorama), FileFinder::FileType::Image));
		if (!pix) {
			pix = QPixmap(core().rtpPath(PANORAMA, ToQString(new_panorama)));
		}
		m_panoramaItem->setPixmap(pix);
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

void MapPropertiesDialog::on_toolSetBackdrop_clicked() {
	auto* widget = new PickerBackdropWidget(this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		ui->lineBackdropName->setText(baseName);
	});
	dialog.setDirectoryAndFile(BACKDROP, ui->lineBackdropName->text());
	dialog.exec();
}
