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
#include <QGraphicsOpacityEffect>
#include <QSortFilterProxyModel>

#include "common/dbstring.h"
#include "common/lcf_widget_binding.h"
#include "model/actor.h"
#include "ui/picker/picker_dialog.h"
#include "ui/picker/picker_charset_widget.h"
#include "ui/picker/picker_faceset_widget.h"

ActorWidget::ActorWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ActorWidget),
	m_project(project)
{
	auto& database = project.database();

	const auto kMaxLevel = database.system.ldb_id == 2003 ? 99 : 50;
	const auto kMaxHp = database.system.ldb_id == 2003 ? 9999 : 999;
	ui->setupUi(this);

	m_current = nullptr;

	ui->spinMaxLv->setMaximum(kMaxLevel);

	ui->graphicsBattleset->setScene(new QGraphicsScene(this));

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

	UpdateModels();

	/*FIXME if (database.system.ldb_id != 2003) {
		for (int i = 0; i < ui->gridBattleSet->count(); ++i) {
			ui->gridBattleSet->itemAt(i)->widget()->hide();
		}
		ui->groupBoxClass->hide();
	}*/

	for (auto& uis : { ui->lineName, ui->lineTitle }) {
		LcfWidgetBinding::connect(this, uis);
	}

	for (auto& uis : {
			ui->checkAI,
			ui->checkDualWeapon,
			ui->checkFixedEquip,
			ui->checkStrongDefense,
			ui->checkTranslucent }) {
		LcfWidgetBinding::connect<bool>(this, uis);
	}

	for (auto& uis : {
			ui->spinMinLv,
			ui->spinMaxLv,
			ui->spinCritChance }) {
		LcfWidgetBinding::connect<int32_t>(this, uis);
	}

	for (auto& uis : {
			ui->comboInitialWeapon,
			ui->comboInitialShield,
			ui->comboInitialArmor,
			ui->comboInitialHelmet,
			ui->comboInitialMisc }) {
		LcfWidgetBinding::connect<int16_t>(this, uis);
		uis->makeModel(project);
	}

	LcfWidgetBinding::connect<bool>(this, ui->groupCritChance);

	LcfWidgetBinding::connect<int32_t>(this, ui->comboUnarmedAnimation);
	ui->comboUnarmedAnimation->makeModel(project);

	// GraphicViews
	m_charsetItem = new CharSetGraphicsItem(project);
	m_charsetItem->setSpin(true);
	m_charsetItem->setWalk(true);
	m_charsetItem->setGraphicsEffect(new QGraphicsOpacityEffect(this));
	ui->graphicsCharset->scale(2.0, 2.0);
	ui->graphicsCharset->setItem(m_charsetItem);
	ui->graphicsCharset->enableTimer();
	QObject::connect(ui->graphicsCharset, &RpgGraphicsViewBase::clicked, this, &ActorWidget::charSetClicked);

	m_faceItem = new FaceSetGraphicsItem(project);
	ui->graphicsFaceset->scale(2.0, 2.0);
	ui->graphicsFaceset->setItem(m_faceItem);
	QObject::connect(ui->graphicsFaceset, &RpgGraphicsViewBase::clicked, this, &ActorWidget::faceSetClicked);
}

void ActorWidget::setData(lcf::rpg::Actor* actor) {
	on_currentActorChanged(actor);
}

ActorWidget::~ActorWidget()
{
	delete ui;
}

void ActorWidget::UpdateModels()
{
	auto& database = m_project.database();

	/* Clear */
	ui->comboBattleset->clear();
	ui->listAttributeRanks->clear();
	ui->listStatusRanks->clear();
	/* Fill */
	ui->comboBattleset->addItem(tr("<none>"));
	for (unsigned int i = 0; i < database.battleranimations.size(); i++)
		ui->comboBattleset->addItem(database.battleranimations[i].name.c_str());
	ui->comboProfession->addItem(tr("<none>"));
	for (unsigned int i = 0; i < database.classes.size(); i++)
		ui->comboProfession->addItem(database.classes[i].name.c_str());
	for (unsigned int i = 0; i < database.attributes.size(); i++)
		ui->listAttributeRanks->addItem(database.attributes[i].name.c_str());
	for (unsigned int i = 0; i < database.states.size(); i++)
		ui->listStatusRanks->addItem(database.states[i].name.c_str());
}

