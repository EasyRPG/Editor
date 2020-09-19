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
#include <lcf/data.h>

class ProjectData;

namespace Ui {
class CommonEventWidget;
}

class CommonEventWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CommonEventWidget(ProjectData& project, QWidget *parent = nullptr);
	~CommonEventWidget() override;

	void setData(lcf::rpg::CommonEvent* common_event);

private:
	Ui::CommonEventWidget *ui;
	ProjectData& m_project;
	lcf::rpg::CommonEvent *m_current = nullptr;
	lcf::rpg::CommonEvent m_dummy;
};

