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

#include "change_actor_graphic_widget.h"
#include "ui_change_actor_graphic_widget.h"

#include "ui/picker/picker_dialog.h"
#include "ui/picker/picker_charset_widget.h"

#include "common/dbstring.h"
#include "model/project_data.h"
#include "defines.h"

#include <lcf/reader_util.h>

ChangeActorGraphicWidget::ChangeActorGraphicWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::ChangeActorGraphicWidget) {

	ui->setupUi(this);

	ui->comboActor_arg0->makeModel(m_project);

	m_charItem = new CharSetGraphicsItem(project);
	m_charItem->setSpin(true);
	m_charItem->setWalk(true);
	ui->viewChar->scale(2.0, 2.0);
	ui->viewChar->setItem(m_charItem);
	ui->viewChar->enableTimer();

	QObject::connect(ui->viewChar, &RpgGraphicsViewBase::clicked, this, &ChangeActorGraphicWidget::charSetClicked);
}

ChangeActorGraphicWidget::~ChangeActorGraphicWidget() {
	delete ui;
}

void ChangeActorGraphicWidget::setData(lcf::rpg::EventCommand* cmd) {
	EventCommandBaseWidget::setData(cmd);

	m_charItem->refresh(ToQString(m_cmd->string), m_cmd->parameters[1]);
}

void ChangeActorGraphicWidget::onParameterChanged(int index, int new_value) {
	if (index == 0) {
		if (m_first) {
			// Ignore the first change on startup, is configured manually
			m_first = false;
			return;
		}

		const auto* actor = lcf::ReaderUtil::GetElement(m_project.database().actors, new_value);
		assert(actor);

		m_charItem->refresh(*actor);

		m_cmd->string = actor->character_name;
		m_cmd->parameters[1] = actor->character_index;
	}
}

void ChangeActorGraphicWidget::charSetClicked() {
	auto* widget = new PickerCharsetWidget(m_cmd->parameters[1], this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_cmd->string = ToDBString(baseName);
		m_cmd->parameters[1] = widget->index();
		m_charItem->refresh(ToQString(m_cmd->string), m_cmd->parameters[1]);
	});
	dialog.setDirectoryAndFile(CHARSET, ToQString(m_cmd->string));
	dialog.exec();
}
