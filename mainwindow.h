#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
