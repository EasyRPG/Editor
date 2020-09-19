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

#include <QTreeWidget>
#include <lcf/rpg/commonevent.h>
#include <lcf/rpg/trooppage.h>
#include <lcf/rpg/eventpage.h>

class EventCommandsWidget : public QTreeWidget
{
	Q_OBJECT

public:
	explicit EventCommandsWidget(QWidget *parent = nullptr);

	void setData(lcf::rpg::CommonEvent* event);
	void setData(lcf::rpg::TroopPage* event);
	void setData(lcf::rpg::EventPage* event);

private:
	template<typename T>
	void setDataInternal(T* event);
	std::vector<lcf::rpg::EventCommand>	* m_commands = nullptr;

	void editRawEvent(QTreeWidgetItem* item, int column, bool show_warning);

private slots:
	void editEvent(QTreeWidgetItem* item, int column);
	void showContextMenu(const QPoint& pos);
};
