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

#include "enemy.h"
#include "ui/database/enemy_widget.h"
#include "common/dbstring.h"

EnemyModel::EnemyModel(ProjectData& project, lcf::rpg::Enemy& data) :
	RpgBase(project), m_data(data) {

}

lcf::rpg::Enemy& EnemyModel::data() {
	return m_data;
}

QPixmap EnemyModel::preview() {
	QPixmap monster = ImageLoader::Load(m_project.project().findFile("Monster", ToQString(data().battler_name), FileFinder::FileType::Image));
	if (!monster) {
		return QPixmap(48, 48);
	}
	return monster.scaled(48, 48, Qt::AspectRatioMode::KeepAspectRatio);
}
