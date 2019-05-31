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

#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>
#include <rpg_event.h>

namespace Ui {
class EventDialog;
}

class EventDialog : public QDialog
{
	Q_OBJECT

public:
	explicit EventDialog(QWidget *parent = nullptr);
	~EventDialog();

	static int edit(QWidget *parent, RPG::Event *event);

	static bool equalEvents(const RPG::Event &e1,
							const RPG::Event &e2);

	RPG::Event getEvent() const;
	void setEvent(RPG::Event *event);

private slots:
	void apply();

	void ok();

private:
	Ui::EventDialog *ui;
	RPG::Event m_event;
	RPG::Event r_event;
	RPG::Event a_event;
	int lst_result;
};
#endif // DIALOGEVENT_H
