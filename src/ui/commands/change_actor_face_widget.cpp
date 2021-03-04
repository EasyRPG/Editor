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

#include "change_actor_face_widget.h"
#include "ui_change_actor_face_widget.h"

#include "ui/picker/picker_dialog.h"
#include "ui/picker/picker_faceset_widget.h"

#include <lcf/reader_util.h>

ChangeActorFaceWidget::ChangeActorFaceWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::ChangeActorFaceWidget) {

	ui->setupUi(this);

	ui->comboActor_arg0->makeModel(m_project);

	m_faceItem = new FaceSetGraphicsItem(project);
	ui->viewFace->scale(2.0, 2.0);
	ui->viewFace->setItem(m_faceItem);
	QObject::connect(ui->viewFace, &RpgGraphicsViewBase::clicked, this, &ChangeActorFaceWidget::faceSetClicked);
}

ChangeActorFaceWidget::~ChangeActorFaceWidget() {
	delete ui;
}

void ChangeActorFaceWidget::setData(lcf::rpg::EventCommand* cmd) {
	EventCommandBaseWidget::setData(cmd);

	m_faceItem->refresh(ToQString(m_cmd->string), m_cmd->parameters[1]);
}

void ChangeActorFaceWidget::onParameterChanged(int index, int new_value) {
	if (index == 0) {
		if (m_first) {
			// Ignore the first change on startup, is configured manually
			m_first = false;
			return;
		}

		const auto* actor = lcf::ReaderUtil::GetElement(m_project.database().actors, new_value);
		assert(actor);

		m_faceItem->refresh(*actor);

		m_cmd->string = actor->face_name;
		m_cmd->parameters[1] = actor->face_index;
	}
}

void ChangeActorFaceWidget::faceSetClicked() {
	auto* widget = new PickerFacesetWidget(m_cmd->parameters[1], this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_cmd->string = ToDBString(baseName);
		m_cmd->parameters[1] = widget->index();
		m_faceItem->refresh(ToQString(m_cmd->string), m_cmd->parameters[1]);
	});
	dialog.setDirectoryAndFile(FACESET, ToQString(m_cmd->string));
	dialog.exec();
}
