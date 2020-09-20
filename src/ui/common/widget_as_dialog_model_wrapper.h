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

#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <QAbstractItemModel>
#include <lcf/rpg/fwd.h>
#include "widget_as_dialog_wrapper.h"
#include "ui/database/database_split_widget.h"

template<typename LCF>
class WidgetAsDialogModelWrapper : public WidgetAsDialogWrapperBase {

public:
	explicit WidgetAsDialogModelWrapper(ProjectData& project, QSortFilterProxyModel* filter, int index, QWidget* parent) : WidgetAsDialogWrapperBase(parent), dataOriginal(project) {
		dataCopy = dataOriginal;

		wrappedWidget = new DatabaseSplitWidget<LCF>(dataCopy, this);

		if (filter) {
			filter->setSourceModel(wrappedWidget->listWidget()->model());
			wrappedWidget->setModel(filter);
		}

		wrappedWidget->listWidget()->setCurrentIndex(
				wrappedWidget->listWidget()->model()->index(index, 0)
		);

		valueSelected(wrappedWidget->listWidget()->currentIndex().row());

		auto* verticalLayout = new QVBoxLayout(this);
		verticalLayout->addWidget(wrappedWidget);
		verticalLayout->addWidget(buttonBox);
		setLayout(verticalLayout);
	}
	DatabaseSplitWidget<LCF>* widget() const {
		return wrappedWidget;
	}

private:
	void apply() override {
		dataOriginal = dataCopy;
		emit valueSelected(wrappedWidget->listWidget()->currentIndex().row());
	}

private:
	DatabaseSplitWidget<LCF>* wrappedWidget = nullptr;

	ProjectData& dataOriginal;
	ProjectData dataCopy;
};
