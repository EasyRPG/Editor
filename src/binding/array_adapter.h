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
#include "binding_base.h"

/**
 * Wrapper for arrays containing lcf-data where 1-indexing is useful.
 */
namespace Binding {
class ArrayAdapter : public QObject {
	Q_OBJECT
	Q_PROPERTY(QVector<Binding::BindingBase*> data READ data CONSTANT)

public:
	ArrayAdapter(QObject* parent = nullptr);

	Q_INVOKABLE Binding::BindingBase* get(int index);
	Q_INVOKABLE Binding::BindingBase* get0(int index);

	QVector<BindingBase*>& data();

signals:

protected:
	QVector<BindingBase*> m_data;
};
} // namespace Binding
