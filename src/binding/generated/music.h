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

#pragma once

// Headers
#include <lcf/rpg/music.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Music class.
 * Exposes lcf::rpg::Music to QML.
 */
namespace Binding::Generated {
class Music : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int fadein READ fadein WRITE set_fadein NOTIFY fadein_changed)
	Q_PROPERTY(int volume READ volume WRITE set_volume NOTIFY volume_changed)
	Q_PROPERTY(int tempo READ tempo WRITE set_tempo NOTIFY tempo_changed)
	Q_PROPERTY(int balance READ balance WRITE set_balance NOTIFY balance_changed)

public:
	Music(ProjectData& project, lcf::rpg::Music& data, QObject* parent = nullptr);

	lcf::rpg::Music& data();
	QString name();
	void set_name(const QString& new_name);
	int fadein();
	void set_fadein(const int& new_fadein);
	int volume();
	void set_volume(const int& new_volume);
	int tempo();
	void set_tempo(const int& new_tempo);
	int balance();
	void set_balance(const int& new_balance);

signals:
	void name_changed();
	void fadein_changed();
	void volume_changed();
	void tempo_changed();
	void balance_changed();

protected:
	lcf::rpg::Music& m_data;
};
} // namespace Binding::Generated
