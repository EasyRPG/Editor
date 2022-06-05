/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QDialog>
#include <lcf/rpg/actor.h>
#include <QDialogButtonBox>
#include "actor_widget.h"
#include "class_widget.h"
#include "skill_widget.h"
#include "item_widget.h"
#include "enemy_widget.h"
#include "enemy_group_widget.h"
#include "attribute_widget.h"
#include "state_widget.h"
#include "battle_animation_widget.h"
#include "battle_animation2_widget.h"
#include "battle_screen_widget.h"
#include "terrain_widget.h"
#include "chipset_widget.h"
#include "vocabulary_widget.h"
#include "system_widget.h"
#include "system2_widget.h"
#include "common_event_widget.h"
#include "switch_widget.h"
#include "variable_widget.h"
#include "core.h"
#include "ui/common/rpg_model.h"

template<class LCF>
class DatabaseSplitWidget;
class ProjectData;

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
	Q_OBJECT

public:
	explicit DatabaseDialog(ProjectData& project, QWidget *parent = nullptr);
	~DatabaseDialog();

signals:
	void currentActorChanged(lcf::rpg::Actor *actor);

public slots:
	void on_currentActorChanged(lcf::rpg::Actor *actor);
	void on_buttonBox_clicked(QAbstractButton *button);

private slots:
	void on_toolSwitchStyle_clicked(bool checked);

	void on_tabOld_Pages_currentChanged(int index);

	void on_lineNew_CharacterFilter_textChanged(const QString &arg1);

	void on_pushNew_CharacterMax_clicked();

	void on_listNew_Character_currentRowChanged(int currentRow);

private:
	Ui::DatabaseDialog *ui;

	DatabaseSplitWidget<lcf::rpg::Actor>* pageActors;
	DatabaseSplitWidget<lcf::rpg::Class>* pageClasses;
	DatabaseSplitWidget<lcf::rpg::Skill>* pageSkills;
	DatabaseSplitWidget<lcf::rpg::Item>* pageItems;
	DatabaseSplitWidget<lcf::rpg::Enemy>* pageEnemies;
	DatabaseSplitWidget<lcf::rpg::Troop>* pageEnemyGroups;
	DatabaseSplitWidget<lcf::rpg::Attribute>* pageAttributes;
	DatabaseSplitWidget<lcf::rpg::State>* pageStates;
	DatabaseSplitWidget<lcf::rpg::Animation>* pageBattleAnimations;
	DatabaseSplitWidget<lcf::rpg::BattlerAnimation>* pageBattleAnimations2;
	BattleScreenWidget* pageBattleScreen;
	DatabaseSplitWidget<lcf::rpg::Terrain>* pageTerrain;
	DatabaseSplitWidget<lcf::rpg::Chipset>* pageChipset;
	VocabularyWidget* pageVocabulary;
	SystemWidget* pageSystem;
	System2Widget* pageSystem2;
	DatabaseSplitWidget<lcf::rpg::CommonEvent>* pageCommonevents;
	DatabaseSplitWidget<lcf::rpg::Switch>* pageSwitches;
	DatabaseSplitWidget<lcf::rpg::Variable>* pageVariables;
	ProjectData& m_project;
	ProjectData m_projectDataCopy;
};
