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

#include "ui/other/new_project_dialog.h"
#include "ui/other/open_project_dialog.h"
#include "ui/other/import_project_dialog.h"
#include "ui/other/rtp_path_dialog.h"
#include "ui/event/event_dialog.h"
#include "ui/maptree/map_properties_dialog.h"
#include "main_window.h"
#include "ui_main_window.h"
#include "common/dbstring.h"
#include <QImage>
#include <QToolBar>
#include <QCloseEvent>
#include <QApplication>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QScrollBar>
#include <QStringList>
#include <QDir>
#include <cassert>
#include <sstream>
#include <iomanip>
#include "core.h"
#include <lcf/lmu/reader.h>
#include <lcf/lmt/reader.h>
#include <lcf/ldb/reader.h>
#include <lcf/inireader.h>
#include <lcf/rpg/map.h>
#include <lcf/rpg/mapinfo.h>
#include "model/project.h"

Q_DECLARE_METATYPE(QList<int>)
Q_DECLARE_METATYPE(QList<float>)

const std::vector<QString> resource_dirs =
	{BACKDROP, BATTLE, BATTLE2, BATTLECHARSET, BATTLEWEAPON, CHARSET, CHIPSET, FACESET,
	GAMEOVER, MONSTER, MOVIE, MUSIC, PANORAMA, PICTURE, SOUND, SYSTEM, SYSTEM2, TITLE};

static void recurseAddDir(QDir d, QStringList & list) {

	QStringList qsl = d.entryList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

	foreach (QString file, qsl) {

		QFileInfo finfo(QString("%1/%2").arg(d.path()).arg(file));

		if (finfo.isSymLink())
			return;

		if (finfo.isDir()) {

			QString dirname = finfo.fileName();
			QDir sd(finfo.filePath());

			recurseAddDir(sd, list);

		} else
			list << QDir::toNativeSeparators(finfo.filePath());
	}
}

#ifdef Q_OS_WIN
static void associateFileTypes(const QStringList &fileTypes)
{
	QString displayName = QGuiApplication::applicationDisplayName();
	QString filePath = QCoreApplication::applicationFilePath();
	QString fileName = QFileInfo(filePath).fileName();

	QSettings settings("HKEY_CURRENT_USER\\Software\\Classes\\Applications\\" + fileName, QSettings::NativeFormat);
	settings.setValue("FriendlyAppName", displayName);

	settings.beginGroup("SupportedTypes");
	foreach (const QString& fileType, fileTypes)
		settings.setValue(fileType, QString());
	settings.endGroup();

	settings.beginGroup("shell");
	settings.beginGroup("open");
	settings.setValue("FriendlyAppName", displayName);
	settings.beginGroup("Command");
	settings.setValue(".", QChar('"') + QDir::toNativeSeparators(filePath) + QString("\" \"%1\""));
}
//! [0]
#endif




MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	refreshIcons();

	// Hide map ids
	ui->treeMap->hideColumn(1);
	// Created hardcoded toolbar for palette window.
	ui->widgetBar->layout()->addWidget(ui->toolBar);
	ui->widgetBar2->layout()->addWidget(ui->toolBar2);
	//Create dialogs
	dlg_resource = new ResourceManagerDialog(this);
	dlg_resource->setModal(true);
	dlg_db = nullptr;
	m_paletteScene = new PaletteScene(ui->graphicsPalette);
	ui->graphicsPalette->setScene(m_paletteScene);
	connect(&core(),
			SIGNAL(toolChanged()),
			this,
			SLOT(updateToolActions()));
	connect(&core(),
			SIGNAL(layerChanged()),
			this,
			SLOT(updateLayerActions()));
	connect(&core(),
			SIGNAL(layerChanged()),
			m_paletteScene,
			SLOT(onLayerChange()));
	connect(&core(),
			SIGNAL(chipsetChanged()),
			m_paletteScene,
			SLOT(onChipsetChange()));
	update_actions();
	core().setRtpDir(m_settings.value(RTP_KEY, QString()).toString());
	if (core().rtpPath("").isEmpty())
		on_actionDebugRtpPath_triggered();
	core().setDefDir(m_settings.value(DEFAULT_DIR_KEY,
										qApp->applicationDirPath()).toString());
	updateLayerActions();
	updateToolActions();
}

MainWindow::~MainWindow()
{
	delete ui;
	if (core().project())
		delete searchdialog;
	delete dlg_resource;
	delete dlg_db;
}

void MainWindow::LoadLastProject()
{
	QString l_project = m_settings.value(CURRENT_PROJECT_KEY, QString()).toString();
	if (!l_project.isEmpty())
		LoadProject(l_project);
}

