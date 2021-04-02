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

#include "core.h"
#include "database_dialog.h"
#include "ui_database_dialog.h"
#include <QPushButton>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <lcf/ldb/reader.h>
#include "database_split_widget.h"

DatabaseDialog::DatabaseDialog(ProjectData& project, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DatabaseDialog),
	m_project(project)
{
	ui->setupUi(this);
	on_currentActorChanged(nullptr);

	m_projectDataCopy = project;

	pageActors = new DatabaseSplitWidget<lcf::rpg::Actor>(m_projectDataCopy, this);
	pageClasses = new DatabaseSplitWidget<lcf::rpg::Class>(m_projectDataCopy, this);
	pageSkills = new DatabaseSplitWidget<lcf::rpg::Skill>(m_projectDataCopy, this);
	pageItems = new DatabaseSplitWidget<lcf::rpg::Item>(m_projectDataCopy, this);
	pageEnemies = new DatabaseSplitWidget<lcf::rpg::Enemy>(m_projectDataCopy, this);
	pageEnemyGroups = new DatabaseSplitWidget<lcf::rpg::Troop>(m_projectDataCopy, this);
	pageAttributes = new DatabaseSplitWidget<lcf::rpg::Attribute>(m_projectDataCopy, this);
	pageStates = new DatabaseSplitWidget<lcf::rpg::State>(m_projectDataCopy, this);
	pageBattleAnimations = new DatabaseSplitWidget<lcf::rpg::Animation>(m_projectDataCopy, this);
	pageBattleAnimations2 = new DatabaseSplitWidget<lcf::rpg::BattlerAnimation>(m_projectDataCopy, this);
	pageBattleScreen = new BattleScreenWidget(m_projectDataCopy, this);
	pageTerrain = new DatabaseSplitWidget<lcf::rpg::Terrain>(m_projectDataCopy, this);
	// FIXME: This fails to compile pageChipset = new DatabaseSplitWidget<lcf::rpg::Chipset>(m_projectDataCopy, this);
	pageCommonevents = new DatabaseSplitWidget<lcf::rpg::CommonEvent>(m_projectDataCopy, this);
	pageSwitches = new DatabaseSplitWidget<lcf::rpg::Switch>(m_projectDataCopy, this);
	pageVariables = new DatabaseSplitWidget<lcf::rpg::Variable>(m_projectDataCopy, this);

	pageVocabulary = new VocabularyWidget(m_projectDataCopy, this);
	pageSystem = new SystemWidget(m_projectDataCopy, this);
	pageSystem2  = new System2Widget(m_projectDataCopy, this);
	ui->tabOld_Pages->insertTab(0, pageActors, tr("Characters"));
	ui->tabOld_Pages->insertTab(1, pageClasses, tr("Professions"));
	ui->tabOld_Pages->insertTab(2, pageSkills, tr("Skills"));
	ui->tabOld_Pages->insertTab(3, pageItems, tr("Items"));
	ui->tabOld_Pages->insertTab(4, pageEnemies, tr("Enemys"));
	ui->tabOld_Pages->insertTab(5, pageEnemyGroups, tr("EnemyGroup"));
	ui->tabOld_Pages->insertTab(6, pageAttributes, tr("Attributes"));
	ui->tabOld_Pages->insertTab(7, pageStates, tr("Hero Status"));
	ui->tabOld_Pages->insertTab(8, pageBattleAnimations, tr("Battle Animation"));
	ui->tabOld_Pages->insertTab(9, pageBattleAnimations2, tr("Battle Animation 2"));
	ui->tabOld_Pages->insertTab(10, pageBattleScreen, tr("Battle screen"));
	ui->tabOld_Pages->insertTab(11, pageTerrain, tr("Terrain"));
	// FIXME ui->tabOld_Pages->insertTab(12, pageChipset, tr("Chipset"));
	ui->tabOld_Pages->insertTab(13, pageVocabulary, tr("Vocabulary"));
	ui->tabOld_Pages->insertTab(14, pageSystem, tr("System"));
	ui->tabOld_Pages->insertTab(15, pageSystem2, tr("System"));
	ui->tabOld_Pages->insertTab(16, pageCommonevents, tr("Common events"));
	ui->tabOld_Pages->insertTab(17, pageSwitches, tr("Switches"));
	ui->tabOld_Pages->insertTab(19, pageVariables, tr("Variables"));

	ui->tabOld_Pages->setCurrentWidget(pageActors);
	ui->stackedStyle->setCurrentWidget(ui->pageOld);
}

DatabaseDialog::~DatabaseDialog()
{
	delete ui;
}

