#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTreeWidgetItem>
#include "dialogresourcemanager.h"
#include "dialogdatabase.h"
#include "tools/QGraphicsMapScene.h"
#include "tools/QGraphicsPaleteScene.h"
#include "musicplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void LoadLastProject();
    void LoadProject(QString foldername);
    void ImportProject(QString p_path, QString d_folder);

private slots:
    void on_action_Quit_triggered();

    void on_actionPalete_triggered(bool checked);

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

    void on_action_Play_Test_triggered();

    void on_mapChanged();

    void on_mapUnchanged();

    void on_actionUndo_triggered();

    void on_actionMap_Properties_dialog_triggered();

    void on_action_Save_Map_triggered();

    void on_actionRevert_Map_triggered();

private:
    void closeEvent(QCloseEvent *event);
    bool saveAll();
    bool removeDir(const QString & dirName, const QString &root);
    QGraphicsView *getView(int id);
    QGraphicsMapScene *getScene(int id);
    QGraphicsView *getTabView(int index);
    QGraphicsMapScene *getTabScene(int index);
    QGraphicsMapScene *currentScene();
    void removeView(int id);

    Ui::MainWindow *ui;
    DialogResourceManager *dlg_resource;
    DialogDataBase *dlg_db;
    QSettings m_settings;
    QSettings *m_projSett;
    QGraphicsPaleteScene *m_paleteScene;
    QMap<int,QGraphicsView*> m_views;
};


#endif // MAINWINDOW_H
