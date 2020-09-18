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
	void ImportProject(const QDir& src_dir, QDir& target_dir, bool convert_xyz);

	MapScene *currentScene();
	void openScene(int mapID);
	void selectTile(int x, int y);

private slots:
	void update_actions();

	void on_actionQuit_triggered();

	void on_actionPaletteToggle_triggered(bool checked);

	void on_actionMapTreeToggle_triggered(bool checked);

	void on_actionResourceManager_triggered();

	void on_actionDatabase_triggered();

	void on_actionProjectNew_triggered();

	void on_actionProjectClose_triggered();

	void on_actionProjectOpen_triggered();

	void on_actionJukebox_triggered(bool disconnect = false);

	void on_actionLayerLower_triggered();

	void on_actionLayerUpper_triggered();

	void on_actionLayerEvents_triggered();

	void on_actionZoomIn_triggered();

	void on_actionZoomOut_triggered();

	void on_actionZoom100_triggered();

	void on_treeMap_itemDoubleClicked(QTreeWidgetItem *item, int column);

	void on_tabMap_tabCloseRequested(int index);

	void on_tabMap_currentChanged(int index);

	void on_actionProjectImport_triggered();

	void on_actionDebugRtpPath_triggered();

	void on_actionZoom_triggered();

	void on_actionDrawPen_triggered();

	void on_actionDrawRectangle_triggered();

	void on_actionDrawCircle_triggered();

	void on_actionDrawFill_triggered();

	void updateLayerActions();

	void updateToolActions();

	void updateSearchUI();

	void on_actionPlayTest_triggered();

	void on_mapChanged();

	void on_mapUnchanged();

	void on_actionUndo_triggered();

	void on_actionMapSave_triggered();

	void on_actionMapRevert_triggered();

	void on_treeMap_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);

	void on_actionMapNew_triggered();

	void on_actionMapCopy_triggered();

	void on_actionMapPaste_triggered();

	void on_actionMapDelete_triggered();

	void on_actionMapProperties_triggered();

	void on_actionSearch_triggered();

	void on_actionDebugEnableCaching_toggled(bool checked);

private:
	void refreshIcons();
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


