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

#include "chipset_widget.h"
#include "ui_chipset_widget.h"

#include "common/lcf_widget_binding.h"
#include "ui/picker/picker_chipset_widget.h"
#include "ui/picker/picker_dialog.h"

#include <QButtonGroup>

ChipsetWidget::ChipsetWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChipsetWidget),
	m_project(project)
{
	ui->setupUi(this);

	QListView& list = *ui->listTerrain;
	list.setModel(new RpgModel<lcf::rpg::Terrain>(project, project.database().terrains, parent));

	LcfWidgetBinding::connect(this, ui->lineName);

	m_buttonGroupSequence = new QButtonGroup(this);
	m_buttonGroupSequence->addButton(ui->radioLowerAnim1232);
	m_buttonGroupSequence->setId(ui->radioLowerAnim1232, 0);
	m_buttonGroupSequence->addButton(ui->radioLowerAnim123);
	m_buttonGroupSequence->setId(ui->radioLowerAnim123, 1);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupSequence);

	m_buttonGroupSpeed = new QButtonGroup(this);
	m_buttonGroupSpeed->addButton(ui->radioLowerAnimSlow);
	m_buttonGroupSpeed->setId(ui->radioLowerAnimSlow, 0);
	m_buttonGroupSpeed->addButton(ui->radioLowerAnimFast);
	m_buttonGroupSpeed->setId(ui->radioLowerAnimFast, 1);
	LcfWidgetBinding::connect<int32_t>(this, m_buttonGroupSpeed);

	ui->graphicsChipsetLower->setProjectData(project);
	ui->graphicsChipsetLower->setLayer(ChipsetGraphicsView::Layer::Lower);
	ui->graphicsChipsetUpper->setProjectData(project);
	ui->graphicsChipsetUpper->setLayer(ChipsetGraphicsView::Layer::Upper);

	QObject::connect(ui->pushTileset, &QPushButton::clicked, this, &ChipsetWidget::chipsetClicked);
}

ChipsetWidget::~ChipsetWidget()
{
	delete ui;
}

void ChipsetWidget::setData(lcf::rpg::Chipset* chipset)
{
	if (!chipset) {
		chipset = &dummy;
	}
	m_current = chipset;

	LcfWidgetBinding::bind(ui->lineName, chipset->name);
	LcfWidgetBinding::bind(m_buttonGroupSpeed, chipset->animation_speed);
	LcfWidgetBinding::bind(m_buttonGroupSequence, chipset->animation_type);

	for (auto* view: {ui->graphicsChipsetLower, ui->graphicsChipsetUpper}) {
		view->setChipset(*chipset);
		view->setShowGrid(true);
		view->refresh();
	}

	ui->pushTileset->setText(ToQString(chipset->chipset_name));

	this->setEnabled(chipset != &dummy);
}

void ChipsetWidget::chipsetClicked() {
	auto* widget = new PickerChipsetWidget(this);
	PickerDialog dialog(m_project, FileFinder::FileType::Image, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_current->chipset_name = ToDBString(baseName);
		ui->pushTileset->setText(ToQString(m_current->chipset_name));
		//m_charsetItem->refresh(*m_current);
	});
	dialog.setDirectoryAndFile(CHIPSET, ToQString(m_current->chipset_name));
	dialog.exec();
}
