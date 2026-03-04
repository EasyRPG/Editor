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

#include "lcf_glaze.h"
#include "json.h"

class JsonListView;

/**
 * A lightweight wrapper around a Json object that points at a subpath (pathPrefix).
 */
class JsonView : public QObject {
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(QString pathPrefix READ pathPrefix WRITE setPathPrefix NOTIFY pathPrefixChanged)

public:
	explicit JsonView(QObject* parent = nullptr) : QObject(parent) {}

	// documentation: see json.h

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return String at the given pointer location
	 */
	Q_INVOKABLE QString str(QString jsonPtr) const;

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return Integer at the given pointer location
	 */
	Q_INVOKABLE int num(QString jsonPtr) const;

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return bool at the given pointer location
	 */
	Q_INVOKABLE bool boolean(QString jsonPtr) const;

	/**
	 * Writes value to the given pointer location
	 *
	 * @param jsonPtr JSON Pointer to write to
	 * @param value Value to write
	 */
	// Limited write support. Implement more types in JsonT<LCFTYPE>::set
	Q_INVOKABLE void set(QString jsonPtr, const QVariant& value);

	/**
	 * @param jsonPtr JSON Pointer
	 * @return JsonView rooted at the given pointer location
	 */
	Q_INVOKABLE JsonView* subtree(QString jsonPtr);

	/**
	 * Access std::vector<> data at the given pointer location.
	 *
	 * @param jsonPtr JSON Pointer
	 * @return JsonListView rooted at the given pointer location
	 */
	Q_INVOKABLE JsonListView* list(QString jsonPtr);

	// Overloads for JsonViewT
	/**
	 * Dump the current tree as a JSON string.
	 * Mostly for debugging purposes.
	 *
	 * @return JSON string
	 */
	Q_INVOKABLE virtual QString toJson() const { return {}; };

	QString pathPrefix() const;
	void setPathPrefix(QString prefix);

signals:
	void pathPrefixChanged();

private:
	QString m_pathPrefix;
};

// LCFTYPE: Type of the LCF object stored (e.g. lcf::rpg::Database)
// ITEMTYPE: Type of the LCF object referenced by the view (e.g. lcf::rpg::Actor)
template<typename LCFTYPE, typename ITEMTYPE>
class JsonViewT : public JsonView {
public:
	explicit JsonViewT(QObject* parent = nullptr) : JsonView(parent) {}

	QString toJson() const override {
		auto raw_data = static_cast<Json*>(parent())->rawData();
		auto data = static_cast<LCFTYPE*>(raw_data);

		const auto& res = glz::get<ITEMTYPE>(*data, pathPrefix().toStdString()).value();

		std::string buffer{};
		auto ec = glz::write_json(res, buffer);
		if (ec) {
			qDebug() << glz::format_error(ec, buffer);
			return {};
		}

		return QString::fromStdString(buffer);
	};
};
