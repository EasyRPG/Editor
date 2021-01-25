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

#include "common/lcf_widget_binding.h"
#include "ui/event/event_command_base_widget.h"
#include <QWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QButtonGroup>

class EventCommandBaseWidget;

class OperandWidgetBase : public QWidget {
	Q_OBJECT
public:
	explicit OperandWidgetBase(QWidget *parent = nullptr) : QWidget(parent) {}

	virtual void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand&, int idx_operand, int idx_value);

protected:
	ProjectData* m_project = nullptr;
	lcf::rpg::EventCommand* m_cmd = nullptr;

	struct {
		int operand = 0;
		int value = 0;
	} m_operation;
};

template <typename LCF>
class OperandWidget : public OperandWidgetBase
{
public:
	OperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override {
		OperandWidgetBase::attach(base_widget, project, cmd, idx_operand, idx_value);

		base_widget.connectParameterHandler(m_buttonGroup, idx_operand);

		m_comboValue->makeModel(project);
		base_widget.connectParameterHandler(m_comboValue, idx_value);

		m_comboVar->makeModel(project);
		base_widget.connectParameterHandler(m_comboVar, idx_value);
	}

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgComboBox<LCF>* m_comboValue = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

template <class LCF>
OperandWidget<LCF>::OperandWidget(QWidget *parent) :
	OperandWidgetBase(parent)
{
	auto* gridLayout = new QGridLayout(this);

	m_radioValue = new QRadioButton(this);
	m_radioValue->setText("Specific:");
	m_radioVar = new QRadioButton(this);
	m_radioVar->setText("By Variable:");
	m_buttonGroup = new QButtonGroup(this);
	m_buttonGroup->addButton(m_radioValue);
	m_buttonGroup->setId(m_radioValue, 0);
	m_buttonGroup->addButton(m_radioVar);
	m_buttonGroup->setId(m_radioVar, 1);
	m_comboValue = new RpgComboBox<LCF>(this);
	m_comboVar = new VariableRpgComboBox(this);
	gridLayout->addWidget(m_radioValue, 0, 0);
	gridLayout->addWidget(m_comboValue, 0, 1);
	gridLayout->addWidget(m_radioVar, 1, 0);
	gridLayout->addWidget(m_comboVar, 1, 1);
}

class PartyOperandWidget : public OperandWidgetBase
{
public:
	PartyOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override;

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioParty = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgComboBox<lcf::rpg::Actor>* m_comboValue = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

class ValueOperandWidget : public OperandWidgetBase
{
public:
	ValueOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override;

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	QSpinBox* m_spinValue = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

using ActorOperandWidget = OperandWidget<lcf::rpg::Actor>;
using SkillOperandWidget = OperandWidget<lcf::rpg::Skill>;
using ItemOperandWidget = OperandWidget<lcf::rpg::Item>;
using EnemyOperandWidget = OperandWidget<lcf::rpg::Enemy>;
using TroopOperandWidget = OperandWidget<lcf::rpg::Troop>;
using TerrainOperandWidget = OperandWidget<lcf::rpg::Terrain>;
using AttributeOperandWidget = OperandWidget<lcf::rpg::Attribute>;
using StateOperandWidget = OperandWidget<lcf::rpg::State>;
using AnimationOperandWidget = OperandWidget<lcf::rpg::Animation>;
using ChipsetOperandWidget = OperandWidget<lcf::rpg::Chipset>;
using CommonEventOperandWidget = OperandWidget<lcf::rpg::CommonEvent>;
using ClassOperandWidget = OperandWidget<lcf::rpg::Class>;
using BattlerAnimationOperandWidget = OperandWidget<lcf::rpg::BattlerAnimation>;
using SwitchOperandWidget = OperandWidget<lcf::rpg::Switch>;
using VariableOperandWidget = OperandWidget<lcf::rpg::Variable>;
