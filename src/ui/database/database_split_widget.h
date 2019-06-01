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

#include <QWidget>
#include "rpg_database.h"
#include "ui/common/rpg_model.h"
#include "actor_widget.h"

namespace Ui {
class DatabaseSplitWidget;
}

class DatabaseSplitWidgetBase : public QWidget
{
	Q_OBJECT

public:
	explicit DatabaseSplitWidgetBase(QWidget *parent = nullptr);
	virtual ~DatabaseSplitWidgetBase();

protected:
	Ui::DatabaseSplitWidget *ui;
};

// Qt MOC limitation: Can't mix Q_OBJECT and template
template<class T, class U>
class DatabaseSplitWidget : public DatabaseSplitWidgetBase {
public:
	explicit DatabaseSplitWidget(RPG::Database& database, std::vector<T>& data, QWidget *parent = nullptr);

	QWidget* listWidget();
	U* contentWidget();

private:
	RPG::Database& db;

	U* m_contentWidget;
};

template class DatabaseSplitWidget<RPG::Actor, ActorWidget>;

