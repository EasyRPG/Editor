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

#include <QObject>
#include <QVariant>

#include "common/dbstring.h"
#include "lcf_glaze.h"
#include "json_t.h"
#include "json_seek_impl.h"

template<typename LCFTYPE>
JsonT<LCFTYPE>::JsonT(QObject* parent) : Json(parent) {}

template<typename LCFTYPE>
QString JsonT<LCFTYPE>::str(QString jsonPtr) const {
	auto res = glz::get<lcf::DBString>(*m_data, jsonPtr.toStdString());

	if (res) {
		return ToQString(res.value());
	}

	qDebug() << "Json::str: Not pointing to DBString: " << jsonPtr;

	return "!BAD POINTER!";
}

template<typename LCFTYPE>
int JsonT<LCFTYPE>::num(QString jsonPtr) const {
	auto res = glz::get<int>(*m_data, jsonPtr.toStdString());

	if (res) {
		return res.value();
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
	switch (value.typeId()) {
		case QMetaType::Int:
			glz::set(m_data, jsonPtr.toStdString(), value.toInt());
			break;
		case QMetaType::QString: {
			lcf::DBString s = ToDBString(value.value<QString>());
			glz::set(m_data, jsonPtr.toStdString(), s);
			break;
		}
		case QMetaType::Bool: {
			glz::set(m_data, jsonPtr.toStdString(), value.toBool());
			break;
		}
		default:
			assert(false);
			break;
	}
}

template<typename LCFTYPE>
QVariant JsonT<LCFTYPE>::list(QString jsonPtr) {
	return QVariant::fromValue(lcf_seek_list_impl<LCFTYPE>(m_data, jsonPtr, this));
}

template<typename LCFTYPE>
QVariant JsonT<LCFTYPE>::subtree(QString jsonPtr) {
	return QVariant::fromValue(lcf_seek_subtree_impl<LCFTYPE>(m_data, jsonPtr, this));
}

template<typename LCFTYPE>
void* JsonT<LCFTYPE>::rawData() {
	return m_data;
}

template<typename LCFTYPE>
void JsonT<LCFTYPE>::setData(LCFTYPE* data) {
	m_data = data;
}
