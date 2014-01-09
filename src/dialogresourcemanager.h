#ifndef DIALOGRESOURCEMANAGER_H
#define DIALOGRESOURCEMANAGER_H

#include <QDialog>
#include <QStringListModel>
#include "gameproject.h"

namespace Ui {
class DialogResourceManager;
}

class DialogResourceManager : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogResourceManager(QWidget *parent = 0);
    ~DialogResourceManager();

private slots:
    void on_listResourceType_currentRowChanged(int currentRow);

    void on_pushImport_clicked();

private:
    Ui::DialogResourceManager *ui;
    QStringListModel *m_model;

    QString m_lastmusicpath;
    QString m_lastsoundpath;
    QString m_lastmoviepath;
    QString m_lastpicturepath;

};

#endif // DIALOGRESOURCEMANAGER_H
