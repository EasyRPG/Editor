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

	/**
	 * Dump the data given at the pointer location as raw JSON data.
	 * Only use this as a last resort or for debugging purposes.
	 *
	 * @param jsonPtr JSON Pointer
	 * @return JSON string
	 */
	Q_INVOKABLE QString toJson(QString jsonPtr) const;

	QString pathPrefix() const;
	void setPathPrefix(QString prefix);

signals:
	void pathPrefixChanged();

private:
	QString m_pathPrefix;
};
