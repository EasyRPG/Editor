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

#ifndef QDBPAGEPROFESSIONS_H
#define QDBPAGEPROFESSIONS_H

#include <QWidget>
#include <rpg_database.h>
#include <rpg_class.h>
#include "ui/common/battle_animation_item.h"

namespace Ui {
class ClassWidget;
}

class ClassWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ClassWidget(RPG::Database &database, QWidget *parent = nullptr);
	~ClassWidget();

	void UpdateModels();

public slots:
	void on_currentClassChanged(RPG::Class *_class);

signals:
	void currentClassChanged(RPG::Class *_class);

private:
	Ui::ClassWidget *ui;

	BattleAnimationItem *m_battlerItem;

	RPG::Class *m_currentClass;
	RPG::Database &m_data;
};

#endif // QDBPAGEPROFESSIONS_H
