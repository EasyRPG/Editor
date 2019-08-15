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

#include "change_party_widget.h"
#include "ui_change_party_widget.h"

ChangePartyWidget::ChangePartyWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangePartyWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	(cmd.parameters[0] ? ui->op_rem : ui->op_add)->setChecked(true);

	if (cmd.parameters[1] == 0)
	{
		ui->target_specific->setCurrentIndex(cmd.parameters[2]);
		ui->target_box_specific->setChecked(true);
	}
	else
	{
		ui->target_variable->setCurrentIndex(cmd.parameters[2]);
		ui->target_box_variable->setChecked(true);
	}
}

ChangePartyWidget::~ChangePartyWidget()
{
	delete ui;
}

void ChangePartyWidget::on_ChangePartyWidget_accepted()
{
	cmd.parameters[0] = ui->op_rem->isChecked() ? 1 : 0;
	cmd.parameters[1] = ui->target_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[2] = ui->target_box_variable->isChecked() ? ui->target_variable->currentIndex() : ui->target_specific->currentIndex();
}
