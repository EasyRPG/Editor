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

#include "timer_operation_widget.h"
#include "ui_timer_operation_widget.h"

TimerOperationWidget::TimerOperationWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::TimerOperationWidget) {

	ui->setupUi(this);

	int i = 0;
	for (auto& button : { ui->radioTimer1, ui->radioTimer2 }) {
		ui->groupTimer_arg5->setId(button, i++);
	}

	i = 0;
	for (auto& button : { ui->radioOpTime, ui->radioOpStart, ui->radioOpEnd }) {
		ui->groupOp_arg0->setId(button, i++);
	}
}

TimerOperationWidget::~TimerOperationWidget() {
	delete ui;
}

void TimerOperationWidget::onParameterChanged(int index, int new_value) {
	if (index == 0) {
		ui->groupBoxOperand->setVisible(new_value == 0);
		ui->groupBoxOptions->setVisible(new_value == 1);
	}
}
