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
#include <lcf/rpg/parameters.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Parameters class.
 * Exposes lcf::rpg::Parameters to QML.
 */
namespace Binding::Generated {
class Parameters : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(QVector<int> maxhp READ maxhp WRITE set_maxhp NOTIFY maxhp_changed)
	Q_PROPERTY(QVector<int> maxsp READ maxsp WRITE set_maxsp NOTIFY maxsp_changed)
	Q_PROPERTY(QVector<int> attack READ attack WRITE set_attack NOTIFY attack_changed)
	Q_PROPERTY(QVector<int> defense READ defense WRITE set_defense NOTIFY defense_changed)
	Q_PROPERTY(QVector<int> spirit READ spirit WRITE set_spirit NOTIFY spirit_changed)
	Q_PROPERTY(QVector<int> agility READ agility WRITE set_agility NOTIFY agility_changed)

public:
	Parameters(ProjectData& project, lcf::rpg::Parameters& data, QObject* parent = nullptr);

	lcf::rpg::Parameters& data();
	QVector<int> maxhp();
	void set_maxhp(const QVector<int>& new_maxhp);
	QVector<int> maxsp();
	void set_maxsp(const QVector<int>& new_maxsp);
	QVector<int> attack();
	void set_attack(const QVector<int>& new_attack);
	QVector<int> defense();
	void set_defense(const QVector<int>& new_defense);
	QVector<int> spirit();
	void set_spirit(const QVector<int>& new_spirit);
	QVector<int> agility();
	void set_agility(const QVector<int>& new_agility);

signals:
	void maxhp_changed();
	void maxsp_changed();
	void attack_changed();
	void defense_changed();
	void spirit_changed();
	void agility_changed();

protected:
	lcf::rpg::Parameters& m_data;
};
} // namespace Binding::Generated
