#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogresourcemanager.h"
#include "dialogdatabase.h"
#include "gameproject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_action_Quit_triggered();

    void on_actionPalete_triggered(bool checked);

    void on_actionMap_Tree_triggered(bool checked);

    void on_actionResource_Manager_triggered();

    void on_actionData_Base_triggered();

    void update_actions();

    void on_action_New_Project_triggered();

private:
    GameProject *m_project;
    Ui::MainWindow *ui;
    DialogResourceManager *dlg_resource;
    DialogDataBase *dlg_db;
};

#endif // MAINWINDOW_H
