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
#include "tools/qdbpageattributes.h"
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
	explicit DialogDataBase(QWidget *parent = nullptr);
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

	QDbPageSkills *Old_PageSkills;
	QDbPageItems *Old_PageItems;
	QDbPageEnemies *Old_PageEnemies;
	QDbPageEnemyGroups *Old_PageEnemyGroup;
	QDbPageAttributes *Old_PageAttributes;
	QDbPageHeroStatus *Old_PageHeroStatus;
	QDbPageBattleAnimations *Old_PageBattleAnimation;
	QDbPageBattleAnimations2 *Old_PageBattleAnimation2;
	QDbPageBattleScreen *Old_PageBatleScreen;
	QDbPageTerrain *Old_PageTerrain;
	QDbPageChipset *Old_PageChipset;
	QDbPageVocabulary *Old_PageVocabulary;
	QDbPageSystem *Old_PageSystem;
	QDbPageSystem2 *Old_PageSystem2;
	QDbPageCommonEvents *Old_PageCommonevents;
	RPG::Database m_data;
	RPG::Actor *m_currentActor;
};

#endif // DIALOGDATABASE_H
