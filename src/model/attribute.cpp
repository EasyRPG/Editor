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

#include "attribute.h"
#include "ui/database/attribute_widget.h"

Attribute::Attribute(lcf::rpg::Attribute& data, lcf::rpg::Database& database) :
	m_data(data), database(database) {

}

lcf::rpg::Attribute& Attribute::data() {
	return m_data;
}

QPixmap Attribute::preview() {
	return QPixmap();
}

QDialog* Attribute::edit(QWidget *parent) {
	return new WidgetAsDialogWrapper<AttributeWidget, lcf::rpg::Attribute>(database, m_data, parent);
}
