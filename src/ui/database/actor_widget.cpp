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

#include "actor_widget.h"
#include "ui_actor_widget.h"
#include <QTimer>
#include <QGraphicsOpacityEffect>

ActorWidget::ActorWidget(lcf::rpg::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ActorWidget),
	m_data(database)
{
	const auto kMaxLevel = database.system.ldb_id == 2003 ? 99 : 50;
	const auto kMaxHp = database.system.ldb_id == 2003 ? 9999 : 999;
	ui->setupUi(this);

	m_currentActor = nullptr;

	ui->spinMaxLv->setMaximum(kMaxLevel);

	ui->graphicsBattleset->setScene(new QGraphicsScene(this));
	m_charaItem = new CharSetItem();
	m_charaItem->setSpin(true);
	m_charaItem->setWalk(true);
	m_charaItem->setScale(2.0);
	m_charaItem->setGraphicsEffect(new QGraphicsOpacityEffect(this));

	m_faceItem = new FaceSetItem();
	m_faceItem->setScale(2.0);

	m_battlerItem = new BattleAnimationItem();

	for (int i = 0; i < kMaxLevel; i++)
		m_dummyCurve.push_back(0);
	m_hpItem = new CurveItem(Qt::red, m_dummyCurve);
	m_hpItem->setMaxValue(kMaxHp);
	m_mpItem = new CurveItem(Qt::magenta, m_dummyCurve);
	m_attItem = new CurveItem(Qt::yellow, m_dummyCurve);
	m_defItem = new CurveItem(Qt::green, m_dummyCurve);
	m_intItem = new CurveItem(Qt::darkBlue, m_dummyCurve);
	m_agyItem = new CurveItem(Qt::blue, m_dummyCurve);

	ui->graphicsCharset->setScene(new QGraphicsScene(this));
	ui->graphicsCharset->scene()->addItem(m_charaItem);
	ui->graphicsCharset->scene()->setSceneRect(0,0,48,64);

	ui->graphicsFaceset->setScene(new QGraphicsScene(this));
	ui->graphicsFaceset->scene()->addItem(m_faceItem);
	ui->graphicsFaceset->scene()->setSceneRect(0,0,96,96);

	ui->graphicsBattleset->setScene(new QGraphicsScene(this));
	ui->graphicsBattleset->scene()->addItem(m_battlerItem);
	ui->graphicsBattleset->scene()->setSceneRect(0,0,48,48);

	ui->graphicsHp->setScene(new QGraphicsScene(this));
	ui->graphicsHp->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsHp->size()));
	ui->graphicsHp->scene()->addItem(m_hpItem);

	ui->graphicsMp->setScene(new QGraphicsScene(this));
	ui->graphicsMp->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsMp->size()));
	ui->graphicsMp->scene()->addItem(m_mpItem);

	ui->graphicsAtt->setScene(new QGraphicsScene(this));
	ui->graphicsAtt->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsAtt->size()));
	ui->graphicsAtt->scene()->addItem(m_attItem);

	ui->graphicsDef->setScene(new QGraphicsScene(this));
	ui->graphicsDef->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsDef->size()));
	ui->graphicsDef->scene()->addItem(m_defItem);

	ui->graphicsInt->setScene(new QGraphicsScene(this));
	ui->graphicsInt->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsInt->size()));
	ui->graphicsInt->scene()->addItem(m_intItem);

	ui->graphicsAgy->setScene(new QGraphicsScene(this));
	ui->graphicsAgy->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsAgy->size()));
	ui->graphicsAgy->scene()->addItem(m_agyItem);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), ui->graphicsCharset->scene(), SLOT(advance()));
	connect(timer, SIGNAL(timeout()), ui->graphicsBattleset->scene(), SLOT(advance()));
	timer->start(200);
	UpdateModels();

	if (database.system.ldb_id != 2003) {
		for (int i = 0; i < ui->gridBattleSet->count(); ++i) {
			ui->gridBattleSet->itemAt(i)->widget()->hide();
		}
		ui->groupBoxClass->hide();
	}
}

void ActorWidget::setData(RPG::Actor* actor)
{
	on_currentActorChanged(actor);
}

