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
#include <QtQmlIntegration>
#include <QVariant>

#include "common/dbstring.h"
#include "lcf_glaze.h"

#include "json.h"
#include "json_view.h"
#include "json_list_view.h"

// Template implementation of Json
// In a different file due to circular dependencies with JsonView and JsonListView

// LCFTYPE: Type of the LCF object stored (e.g. lcf::rpg::Database)
template<typename LCFTYPE>
class JsonT : public Json {
public:
	explicit JsonT(QObject* parent = nullptr) : Json(parent) {}

	QString str(QString jsonPtr) const override;
	int num(QString jsonPtr) const override;
	bool boolean(QString jsonPtr) const override;
	void set(QString jsonPtr, const QVariant& value) override;
	QVariant subtree(QString jsonPtr) override;
	QVariant list(QString jsonPtr) override;

	void* rawData() override;

	LCFTYPE* data() const { return m_data; }
	void setData(LCFTYPE* data) { m_data = data; }

private:
	LCFTYPE* m_data = nullptr;
};

template<typename LCFTYPE>
inline QString JsonT<LCFTYPE>::str(QString jsonPtr) const {
	auto val = glaze_get<lcf::DBString>(m_data, jsonPtr);
	return ToQString(val);
}

template<typename LCFTYPE>
inline int JsonT<LCFTYPE>::num(QString jsonPtr) const {
	auto val = glaze_get<int>(m_data, jsonPtr);
	return val;
}

template <typename LCFTYPE>
inline bool JsonT<LCFTYPE>::boolean(QString jsonPtr) const {
	auto val = glaze_get<bool>(m_data, jsonPtr);
	return val;
}

template<typename LCFTYPE>
inline void JsonT<LCFTYPE>::set(QString jsonPtr, const QVariant& value) {
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

template <typename T>
concept IsVector = requires {
	typename T::value_type;
	requires std::same_as<T, std::vector<typename T::value_type, typename T::allocator_type>>;
};

template<typename LCFTYPE>
inline QVariant JsonT<LCFTYPE>::list(QString jsonPtr) {
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
inline void* JsonT<LCFTYPE>::rawData() {
	return m_data;
}

// Without this filter glz::seek has an awful compile time performance because
// we have so many structs in lcf::rpg::Database
// Opt-in here for all structs that use JsonViewT functionality in QML code
template<typename T>
concept LcfStructFilter =
    std::same_as<T, lcf::rpg::Terms>;

template<typename LCFTYPE>
inline QVariant JsonT<LCFTYPE>::subtree(QString jsonPtr) {
	JsonView* view = nullptr;

	glz::seek([&](auto& val) {
		using T = std::decay_t<decltype(val)>;

		if constexpr (LcfStructFilter<T>) {
			view = new JsonViewT<LCFTYPE, T>(this);
			view->setPathPrefix(jsonPtr);
		}
	}, *m_data, jsonPtr.toStdString());

	if (view == nullptr) {
		view = new JsonView(this);
		view->setPathPrefix(jsonPtr);
	}

	return QVariant::fromValue(view);
}
