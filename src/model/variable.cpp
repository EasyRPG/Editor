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

#include "variable.h"
//#include "ui/database/variable_widget.h"

Variable::Variable(lcf::rpg::Variable& data, lcf::rpg::Database& database) :
	m_data(data), database(database) {

}

lcf::rpg::Variable& Variable::data() {
	return m_data;
}
/*
QPixmap Variable::preview() {
	return QPixmap();
}

QDialog* Variable::edit(QWidget *parent) {
	return new WidgetAsDialogWrapper<VariableWidget, lcf::rpg::Variable>(database, m_data, parent);
}
*/