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

#include <QObject>
#include <QComboBox>
#include <QAbstractItemModel>
#include <QCompleter>
#include <QPushButton>
#include <functional>
#include <QHBoxLayout>
#include <QMessageBox>
#include "rpg_model.h"
#include "edit_dialog.h"
#include "ui/database/actor_widget.h"
#include "ui/database/item_widget.h"
#include "ui/common/widget_as_dialog_wrapper.h"

template <class MODEL>
class RpgComboBox : public QWidget
{
public:
	RpgComboBox(QWidget *parent, QAbstractItemModel *model = new MODEL());
	virtual ~RpgComboBox() {}

	QComboBox* comboBox() {
		return m_comboBox;
	}

	// The member "setEditable" is missing on purpose. Don't set it in the UI!

	void setCurrentIndex(int index) {
		m_comboBox->setCurrentIndex(index);
	}

	int currentIndex() const {
		return m_comboBox->currentIndex();
	}

	void addItem(QString s) {
		m_comboBox->addItem(s);
	}

	void setItemText(int index, const QString& text) {
		m_comboBox->setItemText(index, text);
	}

private:
	QComboBox* m_comboBox;
	QPushButton* m_editButton;
};

template <class MODEL>
RpgComboBox<MODEL>::RpgComboBox(QWidget *parent, QAbstractItemModel *model) :
	QWidget(parent)
{
	m_comboBox = new QComboBox(this);
	m_editButton = new QPushButton("...", this);

	auto* layout = new QHBoxLayout(this);
	layout->addWidget(m_comboBox);
	layout->addWidget(m_editButton);

	QSizePolicy policy;
	policy.setHorizontalPolicy(QSizePolicy::Maximum);
	m_editButton->setSizePolicy(policy);

	m_comboBox->setModel(model);
	m_comboBox->setEditable(true);

	QCompleter *comp = new QCompleter(model, this);
	comp->setCaseSensitivity(Qt::CaseInsensitive);
	comp->setFilterMode(Qt::MatchContains);
	comp->setCompletionMode(QCompleter::PopupCompletion);
	m_comboBox->setCompleter(comp);

	connect(m_comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [&](int index) {

	});

	connect(m_editButton, &QPushButton::pressed, [&] {
		auto type = typename MODEL::typestruct()();

		QVariant data = m_comboBox->currentData();
		// FIXME: Integrate EditDialog better
		/*EditDialog<decltype(type)> edit(this, type);

		edit.exec();*/
		// FIXME: Bad. The database must be forwarded from the parent to reflect the current edit state
		auto db = core().project()->database();

		// FIXME: Super ugly
		if constexpr (std::is_same_v<std::vector<lcf::rpg::Actor>, decltype(type)>) {
			auto* d = reinterpret_cast<lcf::rpg::Actor*>(data.data());
			auto* w = new WidgetAsDialogWrapper<ActorWidget, lcf::rpg::Actor>(db, *d, this);
			w->show();
		} else if constexpr (std::is_same_v<std::vector<lcf::rpg::Item>, decltype(type)>) {
			auto* d = reinterpret_cast<lcf::rpg::Item*>(data.data());
			auto* w = new WidgetAsDialogWrapper<ItemWidget, lcf::rpg::Item>(db, *d, this);
			w->show();
		} else {
			QMessageBox::warning(this, "Edit not supported", "Editing not supported (yet)");
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