ActorWidget::~ActorWidget()
{
	delete ui;
}

void ActorWidget::UpdateModels()
{
	/* Clear */
	//ui->listCharacters->clear();
	ui->comboBattleset->clear();
	ui->comboProfession->clear();
	ui->comboUnarmedAnimation->clear();
	ui->listAttributeRanks->clear();
	ui->listStatusRanks->clear();
	/* Fill */
	ui->comboBattleset->addItem(tr("<none>"));
	for (unsigned int i = 0; i < m_data.battleranimations.size(); i++)
		ui->comboBattleset->addItem(m_data.battleranimations[i].name.c_str());
	ui->comboProfession->addItem(tr("<none>"));
	for (unsigned int i = 0; i < m_data.classes.size(); i++)
		ui->comboProfession->addItem(m_data.classes[i].name.c_str());
	ui->comboUnarmedAnimation->addItem(tr("<none>"));
	for (unsigned int i = 0; i < m_data.animations.size(); i++)
		ui->comboUnarmedAnimation->addItem(m_data.animations[i].name.c_str());
	for (unsigned int i = 0; i < m_data.attributes.size(); i++)
		ui->listAttributeRanks->addItem(m_data.attributes[i].name.c_str());
	for (unsigned int i = 0; i < m_data.states.size(); i++)
		ui->listStatusRanks->addItem(m_data.states[i].name.c_str());
	/*for (unsigned int i = 0; i < m_data.actors.size(); i++)
		ui->listCharacters->addItem(QString("%1: %2")
							   .arg(QString::number(i+1), 4, QLatin1Char('0'))
							   .arg(m_data.actors[i].name.c_str()));*/

	on_currentActorChanged(m_currentActor);
}


void ActorWidget::on_lineName_textChanged(const QString &arg1)
{
	if (!m_currentActor || m_currentActor->name == arg1.toStdString())
		return;
	m_currentActor->name = arg1.toStdString();
	//ui->listCharacters->currentItem()->setText(QString("%1:%2") .arg(QString::number(m_currentActor->ID),4,QLatin1Char('0')) .arg(arg1));
}

void ActorWidget::on_lineTitle_textChanged(const QString &arg1)
{
	if (!m_currentActor || m_currentActor->title == arg1.toStdString())
		return;
	m_currentActor->title = arg1.toStdString();
}

void ActorWidget::on_spinMinLv_valueChanged(int arg1)
{
	if (!m_currentActor || m_currentActor->initial_level == arg1)
		return;
	m_currentActor->initial_level = arg1;
}

void ActorWidget::on_spinMaxLv_valueChanged(int arg1)
{
	if (!m_currentActor || m_currentActor->final_level == arg1)
		return;
	m_currentActor->final_level = arg1;
}

void ActorWidget::on_groupCritChance_toggled(bool checked)
{
	if (!m_currentActor || m_currentActor->critical_hit == checked)
		return;
	m_currentActor->critical_hit = checked;
}

void ActorWidget::on_comboBattleset_currentIndexChanged(int index)
{
	if (!m_currentActor)
		return;

	m_currentActor->battler_animation = index;

	if (index <= 0 || index >= static_cast<int>(m_data.battleranimations.size()))
		m_battlerItem->setBasePix(BattleAnimationItem::Battler,"");
	else
		m_battlerItem->setDemoAnimation(m_data.battleranimations[static_cast<size_t>(index) - 1]);
}

void ActorWidget::on_checkDualWeapon_toggled(bool checked)
{
	if (!m_currentActor || m_currentActor->two_weapon == checked)
		return;
	m_currentActor->two_weapon = checked;
}

void ActorWidget::on_checkAI_toggled(bool checked)
{
	if (!m_currentActor || m_currentActor->auto_battle == checked)
		return;
	m_currentActor->auto_battle = checked;
}

void ActorWidget::on_checkFixedEquip_toggled(bool checked)
{
	if (!m_currentActor || m_currentActor->lock_equipment == checked)
		return;
	m_currentActor->lock_equipment = checked;
}

void ActorWidget::on_checkStrongDefense_toggled(bool checked)
{
	if (!m_currentActor || m_currentActor->super_guard == checked)
	{
		return;
	}
	m_currentActor->super_guard = checked;
}

