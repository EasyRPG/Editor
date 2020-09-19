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

#include "animation.h"
#include "ui/database/battle_animation_widget.h"

Animation::Animation(lcf::rpg::Animation& data, lcf::rpg::Database& database) :
	m_data(data), database(database) {

}

lcf::rpg::Animation& Animation::data() {
	return m_data;
}

QPixmap Animation::preview() {
	return QPixmap();
}

QDialog* Animation::edit(QWidget *parent) {
	return new WidgetAsDialogWrapper<BattleAnimationWidget, lcf::rpg::Animation>(database, m_data, parent);
}
