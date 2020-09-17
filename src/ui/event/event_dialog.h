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

#pragma once

#include <QDialog>
#include <lcf/rpg/event.h>
#include <lcf/rpg/database.h>

namespace Ui {
class EventDialog;
}

class EventDialog : public QDialog
{
	Q_OBJECT

public:
	explicit EventDialog(lcf::rpg::Database& database, QWidget *parent = nullptr);
	~EventDialog();

	static int edit(QWidget *parent, lcf::rpg::Event& event, lcf::rpg::Database& database);

	static bool equalEvents(const lcf::rpg::Event &e1,
							const lcf::rpg::Event &e2);

	lcf::rpg::Event getEvent() const;
	void setEvent(lcf::rpg::Event& event);

private slots:
	void apply();

	void ok();

private:
	Ui::EventDialog *ui;
	lcf::rpg::Event m_event;
	lcf::rpg::Event r_event;
	lcf::rpg::Event a_event;
	int lst_result;
	lcf::rpg::Database& m_database;
};
