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
class QSlider;
class QSpinBox;
class ProjectData;
class RpgComboBoxBase;
class EventCommandList;

class EventCommandBaseWidget : public QWidget
{
	Q_OBJECT
public:
	EventCommandBaseWidget(ProjectData& project, QWidget* parent);

	virtual void setData(lcf::rpg::EventCommand* cmd);
	virtual void setData(EventCommandList* commands);

	void connectParameterHandler(QButtonGroup* group, int index, bool set_value = true);
	void connectParameterHandler(RpgComboBoxBase* combo, int index, bool set_value = true);
	void connectParameterHandler(QSpinBox* spin, int index, bool set_value = true);
	void connectParameterHandler(QCheckBox* check, int index, bool set_value = true);
	void connectParameterHandler(QSlider* slider, int index, bool set_value = true);

	void resizeCommandList(int index);

public slots:
	virtual void onParameterChanged(int index, int new_value) {
		Q_UNUSED(index);
		Q_UNUSED(new_value);
	}

	virtual void onStringParameterChanged(const QString& new_string) {
		Q_UNUSED(new_string);
	}

signals:
	void parameterChanged(int, int);
	void stringParameterChanged(const QString&);

protected:
	ProjectData& m_project;
	EventCommandList* m_commands = nullptr;
	lcf::rpg::EventCommand* m_cmd = nullptr;
};
