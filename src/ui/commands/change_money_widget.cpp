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

#include "change_money_widget.h"
#include "ui_change_money_widget.h"

ChangeMoneyWidgetWidget::ChangeMoneyWidgetWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangeMoneyWidgetWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	(cmd.parameters[0] ? ui->op_dec : ui->op_inc)->setChecked(true);
	if (cmd.parameters[1] == 0)
	{
		ui->amount_box_amount->setChecked(true);
		ui->amount_amount->setValue(cmd.parameters[2]);
	}
	else
	{
		ui->amount_box_variable->setChecked(true);
		ui->amount_variable->setCurrentIndex(cmd.parameters[2]);
	}
}

ChangeMoneyWidgetWidget::~ChangeMoneyWidgetWidget()
{
	delete ui;
}

void ChangeMoneyWidgetWidget::on_ChangeMoneyWidgetWidget_accepted()
{
	cmd.parameters[0] = ui->op_dec->isChecked() ? 1 : 0;
	cmd.parameters[1] = ui->amount_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[2] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_amount->value();
}
