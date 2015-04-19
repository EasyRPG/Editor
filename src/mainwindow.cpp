#include "dialognewproject.h"
#include "dialogopenproject.h"
#include "dialogimportproject.h"
#include "dialogrtppath.h"
#include "dialogEvent.h"
#include "dialogmapproperties.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QCloseEvent>
#include <QApplication>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QStringList>
#include <QDir>
#include <sstream>
#include <iomanip>
#include "core.h"
#include "lmu_reader.h"
#include "lmt_reader.h"
#include "ldb_reader.h"
#include "inireader.h"
#include "rpg_map.h"
#include "rpg_mapinfo.h"
#include "data.h"

Q_DECLARE_METATYPE(QList<int>)
Q_DECLARE_METATYPE(QList<float>)

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
    // Hide map ids
    ui->treeMap->hideColumn(1);
    // Created hardcoded toolbar for palette window.
    ui->widgetBar->layout()->addWidget(ui->toolBar);
    ui->widgetBar2->layout()->addWidget(ui->toolBar2);
    //Create dialogs
    dlg_resource = new DialogResourceManager(this);
    dlg_resource->setModal(true);
    dlg_db = 0;
    m_paleteScene = new QGraphicsPaleteScene(ui->graphicsPalete);
    ui->graphicsPalete->setScene(m_paleteScene);
    connect(mCore,
            SIGNAL(toolChanged()),
            this,
            SLOT(updateToolActions()));
    connect(mCore,
            SIGNAL(layerChanged()),
            this,
            SLOT(updateLayerActions()));
    connect(mCore,
            SIGNAL(layerChanged()),
            m_paleteScene,
            SLOT(onLayerChange()));
    connect(mCore,
            SIGNAL(chipsetChanged()),
            m_paleteScene,
            SLOT(onChipsetChange()));
    update_actions();
    mCore->setRtpDir(m_settings.value(RTP_KEY, QString()).toString());
    if (mCore->rtpPath(ROOT).isEmpty())
        on_actionRtp_Path_triggered();
    mCore->setDefDir(m_settings.value(DEFAULT_DIR_KEY,
                                        qApp->applicationDirPath()).toString());
    updateLayerActions();
    updateToolActions();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dlg_resource;
    delete dlg_db;
}

void MainWindow::LoadLastProject()
{
    QString l_project = m_settings.value(CURRENT_PROJECT_KEY, QString()).toString();
    mCore->setProjectFolder(l_project);
    QFileInfo info(mCore->filePath(ROOT, EASY_DB));
    if (info.exists())
        LoadProject(l_project);
    else
        mCore->setProjectFolder(QString());
    updateLayerActions();
    updateToolActions();
}

void MainWindow::LoadProject(QString foldername)
{
    Data::Clear();
    mCore->setProjectFolder(foldername);
    if (!LDB_Reader::LoadXml(mCore->filePath(ROOT, EASY_DB).toStdString()))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load database file: "+
                              mCore->filePath(ROOT, EASY_DB));
        mCore->setProjectFolder("");
        Data::Clear();
        return;
    }
    if (!LMT_Reader::LoadXml(mCore->filePath(ROOT, EASY_MT).toStdString()))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load map tree file: "+
                              mCore->filePath(ROOT, EASY_MT));
        mCore->setProjectFolder("");
        Data::Clear();
        return;
    }
    m_projSett = new QSettings(mCore->filePath(ROOT, EASY_CFG), QSettings::IniFormat, this);
    QString title = m_projSett->value(GAMETITLE, "Untitled").toString();
    mCore->setGameTitle(title);
    setWindowTitle("EasyRPG Editor - " +  mCore->gameTitle());
    mCore->setLayer(static_cast<Core::Layer>(m_projSett->value(LAYER, Core::LOWER).toInt()));
    mCore->setTileSize(m_projSett->value(TILESIZE, 16).toInt());
    QList<QVariant> m_mapList = m_projSett->value(MAPS, QList<QVariant>()).toList();
    QList<QVariant> m_scaleList = m_projSett->value(SCALES, QList<QVariant>()).toList();
    m_settings.setValue(CURRENT_PROJECT_KEY,  mCore->projectFolder());
    ui->treeMap->clear();
    QTreeWidgetItem *root = new QTreeWidgetItem();
    root->setData(1, Qt::DisplayRole, 0);
    root->setData(0,Qt::DisplayRole,  mCore->gameTitle());
    root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
    RPG::TreeMap maps = Data::treemap;
    ui->treeMap->addTopLevelItem(root);
    m_treeItems.clear();
    m_treeItems[0] = root;
    //Add Items
    for (unsigned int i = 1; i < maps.maps.size(); i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
        item->setData(0,Qt::DisplayRole,QString::fromStdString(maps.maps[i].name));
        item->setIcon(0, QIcon(":/icons/share/old_map.png"));
        m_treeItems[maps.maps[i].ID] = item;
    }
    //Parent Items
    for (unsigned int i = 1; i < (maps.tree_order.size()); i++)
    {
        int id = maps.tree_order[i];
        RPG::MapInfo info;
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

    for(int i = 0; i < m_mapList.count(); i++)
    {
        int mapId = m_mapList[i].toInt();
        if (mapId == 0)
            continue;

        QGraphicsView *view = getView(mapId);
        QGraphicsMapScene *scene = getScene(mapId);
        scene->setScale(i < m_scaleList.size() ? m_scaleList[i].toFloat() : 1.0);
        ui->tabMap->setCurrentWidget(view);
    }
    update_actions();
}

