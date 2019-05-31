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

#ifndef DIALOGFACEPICKER_H
#define DIALOGFACEPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "faceset_item.h"
#include "picker_scene.h"

namespace Ui {
class CharSetPickerDialog;
}

class faceset_picker_dialog: public QDialog
{
	Q_OBJECT

public:
	explicit faceset_picker_dialog(QWidget *parent, bool tile_pick);
	~faceset_picker_dialog();

	int frame();
	void setFrame(int frame);

	int facing();
	void setFacing(int facing);

	std::string name();
	void setName(std::string name);

	void setAnimated(bool animated);

	int index() const;
	void setIndex(int index);

private slots:

	void on_listRes_currentRowChanged(int currentRow);

	void ok();

private:

	Ui::CharSetPickerDialog *ui;
	PickerScene *m_charaScene;
	PickerScene *m_tileScene;
	FaceSetItem *m_chara;
	QTimer *m_timer;
	int m_tileIndex;
	int m_charaIndex;
};

#endif // DIALOGFACEPICKER_H
