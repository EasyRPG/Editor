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

#include "system2_widget.h"
#include "ui_system2_widget.h"

System2Widget::System2Widget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::System2Widget),
	m_project(project)
{
	ui->setupUi(this);
}

System2Widget::~System2Widget()
{
	delete ui;
}
