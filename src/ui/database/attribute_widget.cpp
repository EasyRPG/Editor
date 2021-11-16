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

#include "attribute_widget.h"
#include "ui_attribute_widget.h"

#include "common/lcf_widget_binding.h"
#include "model/attribute.h"

AttributeWidget::AttributeWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AttributeWidget),
	m_project(project)
{
	auto& database = project.database();

	const auto kMinERate = database.system.ldb_id == 2003 ? -99999 : 0;
	ui->setupUi(this);

	m_current = nullptr;

	ui->spinE->setMinimum(kMinERate);

	m_buttonGroupType = new QButtonGroup(this);
	m_buttonGroupType->addButton(ui->radioWeapon);
	m_buttonGroupType->setId(ui->radioWeapon, 0);
	m_buttonGroupType->addButton(ui->radioMagic);
	m_buttonGroupType->setId(ui->radioMagic, 1);

	LcfWidgetBinding::connect(this, ui->lineName);

	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupType);

	for (auto& uis : {
			ui->spinA,
			ui->spinB,
			ui->spinC,
			ui->spinD,
			ui->spinE }) {
		LcfWidgetBinding::connect<int32_t>(this, uis);
	}
}

AttributeWidget::~AttributeWidget() {
	delete ui;
}

void AttributeWidget::setData(lcf::rpg::Attribute* attribute) {
	on_currentAttributeChanged(attribute);
}

void AttributeWidget::on_currentAttributeChanged(lcf::rpg::Attribute *attribute) {
	if (!attribute) {
		attribute = &dummy;
	}
	m_current = attribute;

	auto& database = m_project.database();

	LcfWidgetBinding::bind(ui->lineName, attribute->name);
	LcfWidgetBinding::bind(m_buttonGroupType, attribute->type);
	LcfWidgetBinding::bind(ui->spinA, attribute->a_rate);
	LcfWidgetBinding::bind(ui->spinB, attribute->b_rate);
	LcfWidgetBinding::bind(ui->spinC, attribute->c_rate);
	LcfWidgetBinding::bind(ui->spinD, attribute->d_rate);
	LcfWidgetBinding::bind(ui->spinE, attribute->e_rate);

	this->setEnabled(attribute != &dummy);
}
