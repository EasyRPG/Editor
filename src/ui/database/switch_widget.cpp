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

#include "switch_widget.h"
#include "ui_switch_widget.h"
#include "src/common/lcf_widget_binding.h"

SwitchWidget::SwitchWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SwitchWidget), m_project(project)
{
	ui->setupUi(this);

	LcfWidgetBinding::connect(this, ui->lineName);
}

SwitchWidget::~SwitchWidget()
{
	delete ui;
}

void SwitchWidget::setData(lcf::rpg::Switch* sw) {
	m_current = sw ? sw : &m_dummy;

	LcfWidgetBinding::bind(ui->lineName, m_current->name);

	this->setEnabled(sw != nullptr);
}
