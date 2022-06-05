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

#include <QWidget>
#include <lcf/rpg/eventpage.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <lcf/rpg/eventcommand.h>
#include <lcf/rpg/database.h>
#include "ui/viewer/charset_graphics_item.h"
#include <QProgressBar>
#include <QLabel>

class ProjectData;

namespace Ui {
class QEventWidget;
}

class EventPageWidget : public QWidget
{
	Q_OBJECT

public:
	explicit EventPageWidget(ProjectData& project, QWidget *parent = nullptr);
	~EventPageWidget() override;

	lcf::rpg::EventPage *eventPage() const;
	void setEventPage(lcf::rpg::EventPage *eventPage);

private slots:
	void on_comboMoveType_currentIndexChanged(int index);

	void on_checkVar_toggled(bool checked);

	void on_checkTransparent_toggled(bool checked);

	void on_spinTimerAMin_valueChanged(int arg1);

	void on_spinTimerASec_valueChanged(int arg1);

	void on_spinTimerBMin_valueChanged(int arg1);

	void on_spinTimerBSec_valueChanged(int arg1);

	void on_pushSetSprite_clicked();

private:

	void updateGraphic();

	Ui::QEventWidget *ui;
	ProjectData& m_project;
	lcf::rpg::EventPage *m_eventPage = nullptr;
	QGraphicsPixmapItem *m_tileItem = nullptr;
	CharSetGraphicsItem *m_charaItem = nullptr;
	QGraphicsScene *m_scene = nullptr;
	QGraphicsOpacityEffect *m_effect = nullptr;
};

