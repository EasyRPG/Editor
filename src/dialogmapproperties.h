#ifndef DIALOGMAPPROPERTIES_H
#define DIALOGMAPPROPERTIES_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QTableWidgetItem>
#include <rpg_mapinfo.h>
#include <rpg_map.h>
#include "tools/qencounterdelegate.h"

namespace Ui {
class DialogMapProperties;
}

class DialogMapProperties : public QDialog
{
	Q_OBJECT

public:
	explicit DialogMapProperties(RPG::MapInfo &info, RPG::Map &map, QWidget *parent = nullptr);
	~DialogMapProperties();

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
	Ui::DialogMapProperties *ui;

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