void DatabaseDialog::on_currentActorChanged(lcf::rpg::Actor */* actor */)
{
#if 0
	m_currentActor = actor;
	if (actor == nullptr){
		/* Clear Table */
		for (int i = 0; i < ui->tableNew_CharacterProperties->rowCount(); i++)
			ui->tableNew_CharacterProperties->item(i,1)->setText("");
		/* Disable Table */
		ui->tableNew_CharacterProperties->setEnabled(false);
		return;
	}

	/* Fill Table */
	QString yes = tr("YES");
	QString no = tr("NO");
	ui->tableNew_CharacterProperties->item(0,1)->setText(actor->name.c_str());
	ui->tableNew_CharacterProperties->item(1,1)->setText(actor->title.c_str());
	ui->tableNew_CharacterProperties->item(2,1)->setText(QString::number(actor->initial_level));
	ui->tableNew_CharacterProperties->item(3,1)->setText(QString::number(actor->final_level));
	ui->tableNew_CharacterProperties->item(4,1)->setText(actor->critical_hit ? yes : no);
	ui->tableNew_CharacterProperties->item(5,1)->setText(tr("1 of %1 turns").arg(actor->critical_hit_chance));
	ui->tableNew_CharacterProperties->item(6,1)->setText(actor->two_weapon ? yes :no);
	ui->tableNew_CharacterProperties->item(7,1)->setText(actor->lock_equipment ? yes :no);
	ui->tableNew_CharacterProperties->item(8,1)->setText(actor->auto_battle ? yes :no);
	ui->tableNew_CharacterProperties->item(9,1)->setText(actor->super_guard ? yes :no);
	ui->tableNew_CharacterProperties->item(10,1)->setText(actor->class_id < 1 ? tr("<none>") :
														  actor->class_id >= static_cast<int>(m_dataCopy.classes.size()) ?
														  tr("<%1?>").arg(actor->class_id) :
														  m_dataCopy.classes[static_cast<size_t>(actor->class_id)-1].name.c_str());
	ui->tableNew_CharacterProperties->item(11,1)->setText(QString("%1[%2]")
														  .arg(actor->face_name.c_str())
														  .arg(actor->face_index));
	ui->tableNew_CharacterProperties->item(12,1)->setText(QString("%1[%2]%3")
														  .arg(actor->character_name.c_str())
														  .arg(actor->character_index)
														  .arg(actor->transparent ? " [Transparent]" : ""));
	ui->tableNew_CharacterProperties->item(13,1)->setText(actor->battler_animation < 1 ? tr("<none>") :
														  actor->battler_animation >= static_cast<int>(m_dataCopy.battleranimations.size()) ?
														  tr("<%1?>").arg(actor->battler_animation) :
														  m_dataCopy.battleranimations[static_cast<size_t>(actor->battler_animation) - 1].name.c_str());

	/* TODO: fill the following information */
	ui->tableNew_CharacterProperties->item(14,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(15,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(16,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(17,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(18,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(19,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(20,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(21,1)->setText("ItemName");
	ui->tableNew_CharacterProperties->item(22,1)->setText("ItemName");
	ui->tableNew_CharacterProperties->item(23,1)->setText("ItemName");
	ui->tableNew_CharacterProperties->item(24,1)->setText("ItemName");
	ui->tableNew_CharacterProperties->item(25,1)->setText("ItemName");
	ui->tableNew_CharacterProperties->item(26,1)->setText("AnimName");
	ui->tableNew_CharacterProperties->item(27,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(28,1)->setText("Click to Edit");
	ui->tableNew_CharacterProperties->item(29,1)->setText("Click to Edit");

	/* Enable Table */
	ui->tableNew_CharacterProperties->setEnabled(true);
#endif
}

void DatabaseDialog::on_tabOld_Pages_currentChanged(int index)
{
	ui->listNew_Pages->setCurrentRow(index);
	emit ui->listNew_Pages->currentRowChanged(index);
}

void DatabaseDialog::on_toolSwitchStyle_clicked(bool checked)
{
	ui->stackedStyle->setCurrentIndex(static_cast<int>(checked));
}

void DatabaseDialog::on_buttonBox_clicked(QAbstractButton *button)
{
	switch(ui->buttonBox->standardButton(button))
	{
		// Standard buttons:
		case QDialogButtonBox::Apply:
		case QDialogButtonBox::Ok: {
			m_project = m_projectDataCopy;
			lcf::LDB_Reader::PrepareSave(m_project.database());
			core().project()->saveDatabase();
		}
		break;
		default:
			// shouldn't happen
			break;
	}
}
void DatabaseDialog::on_pushNew_CharacterMax_clicked()
{
	/* TODO: resize characters */
}

void DatabaseDialog::on_lineNew_CharacterFilter_textChanged(const QString &arg1)
{
	for (int i = 0; i < ui->listNew_Character->count(); i++)
		ui->listNew_Character->item(i)->setHidden(ui->listNew_Character->item(i)->text().contains(arg1,Qt::CaseInsensitive));
}

void DatabaseDialog::on_listNew_Character_currentRowChanged(int currentRow)
{
	auto& database = m_projectDataCopy.database();

	if (currentRow < 0 || currentRow >= static_cast<int>(database.actors.size()))
	{
		on_currentActorChanged(nullptr);
		emit currentActorChanged(nullptr);
		return; //invalid
	}

	on_currentActorChanged(&database.actors[static_cast<size_t>(currentRow)]);
	emit currentActorChanged(&database.actors[static_cast<size_t>(currentRow)]);
}