void MainWindow::ImportProject(QString p_path, QString d_folder)
{
    Data::Clear();
    mCore->setProjectFolder(d_folder);
    std::string encoding = ReaderUtil::GetEncoding(QString(p_path+RM_INI).toStdString());
    if (encoding.empty()) {
        encoding = ReaderUtil::DetectEncoding(QString(p_path+RM_DB).toStdString());
    }
    if (!LDB_Reader::Load((p_path+RM_DB).toStdString(), encoding))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load database file: "+p_path+RM_DB);
        mCore->setProjectFolder("");
        Data::Clear();
        return;
    }
    if (!LMT_Reader::Load((p_path+RM_MT).toStdString(), encoding))
    {
        QMessageBox::critical(this,
                              "Error loading project",
                              "Could not load map tree file: "+p_path+RM_MT);
        mCore->setProjectFolder("");
        Data::Clear();
        return;
    }
    INIReader reader((p_path+RM_INI).toStdString());
    QString title (ReaderUtil::Recode(reader.Get("RPG_RT","GameTitle", "Untitled"), encoding).c_str());
    Data::treemap.maps[0].name = title.toStdString();
    mCore->setGameTitle(title);
    switch (reader.GetInteger("RPG_RT","MapEditMode", 0))
    {
    case 1:
         mCore->setLayer(Core::UPPER);
        break;
    case 2:
         mCore->setLayer(Core::EVENT);
        break;
    default:
         mCore->setLayer(Core::LOWER);
        break;
    }
    setWindowTitle("EasyRPG Editor - " +  mCore->gameTitle());
    m_settings.setValue(CURRENT_PROJECT_KEY,  mCore->projectFolder());
    LDB_Reader::SaveXml(mCore->filePath(ROOT, EASY_DB).toStdString());
    LMT_Reader::SaveXml(mCore->filePath(ROOT, EASY_MT).toStdString());
    QDir srcDir(p_path+BACKDROP);
    QStringList entries;
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+PANORAMA);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+BATTLE);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+BATTLE2);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+BATTLECHARSET);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+BATTLEWEAPON);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+CHARSET);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+CHIPSET);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+FACESET);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+GAMEOVER);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+MONSTER);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+MOVIE);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+MUSIC);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+PICTURE);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+SOUND);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+SYSTEM);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+SYSTEM2);
    recurseAddDir(srcDir, entries);
    srcDir = QDir(p_path+TITLE);
    recurseAddDir(srcDir, entries);
    for (int i = 0; i < entries.count(); i++)
    {
        QFileInfo info(entries[i]);
        QString dest_file = mCore->filePath(info.dir().dirName()+"/",info.fileName());
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

            on_action_Close_Project_triggered();
            return;
        }
    }

    QList<QVariant> m_mapList;
    QList<QVariant> m_scaleList;
    ui->treeMap->clear();
    QTreeWidgetItem *root = new QTreeWidgetItem();
    root->setData(1, Qt::DisplayRole, 0);
    root->setData(0,Qt::DisplayRole,  mCore->gameTitle());
    root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
    RPG::TreeMap maps = Data::treemap;
    ui->treeMap->addTopLevelItem(root);
    m_treeItems.clear();
    m_treeItems[0] = root;
    //Add Items
    for (unsigned int i = 1; i < maps.maps.size(); i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
        item->setData(0,Qt::DisplayRole,QString::fromStdString(maps.maps[i].name));
        item->setIcon(0, QIcon(":/icons/share/old_map.png"));
        m_treeItems[maps.maps[i].ID] = item;
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
    //Import Maps
    std::stringstream ss;
    for (unsigned int i = 1; i < maps.maps.size(); i++)
    {
        if (maps.maps[i].type == 2)
            continue;
        ss.str("");
        ss << p_path.toStdString()
           << "Map"
           << std::setfill('0')
           << std::setw(4)
           << maps.maps[i].ID
           << ".lmu";
        RPG::Map map = *LMU_Reader::Load(ss.str(), encoding).get();
        ss.str("");
        ss << mCore->filePath(ROOT).toStdString()
           << "Map"
           << std::setfill('0')
           << std::setw(4)
           << maps.maps[i].ID
           << ".emu";
        LMU_Reader::SaveXml(ss.str(),map);
    }
    m_projSett = new QSettings(mCore->filePath(ROOT, EASY_CFG),
                               QSettings::IniFormat,
                               this);
    m_projSett->setValue(GAMETITLE, title);
    m_projSett->setValue(LAYER, mCore->layer());
    m_projSett->setValue(MAPS, m_mapList);
    m_projSett->setValue(SCALES, m_scaleList);
    m_projSett->setValue(TILESIZE, 16);
    this->on_treeMap_itemDoubleClicked(m_treeItems[m_mapList[0].toInt()], 0);
}

