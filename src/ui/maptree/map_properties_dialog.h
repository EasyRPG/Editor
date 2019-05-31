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

#ifndef DIALOGMAPPROPERTIES_H
#define DIALOGMAPPROPERTIES_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QTableWidgetItem>
#include <rpg_mapinfo.h>
#include <rpg_map.h>
#include "ui/common/encounter_delegate.h"

namespace Ui {
class MapPropertiesDialog;
}

class MapPropertiesDialog : public QDialog
{
	Q_OBJECT

public:
	explicit MapPropertiesDialog(RPG::MapInfo &info, RPG::Map &map, QWidget *parent = nullptr);
	~MapPropertiesDialog();

private slots:
	void on_groupPanorama_toggled(bool arg1);

	void on_groupUseGenerator_toggled(bool arg1);

	void on_groupUpperWall_toggled(bool arg1);

	void on_groupFloorB_toggled(bool arg1);

	void on_groupFloorC_toggled(bool arg1);

	void on_groupObstacleB_toggled(bool arg1);

	void on_groupObstacleC_toggled(bool arg1);

	void on_tableEncounters_itemChanged(QTableWidgetItem *item);

private:
	Ui::MapPropertiesDialog *ui;

	QGraphicsPixmapItem *m_panoramaItem;
	QGraphicsPixmapItem *m_ceilingItem;
	QGraphicsPixmapItem *m_lowerWallItem;
	QGraphicsPixmapItem *m_upperWallItem;
	QGraphicsPixmapItem *m_floorAItem;
	QGraphicsPixmapItem *m_floorBItem;
	QGraphicsPixmapItem *m_floorCItem;
	QGraphicsPixmapItem *m_ObstacleAItem;
	QGraphicsPixmapItem *m_ObstacleBItem;
	QGraphicsPixmapItem *m_ObstacleCItem;

	QEncounterDelegate *m_encounterDelegate;

	RPG::MapInfo &m_info;
	RPG::Map &m_map;

	std::vector<short> m_generatorLowerLayer;
	std::vector<short> m_generatorUpperLayer;
};

#endif // DIALOGMAPPROPERTIES_H
