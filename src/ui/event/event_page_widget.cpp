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

#include "event_page_widget.h"
#include "ui_event_page_widget.h"
#include <QDialogButtonBox>
#include <QMessageBox>
#include "ui/common/charset_picker_dialog.h"
#include "core.h"
#include "stringizer.h"
#include "ui/commands/all_commands.h"
#include "common/dbstring.h"
#include "common/lcf_widget_binding.h"

EventPageWidget::EventPageWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QEventWidget),
	m_project(project)
{
	ui->setupUi(this);

	m_charaItem = new CharSetItem();
	m_tileItem = new QGraphicsPixmapItem();
	m_scene = new QGraphicsScene(this);
	m_effect = new QGraphicsOpacityEffect(this);
	m_charaItem->setGraphicsEffect(m_effect);
	m_tileItem->setGraphicsEffect(new QGraphicsOpacityEffect(m_effect));
	connect(m_effect,
			SIGNAL(enabledChanged(bool)),
			m_tileItem->graphicsEffect(),
			SLOT(setEnabled(bool)));
	m_charaItem->setScale(2.0);
	m_tileItem->setScale(2.0);
	m_scene->addItem(m_charaItem);
	m_scene->addItem(m_tileItem);
	m_scene->setBackgroundBrush(QBrush(QPixmap(":/embedded/share/old_grid.png")));
	ui->graphicsSprite->setScene(m_scene);

	auto& database = project.database();
	ui->comboSwitchA->makeModel(project);
	ui->comboSwitchB->makeModel(project);
	ui->comboVariable->makeModel(project);
	ui->comboItem->makeModel(project);
	ui->comboHero->makeModel(project);
}

EventPageWidget::~EventPageWidget()
{
	delete m_tileItem;
	delete m_charaItem;
	delete ui;
}
lcf::rpg::EventPage *EventPageWidget::eventPage() const
{
	return m_eventPage;
}

void EventPageWidget::setEventPage(lcf::rpg::EventPage *eventPage)
{
	m_eventPage = eventPage;
	ui->checkSwitchA->setChecked(eventPage->condition.flags.switch_a);
	ui->checkSwitchB->setChecked(eventPage->condition.flags.switch_b);
	ui->checkVar->setChecked(eventPage->condition.flags.variable);
	ui->comboVarOperation->setCurrentIndex(eventPage->condition.compare_operator);
	ui->spinVarValue->setValue(eventPage->condition.variable_value);
	ui->checkItem->setChecked(eventPage->condition.flags.item);
	ui->comboItem->setCurrentIndex(eventPage->condition.item_id-1);
	ui->checkHero->setChecked(eventPage->condition.flags.actor);
	ui->comboHero->setCurrentIndex(eventPage->condition.actor_id-1);
	ui->checkTimerA->setChecked(eventPage->condition.flags.timer);
	ui->spinTimerAMin->setValue(eventPage->condition.timer_sec/60);
	ui->spinTimerASec->setValue(eventPage->condition.timer_sec%60);
	ui->checkTimerB->setChecked(eventPage->condition.flags.timer2);
	ui->spinTimerBMin->setValue(eventPage->condition.timer2_sec/60);
	ui->spinTimerBSec->setValue(eventPage->condition.timer2_sec%60);
	ui->checkTransparent->setChecked(eventPage->translucent);
	ui->comboMoveType->setCurrentIndex(eventPage->move_type);
	ui->comboMoveSpeed->setCurrentIndex(eventPage->move_speed-1);
	ui->comboCondition->setCurrentIndex(eventPage->trigger);
	ui->comboLayer->setCurrentIndex(eventPage->layer);
	ui->checkOverlapForbidden->setChecked(eventPage->overlap_forbidden);
	ui->comboAnimationType->setCurrentIndex(eventPage->animation_type);
	ui->comboMoveFrequency->setCurrentIndex(eventPage->move_frequency-1);
	m_effect->setEnabled(m_eventPage->translucent);
	updateGraphic();

	ui->commands->setData(m_project, eventPage);
}

void EventPageWidget::on_comboMoveType_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	ui->label->setEnabled(index != 0);
	ui->comboMoveSpeed->setEnabled(index != 0);
	m_eventPage->move_type = index;
}

void EventPageWidget::on_checkSwitchA_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	if (checked) {
		int switchId = m_eventPage->condition.switch_a_id-1;
		//ui->lineSwitchA->setText(formatSwitchCondition(switchId));
	}
	else {
		//ui->lineSwitchA->setText("");
	}
	m_eventPage->condition.flags.switch_a = checked;
}