void MainWindow::on_action_Quit_triggered()
{
    saveAll();
//    this->on_actionJukebox_triggered(true);
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
    if (dlg_db)
        delete dlg_db;
    dlg_db = new DialogDataBase(this);
    dlg_db->setModal(true);
    dlg_db->exec();
}

void MainWindow::update_actions()
{
    if (mCore->projectFolder().isEmpty()){
        ui->actionCircle->setEnabled(false);
        ui->actionCreate_Game_Disk->setEnabled(false);
        ui->actionData_Base->setEnabled(false);
        ui->actionDraw->setEnabled(false);
        ui->actionFill->setEnabled(false);
        ui->actionImport_Project->setEnabled(true);
        ui->actionRectangle->setEnabled(false);
        ui->actionResource_Manager->setEnabled(false);
        ui->actionRevert_Map->setEnabled(false);
        ui->actionScale_1_1->setEnabled(false);
        ui->actionZoomIn->setEnabled(false);
        ui->actionZoomOut->setEnabled(false);
        ui->actionSearch->setEnabled(false);
        ui->actionUndo->setEnabled(false);
        ui->actionZoom->setEnabled(false);
        ui->action_Close_Project->setEnabled(false);
        ui->action_Events->setEnabled(false);
        ui->action_Full_Screen->setEnabled(false);
        ui->action_Lower_Layer->setEnabled(false);
        ui->action_New_Project->setEnabled(true);
        ui->action_Open_Project->setEnabled(true);
        ui->action_Play_Test->setEnabled(false);
        ui->action_Save_Map->setEnabled(false);
        ui->action_Script_Editor->setEnabled(false);
        ui->action_Title_Background->setEnabled(false);
        ui->action_Upper_Layer->setEnabled(false);
        ui->actionNew_Map->setEnabled(false);
        ui->actionMap_Properties->setEnabled(false);
        ui->actionCopy_Map->setEnabled(false);
        ui->actionPaste_Map->setEnabled(false);
        ui->actionDelete_Map->setEnabled(false);
    } else {
        ui->actionCircle->setEnabled(true);
        ui->actionCreate_Game_Disk->setEnabled(true);
        ui->actionData_Base->setEnabled(true);
        ui->actionDraw->setEnabled(true);
        ui->actionFill->setEnabled(true);
        ui->actionImport_Project->setEnabled(false);
        ui->actionRectangle->setEnabled(true);
        ui->actionResource_Manager->setEnabled(true);
        ui->actionScale_1_1->setEnabled(true);
        ui->actionZoomIn->setEnabled(true);
        ui->actionZoomOut->setEnabled(true);
        ui->actionSearch->setEnabled(true);
        ui->actionZoom->setEnabled(true);
        ui->action_Close_Project->setEnabled(true);
        ui->action_Events->setEnabled(true);
        ui->action_Full_Screen->setEnabled(true);
        ui->action_Lower_Layer->setEnabled(true);
        ui->action_New_Project->setEnabled(false);
        ui->action_Open_Project->setEnabled(false);
        ui->action_Play_Test->setEnabled(true);
        ui->action_Script_Editor->setEnabled(true);
        ui->action_Title_Background->setEnabled(true);
        ui->action_Upper_Layer->setEnabled(true);
        ui->actionNew_Map->setEnabled(true);
        ui->actionMap_Properties->setEnabled(ui->tabMap->count());
        ui->actionCopy_Map->setEnabled(ui->treeMap->currentItem() && ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
        ui->actionPaste_Map->setEnabled(!m_copiedMap.isEmpty());
        ui->actionDelete_Map->setEnabled(ui->treeMap->currentItem() && ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
    }
}

void MainWindow::on_action_New_Project_triggered()
{
    DialogNewProject dlg(this);
    dlg.setDefDir(mCore->defDir());
    dlg.exec();
    if (dlg.result() == QDialog::Accepted)
    {
        if (dlg.getProjectFolder() == QString())
        return;
        QDir d_gamepath(mCore->defDir()+dlg.getProjectFolder());
        if (d_gamepath.exists())
        {
            int response = QMessageBox::warning(this,
                            "Game folder exist",
                            QString("The folder %1 where you want to place your new game already exist.\n"
                                    "Do you want to delete this folder and all it's content?"
                                    ).arg(mCore->defDir()+dlg.getProjectFolder()),
                            QMessageBox::Ok,
                            QMessageBox::Cancel);
            if (response == QMessageBox::Cancel)
                return;
            removeDir(mCore->defDir()+dlg.getProjectFolder(),
                      mCore->defDir()+dlg.getProjectFolder());
        }
        else
            d_gamepath.mkpath(".");
        mCore->setProjectFolder(dlg.getProjectFolder());
        mCore->setGameTitle(dlg.getGameTitle());
        mCore->setTileSize(dlg.getTileSize());
        mCore->setDefDir(dlg.getDefDir());
        Data::Clear();
        d_gamepath.mkpath(mCore->filePath(BACKDROP));
        d_gamepath.mkpath(mCore->filePath(PANORAMA));
        d_gamepath.mkpath(mCore->filePath(BATTLE));
        d_gamepath.mkpath(mCore->filePath(BATTLE2));
        d_gamepath.mkpath(mCore->filePath(BATTLECHARSET));
        d_gamepath.mkpath(mCore->filePath(BATTLEWEAPON));
        d_gamepath.mkpath(mCore->filePath(CHARSET));
        d_gamepath.mkpath(mCore->filePath(CHIPSET));
        d_gamepath.mkpath(mCore->filePath(FACESET));
        d_gamepath.mkpath(mCore->filePath(FRAME));
        d_gamepath.mkpath(mCore->filePath(GAMEOVER));
        d_gamepath.mkpath(mCore->filePath(MONSTER));
        d_gamepath.mkpath(mCore->filePath(MOVIE));
        d_gamepath.mkpath(mCore->filePath(MUSIC));
        d_gamepath.mkpath(mCore->filePath(PICTURE));
        d_gamepath.mkpath(mCore->filePath(SOUND));
        d_gamepath.mkpath(mCore->filePath(SYSTEM));
        d_gamepath.mkpath(mCore->filePath(SYSTEM2));
        d_gamepath.mkpath(mCore->filePath(TITLE));
        m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
        setWindowTitle("EasyRPG Editor - " +  mCore->gameTitle());
        m_settings.setValue(CURRENT_PROJECT_KEY,  mCore->gameTitle());
        QString t_folder = qApp->applicationDirPath()+"/templates/";

        QFile::copy(t_folder+PLAYER, mCore->filePath(PLAYER));
        /* Map tree */
        LMT_Reader::LoadXml(t_folder.toStdString()+EASY_MT);
        Data::treemap.maps[0].name = mCore->gameTitle().toStdString();
        /* Map */
        RPG::Map map = *(LMU_Reader::LoadXml(t_folder.toStdString()+"Map0001.emu").get());
        /* DataBase */
        LDB_Reader::LoadXml(t_folder.toStdString()+EASY_DB);
        /* Save */
        LMU_Reader::SaveXml(mCore->filePath(ROOT,"Map0001.emu").toStdString(), map);
        LDB_Reader::SaveXml(mCore->filePath(ROOT,EASY_DB).toStdString());
        LMT_Reader::SaveXml(mCore->filePath(ROOT,EASY_MT).toStdString());
        m_projSett = new QSettings(mCore->filePath(ROOT, EASY_CFG),
                                   QSettings::IniFormat,
                                   this);
        QList<QVariant> mapList;
        mapList.append(1);
        QList<QVariant> scaleList;
        scaleList.append(1.0);
        m_projSett->setValue(GAMETITLE, mCore->gameTitle());
        m_projSett->setValue(LAYER, mCore->layer());
        m_projSett->setValue(MAPS, mapList);
        m_projSett->setValue(SCALES, scaleList);
        m_projSett->setValue(TILESIZE, 16);
        QTreeWidgetItem *root = new QTreeWidgetItem();
        root->setData(1, Qt::DisplayRole, 0);
        root->setData(0,Qt::DisplayRole,  mCore->gameTitle());
        root->setIcon(0,QIcon(":/icons/share/old_folder.png"));
        RPG::TreeMap maps = Data::treemap;
        ui->treeMap->addTopLevelItem(root);
        m_treeItems.clear();
        m_treeItems[0] = root;
        //Add Items
        for (unsigned int i = 1; i < maps.maps.size(); i++)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setData(1,Qt::DisplayRole,maps.maps[i].ID);
            item->setData(0,Qt::DisplayRole,QString::fromStdString(maps.maps[i].name));
            item->setIcon(0, QIcon(":/icons/share/old_map.png"));
            m_treeItems[maps.maps[i].ID] = item;
        }
        //Parent Items
        for (unsigned int i = 0; i < maps.maps.size(); i++)
        {
            int id = maps.tree_order[i];
            RPG::MapInfo info;
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
        QGraphicsMapScene *scene = getScene(1);
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

QGraphicsView *MainWindow::getView(int id)
{
    QGraphicsView* view = m_views[id];
    if (!view)
    {
        //create
        view = new QGraphicsView(this);
        m_views[id] = view;
        view->setTransformationAnchor(QGraphicsView::NoAnchor);
        std::string mapName;
        for (unsigned int i = 0; i < Data::treemap.maps.size();i++)
            if (Data::treemap.maps[i].ID == id)
            {
                mapName = Data::treemap.maps[i].name;
                break;
            }
        ui->tabMap->addTab(view,
                           QIcon(":/icons/share/old_map.png"),
                           QString::fromStdString(mapName));
        view->setScene(new QGraphicsMapScene(id, view, view));
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
        getScene(id)->setScale(2.0);
        getScene(id)->Init();
        mCore->setCurrentMapEvents(getScene(id)->mapEvents());
    }
    return view;
}

QGraphicsMapScene *MainWindow::getScene(int id)
{
    QGraphicsView* view = m_views[id];
    if (!view)
        return 0;
    return (static_cast<QGraphicsMapScene*>(view->scene()));
}

QGraphicsView *MainWindow::getTabView(int index)
{
    if (index == -1)
        return 0;
    return (static_cast<QGraphicsView*>(ui->tabMap->widget(index)));
}

QGraphicsMapScene *MainWindow::getTabScene(int index)
{
    if (!getTabView(index))
        return 0;
    QGraphicsView* view = getTabView(index);
    return (static_cast<QGraphicsMapScene*>(view->scene()));
}

QGraphicsMapScene *MainWindow::currentScene()
{
    QGraphicsView* view = static_cast<QGraphicsView*>(ui->tabMap->currentWidget());
    if (!view)
        return 0;
    return (static_cast<QGraphicsMapScene*>(view->scene()));
}

void MainWindow::removeView(int id)
{
    QGraphicsView* view = m_views[id];
    QGraphicsMapScene* scene = static_cast<QGraphicsMapScene*>(view->scene());
    m_views.remove(id);
    delete scene;
    delete view;
}

void MainWindow::updateLayerActions()
{
    ui->action_Lower_Layer->setChecked(mCore->layer() == Core::LOWER);
    ui->action_Upper_Layer->setChecked(mCore->layer() == Core::UPPER);
    ui->action_Events->setChecked(mCore->layer() == Core::EVENT);
}

void MainWindow::updateToolActions()
{
    ui->actionZoom->setChecked(mCore->tool() == Core::ZOOM);
    ui->actionDraw->setChecked(mCore->tool() == Core::PENCIL);
    ui->actionRectangle->setChecked(mCore->tool() == Core::RECTANGLE);
    ui->actionCircle->setChecked(mCore->tool() == Core::CIRCLE);
    ui->actionFill->setChecked(mCore->tool() == Core::FILL);
}

void MainWindow::on_action_Close_Project_triggered()
{
    m_settings.setValue(CURRENT_PROJECT_KEY, QString());
    Data::Clear();
    mCore->setGameTitle("");
    mCore->setProjectFolder("");
    ui->treeMap->clear();
    saveAll();
    while (ui->tabMap->currentIndex() != -1)
        removeView(currentScene()->id());
    update_actions();
    setWindowTitle("EasyRPG Editor");
}

void MainWindow::on_action_Open_Project_triggered()
{
    DialogOpenProject dlg(this);
    dlg.setDefDir(mCore->defDir());
    if (dlg.exec() == QDialog::Accepted)
        LoadProject(dlg.getProjectFolder());
    mCore->setDefDir(dlg.getDefDir());
    m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
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
#ifdef Q_OS_WIN
        associateFileTypes(QStringList(".wav,.mp3,.midi"));
        if(!player.isHidden())
        {
            player.playFile("C:\\Users\\Public\\Music\\Sample Music\\Kalimba.mp3");
        }
#endif
        player.resize(300, 60);
        player.show();
    }
}

void MainWindow::on_action_Lower_Layer_triggered()
{
    mCore->setLayer(Core::LOWER);
    updateLayerActions();
}

void MainWindow::on_action_Upper_Layer_triggered()
{
    mCore->setLayer(Core::UPPER);
    updateLayerActions();
}

void MainWindow::on_action_Events_triggered()
{
    mCore->setLayer(Core::EVENT);
    updateLayerActions();
}

void MainWindow::on_actionZoomIn_triggered()
{
    if (currentScene()->scale() != 2.0)
        currentScene()->setScale(currentScene()->scale()*2);
}

void MainWindow::on_actionZoomOut_triggered()
{
    if (currentScene()->scale() != 0.25)
        currentScene()->setScale(currentScene()->scale()/2);
}

void MainWindow::on_actionScale_1_1_triggered()
{
    currentScene()->setScale(1.0);
}

void MainWindow::on_treeMap_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    if (item->data(1,Qt::DisplayRole).toInt() == 0)
        return;
    QGraphicsView *view = getView(item->data(1,Qt::DisplayRole).toInt());
    ui->tabMap->setCurrentWidget(view);
    if (ui->tabMap->count() == 1)
        m_paleteScene->onChipsetChange();
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
        case (QMessageBox::No):
            removeView(getTabScene(index)->id());
        default:
            return;
        }
    }
    removeView(getTabScene(index)->id());
}