void MainWindow::LoadProject(QString foldername)
{
	auto prj = Project::load(foldername);

	if (!prj) {
		QMessageBox::critical(this,
							  "Error loading project",
							  QString("Failed to load project %1").arg(foldername));
		return;
	}

	if (!prj->loadDatabaseAndMapTree()) {
		QMessageBox::critical(this,
							  "Error loading project",
							  QString("Failed to load database or maptree of %1").arg(foldername));
		return;
	}

	core().project() = prj;

	searchdialog = new SearchDialog(core().project()->projectData(), this);

	//m_projSett = new QSettings(core().project()->findFile(ROOT, EASY_CFG), QSettings::IniFormat, this);
	//QString title = m_projSett->value(GAMETITLE, "Untitled").toString();
	setWindowTitle("EasyRPG Editor - " +  core().project()->gameTitle());
	//core().setLayer(static_cast<Core::Layer>(m_projSett->value(LAYER, Core::LOWER).toInt()));
	//core().setTileSize(m_projSett->value(TILESIZE, 16).toInt());
	//QList<QVariant> m_mapList = m_projSett->value(MAPS, QList<QVariant>()).toList();
	//QList<QVariant> m_scaleList = m_projSett->value(SCALES, QList<QVariant>()).toList();
	m_settings.setValue(CURRENT_PROJECT_KEY, core().project()->projectDir().absolutePath());
	ui->treeMap->clear();
	QTreeWidgetItem *root = new QTreeWidgetItem();
	root->setData(1, Qt::DisplayRole, 0);
	root->setData(0,Qt::DisplayRole,  core().project()->gameTitle());
	root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
	lcf::rpg::TreeMap maps = core().project()->treeMap();
	ui->treeMap->addTopLevelItem(root);
	m_treeItems.clear();
	m_treeItems[0] = root;
	//Add Items
	for (unsigned int i = 1; i < maps.maps.size(); i++)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem();
		item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
		item->setData(0,Qt::DisplayRole,ToQString(maps.maps[i].name));
		item->setIcon(0, QIcon(":/icons/share/old_map.png"));
		m_treeItems[maps.maps[i].ID] = item;
	}
	//Parent Items
	for (unsigned int i = 1; i < (maps.tree_order.size()); i++)
	{
		int id = maps.tree_order[i];
		lcf::rpg::MapInfo info;
		for (unsigned int j = 0; j < maps.maps.size(); j++)
			if (id == maps.maps[j].ID)
			{
				info = maps.maps[j];
				break;
			}
		m_treeItems[info.parent_map]->addChild(m_treeItems[info.ID]);
		if (info.ID == maps.active_node)
		{
			ui->treeMap->setCurrentItem(m_treeItems[info.ID]);
			this->on_treeMap_itemDoubleClicked(m_treeItems[info.ID], 0);
		}
	}
	//Expand Items
	for (unsigned int i = 0; i < maps.maps.size(); i++)
	{
		m_treeItems[maps.maps[i].ID]->setExpanded(maps.maps[i].expanded_node);
	}

	/*for(int i = 0; i < m_mapList.count(); i++)
	{
		int mapId = m_mapList[i].toInt();
		if (mapId == 0)
			continue;

		QGraphicsView *view = getView(mapId);
		MapScene *scene = getScene(mapId);
		scene->setScale(i < m_scaleList.size() ? m_scaleList[i].toFloat() : 1.0);
		ui->tabMap->setCurrentWidget(view);
	}*/
	update_actions();
}

void MainWindow::ImportProject(const QDir& src_dir, QDir& target_dir, bool convert_xyz)
{
	if (!FileFinder::IsRPG2kProject(src_dir)) {
		QMessageBox::critical(this,
			"Error loading project",
			QString("The selected project %1 is not a legacy RPG Maker project").arg(src_dir.dirName()));
		return;
	}

	auto prj = Project::load(src_dir);

	if (!prj) {
		QMessageBox::critical(this,
							  "Error loading project",
							  QString("Failed to load project %1").arg(src_dir.dirName()));
		return;
	}

	if (!prj->loadDatabaseAndMapTree()) {
		QMessageBox::critical(this,
							  "Error loading project",
							  QString("Failed to load database or maptree of %1").arg(src_dir.dirName()));
		return;
	}

	// Load all maps
	lcf::rpg::TreeMap& maps = prj->treeMap();
	QProgressDialog progress("Processing Maps...", "", 0, 0, this);
	progress.setMaximum(static_cast<int>(maps.maps.size()));
	progress.setWindowModality(Qt::WindowModal);

	std::vector<std::tuple<int, std::unique_ptr<lcf::rpg::Map>>> loaded_maps;

	for (size_t i = 1; i < maps.maps.size(); i++) {
		progress.setValue(static_cast<int>(i));
		if (maps.maps[i].type == lcf::rpg::TreeMap::MapType_area)
			continue;
		loaded_maps.push_back(std::make_tuple(maps.maps[i].ID, prj->loadMap(maps.maps[i].ID)));
	}

	// Save new database and treemap
	prj->relocate(target_dir, FileFinder::ProjectType::EasyRpg);
	progress.setLabelText("Importing database and map tree...");
	progress.setValue(0);
	progress.setMaximum(0);
	prj->saveDatabase(false);
	prj->saveTreeMap();

	progress.setLabelText("Importing maps...");
	progress.setMaximum(static_cast<int>(loaded_maps.size()));
	int i = 1;
	for (auto& [id, map] : loaded_maps) {
		prj->saveMap(*map, id, false);
		progress.setValue(i++);
	}
	loaded_maps.clear();

	progress.setLabelText("Importing resources...");

	// Create all asset directories
	for (const QString& dir : resource_dirs)
		target_dir.mkpath(dir);

	QStringList entries;
	for (const QString& dir : resource_dirs) {
		// Enumerate source files
		QDir subdir = src_dir;
		if (subdir.cd(dir)) {
			recurseAddDir(subdir, entries);
		}
	}

	progress.setMaximum(entries.count());

	// Copy all assets from the asset subdirectories
	for (int i = 0; i < entries.count(); i++) {
		progress.setValue(i);
		QFileInfo info(entries[i]);
		QString dest_file = target_dir.path() + "/" + info.dir().dirName() + "/" + info.fileName();
		if (!QFile::copy(entries[i], dest_file))
		{
			QMessageBox box(this);
			QString name = tr("Error");
			QString text = tr("Could not copy file %1 to \n"
							  "%2").arg(entries[i]).arg(dest_file);

			box.setModal(true);
			box.setWindowTitle(name);
			box.setText(QString::fromLatin1("%1").arg(text));
			box.setIcon(QMessageBox::Critical);
			box.setStandardButtons(QMessageBox::Ok);

			box.exec();

			on_actionProjectClose_triggered();
			return;
		}
		if (convert_xyz && info.dir().dirName() != MUSIC && info.dir().dirName() != SOUND)
		{
			QFile file(dest_file);
			file.open(QIODevice::ReadOnly);
			if (file.read(4) == "XYZ1")
			{
				QString conv_path = target_dir.path() + "/" + info.dir().dirName() + "/" + info.completeBaseName() + ".png";
				if (convertXYZtoPNG(file, conv_path))
					file.remove();
				else
					qWarning() << QString("Failed to convert %1 to PNG").arg(dest_file);
			}
		}

	}
	progress.setValue(entries.count());

	QList<QVariant> m_mapList;
	QList<QVariant> m_scaleList;
	ui->treeMap->clear();
	QTreeWidgetItem *root = new QTreeWidgetItem();
	root->setData(1, Qt::DisplayRole, 0);
	root->setData(0,Qt::DisplayRole,  prj->gameTitle());
	root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
	ui->treeMap->addTopLevelItem(root);
	m_treeItems.clear();
	m_treeItems[0] = root;
	core().project() = prj;

	//Add Items
	for (unsigned int i = 1; i < maps.maps.size(); i++)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem();
		item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
		item->setData(0,Qt::DisplayRole,ToQString(maps.maps[i].name));
		item->setIcon(0, QIcon(":/icons/share/old_map.png"));
		m_treeItems[maps.maps[i].ID] = item;
	}
	//Parent Items
	for (unsigned int i = 0; i < maps.maps.size(); i++)
	{
		int id = maps.tree_order[i];
		lcf::rpg::MapInfo info;
		for (unsigned int j = 0; j < maps.maps.size(); j++)
			if (id == maps.maps[j].ID)
			{
				info = maps.maps[j];
				break;
			}
		m_treeItems[info.parent_map]->addChild(m_treeItems[info.ID]);
		if (info.ID == maps.active_node)
		{
			ui->treeMap->setCurrentItem(m_treeItems[info.ID]);
			m_mapList.push_back(info.ID);
			m_scaleList.push_back(1.0);
		}
	}
	//Expand Items
	for (unsigned int i = 0; i < maps.maps.size(); i++)
	{
		m_treeItems[maps.maps[i].ID]->setExpanded(maps.maps[i].expanded_node);
	}

	/*m_projSett = new QSettings(core().project()->findFile(ROOT, EASY_CFG),
							   QSettings::IniFormat,
							   this);
	m_projSett->setValue(GAMETITLE, title);
	m_projSett->setValue(LAYER, core().layer());
	m_projSett->setValue(MAPS, m_mapList);
	m_projSett->setValue(SCALES, m_scaleList);
	m_projSett->setValue(TILESIZE, 16);
	this->on_treeMap_itemDoubleClicked(m_treeItems[m_mapList[0].toInt()], 0);*/

	setWindowTitle("EasyRPG Editor - " +  core().project()->gameTitle());
	m_settings.setValue(CURRENT_PROJECT_KEY, core().project()->projectDir().absolutePath());
}

