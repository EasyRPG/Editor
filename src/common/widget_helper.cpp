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

#include <QObject>
#include <QLineEdit>

#include "widget_helper.h"


template<class T>
class LcfObjectHolder : QObject {
public:
	LcfObjectHolder() {}

	LcfObjectHolder(T& obj) : m_obj(&obj) {}

	LcfObjectHolder(const LcfObjectHolder<T>& other) {
		m_obj = other.m_obj;
	}

	T& obj() {
		return *m_obj;
	}

private:
	T* m_obj = nullptr;
};

Q_DECLARE_METATYPE(LcfObjectHolder<std::string>)
Q_DECLARE_METATYPE(LcfObjectHolder<bool>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint8_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint16_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint32_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<double>)

namespace {

}

void WidgetHelper::connect(QWidget* parent, QLineEdit* lineEdit) {
	auto lineEdit_callback = [=](){
		QVariant variant = lineEdit->property("ee_data");
		if (variant.isNull()) {
			return;
		}

		auto data = variant.value<LcfObjectHolder<std::string>>();
		data.obj() = lineEdit->text().toStdString();
	};

	parent->connect(lineEdit, &QLineEdit::textChanged, parent, lineEdit_callback);
}

void WidgetHelper::setProperty(QLineEdit* widget, std::string& data) {
	QVariant v;
	LcfObjectHolder oh(data);
	v.setValue(oh);
	widget->setProperty("ee_data", v);
	widget->setText(QString::fromStdString(data));
}