void MainWindow::on_tabMap_currentChanged(int index)
{
    if (index == -1)
    {
        for (int i = 0; i < m_paleteScene->items().size(); i++)
            m_paleteScene->items()[i]->setVisible(false);
        return;
    }
    if (currentScene())
    {
        mCore->LoadChipset(currentScene()->chipsetId());
        mCore->setCurrentMapEvents(currentScene()->mapEvents());
        ui->actionUndo->setEnabled(currentScene()->isModified());
        ui->action_Save_Map->setEnabled(currentScene()->isModified());
        ui->actionRevert_Map->setEnabled(currentScene()->isModified());
    }
}

void MainWindow::on_actionImport_Project_triggered()
{
    DialogImportProject dlg(this);
    dlg.setDefDir(mCore->defDir());
    dlg.exec();
    if (dlg.result() == QDialog::Accepted){
        mCore->setDefDir(dlg.getDefDir());
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
         mCore->setTileSize(16);
         mCore->setProjectFolder(dlg.getProjectFolder());
        d_gamepath.mkpath(mCore->filePath(BACKDROP));
        d_gamepath.mkpath(mCore->filePath(PANORAMA));
        d_gamepath.mkpath(mCore->filePath(BATTLE));
        d_gamepath.mkpath(mCore->filePath(BATTLE2));
        d_gamepath.mkpath(mCore->filePath(BATTLECHARSET));
        d_gamepath.mkpath(mCore->filePath(BATTLEWEAPON));
        d_gamepath.mkpath(mCore->filePath(CHARSET));
        d_gamepath.mkpath(mCore->filePath(CHIPSET));
        d_gamepath.mkpath(mCore->filePath(FACESET));
        d_gamepath.mkpath(mCore->filePath(FRAME));
        d_gamepath.mkpath(mCore->filePath(GAMEOVER));
        d_gamepath.mkpath(mCore->filePath(MONSTER));
        d_gamepath.mkpath(mCore->filePath(MOVIE));
        d_gamepath.mkpath(mCore->filePath(MUSIC));
        d_gamepath.mkpath(mCore->filePath(PICTURE));
        d_gamepath.mkpath(mCore->filePath(SOUND));
        d_gamepath.mkpath(mCore->filePath(SYSTEM));
        d_gamepath.mkpath(mCore->filePath(SYSTEM2));
        d_gamepath.mkpath(mCore->filePath(TITLE));
        m_settings.setValue(CURRENT_PROJECT_KEY, dlg.getProjectFolder());
        ImportProject(dlg.getSourceFolder(), dlg.getProjectFolder());
    }
    m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
    update_actions();
}

