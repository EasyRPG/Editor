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

#include "enemy_group_widget.h"
#include "ui/event/battle_page_widget.h"
#include "ui_enemy_group_widget.h"
#include "ui/event/event_page_widget.h"

EnemyGroupWidget::EnemyGroupWidget(lcf::rpg::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EnemyGroupWidget),
	m_data(database)
{
	ui->setupUi(this);
}

EnemyGroupWidget::~EnemyGroupWidget() {
	delete ui;
}

void EnemyGroupWidget::setData(lcf::rpg::Troop* troop) {
	m_current = troop ? troop : &m_dummy;

	ui->tabCommands->clear();
	for (auto& page : troop->pages) {
		// FIXME: The CommandWidget must be wrapped in another widget that provides the conditions
		auto* tab = new BattlePageWidget(this);
		tab->setEventPage(&page);
		ui->tabCommands->addTab(tab, QString::number(page.ID));
	}

	this->setEnabled(m_current != nullptr);
}
