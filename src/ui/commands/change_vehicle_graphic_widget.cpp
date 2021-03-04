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

#include "change_vehicle_graphic_widget.h"
#include "ui_change_vehicle_graphic_widget.h"

#include "ui/picker/picker_dialog.h"
#include "ui/picker/picker_charset_widget.h"

#include "common/dbstring.h"
#include "model/project_data.h"
#include "defines.h"

#include <lcf/reader_util.h>

ChangeVehicleGraphicWidget::ChangeVehicleGraphicWidget(ProjectData& project, QWidget *parent) :
	EventCommandBaseWidget(project, parent),
	ui(new Ui::ChangeVehicleGraphicWidget) {

	ui->setupUi(this);

	int i = 0;
	for (auto& button : {
		ui->radioBoat,
		ui->radioSkiff,
		ui->radioAirship
	}) {
		ui->groupVehicle_arg0->setId(button, i++);
	}

	m_charItem = new CharSetGraphicsItem(project);
	m_charItem->setSpin(true);
	m_charItem->setWalk(true);
	ui->viewVehicle->scale(2.0, 2.0);
	ui->viewVehicle->setItem(m_charItem);
	ui->viewVehicle->enableTimer();

	QObject::connect(ui->viewVehicle, &RpgGraphicsViewBase::clicked, this, &ChangeVehicleGraphicWidget::charSetClicked);
}

ChangeVehicleGraphicWidget::~ChangeVehicleGraphicWidget() {
	delete ui;
}

void ChangeVehicleGraphicWidget::setData(lcf::rpg::EventCommand* cmd) {
	EventCommandBaseWidget::setData(cmd);

	m_charItem->refresh(ToQString(m_cmd->string), m_cmd->parameters[1]);
}

void ChangeVehicleGraphicWidget::onParameterChanged(int index, int new_value) {
	if (index == 0) {
		if (m_first) {
			// Ignore the first change on startup, is configured manually
			m_first = false;
			return;
		}

		QString name;
		int index;
		const auto& system = m_project.database().system;

		if (new_value == 0) {
			// Boat
			index = system.boat_index;
			name = ToQString(system.boat_name);
		} else if (new_value == 1) {
			// Ship
			index = system.ship_index;
			name = ToQString(system.ship_name);
		} else if (new_value == 2) {
			// Airship
			index = system.airship_index;
			name = ToQString(system.airship_name);
		} else {
			return;
		}

		m_charItem->refresh(name, index);

		m_cmd->string = ToDBString(name);
		m_cmd->parameters[1] = index;
	}
}

void ChangeVehicleGraphicWidget::charSetClicked() {
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