void MainWindow::on_actionRtp_Path_triggered()
{
    DialogRtpPath dlg(this);
}

void MainWindow::on_actionZoom_triggered()
{
    mCore->setTool(Core::ZOOM);
}

void MainWindow::on_actionDraw_triggered()
{
    mCore->setTool(Core::PENCIL);
}

void MainWindow::on_actionRectangle_triggered()
{
    mCore->setTool(Core::RECTANGLE);
}

void MainWindow::on_actionCircle_triggered()
{
    mCore->setTool(Core::CIRCLE);
}

void MainWindow::on_actionFill_triggered()
{
    mCore->setTool(Core::FILL);
}

void MainWindow::on_action_Play_Test_triggered()
{
    mCore->runGame();
}

void MainWindow::on_mapChanged()
{
    ui->actionRevert_Map->setEnabled(true);
    ui->action_Save_Map->setEnabled(true);
    ui->actionUndo->setEnabled(true);
    ui->tabMap->setTabText(ui->tabMap->currentIndex(), currentScene()->mapName()+" *");
}

void MainWindow::on_mapUnchanged()
{
    ui->actionRevert_Map->setEnabled(false);
    ui->action_Save_Map->setEnabled(false);
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
 //     case (No): do nothing;
        case (QMessageBox::Cancel):
            return false;
        }
    }
    return true;
}