bool MainWindow::convertXYZtoPNG(QFile &xyz_file, QString out_path)
{
	QByteArray compressed_data(xyz_file.readAll());
	assert(!compressed_data.isEmpty());
	uint16_t width = static_cast<uint16_t>(static_cast<uint8_t>(compressed_data[0]) + (static_cast<uint8_t>(compressed_data[1]) << 8));
	uint16_t height = static_cast<uint16_t>(static_cast<uint8_t>(compressed_data[2]) + (static_cast<uint8_t>(compressed_data[3]) << 8));
	uint32_t size = width * height;
	// Put the total size in the first 4 bytes to make it valid for qUncompress
	for (int i = 0; i < 4; ++i)
		compressed_data[i] = static_cast<char>((reinterpret_cast<uint8_t*>(&size))[3-i]);

	QByteArray xyz_data(qUncompress(compressed_data));

	if (xyz_data.isEmpty())
		return false;

	QImage image(reinterpret_cast<uchar*>(xyz_data.data()) + 768, width, height, QImage::Format_Indexed8);
	// Add color table
	for (int i = 0; i < 256; ++i)
		image.setColor(i, qRgb(xyz_data[i * 3], xyz_data[i * 3 + 1], xyz_data[i * 3 + 2]));

	return image.save(out_path, "PNG");
}

void MainWindow::on_actionQuit_triggered()
{
	saveAll();
//	  this->on_actionJukebox_triggered(true);
	qApp->quit();
}

void MainWindow::on_actionPaletteToggle_triggered(bool checked)
{
	if (checked)
		ui->dockPalette->show();
	else
		ui->dockPalette->hide();
}

void MainWindow::on_actionMapTreeToggle_triggered(bool checked)
{
	if (checked)
		ui->dockMapTree->show();
	else
		ui->dockMapTree->hide();
}

void MainWindow::on_actionResourceManager_triggered()
{
	dlg_resource->show();
}

void MainWindow::on_actionDatabase_triggered()
{
	if (dlg_db)
		delete dlg_db;
	dlg_db = new DatabaseDialog(core().project()->projectData(), this);
	dlg_db->setModal(true);
	dlg_db->exec();
}