void ActorWidget::on_comboBattleset_currentIndexChanged(int index)
{
	if (!m_current)
		return;

	m_current->battler_animation = index;

	auto& database = m_project.database();

	if (index <= 0 || index >= static_cast<int>(database.battleranimations.size()))
		m_battlerItem->setBasePix(BattleAnimationItem::Battler,"");
	else
		m_battlerItem->setDemoAnimation(database.battleranimations[static_cast<size_t>(index) - 1]);
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
	if (!actor) {
		actor = &dummy;
	}
	m_current = actor;

	auto& database = m_project.database();

	ResetExpText(actor);

	LcfWidgetBinding::bind(ui->lineName, actor->name);
	LcfWidgetBinding::bind(ui->lineTitle, actor->title);
	LcfWidgetBinding::bind(ui->checkAI, actor->auto_battle);
	LcfWidgetBinding::bind(ui->checkDualWeapon, actor->two_weapon);
	LcfWidgetBinding::bind(ui->checkFixedEquip, actor->lock_equipment);
	LcfWidgetBinding::bind(ui->checkStrongDefense, actor->super_guard);
	LcfWidgetBinding::bind(ui->checkTranslucent, actor->transparent);
	LcfWidgetBinding::bind(ui->spinMinLv, actor->initial_level);
	LcfWidgetBinding::bind(ui->spinMaxLv, actor->final_level);
	LcfWidgetBinding::bind(ui->spinCritChance, actor->critical_hit_chance);
	LcfWidgetBinding::bind(ui->groupCritChance, actor->critical_hit);
	LcfWidgetBinding::bind(ui->comboUnarmedAnimation, actor->unarmed_animation);

	auto equipFilter = [&](auto& cbox, auto type) {
		SignalBlocker s(cbox->comboBox());
		cbox->setFilter(ActorModel(m_project, *m_current).CreateEquipmentFilter(type));
	};

	equipFilter(ui->comboInitialWeapon, lcf::rpg::Item::Type_weapon);
	equipFilter(ui->comboInitialShield, lcf::rpg::Item::Type_shield);
	equipFilter(ui->comboInitialArmor, lcf::rpg::Item::Type_armor);
	equipFilter(ui->comboInitialHelmet, lcf::rpg::Item::Type_helmet);
	equipFilter(ui->comboInitialMisc, lcf::rpg::Item::Type_accessory);

	LcfWidgetBinding::bind(ui->comboInitialWeapon, actor->initial_equipment.weapon_id);
	LcfWidgetBinding::bind(ui->comboInitialShield, actor->initial_equipment.shield_id);
	LcfWidgetBinding::bind(ui->comboInitialHelmet, actor->initial_equipment.helmet_id);
	LcfWidgetBinding::bind(ui->comboInitialArmor, actor->initial_equipment.armor_id);
	LcfWidgetBinding::bind(ui->comboInitialMisc, actor->initial_equipment.accessory_id);

	ui->comboBattleset->setCurrentIndex(actor->battler_animation);

	ui->comboProfession->setCurrentIndex(actor->class_id);
	ui->tableSkills->setRowCount(0);
	for (int i = 0; i < static_cast<int>(actor->skills.size()); i++){
		ui->tableSkills->insertRow(i);
		ui->tableSkills->setItem(i,0,new QTableWidgetItem());
		ui->tableSkills->setItem(i,1,new QTableWidgetItem());
		ui->tableSkills->item(i, 0)->setText(QString::number(actor->skills[static_cast<size_t>(i)].level));
		// TODO: move getSkillName to Core
		QString name = QString("<%1?>").arg(actor->skills[static_cast<size_t>(i)].skill_id);
		if (actor->skills[static_cast<size_t>(i)].skill_id < static_cast<int>(database.skills.size()))
			name = database.skills[static_cast<size_t>(actor->skills[static_cast<size_t>(i)].skill_id)-1].name.c_str();
		// TODO/
		ui->tableSkills->item(i, 1)->setText(name);
	}
	ui->tableSkills->insertRow(static_cast<int>(actor->skills.size()));
	for (int i = 0; i < ui->listAttributeRanks->count(); i++)
	{
		if (i >= static_cast<int>(actor->attribute_ranks.size()))
			ui->listAttributeRanks->item(static_cast<int>(i))->setIcon(QIcon(":/ranks/rank2"));
		else
			ui->listAttributeRanks->item(static_cast<int>(i))->setIcon(QIcon(QString(":/ranks/rank%1").arg(static_cast<int>(actor->attribute_ranks[static_cast<size_t>(i)]))));
	}
	for (int i = 0; i < ui->listStatusRanks->count(); i++)
	{
		if (i >= static_cast<int>(actor->state_ranks.size()))
			ui->listStatusRanks->item(i)->setIcon(QIcon(":/ranks/rank2"));
		else
			ui->listStatusRanks->item(i)->setIcon(QIcon(QString(":/ranks/rank%1").arg(static_cast<int>(actor->state_ranks[static_cast<size_t>(i)]))));
	}

	if (actor->battler_animation <= 0 ||
			actor->battler_animation >= static_cast<int>(database.battleranimations.size()))
		m_battlerItem->setBasePix(BattleAnimationItem::Battler,"");
	else
		m_battlerItem->setDemoAnimation(database.battleranimations[static_cast<size_t>(actor->battler_animation)-1]);

	m_hpItem->setData(actor->parameters.maxhp);
	m_mpItem->setData(actor->parameters.maxsp);
	m_attItem->setData(actor->parameters.attack);
	m_defItem->setData(actor->parameters.defense);
	m_intItem->setData(actor->parameters.spirit);
	m_agyItem->setData(actor->parameters.agility);

	// GraphicViews
	m_faceItem->refresh(*actor);
	m_charsetItem->refresh(*actor);
	m_charsetItem->graphicsEffect()->setEnabled(actor->transparent);

	this->setEnabled(actor != &dummy);
}