void ActorWidget::on_spinCritChance_valueChanged(int arg1)
{
	if (!m_currentActor || m_currentActor->critical_hit_chance == 1)
		return;
	m_currentActor->critical_hit_chance = arg1;
}

void ActorWidget::on_comboInitialWeapon_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->initial_equipment.weapon_id == ui->comboInitialWeapon->itemData(index))
		return;
	m_currentActor->initial_equipment.weapon_id = static_cast<short>(ui->comboInitialWeapon->itemData(index).toInt());
}

void ActorWidget::on_comboInitialShield_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->initial_equipment.shield_id == ui->comboInitialShield->itemData(index).toInt())
		return;
	m_currentActor->initial_equipment.shield_id = static_cast<short>(ui->comboInitialShield->itemData(index).toInt());
}
void ActorWidget::on_comboInitialArmor_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->initial_equipment.armor_id == ui->comboInitialArmor->itemData(index).toInt())
		return;
	m_currentActor->initial_equipment.armor_id = static_cast<short>(ui->comboInitialArmor->itemData(index).toInt());
}
void ActorWidget::on_comboInitialHelmet_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->initial_equipment.helmet_id == ui->comboInitialHelmet->itemData(index).toInt())
		return;
	m_currentActor->initial_equipment.helmet_id = static_cast<short>(ui->comboInitialHelmet->itemData(index).toInt());
}
void ActorWidget::on_comboInitialMisc_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->initial_equipment.accessory_id == ui->comboInitialMisc->itemData(index).toInt())
		return;
	m_currentActor->initial_equipment.accessory_id = static_cast<short>(ui->comboInitialMisc->itemData(index).toInt());
}

void ActorWidget::on_comboUnarmedAnimation_currentIndexChanged(int index)
{
	if(index < 0) return;
	if(!m_currentActor) return;
	if(m_currentActor->unarmed_animation == index)
		return;
	m_currentActor->unarmed_animation = index;
}

void ActorWidget::on_pushSetCharset_clicked()
{
	if (!m_currentActor)
		return;

	CharSetPickerDialog dlg(this, false);
	dlg.setName(m_currentActor->character_name);
	dlg.setIndex(m_currentActor->character_index);
	dlg.exec();
	if (dlg.result() == QDialogButtonBox::Ok)
	{
		m_currentActor->character_name = dlg.name();
		m_currentActor->character_index = dlg.index();

		m_charaItem->setVisible(true);
		m_charaItem->setBasePix(m_currentActor->character_name.c_str());
		m_charaItem->setIndex(m_currentActor->character_index);
	}
}

void ActorWidget::on_pushSetFace_clicked()
{
	faceset_picker_dialog dlg(this, true);
	dlg.setName(m_currentActor->face_name);
	dlg.exec();
	if (dlg.result() == QDialogButtonBox::Ok)
	{
		m_currentActor->face_name = dlg.name();
		m_currentActor->face_index = dlg.index();

		m_faceItem->setVisible(true);
		m_faceItem->setBasePix(m_currentActor->face_name.c_str());
		m_faceItem->setIndex(m_currentActor->face_index);

	}
}

void ActorWidget::ResetExpText(lcf::rpg::Actor* actor) {
	int base = 0;
	int inflation = 0;
	int correction = 0;
	if (actor != nullptr) {
		base = actor->exp_base;
		inflation = actor->exp_inflation;
		correction = actor->exp_correction;
	}
	char buf[1024] = {};
	snprintf(buf, sizeof(buf), "Initial = %d; Increment = %d; Correction = %d",
			 base, inflation, correction);
	ui->labelExpCurve->setText(buf);
}