void MainWindow::update_actions()
{
	bool has_project = core().project() != nullptr;

	ui->actionDrawCircle->setEnabled(has_project);
	ui->actionGameDiskCreate->setEnabled(has_project);
	ui->actionDatabase->setEnabled(has_project);
	ui->actionDrawPen->setEnabled(has_project);
	ui->actionDrawFill->setEnabled(has_project);
	ui->actionProjectImport->setEnabled(!has_project);
	ui->actionDrawRectangle->setEnabled(has_project);
	ui->actionResourceManager->setEnabled(has_project);
	ui->actionZoom100->setEnabled(has_project);
	ui->actionMapRevert->setEnabled(has_project);
	ui->actionZoomIn->setEnabled(has_project);
	ui->actionZoomOut->setEnabled(has_project);
	ui->actionSearch->setEnabled(has_project);
	ui->actionUndo->setEnabled(has_project);
	ui->actionZoom->setEnabled(has_project);
	ui->actionProjectClose->setEnabled(has_project);
	ui->actionLayerEvents->setEnabled(has_project);
	ui->actionFullScreenToggle->setEnabled(has_project);
	ui->actionLayerLower->setEnabled(has_project);
	ui->actionLayerUpper->setEnabled(has_project);
	ui->actionProjectNew->setEnabled(!has_project);
	ui->actionProjectOpen->setEnabled(!has_project);
	ui->actionPlayTest->setEnabled(has_project);
	ui->actionMapSave->setEnabled(has_project);
	ui->actionScriptEditor->setEnabled(has_project);
	ui->actionTitleBackgroundToggle->setEnabled(has_project);
	ui->actionMapNew->setEnabled(has_project);
	ui->actionMapProperties->setEnabled(has_project);
	ui->actionMapCopy->setEnabled(has_project);
	ui->actionMapPaste->setEnabled(has_project);
	ui->actionMapDelete->setEnabled(has_project);

	ui->actionMapProperties->setEnabled(ui->tabMap->count());
	ui->actionMapCopy->setEnabled(ui->treeMap->currentItem() && ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
	ui->actionMapPaste->setEnabled(!m_copiedMap.isEmpty());
	ui->actionMapDelete->setEnabled(ui->treeMap->currentItem() && ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
}

void MainWindow::on_actionProjectNew_triggered() {
	NewProjectDialog dlg(this);
	dlg.setDefDir(core().defDir());
	dlg.exec();
	if (dlg.result() == QDialog::Accepted)
	{
		if (dlg.getProjectFolder() == QString())
			return;
		QDir d_gamepath(core().defDir()+dlg.getProjectFolder());
		if (d_gamepath.exists())
		{
			int response = QMessageBox::warning(this,
							"Game folder exist",
							QString("The folder %1 where you want to place your new game already exist.\n"
									"Do you want to delete this folder and all it's content?"
									).arg(core().defDir()+dlg.getProjectFolder()),
							QMessageBox::Ok,
							QMessageBox::Cancel);
			if (response == QMessageBox::Cancel)
				return;
			removeDir(core().defDir()+dlg.getProjectFolder(),
					  core().defDir()+dlg.getProjectFolder());
		}
		else
			d_gamepath.mkpath(".");
		core().setTileSize(dlg.getTileSize());
		core().setDefDir(dlg.getDefDir());
		for (const QString& dir : resource_dirs)
			d_gamepath.mkpath(dir);
		m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());

		QString t_folder = qApp->applicationDirPath()+"/templates/";

		if (!(QFile::copy(t_folder+EASY_DB, d_gamepath.absolutePath() + "/" + EASY_DB) &&
			QFile::copy(t_folder+EASY_MT, d_gamepath.absolutePath() + "/" + EASY_MT) &&
			QFile::copy(t_folder+"Map0001.emu", d_gamepath.absolutePath() + "/Map0001.emu"))) {
			QMessageBox::critical(this,
				"Creating new project failed",
				"Copying of template failed");
			return;
		}

		// Player not error checked because is not bundled
		QFile::copy(t_folder+PLAYER, d_gamepath.absolutePath() + "/" + PLAYER);

		auto prj = Project::load(d_gamepath);
		prj->loadDatabaseAndMapTree();
		core().project() = prj;

		core().project()->setGameTitle(dlg.getGameTitle());
		setWindowTitle("EasyRPG Editor - " +  core().project()->gameTitle());
		m_settings.setValue(CURRENT_PROJECT_KEY, core().project()->gameTitle());
		m_settings.setValue(CURRENT_PROJECT_KEY, core().project()->projectDir().absolutePath());

		/* Map tree */
		core().project()->treeMap().maps[0].name = ToDBString(core().project()->gameTitle());
		core().project()->saveTreeMap();

		/*m_projSett = new QSettings(core().project()->findFile(ROOT, EASY_CFG),
								   QSettings::IniFormat,
								   this);*/
		QList<QVariant> mapList;
		mapList.append(1);
		QList<QVariant> scaleList;
		scaleList.append(1.0);
		/*m_projSett->setValue(GAMETITLE, core().project()->gameTitle());
		m_projSett->setValue(LAYER, core().layer());
		m_projSett->setValue(MAPS, mapList);
		m_projSett->setValue(SCALES, scaleList);
		m_projSett->setValue(TILESIZE, 16);*/
		QTreeWidgetItem *root = new QTreeWidgetItem();
		root->setData(1, Qt::DisplayRole, 0);
		root->setData(0,Qt::DisplayRole,  core().project()->gameTitle());
		root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
		lcf::rpg::TreeMap maps = core().project()->treeMap();
		ui->treeMap->addTopLevelItem(root);
		m_treeItems.clear();
		m_treeItems[0] = root;
		//Add Items
		for (unsigned int i = 1; i < maps.maps.size(); i++)
		{
			QTreeWidgetItem *item = new QTreeWidgetItem();
			item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
			item->setData(0,Qt::DisplayRole,ToQString(maps.maps[i].name));
			item->setIcon(0, QIcon(":/icons/share/old_map.png"));
			m_treeItems[maps.maps[i].ID] = item;
		}
		//Parent Items
		for (unsigned int i = 0; i < maps.maps.size(); i++)
		{
			int id = maps.tree_order[i];
			lcf::rpg::MapInfo info;
			for (unsigned int j = 1; j < maps.maps.size(); j++)
				if (id == maps.maps[j].ID)
				{
					info = maps.maps[j];
					break;
				}
			m_treeItems[info.parent_map]->addChild(m_treeItems[info.ID]);
			if (info.ID == maps.active_node)
			{
				ui->treeMap->setCurrentItem(m_treeItems[info.ID]);
			}
		}
		//Expand Items
		for (unsigned int i = 0; i < maps.maps.size(); i++)
		{
			m_treeItems[maps.maps[i].ID]->setExpanded(maps.maps[i].expanded_node);
		}
		QGraphicsView *view = getView(1);
		MapScene *scene = getScene(1);
		scene->setScale(0 < scaleList.size() ? scaleList[0].toFloat() : 1.0);
		ui->tabMap->setCurrentWidget(view);
		update_actions();

	}
}

bool MainWindow::removeDir(const QString & dirName, const QString &root)
{
	bool result = true;
	QDir dir(dirName);

	if (dir.exists(dirName)) {
		Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden	| QDir::AllDirs | QDir::Files, QDir::DirsFirst))
		{
			if (info.isDir())
				result = removeDir(info.absoluteFilePath(),root);
			else
				result = QFile::remove(info.absoluteFilePath());

			if (!result)
			{
				QMessageBox::warning(this,
									 "An error ocurred",
									 QString("Could't delete %1").arg(info.absoluteFilePath()),
									 QMessageBox::Ok, 0);
				return false;
			}
		}
		if (root != dirName)
			result = dir.rmdir(dirName);
	}
	return result;
}

