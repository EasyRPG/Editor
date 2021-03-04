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
#include <lcf/rpg/actor.h>
#include <QDialogButtonBox>
#include "ui/viewer/charset_graphics_item.h"
#include "ui/viewer/faceset_graphics_item.h"
#include "ui/viewer/battle_animation_graphics_item.h"
#include "ui/viewer/stat_curve_graphics_item.h"
#include "model/actor.h"

class ProjectData;

namespace Ui {
class ActorWidget;
}

class ActorWidget : public QWidget
{
	Q_OBJECT

public:
	using value_type = lcf::rpg::Actor;

	explicit ActorWidget(ProjectData& project, QWidget *parent = nullptr);
	void setData(lcf::rpg::Actor* actor);
	~ActorWidget();

public slots:
	void on_currentActorChanged(lcf::rpg::Actor *actor);

private slots:
	void on_comboBattleset_currentIndexChanged(int index);
	void on_pushApplyProfession_clicked();

	void faceSetClicked();
	void charSetClicked();

signals:
	void currentActorChanged(lcf::rpg::Actor *actor);

protected:
	void resizeEvent(QResizeEvent * event);

private:
	Ui::ActorWidget *ui;

	void UpdateModels();
	void ResetExpText(lcf::rpg::Actor* actor);

	CharSetGraphicsItem *m_charsetItem = nullptr;
	FaceSetGraphicsItem *m_faceItem = nullptr;

	BattleAnimationItem *m_battlerItem = nullptr;
	CurveItem *m_hpItem = nullptr;
	CurveItem *m_mpItem = nullptr;
	CurveItem *m_attItem = nullptr;
	CurveItem *m_defItem = nullptr;
	CurveItem *m_intItem = nullptr;
	CurveItem *m_agyItem = nullptr;
	std::vector<short> m_dummyCurve;

	lcf::rpg::Actor dummy;
	lcf::rpg::Actor *m_current = nullptr;
	ProjectData& m_project;
};

