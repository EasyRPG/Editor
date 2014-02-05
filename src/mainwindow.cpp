#include "dialognewproject.h"
#include "dialogopenproject.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QApplication>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include "core.h"
#include "lmu_reader.h"
#include "lmt_reader.h"
#include "ldb_reader.h"
#include "inireader.h"
#include "rpg_map.h"
#include "rpg_mapinfo.h"
#include "data.h"

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




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Core::Init();
    ui->setupUi(this);
    // Hide map ids
    ui->treeMap->hideColumn(1);
    // Created hardcoded toolbar for palette window.
    ui->toolBar->setParent(ui->dockWidgetContents);
    //Create dialogs
    dlg_resource = new DialogResourceManager(this);
    dlg_resource->setModal(true);
    dlg_db = new DialogDataBase(this);
    dlg_db->setModal(true);
    update_actions();
    m_defDir = m_settings.value(DEFAULT_DIR_KEY, qApp->applicationDirPath()).toString();
    QString l_project = m_settings.value(CURRENT_PROJECT_KEY, QString()).toString();
    QFileInfo info(m_defDir+l_project+"/rpg_rt.ldb");
    if (l_project != QString() && info.exists())
        LoadProject(m_defDir+l_project+"/");
    m_paleteScene = new QGraphicsPaleteScene(ui->graphicsPalete);
    ui->graphicsPalete->setScene(m_paleteScene);
    QGraphicsScene *m_mapScene = new QGraphicsScene();
    ui->graphicsView->setScene(m_mapScene);
    m_mapWidget = new QGraphicsMapWidget();
    m_mapScene->addItem(m_mapWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dlg_resource;
    delete dlg_db;
    delete m_paleteScene;
    delete m_mapWidget;
}

void MainWindow::LoadProject(QString p_path)
{
    Core::setprojectPath(p_path);
    Data::Clear();
    if (!LDB_Reader::Load(QString(p_path+"rpg_rt.ldb").toStdString()))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load database file: "+p_path+"RPG_RT.ldb");
        Core::setprojectPath("");
        return;
    }
    if (!LMT_Reader::Load(QString(p_path+"RPG_RT.lmt").toStdString()))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load map tree file: "+p_path+"RPG_RT.lmt");
        Core::setprojectPath("");
        return;
    }
    Core::LoadMaps();
    INIReader reader(p_path.toStdString()+"RPG_RT.ini");
    QString title (reader.Get("RPG_RT","GameTitle", "Untitled").c_str());
    Core::setGameTitle(title);
    switch (reader.GetInteger("RPG_RT","MapEditMode", 0))
    {
    case 1:
        Core::setLayer(Core::UPPER);
        break;
    case 2:
        Core::setLayer(Core::EVENT);
        break;
    default:
        Core::setLayer(Core::LOWER);
        break;
    }
    //TODO:: create a new variable on the ini for a suitable zoom mode
    float scale = (float)reader.GetInteger("RPG_RT","MapEditZoom", 0)*0.5+0.5;
    m_mapWidget->setScale(scale);
    setWindowTitle("EasyRPG Editor - " + Core::gameTitle());
    m_settings.setValue(CURRENT_PROJECT_KEY, Core::gameTitle());
    ui->treeMap->clear();
    QTreeWidgetItem *root = new QTreeWidgetItem();
    root->setData(1, Qt::DisplayRole, 0);
    root->setData(0,Qt::DisplayRole, Core::gameTitle());
    root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
    RPG::TreeMap maps = Data::treemap;
    ui->treeMap->addTopLevelItem(root);
    QMap<int,QTreeWidgetItem*> items;
    items[0] = root;
    //Add Items
    for (unsigned int i = 1; i < maps.maps.size(); i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
        item->setData(0,Qt::DisplayRole,QString::fromStdString(maps.maps[i].name));
        item->setIcon(0, QIcon(":/icons/share/old_map.png"));
        items[maps.maps[i].ID] = item;
    }
    //Parent Items
    for (unsigned int i = 0; i < maps.maps.size(); i++)
    {
        int id = maps.tree_order[i];
        RPG::MapInfo info;
        for (unsigned int j = 0; j < maps.maps.size(); j++)
            if (id == maps.maps[j].ID)
            {
                info = maps.maps[j];
                break;
            }
        items[info.parent_map]->addChild(items[info.ID]);
        if (info.ID == maps.active_node)
            ui->treeMap->setCurrentItem(items[info.ID]);
    }
    //Expand Items
    for (unsigned int i = 0; i < maps.maps.size(); i++)
    {
        items[maps.maps[i].ID]->setExpanded(maps.maps[i].expanded_node);
    }
}

