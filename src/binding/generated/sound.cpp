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
#include "sound.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Sound::Sound(ProjectData& project, lcf::rpg::Sound& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	QString Sound::name() {
		return QString::fromStdString(m_data.name);
	}
	void Sound::set_name(const QString& new_name) {
		if (QString::fromStdString(m_data.name) == new_name)
			return;
		m_data.name = new_name.toStdString();
		emit name_changed();
	}

	int Sound::volume() {
		return m_data.volume;
	}
	void Sound::set_volume(const int& new_volume) {
		if (m_data.volume == new_volume)
			return;
		m_data.volume = new_volume;
		emit volume_changed();
	}

	int Sound::tempo() {
		return m_data.tempo;
	}
	void Sound::set_tempo(const int& new_tempo) {
		if (m_data.tempo == new_tempo)
			return;
		m_data.tempo = new_tempo;
		emit tempo_changed();
	}

	int Sound::balance() {
		return m_data.balance;
	}
	void Sound::set_balance(const int& new_balance) {
		if (m_data.balance == new_balance)
			return;
		m_data.balance = new_balance;
		emit balance_changed();
	}

} // namespace Binding::Generated
