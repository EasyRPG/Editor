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
#include <QLineEdit>
#include <QButtonGroup>

EventCommandBaseWidget::EventCommandBaseWidget(ProjectData& project, QWidget* parent) :
	QWidget(parent), m_project(project) {

}

void EventCommandBaseWidget::setData(lcf::rpg::EventCommand* cmd) {
	this->cmd = cmd;

	for (auto& widget: findChildren<QLineEdit*>()) {
		auto idx = widget->objectName().indexOf("_argX");
		if (idx != -1) {
			LcfWidgetBinding::connect(this, widget);
			LcfWidgetBinding::bind(widget, cmd->string);
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
				LcfWidgetBinding::connect<int32_t>(this, widget);
				LcfWidgetBinding::bind(widget, *(cmd->parameters.data() + val));
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
				LcfWidgetBinding::connect<int32_t>(this, widget);
				LcfWidgetBinding::bind(widget, *(cmd->parameters.data() + val));
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
				LcfWidgetBinding::connect<int32_t>(this, widget->comboBox());
				LcfWidgetBinding::bind(widget->comboBox(), *(cmd->parameters.data() + val));
			}
		}
	}

	for (auto& widget: findChildren<QButtonGroup*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QComboBox does not support string arg");
			} else {
				LcfWidgetBinding::connect<int32_t>(this, widget);
				LcfWidgetBinding::bind(widget, *(cmd->parameters.data() + val));
			}
		}
	}

	for (auto& widget: findChildren<OperandWidgetBase*>()) {
		auto idx = widget->objectName().indexOf("_arg");
		if (idx != -1) {
			QString arg = widget->objectName().right(1);
			int val = arg.toInt(nullptr, 10);

			if (arg == "X") {
				Q_ASSERT(false && "QComboBox does not support string arg");
			} else {
				widget->attach(m_project, *cmd, val, val + 1);
			}
		}
	}
}
