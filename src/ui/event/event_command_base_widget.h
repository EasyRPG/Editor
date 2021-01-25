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
#include <lcf/rpg/eventcommand.h>
#include <lcf/rpg/database.h>

class QButtonGroup;
class QCheckBox;
class QSpinBox;
class ProjectData;
class RpgComboBoxBase;

class EventCommandBaseWidget : public QWidget
{
	Q_OBJECT
public:
	EventCommandBaseWidget(ProjectData& project, QWidget* parent);

	virtual void setData(lcf::rpg::EventCommand* cmd);

	void connectParameterHandler(QButtonGroup* group, int index);
	void connectParameterHandler(RpgComboBoxBase* combo, int index);
	void connectParameterHandler(QSpinBox* spin, int index);
	void connectParameterHandler(QCheckBox* combo, int index);

signals:
	void parameterChanged(int, int);
	void stringParameterChanged(const QString&);

protected:
	ProjectData& m_project;
	lcf::rpg::EventCommand* cmd = nullptr;
};
