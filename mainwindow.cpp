#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Hide map ids
    ui->treeMap->hideColumn(0);
    // Created hardcoded toolbar for palette window.
    ui->toolBar->setParent(ui->dockWidgetContents);
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
