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

#include <QPixmap>
#include <QMessageBox>
#include "common/image_loader.h"
#include "ui/common/widget_as_dialog_wrapper.h"
#include "project.h"
#include "core.h"

class RpgBase {
public:
	explicit RpgBase(ProjectData& project);

	virtual QPixmap preview() {
		return QPixmap();
	}

	virtual QDialog* edit(QWidget* parent = nullptr) {
		return new QMessageBox(QMessageBox::Warning, "Not Supported", "Editing not supported (yet)", QMessageBox::Ok, parent);
	}

protected:
	ProjectData& m_project;
};