void ActorWidget::on_currentActorChanged(lcf::rpg::Actor *actor)
{
	m_currentActor = nullptr;

	ResetExpText(actor);

	if (actor == nullptr){
		/* Clear widgets */
		ui->lineName->clear();
		ui->lineTitle->clear();
		ui->spinCritChance->setValue(30);
		ui->spinMaxLv->setValue(1);
		ui->spinMinLv->setValue(1);
		ui->checkAI->setChecked(false);
		ui->checkDualWeapon->setChecked(false);
		ui->checkFixedEquip->setChecked(false);
		ui->checkStrongDefense->setChecked(false);
		ui->checkTranslucent->setChecked(false);
		ui->groupCritChance->setChecked(false);
		ui->comboBattleset->setCurrentIndex(0);
		ui->comboInitialArmor->clear();
		ui->comboInitialHelmet->clear();
		ui->comboInitialMisc->clear();
		ui->comboInitialWeapon->clear();
		ui->comboInitialShield->clear();
		ui->comboProfession->setCurrentIndex(0);
		ui->comboUnarmedAnimation->setCurrentIndex(0);
		ui->tableSkills->setRowCount(0);
		m_charaItem->setVisible(false);
		m_faceItem->setVisible(false);
		for (int i = 0; i < ui->listAttributeRanks->count(); i++)
			ui->listAttributeRanks->item(i)->setIcon(QIcon());
		for (int i = 0; i < ui->listStatusRanks->count(); i++)
			ui->listStatusRanks->item(i)->setIcon(QIcon());
		/* Disable widgets */
		ui->lineName->setEnabled(false);
		ui->lineTitle->setEnabled(false);
		ui->spinMaxLv->setEnabled(false);
		ui->spinMinLv->setEnabled(false);
		ui->checkAI->setEnabled(false);
		ui->checkDualWeapon->setEnabled(false);
		ui->checkFixedEquip->setEnabled(false);
		ui->checkStrongDefense->setEnabled(false);
		ui->checkTranslucent->setEnabled(false);
		ui->groupCritChance->setEnabled(false);
		ui->comboBattleset->setEnabled(false);
		ui->comboInitialArmor->setEnabled(false);
		ui->comboInitialHelmet->setEnabled(false);
		ui->comboInitialMisc->setEnabled(false);
		ui->comboInitialWeapon->setEnabled(false);
		ui->comboInitialShield->setEnabled(false);
		ui->comboProfession->setEnabled(false);
		ui->comboUnarmedAnimation->setEnabled(false);
		ui->tableSkills->setEnabled(false);
		ui->listAttributeRanks->setEnabled(false);
		ui->listStatusRanks->setEnabled(false);
		ui->pushApplyProfession->setEnabled(false);
		ui->pushExpCurveEdit->setEnabled(false);
		ui->pushSetCharset->setEnabled(false);
		ui->pushSetFace->setEnabled(false);
		ui->pushEditCustom->setEnabled(false);
		return;
	}

	/* Fill widgets data */
	ui->lineName->setText(actor->name.c_str());
	ui->lineTitle->setText(actor->title.c_str());
	ui->spinCritChance->setValue(actor->critical_hit_chance);
	ui->spinMaxLv->setValue(actor->final_level);
	ui->spinMinLv->setValue(actor->initial_level);
	ui->checkAI->setChecked(actor->auto_battle);
	ui->checkDualWeapon->setChecked(actor->two_weapon);
	ui->checkFixedEquip->setChecked(actor->lock_equipment);
	ui->checkStrongDefense->setChecked(actor->super_guard);
	ui->checkTranslucent->setChecked(actor->transparent);
	ui->groupCritChance->setChecked(actor->critical_hit);
	ui->comboBattleset->setCurrentIndex(actor->battler_animation);
	ui->comboInitialArmor->clear();
	ui->comboInitialHelmet->clear();
	ui->comboInitialMisc->clear();
	ui->comboInitialShield->clear();
	ui->comboInitialWeapon->clear();
	ui->comboInitialArmor->addItem(tr("<none>"), 0);
	ui->comboInitialHelmet->addItem(tr("<none>"), 0);
	ui->comboInitialMisc->addItem(tr("<none>"), 0);
	ui->comboInitialShield->addItem(tr("<none>"), 0);
	ui->comboInitialWeapon->addItem(tr("<none>"), 0);
	for (size_t i = 0; i < m_data.items.size(); i++)
	{
		/* Check if hero can use item*/
		if (actor->ID <= static_cast<int>(m_data.items[i].actor_set.size()) &&
				!m_data.items[i].actor_set[static_cast<size_t>(actor->ID)-1])
			if (actor->class_id <= 0 ||
					(actor->class_id >= static_cast<int>(m_data.items[i].class_set.size()) &&
					 ((m_data.items[i].class_set.size()>0) &&(!m_data.items[i].class_set[static_cast<size_t>(actor->class_id)-1]))))
				continue;

		switch (m_data.items[i].type)
		{
		case lcf::rpg::Item::Type_armor:
			ui->comboInitialArmor->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
			if (actor->initial_equipment.armor_id == m_data.items[i].ID)
				ui->comboInitialArmor->setCurrentIndex(ui->comboInitialArmor->count()-1);
			break;
		case lcf::rpg::Item::Type_helmet:
			ui->comboInitialHelmet->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
			if (actor->initial_equipment.helmet_id == m_data.items[i].ID)
				ui->comboInitialHelmet->setCurrentIndex(ui->comboInitialHelmet->count()-1);
			break;
		case lcf::rpg::Item::Type_accessory:
			ui->comboInitialMisc->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
			if (actor->initial_equipment.accessory_id == m_data.items[i].ID)
				ui->comboInitialMisc->setCurrentIndex(ui->comboInitialMisc->count()-1);
			break;
		case lcf::rpg::Item::Type_shield:
			ui->comboInitialShield->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
			if (actor->initial_equipment.shield_id == m_data.items[i].ID)
				ui->comboInitialShield->setCurrentIndex(ui->comboInitialShield->count()-1);
			break;
		case lcf::rpg::Item::Type_weapon:
			ui->comboInitialWeapon->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
			if (actor->initial_equipment.weapon_id == m_data.items[i].ID)
				ui->comboInitialWeapon->setCurrentIndex(ui->comboInitialWeapon->count()-1);
			break;
		}
	}
	ui->comboProfession->setCurrentIndex(actor->class_id);
	ui->comboUnarmedAnimation->setCurrentIndex(actor->unarmed_animation);
	ui->tableSkills->setRowCount(0);
	for (int i = 0; i < static_cast<int>(actor->skills.size()); i++){
		ui->tableSkills->insertRow(i);
		ui->tableSkills->setItem(i,0,new QTableWidgetItem());
		ui->tableSkills->setItem(i,1,new QTableWidgetItem());
		ui->tableSkills->item(i, 0)->setText(QString::number(actor->skills[static_cast<size_t>(i)].level));
		// TODO: move getSkillName to Core
		QString name = QString("<%1?>").arg(actor->skills[static_cast<size_t>(i)].skill_id);
		if (actor->skills[static_cast<size_t>(i)].skill_id < static_cast<int>(m_data.skills.size()))
			name = m_data.skills[static_cast<size_t>(actor->skills[static_cast<size_t>(i)].skill_id)-1].name.c_str();
		// TODO/
		ui->tableSkills->item(i, 1)->setText(name);
	}
	ui->tableSkills->insertRow(static_cast<int>(actor->skills.size()));
	for (int i = 0; i < ui->listAttributeRanks->count(); i++)
	{
		if (i >= static_cast<int>(actor->attribute_ranks.size()))
			ui->listAttributeRanks->item(static_cast<int>(i))->setIcon(QIcon(":/embedded/share/old_rank2.png"));
		else
			ui->listAttributeRanks->item(static_cast<int>(i))->setIcon(QIcon(QString(":/embedded/share/old_rank%1.png").arg(static_cast<int>(actor->attribute_ranks[static_cast<size_t>(i)]))));
	}
	for (int i = 0; i < ui->listStatusRanks->count(); i++)
	{
		if (i >= static_cast<int>(actor->state_ranks.size()))
			ui->listStatusRanks->item(i)->setIcon(QIcon(":/embedded/share/old_rank2.png"));
		else
			ui->listStatusRanks->item(i)->setIcon(QIcon(QString(":/embedded/share/old_rank%1.png").arg(static_cast<int>(actor->state_ranks[static_cast<size_t>(i)]))));
	}
	m_charaItem->setVisible(true);
	m_charaItem->setBasePix(actor->character_name.c_str());
	m_charaItem->setIndex(actor->character_index);
	m_charaItem->graphicsEffect()->setEnabled(actor->transparent);

	m_faceItem->setVisible(true);
	m_faceItem->setBasePix(actor->face_name.c_str());
	m_faceItem->setIndex(actor->face_index);

	if (actor->battler_animation <= 0 ||
			actor->battler_animation >= static_cast<int>(m_data.battleranimations.size()))
		m_battlerItem->setBasePix(BattleAnimationItem::Battler,"");
	else
		m_battlerItem->setDemoAnimation(m_data.battleranimations[static_cast<size_t>(actor->battler_animation)-1]);

	m_hpItem->setData(actor->parameters.maxhp);
	m_mpItem->setData(actor->parameters.maxsp);
	m_attItem->setData(actor->parameters.attack);
	m_defItem->setData(actor->parameters.defense);
	m_intItem->setData(actor->parameters.spirit);
	m_agyItem->setData(actor->parameters.agility);

	/* Enable widgets */
	ui->lineName->setEnabled(true);
	ui->lineTitle->setEnabled(true);
	ui->spinMaxLv->setEnabled(true);
	ui->spinMinLv->setEnabled(true);
	ui->checkAI->setEnabled(true);
	ui->checkDualWeapon->setEnabled(true);
	ui->checkFixedEquip->setEnabled(true);
	ui->checkStrongDefense->setEnabled(true);
	ui->checkTranslucent->setEnabled(true);
	ui->groupCritChance->setEnabled(true);
	ui->comboBattleset->setEnabled(true);
	ui->comboInitialArmor->setEnabled(true);
	ui->comboInitialHelmet->setEnabled(true);
	ui->comboInitialMisc->setEnabled(true);
	ui->comboInitialWeapon->setEnabled(true);
	ui->comboInitialShield->setEnabled(true);
	ui->comboProfession->setEnabled(true);
	ui->comboUnarmedAnimation->setEnabled(true);
	ui->tableSkills->setEnabled(true);
	ui->listAttributeRanks->setEnabled(true);
	ui->listStatusRanks->setEnabled(true);
	ui->pushApplyProfession->setEnabled(true);
	ui->pushExpCurveEdit->setEnabled(true);
	ui->pushSetCharset->setEnabled(true);
	ui->pushSetFace->setEnabled(true);
	ui->pushEditCustom->setEnabled(true);

	m_currentActor = actor;
}

