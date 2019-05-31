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

#ifndef RPGCOMBOBOX_H
#define RPGCOMBOBOX_H

#include <QObject>
#include <QComboBox>
#include <QAbstractItemModel>
#include <QCompleter>
#include <functional>
#include "rpg_model.h"
#include "edit_dialog.h"


template <class MODEL>
class RpgComboBox : public QComboBox
{
public:
	RpgComboBox(QWidget *parent, QAbstractItemModel *model = new MODEL());
	virtual ~RpgComboBox() {}
};

template <class MODEL>
RpgComboBox<MODEL>::RpgComboBox(QWidget *parent, QAbstractItemModel *model) :
	QComboBox(parent)
{
	setModel(model);
	setEditable(true);

	QCompleter *comp = new QCompleter(model, this);
	comp->setCaseSensitivity(Qt::CaseInsensitive);
	comp->setFilterMode(Qt::MatchContains);
	comp->setCompletionMode(QCompleter::PopupCompletion);
	setCompleter(comp);


	connect(this, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [&](int index) {
		if (index == 0)
		{
			auto type = typename MODEL::typestruct()();
			EditDialog<decltype(type)> edit(this, type);

			edit.exec();
		}
	});

}

using ActorRpgComboBox = RpgComboBox<ActorRpgModel>;
using SkillRpgComboBox = RpgComboBox<SkillRpgModel>;
using ItemRpgComboBox = RpgComboBox<ItemRpgModel>;
using EnemyRpgComboBox = RpgComboBox<EnemyRpgModel>;
using TroopRpgComboBox = RpgComboBox<TroopRpgModel>;
using TerrainRpgComboBox = RpgComboBox<TerrainRpgModel>;
using AttributeRpgComboBox = RpgComboBox<AttributeRpgModel>;
using StateRpgComboBox = RpgComboBox<StateRpgModel>;
using AnimationRpgComboBox = RpgComboBox<AnimationRpgModel>;
using ChipsetRpgComboBox = RpgComboBox<ChipsetRpgModel>;
using CommonEventRpgComboBox = RpgComboBox<CommonEventRpgModel>;
using ClassRpgComboBox = RpgComboBox<ClassRpgModel>;
using BattlerAnimationRpgComboBox = RpgComboBox<BattlerAnimationRpgModel>;
using SwitchRpgComboBox = RpgComboBox<SwitchRpgModel>;
using VariableRpgComboBox = RpgComboBox<VariableRpgModel>;

#endif // RPGCOMBOBOX_H