void ActorWidget::on_pushApplyProfession_clicked()
{
	if (!m_current)
		return;

	const lcf::rpg::Class &n_class = m_project.database().classes[static_cast<size_t>(ui->comboProfession->currentIndex())];
	/* Disconnect widgets */
	lcf::rpg::Actor *actor = m_current;
	m_current = nullptr;
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

void ActorWidget::on_listStatusRanks_clicked() {
	if (!m_current) {
		return;
	}

	int index = ui->listStatusRanks->currentRow();
	if (m_current->state_ranks.size() <= index) {
		for (int i = m_current->state_ranks.size(); i <= index; i++) {
			m_current->state_ranks.push_back(2);
		}
	}
	int rank = m_current->state_ranks[index];
	rank = (rank + 1) % 5;
	m_current->state_ranks[index] = rank;
	ui->listStatusRanks->item(index)->setIcon(QIcon(QString(":/ranks/rank%1").arg(rank)));

	if (index == m_current->state_ranks.size() - 1 && rank == 2) {
		m_current->state_ranks.pop_back();
		for (int i = m_current->state_ranks.size() - 1; i >= 0; i--) {
			if (m_current->state_ranks[i] == 2) {
				m_current->state_ranks.pop_back();
			} else {
				break;
			}
		}
	}
}

void ActorWidget::on_listAttributeRanks_clicked() {
	if (!m_current) {
		return;
	}

	int index = ui->listAttributeRanks->currentRow();
	if (m_current->attribute_ranks.size() <= index) {
		for (int i = m_current->attribute_ranks.size(); i <= index; i++) {
			m_current->attribute_ranks.push_back(2);
		}
	}
	int rank = m_current->attribute_ranks[index];
	rank = (rank + 1) % 5;
	m_current->attribute_ranks[index] = rank;
	ui->listAttributeRanks->item(index)->setIcon(QIcon(QString(":/ranks/rank%1").arg(rank)));

	if (index == m_current->attribute_ranks.size() - 1 && rank == 2) {
		m_current->attribute_ranks.pop_back();
		for (int i = m_current->attribute_ranks.size() - 1; i >= 0; i--) {
			if (m_current->attribute_ranks[i] == 2) {
				m_current->attribute_ranks.pop_back();
			} else {
				break;
			}
		}
	}
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

void ActorWidget::faceSetClicked() {
	auto* widget = new PickerFacesetWidget(m_current->face_index, this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_current->face_name = ToDBString(baseName);
		m_current->face_index = widget->index();
		m_faceItem->refresh(*m_current);
	});
	dialog.setDirectoryAndFile(FACESET, ToQString(m_current->face_name));
	dialog.exec();
}

void ActorWidget::charSetClicked() {
	auto* widget = new PickerCharsetWidget(m_current->character_index, this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_current->character_name = ToDBString(baseName);
		m_current->character_index = widget->index();
		m_charsetItem->refresh(*m_current);
	});
	dialog.setDirectoryAndFile(CHARSET, ToQString(m_current->character_name));
	dialog.exec();
}
