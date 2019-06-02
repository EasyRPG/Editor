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

#include "database_split_widget.h"
#include "ui_database_split_widget.h"
#include "model/list_model.h"

DatabaseSplitWidgetBase::DatabaseSplitWidgetBase(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::DatabaseSplitWidget)
{
	ui->setupUi(this);
}

DatabaseSplitWidgetBase::~DatabaseSplitWidgetBase()
{
	delete ui;
}

template<class T, class U>
DatabaseSplitWidget<T, U>::DatabaseSplitWidget(RPG::Database& database, std::vector<T>& data, QWidget* parent) :
	db(database), DatabaseSplitWidgetBase(parent)
{
	m_contentWidget = new U(db, this);
	ui->list->setModel(new ListModel<T>(data));
	ui->splitter->addWidget(m_contentWidget);
	ui->splitter->setStretchFactor(0, 1);
	ui->splitter->setStretchFactor(1, 4);

	connect(ui->list, &QListView::activated, this, [&](const QModelIndex &index) {
		m_contentWidget->setData(&data[index.row()]);
	});
}

template<class T, class U>
QWidget* DatabaseSplitWidget<T, U>::listWidget() {
	return ui->list;
}

template<class T, class U>
U* DatabaseSplitWidget<T, U>::contentWidget() {
	return m_contentWidget;
}