QGraphicsView *MainWindow::getView(int id)
{
	QGraphicsView* view = m_views[id];
	if (!view)
	{
		view = new QGraphicsView(this);
		m_views[id] = view;
		view->setTransformationAnchor(QGraphicsView::NoAnchor);
		QString mapName;
		for (auto & map : core().project()->treeMap().maps) {
			if (map.ID == id) {
				mapName = ToQString(map.name);
				break;
			}
		}
		ui->tabMap->addTab(view, QIcon(":/icons/share/old_map.png"), mapName);
		view->setScene(new MapScene(core().project()->projectData(), id, view, this));
		connect(getScene(id),
				SIGNAL(mapChanged()),
				this,
				SLOT(on_mapChanged()));
		connect(getScene(id),
				SIGNAL(mapReverted()),
				this,
				SLOT(on_mapUnchanged()));
		connect(getScene(id),
				SIGNAL(mapSaved()),
				this,
				SLOT(on_mapUnchanged()));
		core().setCurrentMapEvents(getScene(id)->mapEvents());
		getScene(id)->setScale(2.0);
		getScene(id)->Init();
	}
	return view;
}

MapScene *MainWindow::getScene(int id)
{
	QGraphicsView* view = m_views[id];
	if (!view)
		return nullptr;
	return (static_cast<MapScene*>(view->scene()));
}

QGraphicsView *MainWindow::getTabView(int index)
{
	if (index == -1)
		return nullptr;
	return (static_cast<QGraphicsView*>(ui->tabMap->widget(index)));
}

MapScene *MainWindow::getTabScene(int index)
{
	if (!getTabView(index))
		return nullptr;
	QGraphicsView* view = getTabView(index);
	return (static_cast<MapScene*>(view->scene()));
}

MapScene *MainWindow::currentScene()
{
	QGraphicsView* view = static_cast<QGraphicsView*>(ui->tabMap->currentWidget());
	if (!view)
		return nullptr;
	return (static_cast<MapScene*>(view->scene()));
}

void MainWindow::removeView(int id)
{
	QGraphicsView* view = m_views[id];
	MapScene* scene = static_cast<MapScene*>(view->scene());
	m_views.remove(id);
	delete scene;
	delete view;
}

void MainWindow::updateLayerActions()
{
	ui->actionLayerLower->setChecked(core().layer() == Core::LOWER);
	ui->actionLayerUpper->setChecked(core().layer() == Core::UPPER);
	ui->actionLayerEvents->setChecked(core().layer() == Core::EVENT);
}

void MainWindow::updateToolActions()
{
	ui->actionZoom->setChecked(core().tool() == Core::ZOOM);
	ui->actionDrawPen->setChecked(core().tool() == Core::PENCIL);
	ui->actionDrawRectangle->setChecked(core().tool() == Core::RECTANGLE);
	ui->actionDrawCircle->setChecked(core().tool() == Core::CIRCLE);
	ui->actionDrawFill->setChecked(core().tool() == Core::FILL);
}

void MainWindow::on_actionProjectClose_triggered()
{
	m_settings.setValue(CURRENT_PROJECT_KEY, QString());
	ui->treeMap->clear();
	saveAll();
	core().project().reset();

	while (ui->tabMap->currentIndex() != -1)
		removeView(currentScene()->id());
	update_actions();
	setWindowTitle("EasyRPG Editor");
}

void MainWindow::on_actionProjectOpen_triggered()
{
	OpenProjectDialog dlg(this);
	dlg.setDefaultDir(core().defDir());
	if (dlg.exec() == QDialog::Accepted)
		LoadProject(dlg.getProject()->projectDir().absolutePath());
	core().setDefDir(dlg.getDefaultDir());
	m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefaultDir());
}

void MainWindow::on_actionJukebox_triggered(bool disconnect)
{
	  static MusicPlayer player;
	if (disconnect)
	{
		player.disconnect();
	   player.deleteLater();
	   player.close();
	}
	else
	{
		player.resize(300, 60);
		player.show();
	}
}

void MainWindow::on_actionLayerLower_triggered()
{
	core().setLayer(Core::LOWER);
	updateLayerActions();
}

void MainWindow::on_actionLayerUpper_triggered()
{
	core().setLayer(Core::UPPER);
	updateLayerActions();
}

