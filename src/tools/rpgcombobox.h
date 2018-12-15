#ifndef RPGCOMBOBOX_H
#define RPGCOMBOBOX_H

#include <QObject>
#include <QComboBox>
#include <QAbstractItemModel>
#include <QCompleter>
#include <functional>
#include "rpgmodel.h"
#include "../dialogedit.h"


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
			DialogEdit<decltype(type)> edit(this, type);

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
