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
#include "ui/common/rpg_spinbox.h"
#include <QWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QButtonGroup>

class EventCommandBaseWidget;

class OperandWidgetBase : public QWidget {
	Q_OBJECT
public:
	explicit OperandWidgetBase(QWidget *parent = nullptr) : QWidget(parent) {}

	virtual void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand&, int idx_operand, int idx_value);

protected:
	virtual void parameterChanged(int index, int new_value) {
		Q_UNUSED(index)
		Q_UNUSED(new_value)
	}

	ProjectData* m_project = nullptr;
	lcf::rpg::EventCommand* m_cmd = nullptr;

	struct {
		int operand = 0;
		int value = 0;
	} m_operation;
};

template <typename LCF>
class OperandWidget : public OperandWidgetBase {
public:
	OperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override {
		OperandWidgetBase::attach(base_widget, project, cmd, idx_operand, idx_value);

		int op = cmd.parameters[idx_operand];

		m_comboValue->makeModel(project);
		base_widget.connectParameterHandler(m_comboValue, idx_value, op == 0);

		m_comboVar->makeModel(project);
		base_widget.connectParameterHandler(m_comboVar, idx_value, op == 1);

		base_widget.connectParameterHandler(m_buttonGroup, idx_operand);
	}

	void parameterChanged(int index, int new_value) override {
		if (index == m_operation.operand) {
			m_comboValue->setEnabled(new_value == 0);
			m_comboVar->setEnabled(new_value == 1);

			if (new_value == 0) {
				m_cmd->parameters[m_operation.value] = m_comboValue->comboBox()->currentIndex() + 1;
			} else if (new_value == 1) {
				m_cmd->parameters[m_operation.value] = m_comboVar->comboBox()->currentIndex() + 1;
			}
		}
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

	// FIXME: translation does not work without QCoreApplication::translate
	m_radioValue = new QRadioButton(this);
	m_radioValue->setText(QCoreApplication::translate("OperandWidget", "Specific") + ":");
	m_radioVar = new QRadioButton(this);
	m_radioVar->setText(QCoreApplication::translate("OperandWidget", "By Variable") + ":");
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

class PartyOperandWidget : public OperandWidgetBase {
	Q_OBJECT
public:
	PartyOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override;

protected:
	void parameterChanged(int index, int new_value) override;

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioParty = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgComboBox<lcf::rpg::Actor>* m_comboValue = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

class ValueOperandWidget : public OperandWidgetBase {
	Q_OBJECT
public:
	ValueOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override;

protected:
	void parameterChanged(int index, int new_value) override;

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgSpinBox* m_spinValue = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

class TimerOperandWidget : public OperandWidgetBase {
	Q_OBJECT
public:
	TimerOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override;

protected:
	void parameterChanged(int index, int new_value) override;

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgSpinBox* m_spinMin = nullptr;
	RpgSpinBox* m_spinSec = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

template <typename LCF>
class OperationOperandWidget : public OperandWidgetBase {
public:
	OperationOperandWidget(QWidget *parent);

	void attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) override {
		OperandWidgetBase::attach(base_widget, project, cmd, idx_operand, idx_value);

		int op = cmd.parameters[idx_operand];

		m_comboValue->makeModel(project);
		base_widget.connectParameterHandler(m_comboValue, idx_value, op == 0);

		base_widget.connectParameterHandler(m_spinBatchMin, idx_value, op == 1);
		base_widget.connectParameterHandler(m_spinBatchMax, idx_value + 1, op == 1);

		m_comboVar->makeModel(project);
		base_widget.connectParameterHandler(m_comboVar, idx_value, op == 2);

		base_widget.connectParameterHandler(m_buttonGroup, idx_operand);
	}

	void parameterChanged(int index, int new_value) override {
		if (index == m_operation.operand) {
			m_comboValue->setEnabled(new_value == 0);
			m_spinBatchMin->setEnabled(new_value == 1);
			m_spinBatchMax->setEnabled(new_value == 1);
			m_comboVar->setEnabled(new_value == 2);

			if (new_value == 0) {
				m_cmd->parameters[m_operation.value] = m_comboValue->comboBox()->currentIndex() + 1;
			} else if (new_value == 1) {
				m_cmd->parameters[m_operation.value] = m_spinBatchMin->value();
				m_cmd->parameters[m_operation.value + 1] = m_spinBatchMax->value();
			} else if (new_value == 2) {
				m_cmd->parameters[m_operation.value] = m_comboVar->comboBox()->currentIndex() + 1;
			}
		}
	}

private:
	QButtonGroup* m_buttonGroup = nullptr;
	QRadioButton* m_radioValue = nullptr;
	QRadioButton* m_radioBatch = nullptr;
	QRadioButton* m_radioVar = nullptr;
	RpgComboBox<LCF>* m_comboValue = nullptr;
	RpgSpinBox* m_spinBatchMin = nullptr;
	RpgSpinBox* m_spinBatchMax = nullptr;
	VariableRpgComboBox* m_comboVar = nullptr;
};

template <class LCF>
OperationOperandWidget<LCF>::OperationOperandWidget(QWidget *parent) :
	OperandWidgetBase(parent)
{
	auto* gridLayout = new QGridLayout(this);

	// FIXME: translation does not work without QCoreApplication::translate
	m_radioValue = new QRadioButton(this);
	m_radioValue->setText(QCoreApplication::translate("OperationOperandWidget", "Specific") + ":");
	m_radioBatch = new QRadioButton(this);
	m_radioBatch->setText(QCoreApplication::translate("OperationOperandWidget", "Range") + ":");
	m_radioVar = new QRadioButton(this);
	m_radioVar->setText(QCoreApplication::translate("OperationOperandWidget", "By Variable") + ":");
	m_spinBatchMin = new RpgSpinBox(this);
	m_spinBatchMin->setPrefix(QCoreApplication::translate("OperationOperandWidget", "From") + " ");
	m_spinBatchMax = new RpgSpinBox(this);
	m_spinBatchMax->setPrefix(QCoreApplication::translate("OperationOperandWidget", "To") + " ");
	m_buttonGroup = new QButtonGroup(this);
	m_buttonGroup->addButton(m_radioValue);
	m_buttonGroup->setId(m_radioValue, 0);
	m_buttonGroup->addButton(m_radioBatch);
	m_buttonGroup->setId(m_radioBatch, 1);
	m_buttonGroup->addButton(m_radioVar);
	m_buttonGroup->setId(m_radioVar, 2);
	m_comboValue = new RpgComboBox<LCF>(this);
	m_comboVar = new VariableRpgComboBox(this);
	gridLayout->addWidget(m_radioValue, 0, 0);
	gridLayout->addWidget(m_comboValue, 0, 1);
	gridLayout->addWidget(m_radioBatch, 1, 0);
	auto* hboxLayout = new QHBoxLayout(this);
	hboxLayout->addWidget(m_spinBatchMin);
	hboxLayout->addWidget(m_spinBatchMax);
	hboxLayout->addSpacing(0);
	gridLayout->addLayout(hboxLayout, 1, 1);
	gridLayout->addWidget(m_radioVar, 2, 0);
	gridLayout->addWidget(m_comboVar, 2, 1);
}

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
using SwitchOperationOperandWidget = OperationOperandWidget<lcf::rpg::Switch>;
using VariableOperationOperandWidget = OperationOperandWidget<lcf::rpg::Variable>;
