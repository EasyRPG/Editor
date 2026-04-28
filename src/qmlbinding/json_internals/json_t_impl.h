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

// Do not include this file! Only include json_t.h

#include <QObject>
#include <QVariant>
#include <glaze/json/generic.hpp>

#include "common/dbstring.h"
#include "lcf_glaze.h"
#include "json_view.h"
#include "json_list_view.h"
#include "json_t.h"

template<typename LCFTYPE>
JsonT<LCFTYPE>::JsonT(QObject* parent) : Json(parent) {}

template<typename LCFTYPE>
QString JsonT<LCFTYPE>::str(QString jsonPtr) const {
	auto res = glz::get<lcf::DBString>(*m_data, jsonPtr.toStdString());
	if (res) {
		return ToQString(res.value());
	}

	auto res2 = glz::get<std::string>(*m_data, jsonPtr.toStdString());
	if (res2) {
		return ToQString(res2.value());
	}

	qDebug() << "Json::str: Not pointing to String: " << jsonPtr;

	return "!BAD POINTER!";
}

template<typename LCFTYPE>
int JsonT<LCFTYPE>::num(QString jsonPtr) const {
	std::string ptr = jsonPtr.toStdString();

	if (auto res = glz::get<int32_t>(*m_data, ptr)) {
		return res.value().get();
	}

	if (auto res = glz::get<uint32_t>(*m_data, ptr)) {
		return static_cast<int>(res.value().get());
	}

	if (auto res = glz::get<int16_t>(*m_data, ptr)) {
		return static_cast<int>(res.value().get());
	}

	if (auto res = glz::get<uint16_t>(*m_data, ptr)) {
		return static_cast<int>(res.value().get());
	}

	qDebug() << "Json::num: Not pointing to int: " << jsonPtr;

	return -0xEA51;
}

template <typename LCFTYPE>
bool JsonT<LCFTYPE>::boolean(QString jsonPtr) const {
	auto res = glz::get<bool>(*m_data, jsonPtr.toStdString());

	if (res) {
		return res.value();
	}

	qDebug() << "Json::boolean: Not pointing to bool: " << jsonPtr;

	return false;
}

template<typename LCFTYPE>
void JsonT<LCFTYPE>::set(QString jsonPtr, const QVariant& value) {
	bool ok = true;
	std::string ptr = jsonPtr.toStdString();

	switch (value.typeId()) {
		case QMetaType::Int:
			ok = glz::set(m_data, ptr, value.toInt());
			break;
		case QMetaType::Double:
			ok = glz::set(m_data, ptr, value.toDouble());
			break;
		case QMetaType::QString: {
			lcf::DBString s = ToDBString(value.value<QString>());
			ok = glz::set(m_data, ptr, s);

			if (!ok) {
				std::string s2 = value.value<QString>().toStdString();
				ok = glz::set(m_data, ptr, s2);
			}
			break;
		}
		case QMetaType::Bool: {
			ok = glz::set(m_data, ptr, value.toBool());
			break;
		}
		default:
			qDebug() << QString("Json::set: Type %1 unsupported for path %2").arg(value.typeName()).arg(jsonPtr);
			break;
	}

	if (!ok) {
		qDebug() << QString("Json::set: Assignment of type %1 failed for path %2").arg(value.typeName()).arg(jsonPtr);
	}
}

template <typename T>
concept IsVector = requires {
	typename T::value_type;
} && std::is_class_v<typename T::value_type>;

template<typename LCFTYPE>
QVariant JsonT<LCFTYPE>::list(QString jsonPtr) {
	JsonListView* list_view = nullptr;

	glz::seek([&](auto& val) {
		using T = std::decay_t<decltype(val)>;

		if constexpr (IsVector<T>) {
			auto view = new JsonView(this);
			view->setPathPrefix(jsonPtr);
			list_view = new JsonListViewT<typename T::value_type>(this, &val, view);
		}
	}, *m_data, jsonPtr.toStdString());

	return QVariant::fromValue(list_view);
}

template<typename LCFTYPE>
QVariant JsonT<LCFTYPE>::subtree(QString jsonPtr) {
	JsonView* view = new JsonView(this);
	view->setPathPrefix(jsonPtr);
	return QVariant::fromValue(view);
}

template<typename LCFTYPE>
QString JsonT<LCFTYPE>::toJson(QString jsonPtr) const {
	std::string buffer{};
	auto ec = glz::write_json(*m_data, buffer);
	if (ec) {
		qDebug() << glz::format_error(ec, buffer);
		return {};
	}

	auto view = glz::get_view_json(jsonPtr.toStdString(), buffer);
	if (view) {
		return QString::fromUtf8(view->data(), view->size());
	}

	qDebug() << "Json::toJson: Invalid pointer: " << jsonPtr;

	return "!BAD POINTER!";
}

template<typename LCFTYPE>
void JsonT<LCFTYPE>::setData(LCFTYPE* data) {
	m_data = data;
}
