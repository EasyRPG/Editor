#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "tools/qdbpageactors.h"
#include "tools/qdbpageclasses.h"
#include "core.h"

namespace Ui {
class DialogDataBase;
}

class DialogDataBase : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDataBase(QWidget *parent = 0);
    ~DialogDataBase();

signals:
    void currentActorChanged(RPG::Actor *actor);
public slots:
    void on_currentActorChanged(RPG::Actor *actor);
    void on_buttonBox_clicked(QAbstractButton *button);

private slots:

    void on_toolSwitchStyle_clicked(bool checked);

    void on_tabOld_Pages_currentChanged(int index);

    void on_lineNew_CharacterFilter_textChanged(const QString &arg1);

    void on_pushNew_CharacterMax_clicked();

    void on_listNew_Character_currentRowChanged(int currentRow);

private:
    Ui::DialogDataBase *ui;

    QDbPageActors *Old_PageActors;
    QDbPageClasses *Old_PageClasses;

    RPG::Database m_data;
    RPG::Actor *m_currentActor;
};

#endif // DIALOGDATABASE_H
