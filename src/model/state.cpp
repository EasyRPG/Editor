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

#include "state.h"
#include "ui/database/state_widget.h"

StateModel::StateModel(ProjectData& project, lcf::rpg::State& data) :
	RpgBase(project), m_data(data) {

}

lcf::rpg::State& StateModel::data() {
	return m_data;
}

QPixmap StateModel::preview() {
	return QPixmap();
}

QDialog* StateModel::edit(QWidget *parent) {
	return new WidgetAsDialogWrapper<StateWidget, lcf::rpg::State>(m_project, m_data, parent);
}
