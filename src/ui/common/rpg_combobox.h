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
#include <QSortFilterProxyModel>
#include <QCompleter>
#include <QPushButton>
#include <functional>
#include <QHBoxLayout>
#include <QMessageBox>
#include "rpg_model.h"
#include "model/rpg_reflect.h"
#include "edit_dialog.h"
#include "ui/common/widget_as_dialog_wrapper.h"
#include "ui/common/widget_as_dialog_model_wrapper.h"
#include "ui/database/database_split_widget.h"

class RpgComboBoxBase : public QWidget {
	Q_OBJECT
public:
	explicit RpgComboBoxBase(QWidget *parent = nullptr) : QWidget(parent) {}

	QComboBox* comboBox() {
		return m_comboBox;
	}

public slots:
	virtual void indexChanged(int) {};

	void connect(QDialog* diag) {
		QObject::connect(diag, SIGNAL(valueSelected(int)), this, SLOT(indexChanged(int)));
	}

signals:
	void currentIndexChanged(int);

protected:
	QComboBox* m_comboBox;
};

template <typename LCF>
class RpgComboBox : public RpgComboBoxBase
{
public:
	RpgComboBox(QWidget *parent, QAbstractItemModel *model = nullptr);

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

	void makeModel(ProjectData& project) {
		m_project = &project;
		m_model = new RpgModel<LCF>(project);

		m_comboBox->setModel(m_model);
		m_comboBox->setEditable(true);

		QCompleter *comp = new QCompleter(m_model, this);
		comp->setCaseSensitivity(Qt::CaseInsensitive);
		comp->setFilterMode(Qt::MatchContains);
		comp->setCompletionMode(QCompleter::PopupCompletion);
		m_comboBox->setCompleter(comp);
	}

	void setFilter(QSortFilterProxyModel* filter) {
		filter->setParent(this);
		filter->setSourceModel(m_model);
		m_comboBox->setModel(filter);
		filter->invalidate();
		m_filter = filter;
	}

	void indexChanged(int index) override {
		m_comboBox->setCurrentIndex(index);
		emit currentIndexChanged(index);
	};

private:
	QPushButton* m_editButton;
	ProjectData* m_project = nullptr;
	RpgModel<LCF>* m_model = nullptr;
	QSortFilterProxyModel* m_filter = nullptr;
};

template <class LCF>
RpgComboBox<LCF>::RpgComboBox(QWidget *parent, QAbstractItemModel *model) :
	RpgComboBoxBase(parent)
{
	m_comboBox = new QComboBox(this);
	m_editButton = new QPushButton("...", this);

	auto* layout = new QHBoxLayout(this);
	layout->addWidget(m_comboBox);
	layout->addWidget(m_editButton);

	QSizePolicy policy;
	policy.setHorizontalPolicy(QSizePolicy::Maximum);
	m_editButton->setSizePolicy(policy);

	if (model) {
		m_comboBox->setModel(model);
	}

	QObject::connect(m_editButton, &QPushButton::pressed, [&] {
		int id = m_comboBox->currentData().toInt();
		if (id == 0) {
			return;
		}

		// FIXME: This copies the entire project, kinda slow
		// The reassigning of the model alters the index, remember it
		auto idx = m_comboBox->currentIndex();
		auto* dialog = new WidgetAsDialogModelWrapper<LCF>(
				*m_project, m_filter, m_comboBox->currentIndex(), this);
		m_comboBox->setCurrentIndex(idx);
		connect(dialog);
		dialog->exec();
	});

	QObject::connect(m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
}

using ActorRpgComboBox = RpgComboBox<lcf::rpg::Actor>;
using SkillRpgComboBox = RpgComboBox<lcf::rpg::Skill>;
using ItemRpgComboBox = RpgComboBox<lcf::rpg::Item>;
using EnemyRpgComboBox = RpgComboBox<lcf::rpg::Enemy>;
using TroopRpgComboBox = RpgComboBox<lcf::rpg::Troop>;
using TerrainRpgComboBox = RpgComboBox<lcf::rpg::Terrain>;
using AttributeRpgComboBox = RpgComboBox<lcf::rpg::Attribute>;
using StateRpgComboBox = RpgComboBox<lcf::rpg::State>;
using AnimationRpgComboBox = RpgComboBox<lcf::rpg::Animation>;
using ChipsetRpgComboBox = RpgComboBox<lcf::rpg::Chipset>;
using CommonEventRpgComboBox = RpgComboBox<lcf::rpg::CommonEvent>;
using ClassRpgComboBox = RpgComboBox<lcf::rpg::Class>;
using BattlerAnimationRpgComboBox = RpgComboBox<lcf::rpg::BattlerAnimation>;
using SwitchRpgComboBox = RpgComboBox<lcf::rpg::Switch>;
using VariableRpgComboBox = RpgComboBox<lcf::rpg::Variable>;

