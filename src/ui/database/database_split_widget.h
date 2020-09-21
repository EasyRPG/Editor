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
#include <QPoint>
#include <QAction>
#include <QMenu>
#include <lcf/rpg/database.h>
#include "ui/common/rpg_model.h"
#include "ui_database_split_widget.h"
#include "ui/common/rpg_model.h"
#include "ui/common/widget_as_dialog_wrapper.h"
#include "model/rpg_base.h"
#include "model/rpg_reflect.h"
#include "actor_widget.h"
#include "attribute_widget.h"
#include "battle_animation2_widget.h"
#include "battle_animation_widget.h"
#include "chipset_widget.h"
#include "class_widget.h"
#include "common_event_widget.h"
#include "enemy_group_widget.h"
#include "enemy_widget.h"
#include "item_widget.h"
#include "skill_widget.h"
#include "state_widget.h"
#include "terrain_widget.h"
#include "variable_widget.h"
#include "switch_widget.h"

namespace Ui {
class DatabaseSplitWidget;
}

class DatabaseSplitWidgetBase : public QWidget
{
	Q_OBJECT

public:
	explicit DatabaseSplitWidgetBase(QWidget *parent = nullptr);
	~DatabaseSplitWidgetBase() override;

protected:
	Ui::DatabaseSplitWidget *ui;
};

// Qt MOC limitation: Can't mix Q_OBJECT and template
template<class LCF>
class DatabaseSplitWidget : public DatabaseSplitWidgetBase {
public:
	using widget_type = typename RpgReflect<LCF>::widget_type;

	explicit DatabaseSplitWidget(ProjectData& project, QWidget* parent = nullptr);
	DatabaseSplitWidget(ProjectData& project, std::vector<LCF>& data, QWidget* parent = nullptr);

	QListView* listWidget() {
		return ui->list;
	}
	widget_type* contentWidget() {
		return m_contentWidget;
	}
	void setModel(QAbstractItemModel* model);

private:
	ProjectData& m_project;

	widget_type* m_contentWidget;
};

template<class LCF>
inline DatabaseSplitWidget<LCF>::DatabaseSplitWidget(ProjectData& project, std::vector<LCF>& data, QWidget* parent) :
		m_project(project), DatabaseSplitWidgetBase(parent)
{
	m_contentWidget = new typename RpgReflect<LCF>::widget_type(m_project, this);
	QListView& list = *ui->list;
	list.setModel(new RpgModel<LCF>(project, data, parent));
	ui->splitter->addWidget(m_contentWidget);
	ui->splitter->setStretchFactor(0, 1);
	ui->splitter->setStretchFactor(1, 4);

	list.setContextMenuPolicy(Qt::CustomContextMenu);

	connect(list.selectionModel(), &QItemSelectionModel::currentChanged, this, [&](const QModelIndex &index) {
		// Based on the list index update the data of the content widget
		m_contentWidget->setData(
				list.model()->data(index, ModelData::ModelDataObject)
				.value<LCF*>());
	});

	connect(&list, &QListView::customContextMenuRequested, this, [&](const QPoint& pos) {
		QModelIndex index = list.indexAt(pos);
		if (index.row() == -1) {
			return;
		}

		auto* editAct = new QAction("Edit...", &list);

		connect(editAct, &QAction::triggered, &list, [&]{
			auto* d = new WidgetAsDialogWrapper<typename RpgReflect<LCF>::widget_type, LCF>
			        (m_project, *list.model()->data(index, ModelData::ModelDataObject)
							.value<LCF*>(), this);
			d->show();
		});

		QMenu menu(&list);
		menu.addAction(editAct);

		menu.exec(mapToGlobal(pos));
	});

}

template<class LCF>
inline DatabaseSplitWidget<LCF>::DatabaseSplitWidget(ProjectData& project, QWidget* parent) :
	DatabaseSplitWidget(project, RpgReflect<LCF>::items(project.database()), parent)
{
}

template<class LCF>
void DatabaseSplitWidget<LCF>::setModel(QAbstractItemModel *model) {
	listWidget()->setModel(model);
	connect(listWidget()->selectionModel(), &QItemSelectionModel::currentChanged, this, [&](const QModelIndex &index) {
		// Based on the list index update the data of the content widget
		m_contentWidget->setData(
				listWidget()->model()->data(index, ModelData::ModelDataObject).template value<LCF*>());
	});
}
