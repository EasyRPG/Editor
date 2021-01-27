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

#include "shake_screen_widget.h"
#include "ui_shake_screen_widget.h"

ShakeScreenWidget::ShakeScreenWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::ShakeScreenWidget) {

	ui->setupUi(this);

	int i = 0;
	for (auto& button : { ui->radioOnce, ui->radioBegin, ui->radioEnd }) {
		ui->groupOptions_arg4->setId(button, i++);
	}
}

ShakeScreenWidget::~ShakeScreenWidget() {
	delete ui;
}

void ShakeScreenWidget::onParameterChanged(int index, int new_value) {
	// Shake type
	if (index == 4) {
		// Wait for Completion only for "Shake Once"
		ui->checkWait_arg3->setEnabled(new_value == 0);
		// Duration only for "Shake Once"
		ui->spinTime_arg2->setEnabled(new_value == 0);
		// Disable strength and speed for "Stop Shake"
		ui->groupStrength->setEnabled(new_value != 2);
		ui->groupSpeed->setEnabled(new_value != 2);
	}
}