void MainWindow::on_actionLayerEvents_triggered()
{
	core().setLayer(Core::EVENT);
	updateLayerActions();
}

void MainWindow::on_actionZoomIn_triggered()
{
	if (static_cast<double>(currentScene()->scale()) < 8.0)
		currentScene()->setScale(currentScene()->scale()*2);
}

void MainWindow::on_actionZoomOut_triggered()
{
	if (static_cast<double>(currentScene()->scale()) > 0.125)
		currentScene()->setScale(currentScene()->scale()/2);
}

void MainWindow::on_actionZoom100_triggered()
{
	currentScene()->setScale(1.0);
}

void MainWindow::on_treeMap_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	Q_UNUSED(column)
	if (item->data(1,Qt::DisplayRole).toInt() == 0)
		return;
	QGraphicsView *view = getView(item->data(1,Qt::DisplayRole).toInt());
	ui->tabMap->setCurrentWidget(view);
	if (ui->tabMap->count() == 1)
		m_paletteScene->onChipsetChange();
}

void MainWindow::on_tabMap_tabCloseRequested(int index)
{
	if (!getTabScene(index))
		return;
	if (getTabScene(index)->isModified())
	{
		int result = QMessageBox::question(this,
										   "Save map changes",
										   QString("%1 has unsaved changes.\n"
										   "Do you want to save them before clossing"
										   " it?").arg(getTabScene(index)->mapName()),
										   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		switch (result)
		{
		case (QMessageBox::Yes):
			getTabScene(index)->Save();
			break;
		case (QMessageBox::No):
			removeView(getTabScene(index)->id());
			break;
		case (QMessageBox::Cancel):
			return;
		}
	}
	removeView(getTabScene(index)->id());
}

void MainWindow::on_tabMap_currentChanged(int index)
{
	if (index == -1)
	{
		for (int i = 0; i < m_paletteScene->items().size(); i++)
			m_paletteScene->items()[i]->setVisible(false);
		return;
	}
	if (currentScene())
	{
		core().LoadChipset(currentScene()->chipsetId());
		core().setCurrentMapEvents(currentScene()->mapEvents());
		ui->actionUndo->setEnabled(currentScene()->isModified());
		ui->actionMapSave->setEnabled(currentScene()->isModified());
		ui->actionMapRevert->setEnabled(currentScene()->isModified());
	}
}

void MainWindow::on_actionProjectImport_triggered()
{
	ImportProjectDialog dlg(this);
	dlg.setDefDir(core().defDir());
	dlg.exec();
	if (dlg.result() == QDialog::Accepted) {
		core().setDefDir(dlg.getDefDir());
		if (dlg.getProjectFolder() == QString())
			return;
		QDir d_gamepath(dlg.getDefDir()+dlg.getProjectFolder());
			if (d_gamepath.exists())
			{
				int response = QMessageBox::warning(this,
								"Game folder exist",
								QString("The folder %1 where you want to place your new game already exist.\n"
										"Do you want to delete this folder and all it's content?"
										).arg(dlg.getDefDir()+dlg.getProjectFolder()),
								QMessageBox::Ok,
								QMessageBox::Cancel);
				if (response == QMessageBox::Cancel)
					return;
				removeDir(dlg.getDefDir()+dlg.getProjectFolder(),
						  dlg.getDefDir()+dlg.getProjectFolder());
			}
			else
				d_gamepath.mkpath(".");
		core().setTileSize(16);
		ImportProject(dlg.getSourceFolder(), d_gamepath, dlg.getConvertXYZ());
	}
	m_settings.setValue(DEFAULT_DIR_KEY, dlg.getDefDir());
	update_actions();
}

void MainWindow::on_actionDebugRtpPath_triggered()
{
	RtpPathDialog dlg(this);
}

void MainWindow::on_actionZoom_triggered()
{
	core().setTool(Core::ZOOM);
}

void MainWindow::on_actionDrawPen_triggered()
{
	core().setTool(Core::PENCIL);
}

void MainWindow::on_actionDrawRectangle_triggered()
{
	core().setTool(Core::RECTANGLE);
}

void MainWindow::on_actionDrawCircle_triggered()
{
	core().setTool(Core::CIRCLE);
}

void MainWindow::on_actionDrawFill_triggered()
{
	core().setTool(Core::FILL);
}

void MainWindow::on_actionPlayTest_triggered()
{
	core().runGame();
}

void MainWindow::on_mapChanged()
{
	ui->actionMapRevert->setEnabled(true);
	ui->actionMapSave->setEnabled(true);
	ui->actionUndo->setEnabled(true);
	ui->tabMap->setTabText(ui->tabMap->currentIndex(), currentScene()->mapName()+" *");
}

void MainWindow::on_mapUnchanged()
{
	ui->actionMapRevert->setEnabled(false);
	ui->actionMapSave->setEnabled(false);
	ui->actionUndo->setEnabled(false);
	ui->tabMap->setTabText(ui->tabMap->currentIndex(), currentScene()->mapName());
}

void MainWindow::on_actionUndo_triggered()
{
	currentScene()->undo();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (!saveAll())
		event->ignore();
	else
		QMainWindow::closeEvent(event);
}

bool MainWindow::saveAll()
{
	bool need_save = false;
	for (int i = 0; i < ui->tabMap->count(); i++)
		if (getTabScene(i)->isModified())
		{
			need_save = true;
			break;
		}
	if (need_save)
	{
		int result = QMessageBox::question(this,
										   "Save map changes",
										   "Some maps have unsaved changes.\n"
										   "Do you want to save them before clossing them?",
										   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		switch (result)
		{
		case (QMessageBox::Yes):
			for (int i = 0; i < ui->tabMap->count(); i++)
				getTabScene(i)->Save();
			break;
 //		case (No): do nothing;
		case (QMessageBox::Cancel):
			return false;
		}
	}

	if (core().project()) {
		core().project()->saveTreeMap();
	}

	return true;
}

void MainWindow::on_actionMapSave_triggered()
{
	if(currentScene())
		currentScene()->Save();
}

void MainWindow::on_actionMapRevert_triggered()
{
	if (currentScene())
		currentScene()->Load();
}


void MainWindow::on_treeMap_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous)
{
	Q_UNUSED(previous)

	if (!current)
	{
		ui->actionMapCopy->setEnabled(false);
		ui->actionMapDelete->setEnabled(false);
		return;
	}
	ui->actionMapCopy->setEnabled(current->data(1,Qt::DisplayRole).toInt() != 0);
	ui->actionMapDelete->setEnabled(current->data(1,Qt::DisplayRole).toInt() != 0);
	core().project()->treeMap().active_node = current->data(1,Qt::DisplayRole).toInt() != 0;
}

void MainWindow::on_actionMapCopy_triggered()
{
	m_copiedMap = core().project()->findFile("Map%1.emu");
	m_copiedMap = m_copiedMap.arg(QString::number(ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt()),
								  4, QLatin1Char('0'));
	ui->actionMapPaste->setEnabled(true);
}


void MainWindow::on_actionMapNew_triggered()
{
	QString template_file = qApp->applicationDirPath()+"/templates/Map0001.emu";
	QFileInfo f(template_file);

	if (!f.exists())
	{
		QMessageBox::critical(this,
							  "File not found",
							  "The file " + template_file + " can't be found.");
		return;
	}

	std::unique_ptr<lcf::rpg::Map> map = lcf::LMU_Reader::LoadXml(template_file.toStdString());
	lcf::rpg::MapInfo info;

	// Find first free map id
	for (int i = 1;;++i)
	{
		if (!m_treeItems.contains(i))
		{
			info.ID = i;
			info.name = ToDBString(tr("MAP%1").arg(QString::number(i),4, QLatin1Char('0')));
			break;
		}
	}

	info.parent_map = ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt();
	if (info.parent_map == 0)
	{
		info.music_type = lcf::rpg::MapInfo::MusicType_event;
		info.background_type = lcf::rpg::MapInfo::BGMType_terrain;
		info.teleport = lcf::rpg::MapInfo::TriState_allow;
		info.escape = lcf::rpg::MapInfo::TriState_allow;
		info.save = lcf::rpg::MapInfo::TriState_allow;
	}

	core().project()->treeMap().maps.push_back(info);
	QTreeWidgetItem *item = new QTreeWidgetItem();
	item->setData(1,Qt::DisplayRole,info.ID);
	item->setData(0,Qt::DisplayRole,ToQString(info.name));
	item->setIcon(0, QIcon(":/icons/share/old_map.png"));
	m_treeItems[info.ID] = item;
	m_treeItems[info.parent_map]->addChild(item);
	QTreeWidgetItem *root = m_treeItems[0];
	QTreeWidgetItemIterator it(root);
	std::vector<int> tree_order;
	while (*it)
	{
		tree_order.push_back((*it)->data(1, Qt::DisplayRole).toInt());
		it++;
	}
	core().project()->treeMap().tree_order = tree_order;
	ui->treeMap->currentItem()->setExpanded(true);
	ui->treeMap->currentItem()->setSelected(false);
	item->setSelected(true);
	core().project()->saveTreeMap();
	QString path = core().project()->findFile("Map%1.emu");
	path = path.arg(QString::number(info.ID), 4, QLatin1Char('0'));
	auto lcf_engine = lcf::GetEngineVersion(core().project()->database());
	lcf::LMU_Reader::SaveXml(path.toStdString(), *map, lcf_engine);
	on_treeMap_itemDoubleClicked(item, 0);
}

void MainWindow::on_actionMapPaste_triggered()
{
	QFileInfo f(m_copiedMap);

	if (!f.exists())
	{
		QMessageBox::critical(this,
							  "File not found",
							  "The file " + m_copiedMap + " can't be found.");
		return;
	}

	std::unique_ptr<lcf::rpg::Map> map = lcf::LMU_Reader::LoadXml(m_copiedMap.toStdString());
	lcf::rpg::MapInfo info;
	for (size_t i = 0; i < core().project()->treeMap().maps.size(); i++)
	{
		if (core().project()->treeMap().maps[i].ID == info.ID)
		{
			info = core().project()->treeMap().maps[i];
			break;
		}
	}

	// Find first free map id
	for (int i = 1;;++i)
	{
		if (!m_treeItems.contains(i))
		{
			info.ID = i;
			info.name = ToDBString(tr("MAP%1").arg(QString::number(i),4, QLatin1Char('0')));
			break;
		}
	}

	info.parent_map = ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt();
	if (info.parent_map == 0)
	{
		if (info.music_type == lcf::rpg::MapInfo::MusicType_parent)
			info.music_type = lcf::rpg::MapInfo::MusicType_event;
		if (info.background_type == lcf::rpg::MapInfo::BGMType_parent)
			info.background_type = lcf::rpg::MapInfo::BGMType_terrain;
		if (info.teleport == lcf::rpg::MapInfo::TriState_parent)
			info.teleport = lcf::rpg::MapInfo::TriState_allow;
		if (info.escape == lcf::rpg::MapInfo::TriState_parent)
			info.escape = lcf::rpg::MapInfo::TriState_allow;
		if (info.save == lcf::rpg::MapInfo::TriState_parent)
			info.save = lcf::rpg::MapInfo::TriState_allow;
	}

	core().project()->treeMap().maps.push_back(info);
	QTreeWidgetItem *item = new QTreeWidgetItem();
	item->setData(1,Qt::DisplayRole,info.ID);
	item->setData(0,Qt::DisplayRole,ToQString(info.name));
	item->setIcon(0, QIcon(":/icons/share/old_map.png"));
	m_treeItems[info.ID] = item;
	m_treeItems[info.parent_map]->addChild(item);
	QTreeWidgetItem *root = m_treeItems[0];
	QTreeWidgetItemIterator it(root);
	std::vector<int> tree_order;
	while (*it)
	{
		tree_order.push_back((*it)->data(1, Qt::DisplayRole).toInt());
		it++;
	}
	core().project()->treeMap().tree_order = tree_order;
	ui->treeMap->currentItem()->setExpanded(true);
	ui->treeMap->currentItem()->setSelected(false);
	item->setSelected(true);
	core().project()->saveTreeMap();
	QString path = core().project()->findFile("Map%1.emu");
	path = path.arg(QString::number(info.ID), 4, QLatin1Char('0'));
	auto lcf_engine = lcf::GetEngineVersion(core().project()->database());
	lcf::LMU_Reader::SaveXml(path.toStdString(), *map, lcf_engine);
	on_treeMap_itemDoubleClicked(item, 0);
}

void MainWindow::on_actionMapDelete_triggered()
{
	removeMap(ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt());

	core().project()->saveTreeMap();
}

void MainWindow::removeMap(const int id)
{
	// First remove children maps
	for (int i = 0; i < m_treeItems[id]->childCount(); i++)
		removeMap(m_treeItems[id]->child(i)->data(1, Qt::DisplayRole).toInt());

	QString mapPath = core().project()->findFile("Map%1.emu");
	mapPath = mapPath.arg(QString::number(id), 4, QLatin1Char('0'));

	if (QFileInfo(mapPath).exists())
		QFile::remove(mapPath);
	else
		qWarning() << QString("file not found: %1").arg(mapPath);

	for (unsigned int i = 0; i < core().project()->treeMap().maps.size(); i++)
	{
		if (core().project()->treeMap().maps[i].ID == id)
		{
			core().project()->treeMap().maps.erase(core().project()->treeMap().maps.begin()+i);
			break;
		}
	}

	for (unsigned int i = 0; i < core().project()->treeMap().tree_order.size(); i++)
	{
		if (core().project()->treeMap().tree_order[i] == id)
		{
			core().project()->treeMap().tree_order.erase(core().project()->treeMap().tree_order.begin()+i);
			break;
		}
	}

	QGraphicsView* view = m_views[id];
	if (view)
	{
		ui->tabMap->removeTab(ui->tabMap->indexOf(view));
		m_views.remove(id);
	}

	m_treeItems[id]->parent()->removeChild(m_treeItems[id]);
	m_treeItems.remove(id);
}

void MainWindow::on_actionMapProperties_triggered()
{
	if (!currentScene())
		return;

	currentScene()->editMapProperties();
}

void MainWindow::on_actionSearch_triggered()
{
	searchdialog->setVisible(true);
}

void MainWindow::updateSearchUI()
{
	searchdialog->updateUI();
}

void MainWindow::openScene(int mapID)
{
	this->on_treeMap_itemDoubleClicked(m_treeItems[mapID], 0);
}

void MainWindow::selectTile(int x, int y)
{
	if (currentScene())
	{
		core().setLayer(Core::EVENT);
		updateLayerActions();

		currentScene()->selectTile(x, y);
	}
}

void MainWindow::on_actionDebugEnableCaching_toggled(bool checked)
{
	searchdialog->enableCache(checked);
}

void MainWindow::refreshIcons() {
	auto set = [this](auto& action, const auto& icon) {
		QString theme = palette().color(QWidget::backgroundRole()).lightness() >= 128 ? ":/bright" : ":/dark";
		return action->setIcon(QIcon(theme + "/" + icon));
	};

	// File
	set(ui->actionProjectNew, "project-new");
	set(ui->actionProjectOpen, "project-open");
	set(ui->actionProjectClose, "project-close");
	set(ui->actionQuit, "exit");

	// Map
	set(ui->actionMapProperties, "properties");
	set(ui->actionMapSave, "save");
	set(ui->actionMapRevert, "revert");
	set(ui->actionLayerEvents, "layer-event");
	set(ui->actionLayerUpper, "layer-high");
	set(ui->actionLayerLower, "layer-low");
	set(ui->actionZoom100, "zoom-original");
	set(ui->actionZoomIn, "zoom-in");
	set(ui->actionZoomOut, "zoom-out");
	set(ui->actionPaletteToggle, "palette");
	set(ui->actionMapTreeToggle, "tree");

	// Tilemap
	set(ui->actionDrawPen, "draw-pen");
	set(ui->actionDrawCircle, "draw-circle");
	set(ui->actionDrawRectangle, "draw-rectangle");
	set(ui->actionDrawFill, "draw-fill");
	set(ui->actionUndo, "edit-undo");
	set(ui->actionZoom, "zoom");

	// Map Tree
	set(ui->actionMapNew, "new");
	set(ui->actionMapCopy, "edit-copy");
	set(ui->actionMapPaste, "edit-paste");
	set(ui->actionMapDelete, "edit-delete");

	// Tools
	set(ui->actionDatabase, "database");
	set(ui->actionJukebox, "audio");
	set(ui->actionResourceManager, "resources");
	set(ui->actionSearch, "edit-find");

	// Other
	set(ui->actionGameDiskCreate, "gamedisk-create");
	set(ui->actionScriptEditor, "code");

	// Game
	set(ui->actionPlayTest, "play");
	set(ui->actionFullScreenToggle, "fullscreen");
	set(ui->actionTitleBackgroundToggle, "show-title");

	// Help
	set(ui->actionContents, "help-about");
}
