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

#include "item_widget.h"
#include "ui_item_widget.h"
#include "common/lcf_widget_binding.h"

ItemWidget::ItemWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ItemWidget),
	m_project(project)
{
	ui->setupUi(this);

	LcfWidgetBinding::connect(this, ui->lineName);
	LcfWidgetBinding::connect<decltype(lcf::rpg::Item::price)>(this, ui->spinPrice);
	LcfWidgetBinding::connect(this, ui->lineDescription);
}

ItemWidget::~ItemWidget()
{
	delete ui;
}

void ItemWidget::setData(lcf::rpg::Item* item)
{
	m_current = item ? item : &m_dummy;

	LcfWidgetBinding::bind(ui->lineName, m_current->name);
	LcfWidgetBinding::bind(ui->spinPrice, m_current->price);
	LcfWidgetBinding::bind(ui->lineDescription, m_current->description);
}