void MainWindow::on_action_Save_Map_triggered()
{
    if(currentScene())
        currentScene()->Save();
}

void MainWindow::on_actionRevert_Map_triggered()
{
    if (currentScene())
        currentScene()->Load();
}


void MainWindow::on_treeMap_itemSelectionChanged()
{
    if (!ui->treeMap->currentItem())
    {
        ui->actionCopy_Map->setEnabled(false);
        ui->actionDelete_Map->setEnabled(false);
        return;
    }
    ui->actionCopy_Map->setEnabled(ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
    ui->actionDelete_Map->setEnabled(ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0);
    Data::treemap.active_node = ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt() != 0;
    LMT_Reader::SaveXml(mCore->filePath(ROOT, EASY_MT).toStdString());
}

void MainWindow::on_actionCopy_Map_triggered()
{
    m_copiedMap = mCore->filePath(ROOT)+"Map%1.emu";
    m_copiedMap = m_copiedMap.arg(QString::number(ui->treeMap->currentItem()->data(1,Qt::DisplayRole).toInt()),
                                  4, QLatin1Char('0'));
    ui->actionPaste_Map->setEnabled(true);
    return;
}


void MainWindow::on_actionNew_Map_triggered()
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

    std::unique_ptr<RPG::Map> map = LMU_Reader::LoadXml(template_file.toStdString());
    RPG::MapInfo info;

    // Find first free map id
    for (int i = 1;;++i)
    {
        if (!m_treeItems.contains(i))
        {
            map->ID = i;
            info.ID = i;
            info.name = tr("MAP%1").arg(QString::number(i),4, QLatin1Char('0')).toStdString();
            break;
        }
    }

    info.parent_map = ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt();
    if (info.parent_map == 0)
    {
        info.music_type = RPG::MapInfo::MusicType_event;
        info.background_type = RPG::MapInfo::BGMType_terrain;
        info.teleport = RPG::MapInfo::TriState_allow;
        info.escape = RPG::MapInfo::TriState_allow;
        info.save = RPG::MapInfo::TriState_allow;
    }

    Data::treemap.maps.push_back(info);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setData(1,Qt::DisplayRole,map->ID);
    item->setData(0,Qt::DisplayRole,QString::fromStdString(info.name));
    item->setIcon(0, QIcon(":/icons/share/old_map.png"));
    m_treeItems[map->ID] = item;
    m_treeItems[info.parent_map]->addChild(item);
    QTreeWidgetItem *root = m_treeItems[0];
    QTreeWidgetItemIterator it(root);
    std::vector<int> tree_order;
    while (*it)
    {
        tree_order.push_back((*it)->data(1, Qt::DisplayRole).toInt());
        it++;
    }
    Data::treemap.tree_order = tree_order;
    ui->treeMap->currentItem()->setExpanded(true);
    ui->treeMap->currentItem()->setSelected(false);
    item->setSelected(true);
    LMT_Reader::SaveXml(mCore->filePath(ROOT, EASY_MT).toStdString());
    QString path = mCore->filePath(ROOT, "Map%1.emu");
    path = path.arg(QString::number(map->ID), 4, QLatin1Char('0'));
    LMU_Reader::SaveXml(path.toStdString(), *map);
    on_treeMap_itemDoubleClicked(item, 0);
}


