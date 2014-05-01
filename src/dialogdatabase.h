#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "tools/qdbpageactors.h"
#include "tools/qdbpageclasses.h"
#include "tools/qdbpageskills.h"
#include "tools/qdbpageitems.h"
#include "tools/qdbpageenemies.h"
#include "tools/qdbpageenemygroups.h"
#include "tools/qdbpageattibutes.h"
#include "tools/qdbpageherostatus.h"
#include "tools/qdbpagebattleanimations.h"
#include "tools/qdbpagebattleanimations2.h"
#include "tools/qdbpagebattlescreen.h"
#include "tools/qdbpageterrain.h"
#include "tools/qdbpagechipset.h"
#include "tools/qdbpagevocabulary.h"
#include "tools/qdbpagesystem.h"
#include "tools/qdbpagesystem2.h"
#include "tools/qdbpagecommonevents.h"
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
    qdbpageclasses *Old_PageClasses;
    qdbpageskills *Old_PageSkills;
    qdbpageitems *Old_PageItems;
    qdbpageenemies *Old_PageEnemies;
    qdbpageenemygroups *Old_PageEnemyGroup;
    qdbpageattibutes *Old_PageAttributes;
    qdbpageherostatus *Old_PageHeroStatus;
    qdbpagebattleanimations *Old_PageBattleAnimation;
    qdbpagebattleanimations2 *Old_PageBattleAnimation2;
    qdbpagebattlescreen *Old_PageBatleScreen;
    qdbpageterrain *Old_PageTerrain;
    qdbpagechipset *Old_PageChipset;
    qdbpagevocabulary *Old_PageVocabulary;
    qdbpagesystem *Old_PageSystem;
    qdbpagesystem2 *Old_PageSystem2;
    qdbpagecommonevents *Old_PageCommonevents;
    RPG::Database m_data;
    RPG::Actor *m_currentActor;
};

#endif // DIALOGDATABASE_H
