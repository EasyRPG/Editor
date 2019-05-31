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
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "ui/common/charset_item.h"
#include "ui/common/faceset_item.h"
#include "ui/common/charset_picker_dialog.h"
#include "ui/common/faceset_picker_dialog.h"
#include "ui/common/battle_animation_item.h"
#include "ui/common/stat_curve_item.h"

namespace Ui {
class ActorWidget;
}

class ActorWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ActorWidget(RPG::Database &database, QWidget *parent = nullptr);
	~ActorWidget();

public slots:
	void on_currentActorChanged(RPG::Actor *actor);

private slots:
	void on_listCharacters_currentRowChanged(int currentRow);
	void on_lineName_textChanged(const QString &arg1);
	void on_lineTitle_textChanged(const QString &arg1);
	void on_checkTranslucent_toggled(bool checked);
	void on_checkDualWeapon_toggled(bool checked);
	void on_checkAI_toggled(bool checked);
	void on_checkFixedEquip_toggled(bool checked);
	void on_checkStrongDefense_toggled(bool checked);
	void on_spinMinLv_valueChanged(int arg1);
	void on_spinMaxLv_valueChanged(int arg1);
	void on_groupCritChance_toggled(bool on);
	void on_comboInitialWeapon_currentIndexChanged(int index);
	void on_comboInitialShield_currentIndexChanged(int index);
	void on_comboInitialArmor_currentIndexChanged(int index);
	void on_comboInitialHelmet_currentIndexChanged(int index);
	void on_comboInitialMisc_currentIndexChanged(int index);
	void on_comboUnarmedAnimation_currentIndexChanged(int index);
	void on_pushSetCharset_clicked();
	void on_pushSetFace_clicked();
	void on_comboBattleset_currentIndexChanged(int index);
	void on_spinCritChance_valueChanged(int arg1);
	void on_pushApplyProfession_clicked();

signals:
	void currentActorChanged(RPG::Actor *actor);

protected:
	void resizeEvent(QResizeEvent * event);

private:
	Ui::ActorWidget *ui;

	void UpdateModels();
	void ResetExpText(RPG::Actor* actor);

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

	RPG::Actor *m_currentActor;
	RPG::Database &m_data;
};

