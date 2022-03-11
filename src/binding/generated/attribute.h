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
#include <lcf/rpg/attribute.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Attribute class.
 * Exposes lcf::rpg::Attribute to QML.
 */
namespace Binding::Generated {
class Attribute : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)
	Q_PROPERTY(int a_rate READ a_rate WRITE set_a_rate NOTIFY a_rate_changed)
	Q_PROPERTY(int b_rate READ b_rate WRITE set_b_rate NOTIFY b_rate_changed)
	Q_PROPERTY(int c_rate READ c_rate WRITE set_c_rate NOTIFY c_rate_changed)
	Q_PROPERTY(int d_rate READ d_rate WRITE set_d_rate NOTIFY d_rate_changed)
	Q_PROPERTY(int e_rate READ e_rate WRITE set_e_rate NOTIFY e_rate_changed)

public:
	Attribute(ProjectData& project, lcf::rpg::Attribute& data, QObject* parent = nullptr);

	lcf::rpg::Attribute& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int type();
	void set_type(const int& new_type);
	int a_rate();
	void set_a_rate(const int& new_a_rate);
	int b_rate();
	void set_b_rate(const int& new_b_rate);
	int c_rate();
	void set_c_rate(const int& new_c_rate);
	int d_rate();
	void set_d_rate(const int& new_d_rate);
	int e_rate();
	void set_e_rate(const int& new_e_rate);

signals:
	void name_changed();
	void type_changed();
	void a_rate_changed();
	void b_rate_changed();
	void c_rate_changed();
	void d_rate_changed();
	void e_rate_changed();

protected:
	lcf::rpg::Attribute& m_data;
};
} // namespace Binding::Generated
