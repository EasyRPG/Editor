#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_project(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Hide map ids
    ui->treeMap->hideColumn(0);
    // Created hardcoded toolbar for palette window.
    ui->toolBar->setParent(ui->dockWidgetContents);
    //Create dialogs
    dlg_resource = new DialogResourceManager(this, m_project);
    dlg_resource->setModal(true);
    dlg_db = new DialogDataBase(this);
    dlg_db->setModal(true);
    update_actions();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    if (m_project == 0){
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