void MainWindow::on_actionPaste_Map_triggered()
{
    QFileInfo f(m_copiedMap);

    if (!f.exists())
    {
        QMessageBox::critical(this,
                              "File not found",
                              "The file " + m_copiedMap + " can't be found.");
        return;
    }

    std::unique_ptr<RPG::Map> map = LMU_Reader::LoadXml(m_copiedMap.toStdString());
    RPG::MapInfo info;
    for (int i = 0; i < (int) Data::treemap.maps.size(); i++)
    {
        if (Data::treemap.maps[i].ID == map->ID)
        {
            info = Data::treemap.maps[i];
            break;
        }
    }

    // Find first free map id
    for (int i = 1;;++i)
    {
        if (!m_treeItems.contains(i))
        {
            map->ID = i;
            info.ID = i;
            info.name = tr("MAP%1").arg(QString::number(i),4, QLatin1Char('0')).toStdString();
            break;
        }
    }

    info.parent_map = ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt();
    if (info.parent_map == 0)
    {
        if (info.music_type == RPG::MapInfo::MusicType_parent)
            info.music_type = RPG::MapInfo::MusicType_event;
        if (info.background_type == RPG::MapInfo::BGMType_parent)
            info.background_type = RPG::MapInfo::BGMType_terrain;
        if (info.teleport == RPG::MapInfo::TriState_parent)
            info.teleport = RPG::MapInfo::TriState_allow;
        if (info.escape == RPG::MapInfo::TriState_parent)
            info.escape = RPG::MapInfo::TriState_allow;
        if (info.save == RPG::MapInfo::TriState_parent)
            info.save = RPG::MapInfo::TriState_allow;
    }

    Data::treemap.maps.push_back(info);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setData(1,Qt::DisplayRole,map->ID);
    item->setData(0,Qt::DisplayRole,QString::fromStdString(info.name));
    item->setIcon(0, QIcon(":/icons/share/old_map.png"));
    m_treeItems[map->ID] = item;
    m_treeItems[info.parent_map]->addChild(item);
    QTreeWidgetItem *root = m_treeItems[0];
    QTreeWidgetItemIterator it(root);
    std::vector<int> tree_order;
    while (*it)
    {
        tree_order.push_back((*it)->data(1, Qt::DisplayRole).toInt());
        it++;
    }
    Data::treemap.tree_order = tree_order;
    ui->treeMap->currentItem()->setExpanded(true);
    ui->treeMap->currentItem()->setSelected(false);
    item->setSelected(true);
    LMT_Reader::SaveXml(mCore->filePath(ROOT, EASY_MT).toStdString());
    QString path = mCore->filePath(ROOT, "Map%1.emu");
    path = path.arg(QString::number(map->ID), 4, QLatin1Char('0'));
    LMU_Reader::SaveXml(path.toStdString(), *map);
    on_treeMap_itemDoubleClicked(item, 0);
}

