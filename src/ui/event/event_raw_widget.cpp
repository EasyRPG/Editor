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

#include "event_raw_widget.h"
#include "ui_event_raw_widget.h"
#include "common/lcf_widget_binding.h"

EventRawWidget::EventRawWidget(ProjectData& project, QWidget* parent) :
	QWidget(parent),
	m_project(project), ui(new Ui::EventRawWidget)
{
	ui->setupUi(this);

	LcfWidgetBinding::connect(this, ui->lineString);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinCode);
}

EventRawWidget::~EventRawWidget() {
	delete ui;
}

void EventRawWidget::on_buttonAddNum_clicked() {
	int index = cmd->parameters.size();
	auto new_arr = lcf::DBArray<int32_t>(index + 1);
	std::copy(cmd->parameters.begin(), cmd->parameters.end(), new_arr.begin());
	cmd->parameters = new_arr;

	for (size_t i = 0; i < cmd->parameters.size() - 1; ++i) {
		QSpinBox *spin = static_cast<QSpinBox*>(ui->gridLayoutNum->itemAtPosition(i, 1)->widget());
		LcfWidgetBinding::connect<int32_t>(this, spin);
		LcfWidgetBinding::bind(spin, cmd->parameters[i]);
	}

	addParameterWidget(index);
}

void EventRawWidget::on_buttonRemoveNum_clicked() {
	if (cmd->parameters.size() > 0) {
		int index = cmd->parameters.size();
		auto new_arr = lcf::DBArray<int32_t>(index - 1);
		std::copy(cmd->parameters.begin(), cmd->parameters.end() - 1, new_arr.begin());
		cmd->parameters = new_arr;

		for (int i = 1; i >= 0; --i) {
			delete ui->gridLayoutNum->itemAtPosition(index - 1, i)->widget();
		}

		for (size_t i = 0; i < cmd->parameters.size(); ++i) {
			QSpinBox *spin = static_cast<QSpinBox*>(ui->gridLayoutNum->itemAtPosition(i, 1)->widget());
			LcfWidgetBinding::connect<int32_t>(this, spin);
			LcfWidgetBinding::bind(spin, cmd->parameters[i]);
		}
	}
}

void EventRawWidget::setData(lcf::rpg::EventCommand* cmd) {
	this->cmd = cmd;

	LcfWidgetBinding::bind(ui->lineString, cmd->string);
	LcfWidgetBinding::bind(ui->spinCode, cmd->code);

	for (size_t i = 0; i < cmd->parameters.size(); ++i) {
		addParameterWidget(i);
	}
}

void EventRawWidget::setShowWarning(bool show) {
	ui->labelWarn->setHidden(!show);
}

void EventRawWidget::addParameterWidget(int index) {
	auto& param = cmd->parameters[index];

	auto label = new QLabel(this);
	label->setText(QString("%1:").arg(index + 1));
	auto spin = new QSpinBox(this);
	spin->setMinimum(INT_MIN);
	spin->setMaximum(INT_MAX);
	QSizePolicy policy;
	policy.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
	spin->setSizePolicy(policy);

	LcfWidgetBinding::connect<int32_t>(this, spin);
	LcfWidgetBinding::bind(spin, param);

	ui->gridLayoutNum->addWidget(label, index, 0);
	ui->gridLayoutNum->addWidget(spin, index, 1);
}
