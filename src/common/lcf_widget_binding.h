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

class QWidget;
class QLineEdit;
class QCheckBox;
class QGroupBox;

#include <QObject>
#include <QCheckBox>
#include <QSpinBox>
#include <QComboBox>
#include <QGroupBox>
#include <QVariant>
#include <QButtonGroup>
#include <string>

#include "ui/common/rpg_combobox.h"
#include "signal_blocker.h"

template<class T>
class LcfObjectHolder : QObject {
public:
	LcfObjectHolder() = default;

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
Q_DECLARE_METATYPE(LcfObjectHolder<int8_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint8_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<int16_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint16_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<int32_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<uint32_t>)
Q_DECLARE_METATYPE(LcfObjectHolder<double>)
Q_DECLARE_METATYPE(LcfObjectHolder<lcf::DBString>)

namespace LcfWidgetBinding {
	void connect(QWidget* parent, QLineEdit* lineEdit);

	template<typename T>
	void connect(QWidget* parent, QCheckBox* checkBox) {
		auto callback = [=](){
			QVariant variant = checkBox->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			data.obj() = static_cast<T>(checkBox->isChecked());
		};

		QWidget::connect(checkBox, &QCheckBox::stateChanged, parent, callback);
	}

	template<typename T>
	void connect(QWidget* parent, QGroupBox* groupBox) {
		auto callback = [=](){
			QVariant variant = groupBox->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			data.obj() = static_cast<T>(groupBox->isChecked());
		};

		QWidget::connect(groupBox, &QGroupBox::toggled, parent, callback);
	}

	template<typename T>
	void connect(QWidget* parent, QSpinBox* spinBox) {
		auto callback = [=](){
			QVariant variant = spinBox->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			data.obj() = static_cast<T>(spinBox->value());
		};

		QWidget::connect(spinBox, qOverload<int>(&QSpinBox::valueChanged), parent, callback);
	}

	template<typename T>
	void connect(QWidget* parent, QComboBox* comboBox) {
		auto callback = [=](){
			QVariant variant = comboBox->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			data.obj() = static_cast<T>(comboBox->currentIndex());
		};

		QWidget::connect(comboBox, qOverload<int>(&QComboBox::currentIndexChanged), parent, callback);
	}

	template<typename T>
	void connect(QWidget* parent, QButtonGroup* buttonGroup) {
		auto callback = [=](){
			QVariant variant = buttonGroup->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			auto id = buttonGroup->checkedId();
			Q_ASSERT(id >= 0);

			data.obj() = static_cast<T>(id);
		};

		QWidget::connect(buttonGroup, QOverload<QAbstractButton *, bool>::of(&QButtonGroup::buttonToggled), parent, callback);
	}

	template<typename T, typename U>
	void connect(QWidget* parent, RpgComboBox<U>* comboBox) {
		auto callback = [=](){
			QVariant variant = comboBox->property("ee_data");
			if (variant.isNull()) {
				return;
			}

			auto data = variant.value<LcfObjectHolder<T>>();
			data.obj() = static_cast<T>(comboBox->comboBox()->currentData().toInt());
		};

		QWidget::connect(comboBox->comboBox(), qOverload<int>(&QComboBox::currentIndexChanged), parent, callback);
	}

	void bind(QLineEdit* widget, lcf::DBString& data);

	template<typename T>
	void bind(QCheckBox* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);
		SignalBlocker s(widget);
		widget->setChecked(data != 0);
	}

	template<>
	void bind(QCheckBox* widget, bool& data);

	template<typename T>
	void bind(QGroupBox* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);
		SignalBlocker s(widget);
		widget->setChecked(data != 0);
	}

	template<>
	void bind(QGroupBox* widget, bool& data);

	template<typename T>
	void bind(QSpinBox* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);
		SignalBlocker s(widget);
		widget->setValue(data);
	}

	template<typename T>
	void bind(QComboBox* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);

		SignalBlocker s(widget);
		widget->setCurrentIndex(widget->findData(data));
	}

	template<typename T, typename U>
	void bind(RpgComboBox<U>* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);

		SignalBlocker s(widget->comboBox());
		widget->setCurrentIndex(widget->comboBox()->findData(data));
	}

	template<typename T>
	void bind(QButtonGroup* widget, T& data) {
		QVariant v;
		LcfObjectHolder oh(data);
		v.setValue(oh);
		widget->setProperty("ee_data", v);

		SignalBlocker s(widget);
		auto* button = widget->button(data);
		Q_ASSERT(button && "No button with this ID!");

		button->setChecked(true);
	}
}
