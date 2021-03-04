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

#include "change_actor_name_widget.h"
#include "ui_change_actor_name_widget.h"
#include "common/dbstring.h"

#include <lcf/reader_util.h>

ChangeActorNameWidget::ChangeActorNameWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::ChangeActorNameWidget) {

	ui->setupUi(this);

	ui->comboActor_arg0->makeModel(m_project);
}

ChangeActorNameWidget::~ChangeActorNameWidget() {
	delete ui;
}

void ChangeActorNameWidget::setData(lcf::rpg::EventCommand* cmd_) {
	EventCommandBaseWidget::setData(cmd_);

	ui->lineName_argX->setText(ToQString(cmd_->string));
}

void ChangeActorNameWidget::onParameterChanged(int index, int new_value) {
	if (index == 0) {
		const auto& actor = lcf::ReaderUtil::GetElement(m_project.database().actors, new_value);

		ui->lineName_argX->setText(ToQString(actor->name));
		m_cmd->string = actor->title;
	}
}
