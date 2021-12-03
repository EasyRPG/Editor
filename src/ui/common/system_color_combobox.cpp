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

#include "system_color_combobox.h"

SystemColorComboBox::SystemColorComboBox(QWidget *parent) : QComboBox(parent) {}

void SystemColorComboBox::setup(ProjectData& project) {
	auto& database = project.database();

	QPixmap systemimage = ImageLoader::Load(project.project().findFile("System", ToQString(database.system.system_name), FileFinder::FileType::Image));

	clear();
	for (int i = 0; i < 20; i++) {
		QPixmap colorpixmap = systemimage.copy((i % 10) * 16, (i / 10) * 16 + 48, 16, 16);
		QIcon coloricon;
		coloricon.addPixmap(colorpixmap, QIcon::Normal);
		coloricon.addPixmap(colorpixmap, QIcon::Disabled);
		addItem(coloricon, QString("Color %1").arg(i), i);
	}
}
