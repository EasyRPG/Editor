/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
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

// Headers
#include "savetitle.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveTitle::SaveTitle(ProjectData& project, lcf::rpg::SaveTitle& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	double SaveTitle::timestamp() {
		return m_data.timestamp;
	}
	void SaveTitle::set_timestamp(const double& new_timestamp) {
		if (m_data.timestamp == new_timestamp)
			return;
		m_data.timestamp = new_timestamp;
		emit timestamp_changed();
	}

	QString SaveTitle::hero_name() {
		return QString::fromStdString(m_data.hero_name);
	}
	void SaveTitle::set_hero_name(const QString& new_hero_name) {
		if (QString::fromStdString(m_data.hero_name) == new_hero_name)
			return;
		m_data.hero_name = new_hero_name.toStdString();
		emit hero_name_changed();
	}

	int SaveTitle::hero_level() {
		return m_data.hero_level;
	}
	void SaveTitle::set_hero_level(const int& new_hero_level) {
		if (m_data.hero_level == new_hero_level)
			return;
		m_data.hero_level = new_hero_level;
		emit hero_level_changed();
	}

	int SaveTitle::hero_hp() {
		return m_data.hero_hp;
	}
	void SaveTitle::set_hero_hp(const int& new_hero_hp) {
		if (m_data.hero_hp == new_hero_hp)
			return;
		m_data.hero_hp = new_hero_hp;
		emit hero_hp_changed();
	}

	QString SaveTitle::face1_name() {
		return QString::fromStdString(m_data.face1_name);
	}
	void SaveTitle::set_face1_name(const QString& new_face1_name) {
		if (QString::fromStdString(m_data.face1_name) == new_face1_name)
			return;
		m_data.face1_name = new_face1_name.toStdString();
		emit face1_name_changed();
	}

	int SaveTitle::face1_id() {
		return m_data.face1_id;
	}
	void SaveTitle::set_face1_id(const int& new_face1_id) {
		if (m_data.face1_id == new_face1_id)
			return;
		m_data.face1_id = new_face1_id;
		emit face1_id_changed();
	}

	QString SaveTitle::face2_name() {
		return QString::fromStdString(m_data.face2_name);
	}
	void SaveTitle::set_face2_name(const QString& new_face2_name) {
		if (QString::fromStdString(m_data.face2_name) == new_face2_name)
			return;
		m_data.face2_name = new_face2_name.toStdString();
		emit face2_name_changed();
	}

	int SaveTitle::face2_id() {
		return m_data.face2_id;
	}
	void SaveTitle::set_face2_id(const int& new_face2_id) {
		if (m_data.face2_id == new_face2_id)
			return;
		m_data.face2_id = new_face2_id;
		emit face2_id_changed();
	}

	QString SaveTitle::face3_name() {
		return QString::fromStdString(m_data.face3_name);
	}
	void SaveTitle::set_face3_name(const QString& new_face3_name) {
		if (QString::fromStdString(m_data.face3_name) == new_face3_name)
			return;
		m_data.face3_name = new_face3_name.toStdString();
		emit face3_name_changed();
	}

	int SaveTitle::face3_id() {
		return m_data.face3_id;
	}
	void SaveTitle::set_face3_id(const int& new_face3_id) {
		if (m_data.face3_id == new_face3_id)
			return;
		m_data.face3_id = new_face3_id;
		emit face3_id_changed();
	}

	QString SaveTitle::face4_name() {
		return QString::fromStdString(m_data.face4_name);
	}
	void SaveTitle::set_face4_name(const QString& new_face4_name) {
		if (QString::fromStdString(m_data.face4_name) == new_face4_name)
			return;
		m_data.face4_name = new_face4_name.toStdString();
		emit face4_name_changed();
	}

	int SaveTitle::face4_id() {
		return m_data.face4_id;
	}
	void SaveTitle::set_face4_id(const int& new_face4_id) {
		if (m_data.face4_id == new_face4_id)
			return;
		m_data.face4_id = new_face4_id;
		emit face4_id_changed();
	}

} // namespace Binding::Generated
