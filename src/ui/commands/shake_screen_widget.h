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

#include "ui/event/event_command_base_widget.h"

namespace Ui {
class ShakeScreenWidget;
}

class ShakeScreenWidget : public EventCommandBaseWidget
{
	Q_OBJECT

public:
	explicit ShakeScreenWidget(ProjectData& project, QWidget *parent);
	~ShakeScreenWidget();

public slots:
	void onParameterChanged(int index, int new_value) override;

private:
	Ui::ShakeScreenWidget *ui;
};
