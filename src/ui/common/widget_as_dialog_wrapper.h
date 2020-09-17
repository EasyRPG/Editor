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

/**
 * Wraps a Widget inside a Dialog and applies the forwarded data when OK or Apply
 * are pressed
 * @tparam WIDGET Type of the managed widget
 * @tparam DATA Data forwarded to the widget
 */
template<class WIDGET, typename DATA>
class WidgetAsDialogWrapper : public QDialog {

public:
	explicit WidgetAsDialogWrapper<WIDGET>(lcf::rpg::Database& db, DATA& data, QWidget* parent = nullptr) : QDialog(parent), dataOriginal(data) {
		dataCopy = data;

		wrappedWidget = new WIDGET(db, this);
		wrappedWidget->setData(&dataCopy);

		init();
	}

	explicit WidgetAsDialogWrapper<WIDGET>(DATA& data, QWidget* parent = nullptr) : QDialog(parent), dataOriginal(data) {
		dataCopy = data;

		wrappedWidget = new WIDGET(this);
		wrappedWidget->setData(&dataCopy);

		init();
	}

	WIDGET* widget() const {
		return wrappedWidget;
	}

private:
	void init() {
		buttonBox = new QDialogButtonBox(this);
		buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Help);

		auto* verticalLayout = new QVBoxLayout(this);
		verticalLayout->addWidget(wrappedWidget);
		verticalLayout->addWidget(buttonBox);

		QObject::connect(buttonBox, &QDialogButtonBox::clicked, this, &WidgetAsDialogWrapper::clicked);
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

	void apply() {
		dataOriginal = dataCopy;
	}

	void reject() override {
		QDialog::reject();
	}

	void help() {
		// FIXME: not implemented
	}

private:
	WIDGET* wrappedWidget = nullptr;
	QDialogButtonBox* buttonBox = nullptr;

	DATA& dataOriginal;
	DATA dataCopy;
};
