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

#include "battleranimation.h"
#include "ui/database/battle_animation2_widget.h"

BattlerAnimation::BattlerAnimation(lcf::rpg::BattlerAnimation& data, lcf::rpg::Database& database) :
	m_data(data), database(database) {

}

lcf::rpg::BattlerAnimation& BattlerAnimation::data() {
	return m_data;
}

QPixmap BattlerAnimation::preview() {
	return QPixmap();
}

QDialog* BattlerAnimation::edit(QWidget *parent) {
	return new WidgetAsDialogWrapper<BattleAnimation2Widget, lcf::rpg::BattlerAnimation>(database, m_data, parent);
}
