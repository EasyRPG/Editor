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

#include <QCheckBox>
#include <QLineEdit>
#include <QGroupBox>

#include "widget_helper.h"

namespace {

}

void WidgetHelper::connect(QWidget* parent, QLineEdit* lineEdit) {
	auto callback = [=](){
		QVariant variant = lineEdit->property("ee_data");
		if (variant.isNull()) {
			return;
		}

		auto data = variant.value<LcfObjectHolder<std::string>>();
		data.obj() = lineEdit->text().toStdString();
	};

	parent->connect(lineEdit, &QLineEdit::textChanged, parent, callback);
}

void WidgetHelper::connect(QWidget* parent, QCheckBox* checkBox) {
	auto callback = [=](){
		QVariant variant = checkBox->property("ee_data");
		if (variant.isNull()) {
			return;
		}

		auto data = variant.value<LcfObjectHolder<bool>>();
		data.obj() = checkBox->isChecked();
	};

	parent->connect(checkBox, &QCheckBox::stateChanged, parent, callback);
}

void WidgetHelper::connect(QWidget* parent, QGroupBox* groupBox) {
	auto callback = [=](){
		QVariant variant = groupBox->property("ee_data");
		if (variant.isNull()) {
			return;
		}

		auto data = variant.value<LcfObjectHolder<bool>>();
		data.obj() = groupBox->isChecked();
	};

	parent->connect(groupBox, &QGroupBox::toggled, parent, callback);
}

void WidgetHelper::setProperty(QLineEdit* widget, std::string& data) {
	QVariant v;
	LcfObjectHolder oh(data);
	v.setValue(oh);
	widget->setProperty("ee_data", v);
	widget->setText(QString::fromStdString(data));
}

void WidgetHelper::setProperty(QCheckBox* widget, bool& data) {
	QVariant v;
	LcfObjectHolder oh(data);
	v.setValue(oh);
	widget->setProperty("ee_data", v);
	widget->setChecked(data);
}

void WidgetHelper::setProperty(QGroupBox* widget, bool& data) {
	QVariant v;
	LcfObjectHolder oh(data);
	v.setValue(oh);
	widget->setProperty("ee_data", v);
	widget->setChecked(data);
}
