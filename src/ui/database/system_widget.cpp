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

#include "system_widget.h"
#include "ui_system_widget.h"

#include "src/common/lcf_widget_binding.h"

SystemWidget::SystemWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SystemWidget),
	m_project(project) {
	ui->setupUi(this);

	ui->lineTitleBgm->makeModel(project);
	ui->lineCursorSound->makeModel(project);

	auto& sys = project.database().system;

	ui->lineTitleBgm->bindMusic(sys.title_music);
	ui->lineCursorSound->bindSound(sys.cursor_se);
}

SystemWidget::~SystemWidget() {
	delete ui;
}
