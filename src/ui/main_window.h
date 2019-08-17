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

#include <QFile>
#include <QMainWindow>
#include <QSettings>
#include <QTreeWidgetItem>
#include "ui/other/resource_manager_dialog.h"
#include "ui/database/database_dialog.h"
#include "ui/other/search_dialog.h"
#include "ui/map/map_scene.h"
#include "ui/common/palette_scene.h"
#include "ui/other/musicplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void LoadLastProject();
	void LoadProject(QString foldername);
	void ImportProject(QString p_path, QString d_folder, bool convert_xyz);

	MapScene *currentScene();
	void openScene(int mapID);
	void selectTile(int x, int y);

private slots:
	void on_action_Quit_triggered();

	void on_actionPalette_triggered(bool checked);

	void on_actionMap_Tree_triggered(bool checked);

	void on_actionResource_Manager_triggered();

	void on_actionData_Base_triggered();

	void update_actions();

	void on_action_New_Project_triggered();

	void on_action_Close_Project_triggered();

	void on_action_Open_Project_triggered();

	void on_actionJukebox_triggered(bool disconnect = false);

	void on_action_Lower_Layer_triggered();

	void on_action_Upper_Layer_triggered();

	void on_action_Events_triggered();

	void on_actionZoomIn_triggered();

	void on_actionZoomOut_triggered();

	void on_actionScale_1_1_triggered();

	void on_treeMap_itemDoubleClicked(QTreeWidgetItem *item, int column);

	void on_tabMap_tabCloseRequested(int index);

	void on_tabMap_currentChanged(int index);

	void on_actionImport_Project_triggered();

	void on_actionRtp_Path_triggered();

	void on_actionZoom_triggered();

	void on_actionDraw_triggered();

	void on_actionRectangle_triggered();

	void on_actionCircle_triggered();

	void on_actionFill_triggered();

	void updateLayerActions();

	void updateToolActions();

	void updateSearchUI();

	void on_action_Play_Test_triggered();

	void on_mapChanged();

	void on_mapUnchanged();

	void on_actionUndo_triggered();

	void on_action_Save_Map_triggered();

	void on_actionRevert_Map_triggered();

	void on_treeMap_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);

	void on_actionNew_Map_triggered();

	void on_actionCopy_Map_triggered();

	void on_actionPaste_Map_triggered();

	void on_actionDelete_Map_triggered();

	void on_actionMap_Properties_triggered();

	void on_actionSearch_triggered();

	void on_actionEnable_Caching_toggled(bool checked);

private:
	void closeEvent(QCloseEvent *event);
	bool saveAll();
	bool removeDir(const QString & dirName, const QString &root);
	QGraphicsView *getView(int id);
	MapScene *getScene(int id);
	QGraphicsView *getTabView(int index);
	MapScene *getTabScene(int index);
	void removeView(int id);
	void removeMap(const int id);
	bool convertXYZtoPNG(QFile &xyz_file, QString out_path);

	Ui::MainWindow *ui;
	ResourceManagerDialog *dlg_resource;
	DatabaseDialog *dlg_db;
	QSettings m_settings;
	PaletteScene *m_paletteScene;
	QMap<int,QGraphicsView*> m_views;
	QMap<int,QTreeWidgetItem*> m_treeItems;
	QString m_copiedMap;
	SearchDialog *searchdialog;
};


