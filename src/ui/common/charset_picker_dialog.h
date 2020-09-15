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

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "charset_item.h"
#include "picker_scene.h"

namespace Ui {
class CharSetPickerDialog;
}

class CharSetPickerDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CharSetPickerDialog(QWidget *parent, bool tile_pick);
	~CharSetPickerDialog();

	int frame();
	void setFrame(int frame);

	int facing();
	void setFacing(int facing);

	QString name();
	void setName(QString name);

	void setAnimated(bool animated);

	int index() const;
	void setIndex(int index);

private slots:
	void on_toolUp_clicked();

	void on_toolRight_clicked();

	void on_toolDown_clicked();

	void on_toolLeft_clicked();

	void on_radioLeft_clicked();

	void on_radioMiddle_clicked();

	void on_radioRight_clicked();

	void on_listRes_currentRowChanged(int currentRow);

	void ok();

private:
	void updateFrame();
	void updateFacing();

	Ui::CharSetPickerDialog *ui;
	PickerScene *m_charaScene;
	PickerScene *m_tileScene;
	CharSetItem *m_chara;
	bool m_tilePick;
	QTimer *m_timer;
	int m_tileIndex;
	int m_charaIndex;
};

