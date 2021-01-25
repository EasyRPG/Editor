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
#include "model/project.h"
#include "ui/database/actor_widget.h"
#include "ui/database/attribute_widget.h"
#include "ui/database/battle_animation2_widget.h"
#include "ui/database/battle_animation_widget.h"
#include "ui/database/chipset_widget.h"
#include "ui/database/class_widget.h"
#include "ui/database/common_event_widget.h"
#include "ui/database/enemy_group_widget.h"
#include "ui/database/enemy_widget.h"
#include "ui/database/item_widget.h"
#include "ui/database/skill_widget.h"
#include "ui/database/state_widget.h"
#include "ui/database/terrain_widget.h"

class WidgetAsDialogWrapperBase : public QDialog {
	Q_OBJECT
public:
	explicit WidgetAsDialogWrapperBase(QWidget* parent = nullptr) : QDialog(parent) {
		buttonBox = new QDialogButtonBox(this);
		buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Help);

		QObject::connect(buttonBox, &QDialogButtonBox::clicked, this, &WidgetAsDialogWrapperBase::clicked);
	}

	void clicked(QAbstractButton* button) {
		switch (buttonBox->standardButton(button)) {
			case QDialogButtonBox::Ok:
				accept();
				break;
			case QDialogButtonBox::Cancel:
			case QDialogButtonBox::Close:
				reject();
				break;
			case QDialogButtonBox::Apply:
				apply();
				break;
			case QDialogButtonBox::Help:
				help();
				break;
			default:
				break;
		}
	}

	void accept() override {
		apply();
		QDialog::accept();
	};

	virtual void apply() {}

	void reject() override {
		QDialog::reject();
	}

	void help() {
		// FIXME: not implemented
	}

signals:
	void valueSelected(int newValue);

protected:
	QDialogButtonBox* buttonBox = nullptr;
};

template <typename T>
class HasApply {
private:
	typedef char YesType[1];
	typedef char NoType[2];
	template <typename C> static YesType& test( decltype(&C::apply) ) ;
	template <typename C> static NoType& test(...);
public:
	enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};

/**
 * Wraps a Widget inside a Dialog and applies the forwarded data when OK or Apply
 * are pressed
 * @tparam WIDGET Type of the managed widget
 * @tparam DATA Data forwarded to the widget
 */
template<typename WIDGET, typename DATA>
class WidgetAsDialogWrapper : public WidgetAsDialogWrapperBase {
public:
	explicit WidgetAsDialogWrapper(ProjectData& project, DATA& data, QWidget* parent = nullptr) :
	WidgetAsDialogWrapperBase(parent), dataOriginal(data) {
		dataCopy = data;

		wrappedWidget = new WIDGET(project, this);
		wrappedWidget->setData(&dataCopy);

		auto* verticalLayout = new QVBoxLayout(this);
		verticalLayout->addWidget(wrappedWidget);
		verticalLayout->addWidget(buttonBox);
		setLayout(verticalLayout);
	}

	WIDGET* widget() const {
		return wrappedWidget;
	}

private:
	void apply() override {
		if constexpr (HasApply<WIDGET>::value) {
			wrappedWidget->apply();
		}

		dataOriginal = dataCopy;
	}

private:
	DATA& dataOriginal;
	DATA dataCopy;
	WIDGET* wrappedWidget = nullptr;
};
