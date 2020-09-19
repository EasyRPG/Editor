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

#include "variable_widget.h"
#include "ui_variable_widget.h"
#include "src/common/lcf_widget_binding.h"

VariableWidget::VariableWidget(lcf::rpg::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::VariableWidget), m_database(database)
{
	ui->setupUi(this);

	LcfWidgetBinding::connect(this, ui->lineName);
}

VariableWidget::~VariableWidget()
{
	delete ui;
}

void VariableWidget::setData(lcf::rpg::Variable *var) {
	m_current = var ? var : &m_dummy;

	LcfWidgetBinding::bind(ui->lineName, m_current->name);

	this->setEnabled(var != nullptr);
}