void ActorWidget::on_checkTranslucent_toggled(bool checked)
{
	if (!m_currentActor)
		return;

	m_currentActor->transparent = checked;
	m_charaItem->graphicsEffect()->setEnabled(checked);
}

void ActorWidget::on_pushApplyProfession_clicked()
{
	if (!m_currentActor)
		return;

	const lcf::rpg::Class &n_class = m_data.classes[static_cast<size_t>(ui->comboProfession->currentIndex())];
	/* Disconnect widgets */
	lcf::rpg::Actor *actor = m_currentActor;
	m_currentActor = nullptr;
	/* /Disconnect widgets */
	actor->class_id = ui->comboProfession->currentIndex();
	actor->attribute_ranks = n_class.attribute_ranks;
	actor->auto_battle = n_class.auto_battle;
	actor->battle_commands = n_class.battle_commands;
	actor->exp_base = n_class.exp_base;
	actor->exp_correction = n_class.exp_correction;
	actor->exp_inflation = n_class.exp_inflation;
	actor->lock_equipment = n_class.lock_equipment;
	actor->parameters = n_class.parameters;
	actor->skills = n_class.skills;
	actor->state_ranks = n_class.state_ranks;
	actor->super_guard = n_class.super_guard;
	actor->two_weapon = n_class.two_weapon;
	actor->battler_animation = n_class.battler_animation;
	/* /TODO */

	/* ConnectWidgets */
	on_currentActorChanged(actor);
}

void ActorWidget::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event)
	ui->graphicsHp->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsHp->size()));
	ui->graphicsMp->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsMp->size()));
	ui->graphicsAtt->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsAtt->size()));
	ui->graphicsDef->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsDef->size()));
	ui->graphicsInt->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsInt->size()));
	ui->graphicsAgy->scene()->setSceneRect(QRectF(QPointF(0,0),ui->graphicsAgy->size()));
}
