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

#ifndef QDBPAGEBATTLEANIMATIONS2_H
#define QDBPAGEBATTLEANIMATIONS2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class BattleAnimationWidget2;
}

class BattleAnimationWidget2 : public QWidget
{
	Q_OBJECT

public:
	explicit BattleAnimationWidget2(RPG::Database &database, QWidget *parent = nullptr);
	~BattleAnimationWidget2();

private:
	Ui::BattleAnimationWidget2 *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS2_H
