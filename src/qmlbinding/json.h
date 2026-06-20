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

/**
 * Base class holding a LCF Object for use with the Glaze JSON API.
 * The implementing template class is JsonT.
 * This is required because the Qt MOC preprocessor does not support templates.
 */
class Json : public QObject {
	Q_OBJECT
	QML_ELEMENT
	QML_UNCREATABLE("Json is an abstract base class")

public:
	explicit Json(QObject* parent = nullptr) : QObject(parent) {}

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return String at the given pointer location
	 */
	Q_INVOKABLE virtual QString str(QString jsonPtr) const = 0;

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return Integer at the given pointer location
	 */
	Q_INVOKABLE virtual int num(QString jsonPtr) const = 0;

	/**
	 * @param jsonPtr JSON Pointer to read from
	 * @return bool at the given pointer location
	 */
	Q_INVOKABLE virtual bool boolean(QString jsonPtr) const = 0;

	/**
	 * Writes value to the given pointer location
	 *
	 * @param jsonPtr JSON Pointer to write to
	 * @param value Value to write
	 */
	// Limited write support. Implement more types in JsonT<LCFTYPE>::set
	Q_INVOKABLE virtual void set(QString jsonPtr, const QVariant& value) = 0;

	/**
	 * @param jsonPtr JSON Pointer
	 * @return JsonView rooted at the given pointer location
	 */
	Q_INVOKABLE virtual QVariant subtree(QString jsonPtr) = 0;

	/**
	 * Access std::vector<> data at the given pointer location.
	 *
	 * @param jsonPtr JSON Pointer
	 * @return JsonListView rooted at the given pointer location
	 */
	Q_INVOKABLE virtual QVariant list(QString jsonPtr) = 0;

	/**
	 * Dump the data given at the pointer location as raw JSON data.
	 * Only use this as a last resort or for debugging purposes.
	 *
	 * @param jsonPtr JSON Pointer
	 * @return JSON string
	 */
	Q_INVOKABLE virtual QString toJson(QString jsonPtr) const = 0;

signals:
	void valueChanged(QString jsonPtr);
};
