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

#include "operand_widget.h"

void OperandWidgetBase::attach(EventCommandBaseWidget& base, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) {
	m_project = &project;
	m_cmd = &cmd;
	m_operation.operand = idx_operand;
	m_operation.value = idx_value;

	connect(&base, &EventCommandBaseWidget::parameterChanged, this, &OperandWidgetBase::parameterChanged);
}

PartyOperandWidget::PartyOperandWidget(QWidget *parent) :
	OperandWidgetBase(parent)
{
	auto* gridLayout = new QGridLayout(this);

	m_radioParty = new QRadioButton(this);
	m_radioParty->setText("Entiry Party");
	m_radioValue = new QRadioButton(this);
	m_radioValue->setText("Specific:");
	m_radioVar = new QRadioButton(this);
	m_radioVar->setText("By Variable:");
	m_buttonGroup = new QButtonGroup(this);
	m_buttonGroup->addButton(m_radioParty);
	m_buttonGroup->setId(m_radioParty, 0);
	m_buttonGroup->addButton(m_radioValue);
	m_buttonGroup->setId(m_radioValue, 1);
	m_buttonGroup->addButton(m_radioVar);
	m_buttonGroup->setId(m_radioVar, 2);
	m_comboValue = new RpgComboBox<lcf::rpg::Actor>(this);
	m_comboVar = new VariableRpgComboBox(this);
	gridLayout->addWidget(m_radioParty, 0, 0);
	gridLayout->addWidget(m_radioValue, 1, 0);
	gridLayout->addWidget(m_comboValue, 1, 1);
	gridLayout->addWidget(m_radioVar, 2, 0);
	gridLayout->addWidget(m_comboVar, 2, 1);
}

void PartyOperandWidget::attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) {
	OperandWidgetBase::attach(base_widget, project, cmd, idx_operand, idx_value);

	base_widget.connectParameterHandler(m_buttonGroup, idx_operand);

	m_comboValue->makeModel(project);
	base_widget.connectParameterHandler(m_comboValue, idx_value);

	m_comboVar->makeModel(project);
	base_widget.connectParameterHandler(m_comboVar, idx_value);
}

void PartyOperandWidget::parameterChanged(int index, int new_value) {
	if (index == m_operation.operand) {
		m_comboValue->setEnabled(new_value == 1);
		m_comboVar->setEnabled(new_value == 2);
	}
}

ValueOperandWidget::ValueOperandWidget(QWidget *parent) :
	OperandWidgetBase(parent)
{
	auto* gridLayout = new QGridLayout(this);

	m_radioValue = new QRadioButton(this);
	m_radioValue->setText("Constant:");
	m_radioVar = new QRadioButton(this);
	m_radioVar->setText("By Variable:");
	m_buttonGroup = new QButtonGroup(this);
	m_buttonGroup->addButton(m_radioValue);
	m_buttonGroup->setId(m_radioValue, 0);
	m_buttonGroup->addButton(m_radioVar);
	m_buttonGroup->setId(m_radioVar, 1);
	m_spinValue = new RpgSpinBox(this);
	m_comboVar = new VariableRpgComboBox(this);
	gridLayout->addWidget(m_radioValue, 0, 0);
	gridLayout->addWidget(m_spinValue, 0, 1);
	gridLayout->addWidget(m_radioVar, 1, 0);
	gridLayout->addWidget(m_comboVar, 1, 1);
}

void ValueOperandWidget::attach(EventCommandBaseWidget& base_widget, ProjectData& project, lcf::rpg::EventCommand& cmd, int idx_operand, int idx_value) {
	OperandWidgetBase::attach(base_widget, project, cmd, idx_operand, idx_value);

	base_widget.connectParameterHandler(m_buttonGroup, idx_operand);

	base_widget.connectParameterHandler(m_spinValue, idx_value);

	m_comboVar->makeModel(project);
	base_widget.connectParameterHandler(m_comboVar, idx_value);
}

void ValueOperandWidget::parameterChanged(int index, int new_value) {
	if (index == m_operation.operand) {
		m_spinValue->setEnabled(new_value == 0);
		m_comboVar->setEnabled(new_value == 1);
	}
}
