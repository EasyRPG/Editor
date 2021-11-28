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
#include <lcf/rpg/state.h>
#include "model/state.h"
#include <QButtonGroup>

class ProjectData;

namespace Ui {
class StateWidget;
}

class StateWidget : public QWidget
{
	Q_OBJECT

public:
	using value_type = lcf::rpg::State;

	explicit StateWidget(ProjectData& project, QWidget *parent = nullptr);
	~StateWidget();

	void setData(lcf::rpg::State* state);

public slots:
	void on_currentStateChanged(lcf::rpg::State *state);

signals:
	void currentStateChanged(lcf::rpg::State *state);

private:
	Ui::StateWidget *ui;

	lcf::rpg::State dummy;
	lcf::rpg::State *m_current = nullptr;
	ProjectData& m_project;

	QButtonGroup* m_buttonGroupStatAlteration = nullptr;
	QButtonGroup* m_buttonGroupHPEffect = nullptr;
	QButtonGroup* m_buttonGroupMPEffect = nullptr;
};

