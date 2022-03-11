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

#include "array_adapter.h"

using namespace Binding;

ArrayAdapter::ArrayAdapter(QObject* parent) : QObject(parent) {

}

BindingBase* ArrayAdapter::get(int index) {
	return get0(index - 1);
}

BindingBase* ArrayAdapter::get0(int index) {
	if (index < 0 || index >= m_data.size()) {
		return nullptr;
	}

	return m_data[index];
}

QVector<BindingBase*>& ArrayAdapter::data() {
	return m_data;
}
