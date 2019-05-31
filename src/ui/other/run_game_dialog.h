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

#ifndef DIALOGRUNGAME_H
#define DIALOGRUNGAME_H

#include <QDialog>
#include <QTableWidgetItem>
#include <rpg_testbattler.h>

namespace Ui {
class RunGameDialog;
}

class RunGameDialog : public QDialog
{
	Q_OBJECT

public:

	explicit RunGameDialog(QWidget *parent = nullptr);
	~RunGameDialog();

	void runHere(int map_id, int x, int y);

	void runBattle(int troop_id);

private slots:
	void on_comboMode_currentIndexChanged(int index);

	void on_tableInitialParty_itemChanged(QTableWidgetItem *item);

private:
	void UpdateModels();

	Ui::RunGameDialog *ui;
	std::vector<RPG::TestBattler> battletest_data;
};

#endif // DIALOGRUNGAME_H
