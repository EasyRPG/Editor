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
#include <lcf/data.h>
#include <lcf/rpg/actor.h>
#include <QDialogButtonBox>
#include "ui/common/charset_item.h"
#include "ui/common/faceset_item.h"
#include "ui/common/charset_picker_dialog.h"
#include "ui/common/faceset_picker_dialog.h"
#include "ui/common/battle_animation_item.h"
#include "ui/common/stat_curve_item.h"

class ProjectData;

namespace Ui {
class ActorWidget;
}

class ActorWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ActorWidget(ProjectData& project, QWidget *parent = nullptr);
	void setData(lcf::rpg::Actor* actor);
	~ActorWidget();

public slots:
	void on_currentActorChanged(lcf::rpg::Actor *actor);

private slots:
	void on_pushSetCharset_clicked();
	void on_pushSetFace_clicked();
	void on_comboBattleset_currentIndexChanged(int index);
	void on_pushApplyProfession_clicked();

signals:
	void currentActorChanged(lcf::rpg::Actor *actor);

protected:
	void resizeEvent(QResizeEvent * event);

private:
	Ui::ActorWidget *ui;

	void UpdateModels();
	void ResetExpText(lcf::rpg::Actor* actor);

	CharSetItem *m_charaItem;
	FaceSetItem *m_faceItem;
	BattleAnimationItem *m_battlerItem;
	CurveItem *m_hpItem;
	CurveItem *m_mpItem;
	CurveItem *m_attItem;
	CurveItem *m_defItem;
	CurveItem *m_intItem;
	CurveItem *m_agyItem;
	std::vector<short> m_dummyCurve;

	lcf::rpg::Actor dummy;
	lcf::rpg::Actor *m_current;
	ProjectData& m_project;
};

