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

#include "common_event_widget.h"
#include "ui_common_event_widget.h"
#include "src/common/lcf_widget_binding.h"

CommonEventWidget::CommonEventWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CommonEventWidget),
	m_project(project)
{
	ui->setupUi(this);

	LcfWidgetBinding::connect(this, ui->lineName);
	LcfWidgetBinding::connect<int32_t>(this, ui->comboTrigger);
	LcfWidgetBinding::connect<bool>(this, ui->groupSwitch);
	ui->comboSwitch->makeModel(project);
}

CommonEventWidget::~CommonEventWidget()
{
	delete ui;
}

void CommonEventWidget::setData(lcf::rpg::CommonEvent* common_event) {
	m_current = common_event ? common_event : &m_dummy;

	LcfWidgetBinding::bind(ui->lineName, m_current->name);
	LcfWidgetBinding::bind(ui->comboTrigger, m_current->trigger);
	LcfWidgetBinding::bind(ui->groupSwitch, m_current->switch_flag);
	LcfWidgetBinding::bind(ui->comboSwitch->comboBox(), m_current->switch_id);

	ui->commands->setData(m_project, m_current);

	this->setEnabled(common_event != nullptr);
}
