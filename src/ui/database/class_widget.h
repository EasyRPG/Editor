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
#include <lcf/rpg/database.h>
#include <lcf/rpg/class.h>
#include "ui/viewer/battle_animation_graphics_item.h"

class ProjectData;

namespace Ui {
class ClassWidget;
}

class ClassWidget : public QWidget
{
	Q_OBJECT

public:
	using value_type = lcf::rpg::Class;

	explicit ClassWidget(ProjectData& project, QWidget *parent = nullptr);
	~ClassWidget();
	void setData(lcf::rpg::Class* cls);

	void UpdateModels();

public slots:
	void on_currentClassChanged(lcf::rpg::Class *_class);

signals:
	void currentClassChanged(lcf::rpg::Class *_class);

private:
	Ui::ClassWidget *ui;

	BattleAnimationItem *m_battlerItem;

	lcf::rpg::Class *m_currentClass;
	ProjectData& m_project;
};