void MainWindow::on_action_Quit_triggered()
{
    this->on_actionJukebox_triggered(true);
    Data::Clear();
    qApp->quit();
}

void MainWindow::on_actionPalete_triggered(bool checked)
{
    if (checked)
        ui->dockPalete->show();
    else
        ui->dockPalete->hide();
}

void MainWindow::on_actionMap_Tree_triggered(bool checked)
{
    if (checked)
        ui->dockMapTree->show();
    else
        ui->dockMapTree->hide();
}

void MainWindow::on_actionResource_Manager_triggered()
{
    dlg_resource->show();
}

void MainWindow::on_actionData_Base_triggered()
{
    dlg_db->show();
}

void MainWindow::update_actions()
{
    if (Core::projectPath().isEmpty()){
        ui->actionCircle->setEnabled(false);
        ui->actionCreate_Game_Disk->setEnabled(false);
        ui->actionData_Base->setEnabled(false);
        ui->actionDraw->setEnabled(false);
        ui->actionFill->setEnabled(false);
        ui->actionRectangle->setEnabled(false);
        ui->actionResource_Manager->setEnabled(false);
        ui->actionRevert_all_Maps->setEnabled(false);
        ui->actionScale_1_1->setEnabled(false);
        ui->actionZoomIn->setEnabled(false);
        ui->actionZoomOut->setEnabled(false);
        ui->actionSearch->setEnabled(false);
        ui->actionSelect->setEnabled(false);
        ui->actionUndo->setEnabled(false);
        ui->actionZoom->setEnabled(false);
        ui->action_Close_Project->setEnabled(false);
        ui->action_Events->setEnabled(false);
        ui->action_Full_Screen->setEnabled(false);
        ui->action_Lower_Layer->setEnabled(false);
        ui->action_New_Project->setEnabled(true);
        ui->action_Open_Project->setEnabled(true);
        ui->action_Play_Test->setEnabled(false);
        ui->action_Save_all_Maps->setEnabled(false);
        ui->action_Script_Editor->setEnabled(false);
        ui->action_Title_Background->setEnabled(false);
        ui->action_Upper_Layer->setEnabled(false);
    } else {
        ui->actionCircle->setEnabled(true);
        ui->actionCreate_Game_Disk->setEnabled(true);
        ui->actionData_Base->setEnabled(true);
        ui->actionDraw->setEnabled(true);
        ui->actionFill->setEnabled(true);
        ui->actionRectangle->setEnabled(true);
        ui->actionResource_Manager->setEnabled(true);
        ui->actionRevert_all_Maps->setEnabled(true);
        ui->actionScale_1_1->setEnabled(true);
        ui->actionZoomIn->setEnabled(true);
        ui->actionZoomOut->setEnabled(true);
        ui->actionSearch->setEnabled(true);
        ui->actionSelect->setEnabled(true);
        ui->actionUndo->setEnabled(true);
        ui->actionZoom->setEnabled(true);
        ui->action_Close_Project->setEnabled(true);
        ui->action_Events->setEnabled(true);
        ui->action_Full_Screen->setEnabled(true);
        ui->action_Lower_Layer->setEnabled(true);
        ui->action_New_Project->setEnabled(false);
        ui->action_Open_Project->setEnabled(false);
        ui->action_Play_Test->setEnabled(true);
        ui->action_Save_all_Maps->setEnabled(true);
        ui->action_Script_Editor->setEnabled(true);
        ui->action_Title_Background->setEnabled(true);
        ui->action_Upper_Layer->setEnabled(true);
    }
}

