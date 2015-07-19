#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTreeWidgetItem>
#include "dialogresourcemanager.h"
#include "dialogdatabase.h"
#include "tools/qgraphicsmapscene.h"
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

public slots:
    void on_gameTitleChanged(const QString &gameTitle);

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

    void on_action_Save_Map_triggered();

    void on_actionRevert_Map_triggered();

    void on_treeMap_itemSelectionChanged();

    void on_actionNew_Map_triggered();

    void on_actionCopy_Map_triggered();

    void on_actionPaste_Map_triggered();

    void on_actionDelete_Map_triggered();

    void on_actionMap_Properties_triggered();


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
    void removeMap(const int id);

    Ui::MainWindow *ui;
    DialogResourceManager *dlg_resource;
    DialogDataBase *dlg_db;
    QSettings m_settings;
    QGraphicsPaleteScene *m_paleteScene;
    QMap<int,QGraphicsView*> m_views;
    QMap<int,QTreeWidgetItem*> m_treeItems;
    QString m_copiedMap;
};


#endif // MAINWINDOW_H
