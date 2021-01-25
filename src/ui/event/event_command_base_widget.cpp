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

#include "event_command_base_widget.h"
#include "common/lcf_widget_binding.h"
#include "ui/common/operand_widget.h"
#include "model/event_command_list.h"
#include <QLineEdit>
#include <QButtonGroup>

EventCommandBaseWidget::EventCommandBaseWidget(ProjectData& project, QWidget* parent) :
	QWidget(parent), m_project(project) {
	setObjectName("EventWidget");
}

void EventCommandBaseWidget::setData(lcf::rpg::EventCommand* cmd) {
	this->cmd = cmd;

	for (auto& widget: findChildren<QLineEdit*>()) {
		auto idx = widget->objectName().indexOf("_argX");
		if (idx != -1) {
			connect(widget, &QLineEdit::textEdited, this,
					[=] (auto text) {
				cmd->string = lcf::DBString(ToDBString(text));
				stringParameterChanged(text);
			});

			widget->setText(QString(ToQString(cmd->string)));
		}
	}

	for (auto& widget: findChildren<QSpinBox*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QSpinBox does not support string arg");
			} else {
				connectParameterHandler(widget, val);
			}
		}
	}

	for (auto& widget: findChildren<QCheckBox*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QCheckBox does not support string arg");
			} else {
				connectParameterHandler(widget, val);
			}
		}
	}

	for (auto& widget: findChildren<RpgComboBoxBase*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QComboBox does not support string arg");
			} else {
				connectParameterHandler(widget, val);
			}
		}
	}

	for (auto& widget: findChildren<QButtonGroup*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QButtonGroup does not support string arg");
			} else {
				connectParameterHandler(widget, val);
			}
		}
	}

	for (auto& widget: findChildren<OperandWidgetBase*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "OperandWidgetBase does not support string arg");
			} else {
				widget->attach(*this, m_project, *cmd, val, val + 1);
			}
		}
	}
}

void EventCommandBaseWidget::setData(EventCommandList* commands) {
	m_commands = commands;
	setData(&commands->command());
}

void EventCommandBaseWidget::connectParameterHandler(QButtonGroup* group, int index) {
	auto* button = group->button(cmd->parameters[index]);
	// FIXME: Better fallback
	Q_ASSERT(button && "No AbstractButton with this parameter value");

	connect(group, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled), this,
		[=](QAbstractButton*, bool checked) {

		if (checked) {
			int id = group->checkedId();
			Q_ASSERT(id >= 0 && "AbstractButton must have an ID that corresponds to the parameter value");
			cmd->parameters[index] = id;
			emit parameterChanged(index, id);
		}
	});

	button->setChecked(true);
}

void EventCommandBaseWidget::connectParameterHandler(RpgComboBoxBase* combo, int index) {
	connect(combo->comboBox(), QOverload<int>::of(&QComboBox::currentIndexChanged), this,
		[=](int selected_index){
		cmd->parameters[index] = selected_index + 1;
		emit parameterChanged(index, selected_index + 1);
	});

	combo->comboBox()->setCurrentIndex(cmd->parameters[index] - 1);
}

void EventCommandBaseWidget::connectParameterHandler(QSpinBox *spin, int index) {
	connect(spin, qOverload<int>(&QSpinBox::valueChanged), this,
			[=] (int new_value) {
		cmd->parameters[index] = new_value;
		emit parameterChanged(index, new_value);
	});

	spin->setValue(cmd->parameters[index]);
}

void EventCommandBaseWidget::connectParameterHandler(QCheckBox* check, int index) {
	connect(check, qOverload<int>(&QCheckBox::stateChanged), this,
			[=] (int new_value) {
		cmd->parameters[index] = new_value;
		emit parameterChanged(index, new_value);
	});

	check->setChecked(cmd->parameters[index] != 0);
}