void MainWindow::on_actionDelete_Map_triggered()
{
    removeMap(ui->treeMap->currentItem()->data(1, Qt::DisplayRole).toInt());

    LMT_Reader::SaveXml(mCore->filePath(ROOT, EASY_MT).toStdString());
}

void MainWindow::removeMap(const int id)
{
    // First remove children maps
    for (int i = 0; i < m_treeItems[id]->childCount(); i++)
        removeMap(m_treeItems[id]->child(i)->data(1, Qt::DisplayRole).toInt());

    QString mapPath = mCore->filePath(ROOT, "Map%1.emu");
    mapPath = mapPath.arg(QString::number(id), 4, QLatin1Char('0'));

    if (QFileInfo(mapPath).exists())
        QFile::remove(mapPath);
    else
        qWarning() << QString("file not found: %1").arg(mapPath);

    for (unsigned int i = 0; i < Data::treemap.maps.size(); i++)
    {
        if (Data::treemap.maps[i].ID == id)
        {
            Data::treemap.maps.erase(Data::treemap.maps.begin()+i);
            break;
        }
    }

    for (unsigned int i = 0; i < Data::treemap.tree_order.size(); i++)
    {
        if (Data::treemap.tree_order[i] == id)
        {
            Data::treemap.tree_order.erase(Data::treemap.tree_order.begin()+i);
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

void MainWindow::on_actionMap_Properties_triggered()
{
    if (!currentScene())
        return;

    currentScene()->editMapProperties();
}
