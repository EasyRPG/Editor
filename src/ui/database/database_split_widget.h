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

	QListView* listWidget() {
		return ui->list;
	}
	widget_type* contentWidget() {
		return m_contentWidget;
	}

private:
	ProjectData& m_project;

	widget_type* m_contentWidget;
};

template<class LCF>
inline DatabaseSplitWidget<LCF>::DatabaseSplitWidget(ProjectData& project, QWidget* parent) :
		m_project(project), DatabaseSplitWidgetBase(parent)
{
	m_contentWidget = new typename RpgReflect<LCF>::widget_type(m_project, this);
	QListView& list = *ui->list;
	list.setModel(new RpgModel<LCF>(project, parent));
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
			typename RpgReflect<LCF>::model_type(project, *list.model()->data(
					index, ModelData::ModelDataObject).value<LCF*>()).edit(this)->show();
		});

		QMenu menu(&list);
		menu.addAction(editAct);

		menu.exec(mapToGlobal(pos));
	});

}