void EventPageWidget::on_checkSwitchB_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	if (checked) {
		int switchId = m_eventPage->condition.switch_b_id-1;
		//ui->lineSwitchB->setText(formatSwitchCondition(switchId));
	}
	else {
		//ui->lineSwitchB->setText("");
	}
	m_eventPage->condition.flags.switch_b = checked;
}

void EventPageWidget::on_checkVar_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	/*if (checked) {
		int varId = m_eventPage->condition.variable_id;
		if (varId >= 1 && varId <= static_cast<int>(core().project()->database().variables.size())) {
			ui->lineVar->setText(QString("%1: %2").arg(varId)
				.arg(ToQString
					 (core().project()->database().variables[static_cast<size_t>(varId) - 1].name)));
		}
		else {
			ui->lineVar->setText(QString("%1: ???").arg(varId));
		}
	}
	else {
		ui->lineVar->setText("");
	}*/
	m_eventPage->condition.flags.variable = checked;
}

void EventPageWidget::on_checkItem_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.flags.item = checked;
}

void EventPageWidget::on_comboVarOperation_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.compare_operator = index;
}

void EventPageWidget::on_spinVarValue_valueChanged(int arg1)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.variable_value = arg1;
}

void EventPageWidget::on_comboItem_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.item_id = index+1;
}

void EventPageWidget::on_comboHero_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.actor_id = index+1;
}

void EventPageWidget::on_checkHero_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.flags.item = checked;
}

void EventPageWidget::on_checkTimerA_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.flags.timer = checked;
}

void EventPageWidget::on_spinTimerAMin_valueChanged(int arg1)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.timer_sec = arg1*60 + ui->spinTimerASec->value();
}

void EventPageWidget::on_spinTimerASec_valueChanged(int arg1)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.timer_sec = ui->spinTimerAMin->value()*60 + arg1;
}

void EventPageWidget::on_checkTimerB_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.flags.timer2 = checked;
}

void EventPageWidget::on_spinTimerBMin_valueChanged(int arg1)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.timer2_sec = arg1*60 + ui->spinTimerBSec->value();
}

void EventPageWidget::on_spinTimerBSec_valueChanged(int arg1)
{
	if (!m_eventPage)
		return;
	m_eventPage->condition.timer2_sec = ui->spinTimerBMin->value()*60 + arg1;
}

void EventPageWidget::on_checkTransparent_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->translucent = checked;
	m_effect->setEnabled(checked);
}

void EventPageWidget::on_comboMoveSpeed_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->move_speed = index+1;
}

void EventPageWidget::on_comboCondition_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->trigger = index;
}

void EventPageWidget::on_comboLayer_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->layer = index;
}

void EventPageWidget::on_checkOverlapForbidden_toggled(bool checked)
{
	if (!m_eventPage)
		return;
	m_eventPage->overlap_forbidden = checked;
}

void EventPageWidget::on_comboAnimationType_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->animation_type = index;
}

void EventPageWidget::on_comboMoveFrequency_currentIndexChanged(int index)
{
	if (!m_eventPage)
		return;
	m_eventPage->move_frequency = index+1;
}

void EventPageWidget::on_pushSetSprite_clicked()
{
	CharSetPickerDialog dlg(this, true);
	dlg.setName(ToQString(m_eventPage->character_name));
	dlg.setFrame(m_eventPage->character_pattern);
	dlg.setFacing(m_eventPage->character_direction);
	dlg.setIndex(m_eventPage->character_index);
	dlg.exec();
	if (dlg.result() == QDialogButtonBox::Ok)
	{
		m_eventPage->character_name = ToDBString(dlg.name());
		m_eventPage->character_pattern = dlg.frame();
		m_eventPage->character_direction = dlg.facing();
		m_eventPage->character_index = dlg.index();
		updateGraphic();
	}
}

void EventPageWidget::updateGraphic()
{
	if (m_eventPage->character_name.empty())
	{
		QPixmap pix(16,16);
		pix.fill(QColor(0,0,0,0));
		core().beginPainting(pix);
		core().renderTile(10000 + static_cast<short>(m_eventPage->character_index), QRect(0,0,16,16));
		core().endPainting();
		m_tileItem->setPixmap(pix);
		m_tileItem->setVisible(true);
		m_charaItem->setVisible(false);
		m_scene->setSceneRect(0,0,32,32);
	}
	else
	{
		m_charaItem->setBasePix(ToQString(m_eventPage->character_name));
		m_charaItem->setIndex(m_eventPage->character_index);
		m_charaItem->setFrame(m_eventPage->character_pattern);
		m_charaItem->setFacing(m_eventPage->character_direction);
		m_tileItem->setVisible(false);
		m_charaItem->setVisible(true);
		m_scene->setSceneRect(0,0,48,64);
	}
}
