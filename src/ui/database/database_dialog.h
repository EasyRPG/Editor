#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "tools/actor_widget.h"
#include "tools/class_widget.h"
#include "tools/skill_widget.h"
#include "tools/item_widget.h"
#include "tools/enemy_widget.h"
#include "tools/enemy_group_widget.h"
#include "tools/attribute_widget.h"
#include "tools/state_widget.h"
#include "tools/battle_animation_widget.h"
#include "tools/battle_animation_widget2.h"
#include "tools/battle_screen_widget.h"
#include "tools/terrain_widget.h"
#include "tools/chipset_widget.h"
#include "tools/vocabulary_widget.h"
#include "tools/system_widget.h"
#include "tools/system_widget2.h"
#include "tools/common_event_widget.h"
#include "core.h"

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit DatabaseDialog(QWidget *parent = nullptr);
	~DatabaseDialog();

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
	Ui::DatabaseDialog *ui;

	ActorWidget *Old_PageActors;
	ClassWidget *Old_PageClasses;

	SkillWidget *Old_PageSkills;
	ItemWidget *Old_PageItems;
	EnemyWidget *Old_PageEnemies;
	EnemyGroupWidget *Old_PageEnemyGroup;
	AttributeWidget *Old_PageAttributes;
	StateWidget *Old_PageHeroStatus;
	BattleAnimationWidget *Old_PageBattleAnimation;
	BattleAnimationWidget2 *Old_PageBattleAnimation2;
	BattleScreenWidget *Old_PageBatleScreen;
	TerrainWidget *Old_PageTerrain;
	ChipSetWidget *Old_PageChipset;
	VocabularyWidget *Old_PageVocabulary;
	SystemWidget *Old_PageSystem;
	SystemWidget2 *Old_PageSystem2;
	CommonEventWidget *Old_PageCommonevents;
	RPG::Database m_data;
	RPG::Actor *m_currentActor;
};

#endif // DIALOGDATABASE_H
