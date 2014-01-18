#include "dialognewproject.h"
#include "dialogopenproject.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QApplication>
#include <QFileInfo>
#include <QMessageBox>
#include <QDir>
#include "EasyRPGCore.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    const QString DEFAULT_DIR_KEY("default_dir");
    const QString CURRENT_PROJECT_KEY("current_project");
    ui->setupUi(this);
    // Hide map ids
    ui->treeMap->hideColumn(0);
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
    QFileInfo info(m_defDir+l_project+"/project.erp");
    if (l_project != QString() && info.exists())
        LoadProject(m_defDir+l_project+"/");
    m_paleteScene = new QGraphicsPaleteScene(ui->graphicsPalete);
    connect(this,SIGNAL(chipsetLoaded()),m_paleteScene,SLOT(onChipsetChange()));
    ui->graphicsPalete->setScene(m_paleteScene);
    /**  Test  **/
    EasyRPGCore::LoadChipset("C:/Program Files (x86)/ASCII/RPG2000/RTP/ChipSet/Basis.png");
    m_paleteScene->onChipsetChange();
    m_paleteScene->onLayerChange();
    /** /Test  **/
    if (project())
        m_paleteScene->onLayerChange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadProject(QString p_path)
{
    const QString CURRENT_PROJECT_KEY("current_project");
    EasyRPGCore::setCurrentProject(new GameProject());
    EasyRPGCore::setCurrentProjectPath(p_path);
    project()->Load();
    setWindowTitle("EasyRPG Editor - " + EasyRPGCore::currentGameTitle());
    m_settings.setValue(CURRENT_PROJECT_KEY, EasyRPGCore::currentGameTitle());
    update_actions();
}

void MainWindow::on_action_Quit_triggered()
{
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
    if (!project()){
        ui->actionCircle->setEnabled(false);
        ui->actionCreate_Game_Disk->setEnabled(false);
        ui->actionData_Base->setEnabled(false);
        ui->actionDraw->setEnabled(false);
        ui->actionFill->setEnabled(false);
        ui->actionRectangle->setEnabled(false);
        ui->actionResource_Manager->setEnabled(false);
        ui->actionRevert_all_Maps->setEnabled(false);
        ui->actionScale_1_1->setEnabled(false);
        ui->actionScale_1_2->setEnabled(false);
        ui->actionScale_1_4->setEnabled(false);
        ui->actionScale_1_8->setEnabled(false);
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
        ui->actionScale_1_2->setEnabled(true);
        ui->actionScale_1_4->setEnabled(true);
        ui->actionScale_1_8->setEnabled(true);
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
    const QString DEFAULT_DIR_KEY("default_dir");
    const QString CURRENT_PROJECT_KEY("current_project");
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
        if (!project())
            on_action_Close_Project_triggered();
        EasyRPGCore::setCurrentProject(new GameProject());
        if (!d_gamepath.exists())
            d_gamepath.mkdir(".");
        EasyRPGCore::setCurrentProjectPath(dlg.getProjectPath());
        EasyRPGCore::setCurrentGameTitle(dlg.getGameTitle());
        EasyRPGCore::setTileSize(dlg.getTileSize());
        d_gamepath.mkdir(EasyRPGCore::pathBackdrop());
        d_gamepath.mkdir(EasyRPGCore::pathBackground());
        d_gamepath.mkdir(EasyRPGCore::pathBattle());
        d_gamepath.mkdir(EasyRPGCore::pathBattle2());
        d_gamepath.mkdir(EasyRPGCore::pathBattleCharSet());
        d_gamepath.mkdir(EasyRPGCore::pathBattleWeapon());
        d_gamepath.mkdir(EasyRPGCore::pathCharSet());
        d_gamepath.mkdir(EasyRPGCore::pathChipSet());
        d_gamepath.mkdir(EasyRPGCore::pathFaceSet());
        d_gamepath.mkdir(EasyRPGCore::pathFrame());
        d_gamepath.mkdir(EasyRPGCore::pathGameOver());
        d_gamepath.mkdir(EasyRPGCore::pathMonster());
        d_gamepath.mkdir(EasyRPGCore::pathMovie());
        d_gamepath.mkdir(EasyRPGCore::pathMusic());
        d_gamepath.mkdir(EasyRPGCore::pathPicture());
        d_gamepath.mkdir(EasyRPGCore::pathSound());
        d_gamepath.mkdir(EasyRPGCore::pathSystem());
        d_gamepath.mkdir(EasyRPGCore::pathSystem2());
        d_gamepath.mkdir(EasyRPGCore::pathTitle());
        m_settings.setValue(DEFAULT_DIR_KEY,dlg.getDefDir());
        setWindowTitle("EasyRPG Editor - " + EasyRPGCore::currentGameTitle());
        m_settings.setValue(CURRENT_PROJECT_KEY, EasyRPGCore::currentGameTitle());
        //TODO: write RPT template code

        if (!project()->Save())
            QMessageBox::warning(this,"Error","An error ocurred while saving",QMessageBox::Ok,QMessageBox::Cancel);
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
    //TODO: check if there are unsaved maps and ask for saving.
    const QString CURRENT_PROJECT_KEY("current_project");
    m_settings.setValue(CURRENT_PROJECT_KEY, QString());
    EasyRPGCore::setCurrentProject(0);
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
}

void MainWindow::on_actionChipset_triggered()
{
    if (!EasyRPGCore::debugChipset())
        return;
    EasyRPGCore::debugChipset()->show();
}

void MainWindow::on_action_Lower_Layer_triggered()
{
    ui->action_Lower_Layer->setChecked(true);
    ui->action_Upper_Layer->setChecked(false);
    ui->action_Events->setChecked(false);
    EasyRPGCore::setCurrentLayer(EasyRPGCore::LOWER);
    m_paleteScene->onLayerChange();
}

void MainWindow::on_action_Upper_Layer_triggered()
{
    ui->action_Lower_Layer->setChecked(false);
    ui->action_Upper_Layer->setChecked(true);
    ui->action_Events->setChecked(false);
    EasyRPGCore::setCurrentLayer(EasyRPGCore::UPPER);
    m_paleteScene->onLayerChange();
}

void MainWindow::on_action_Events_triggered()
{
    ui->action_Lower_Layer->setChecked(false);
    ui->action_Upper_Layer->setChecked(false);
    ui->action_Events->setChecked(true);
    EasyRPGCore::setCurrentLayer(EasyRPGCore::EVENT);
    m_paleteScene->onLayerChange();
}