void MainWindow::on_action_New_Project_triggered()
{
    DialogNewProject dlg(this);
    dlg.setDefDir(m_defDir);
    dlg.exec();
    if (dlg.result() == QDialog::Accepted){
        if (dlg.getProjectPath() == QString())
            return;
        QDir d_gamepath(dlg.getProjectPath());
            if (d_gamepath.exists())
            {
                int response = QMessageBox::warning(this,
                                "Game folder exist",
                                QString("The folder %1 where you want to place your new game already exist. Do you want to delete this folder and all it's content?").arg(dlg.getProjectPath()),
                                QMessageBox::Ok,
                                QMessageBox::Cancel);
                if (response == QMessageBox::Cancel)
                    return;
                removeDir(dlg.getProjectPath(),dlg.getProjectPath());
            }
            else
                d_gamepath.mkdir(".");
        Core::setprojectPath(dlg.getProjectPath());
        Core::setGameTitle(dlg.getGameTitle());
        Core::setTileSize(dlg.getTileSize());
        m_defDir = dlg.getDefDir();
        Data::Clear();
        d_gamepath.mkdir(dlg.getProjectPath()+"Backdrop");
        d_gamepath.mkdir(dlg.getProjectPath()+"Panorama");
        d_gamepath.mkdir(dlg.getProjectPath()+"Battle");
        d_gamepath.mkdir(dlg.getProjectPath()+"Battle2");
        d_gamepath.mkdir(dlg.getProjectPath()+"BattleCharSet");
        d_gamepath.mkdir(dlg.getProjectPath()+"BattleWeapon");
        d_gamepath.mkdir(dlg.getProjectPath()+"CharSet");
        d_gamepath.mkdir(dlg.getProjectPath()+"ChipSet");
        d_gamepath.mkdir(dlg.getProjectPath()+"FaceSet");
        d_gamepath.mkdir(dlg.getProjectPath()+"Frame");
        d_gamepath.mkdir(dlg.getProjectPath()+"GameOver");
        d_gamepath.mkdir(dlg.getProjectPath()+"Monster");
        d_gamepath.mkdir(dlg.getProjectPath()+"Movie");
        d_gamepath.mkdir(dlg.getProjectPath()+"Music");
        d_gamepath.mkdir(dlg.getProjectPath()+"Picture");
        d_gamepath.mkdir(dlg.getProjectPath()+"Sound");
        d_gamepath.mkdir(dlg.getProjectPath()+"System");
        d_gamepath.mkdir(dlg.getProjectPath()+"System2");
        d_gamepath.mkdir(dlg.getProjectPath()+"Title");
        m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
        setWindowTitle("EasyRPG Editor - " + Core::gameTitle());
        m_settings.setValue(CURRENT_PROJECT_KEY, Core::gameTitle());
        //TODO:: add a map;
        LDB_Reader::Save(Core::projectPath().toStdString()+"RPG_RT.ldb");
        LMT_Reader::Save(Core::projectPath().toStdString()+"RPG_RT.lmt");
        //TODO:: create ini;
        update_actions();
    }
}

bool MainWindow::removeDir(const QString & dirName, const QString &root)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
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

void MainWindow::on_action_Close_Project_triggered()
{
    m_settings.setValue(CURRENT_PROJECT_KEY, QString());
    Data::Clear();
    Core::setGameTitle("");
    Core::setprojectPath("");
    ui->treeMap->clear();
    update_actions();
    setWindowTitle("EasyRPG Editor");
}

void MainWindow::on_action_Open_Project_triggered()
{
    DialogOpenProject dlg(this);
    dlg.setDefDir(m_defDir);
    if (dlg.exec() == QDialog::Accepted)
        LoadProject(dlg.getProjectPath());
    m_defDir = dlg.getDefDir();
    m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
    update_actions();
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
        associateFileTypes(QStringList(".wav,.mp3,.midi"));
        if(!player.isHidden())
        {
            player.playFile("C:\\Users\\Public\\Music\\Sample Music\\Kalimba.mp3");
        }
        player.resize(300, 60);
        player.show();
    }
}

void MainWindow::on_actionChipset_triggered()
{
    if (!Core::debugChipset())
        return;
    Core::debugChipset()->show();
}

void MainWindow::on_action_Lower_Layer_triggered()
{
    ui->action_Lower_Layer->setChecked(true);
    ui->action_Upper_Layer->setChecked(false);
    ui->action_Events->setChecked(false);
    Core::setLayer(Core::LOWER);
    m_paleteScene->onLayerChange();
}

void MainWindow::on_action_Upper_Layer_triggered()
{
    ui->action_Lower_Layer->setChecked(false);
    ui->action_Upper_Layer->setChecked(true);
    ui->action_Events->setChecked(false);
    Core::setLayer(Core::UPPER);
    m_paleteScene->onLayerChange();
}

void MainWindow::on_action_Events_triggered()
{
    ui->action_Lower_Layer->setChecked(false);
    ui->action_Upper_Layer->setChecked(false);
    ui->action_Events->setChecked(true);
    Core::setLayer(Core::EVENT);
    m_paleteScene->onLayerChange();
}

void MainWindow::on_actionZoomIn_triggered()
{
    if (m_mapWidget->scale() != 2.0)
        m_mapWidget->setScale(m_mapWidget->scale()+0.5);
}

void MainWindow::on_actionZoomOut_triggered()
{
    if (m_mapWidget->scale() != 0.5)
        m_mapWidget->setScale(m_mapWidget->scale()-0.5);
}

void MainWindow::on_actionScale_1_1_triggered()
{
    m_mapWidget->setScale(1.0);
}

void MainWindow::on_treeMap_itemSelectionChanged()
{
    Core::setMap(ui->treeMap->selectedItems()[0]->data(1,Qt::DisplayRole).toInt());
    m_mapWidget->onMapChange();
    m_paleteScene->onChipsetChange();
    m_paleteScene->onLayerChange();
}
