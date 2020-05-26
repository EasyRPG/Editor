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

#include "change_item_widget.h"
#include "ui_change_item_widget.h"

ChangeItemWidget::ChangeItemWidget(QWidget *parent, lcf::rpg::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangeItemWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	(cmd.parameters[0] ? ui->op_rem : ui->op_add)->setChecked(true);

	if (cmd.parameters[1] == 0)
	{
		ui->item_item->setCurrentIndex(cmd.parameters[2]);
		ui->item_box_item->setChecked(true);
	}
	else
	{
		ui->item_variable->setCurrentIndex(cmd.parameters[2]);
		ui->item_box_variable->setChecked(true);
	}

	if (cmd.parameters[3] == 0)
	{
		ui->amount_amount->setValue(cmd.parameters[4]);
		ui->amount_box_fix->setChecked(true);
	}
	else
	{
		ui->amount_variable->setCurrentIndex(cmd.parameters[4]);
		ui->amount_box_variable->setChecked(true);
	}
}

ChangeItemWidget::~ChangeItemWidget()
{
	delete ui;
}

void ChangeItemWidget::on_ChangeItemWidget_accepted()
{
	cmd.parameters[0] = ui->op_rem->isChecked() ? 1 : 0;
	cmd.parameters[1] = ui->item_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[2] = ui->item_box_variable->isChecked() ? ui->item_variable->currentIndex() : ui->item_item->currentIndex();
	cmd.parameters[3] = ui->amount_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[4] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_amount->value();
}
