#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include <QDialog>

namespace Ui {
class DialogNewProject;
}

class DialogNewProject : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogNewProject(QWidget *parent = 0);
    ~DialogNewProject();
    
    QString getProjectPath();
    QString getGameTitle();
    int getTileSize();
    //TODO: generate RTP template code.

    void setDefDir(QString n_defDir);
    QString getDefDir();

private slots:
    void on_toolProjectPath_clicked();

private:
    Ui::DialogNewProject *ui;
    QString m_defDir;
};

#endif // DIALOGNEWPROJECT_H
