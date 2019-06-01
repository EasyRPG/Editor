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

DatabaseDialog::DatabaseDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DatabaseDialog),
	m_data(core().project()->database())
{
	ui->setupUi(this);
	m_currentActor = nullptr;
	on_currentActorChanged(nullptr);
	pageActors = new DatabaseSplitWidget<RPG::Actor, ActorWidget>(m_data, m_data.actors, this);
	Old_PageClasses = new ClassWidget(m_data, this);
	Old_PageSkills= new SkillWidget(m_data, this);
	Old_PageItems=new ItemWidget(m_data, this);
	Old_PageEnemies=new EnemyWidget(m_data, this);
	Old_PageEnemyGroup= new EnemyGroupWidget(m_data, this);
	Old_PageAttributes=new AttributeWidget(m_data, this);
	Old_PageHeroStatus=new StateWidget(m_data, this);
	Old_PageBattleAnimation=new BattleAnimationWidget(m_data, this);
	Old_PageBattleAnimation2=new BattleAnimation2Widget(m_data, this);
	Old_PageBatleScreen=new BattleScreenWidget(m_data, this);
	Old_PageTerrain=new TerrainWidget(m_data, this);
	Old_PageChipset= new ChipSetWidget(m_data, this);
	Old_PageVocabulary= new VocabularyWidget(m_data, this);
	Old_PageSystem= new SystemWidget(m_data, this);
	Old_PageSystem2= new System2Widget(m_data, this);
	Old_PageCommonevents= new CommonEventWidget(m_data, this);
	ui->tabOld_Pages->insertTab(0, pageActors, tr("Characters"));
	ui->tabOld_Pages->insertTab(1, Old_PageClasses, tr("Professions"));
	ui->tabOld_Pages->insertTab(2, Old_PageSkills, tr("Skills"));
	ui->tabOld_Pages->insertTab(3, Old_PageItems, tr("Items"));
	ui->tabOld_Pages->insertTab(4, Old_PageEnemies, tr("Enemys"));
	ui->tabOld_Pages->insertTab(5, Old_PageEnemyGroup, tr("EnemyGroup"));
	ui->tabOld_Pages->insertTab(6, Old_PageAttributes, tr("Attributes"));
	ui->tabOld_Pages->insertTab(7, Old_PageHeroStatus, tr("Hero Status"));
	ui->tabOld_Pages->insertTab(8, Old_PageBattleAnimation, tr("Battle Animation"));
	ui->tabOld_Pages->insertTab(9, Old_PageBattleAnimation2, tr("Battle Animation 2"));
	ui->tabOld_Pages->insertTab(10, Old_PageBatleScreen, tr("Battle screen"));
	ui->tabOld_Pages->insertTab(11, Old_PageTerrain, tr("Terrain"));
	ui->tabOld_Pages->insertTab(12, Old_PageChipset, tr("Chipset"));
	ui->tabOld_Pages->insertTab(13, Old_PageVocabulary, tr("Vocuabulary"));
	ui->tabOld_Pages->insertTab(14, Old_PageSystem, tr("System"));
	ui->tabOld_Pages->insertTab(15, Old_PageSystem2, tr("System"));
	ui->tabOld_Pages->insertTab(16, Old_PageCommonevents, tr("Common events"));

	ui->tabOld_Pages->setCurrentWidget(pageActors);
	ui->stackedStyle->setCurrentWidget(ui->pageOld);
	/* Fill Characters list */
	for (unsigned int i = 0; i < core().project()->database().actors.size(); i++)
		ui->listNew_Character->addItem(QString("%1:%2")
								   .arg(QString::number(i+1), 4, QLatin1Char('0'))
								   .arg(core().project()->database().actors[i].name.c_str()));
}

DatabaseDialog::~DatabaseDialog()
{
	delete ui;
}

void DatabaseDialog::on_currentActorChanged(lcf::rpg::Actor *actor)
{
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
														  actor->class_id >= static_cast<int>(m_data.classes.size()) ?
														  tr("<%1?>").arg(actor->class_id) :
														  m_data.classes[static_cast<size_t>(actor->class_id)-1].name.c_str());
	ui->tableNew_CharacterProperties->item(11,1)->setText(QString("%1[%2]")
														  .arg(actor->face_name.c_str())
														  .arg(actor->face_index));
	ui->tableNew_CharacterProperties->item(12,1)->setText(QString("%1[%2]%3")
														  .arg(actor->character_name.c_str())
														  .arg(actor->character_index)
														  .arg(actor->transparent ? " [Transparent]" : ""));
	ui->tableNew_CharacterProperties->item(13,1)->setText(actor->battler_animation < 1 ? tr("<none>") :
														  actor->battler_animation >= static_cast<int>(m_data.battleranimations.size()) ?
														  tr("<%1?>").arg(actor->battler_animation) :
														  m_data.battleranimations[static_cast<size_t>(actor->battler_animation) - 1].name.c_str());

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
		case QDialogButtonBox::Ok:
			lcf::LDB_Reader::PrepareSave(m_data);
			core().project()->saveDatabase();
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
	if (currentRow < 0 || currentRow >= static_cast<int>(m_data.actors.size()))
	{
		on_currentActorChanged(nullptr);
		emit currentActorChanged(nullptr);
		return; //invalid
	}

	on_currentActorChanged(&m_data.actors[static_cast<size_t>(currentRow)]);
	emit currentActorChanged(&m_data.actors[static_cast<size_t>(currentRow)]);
}
