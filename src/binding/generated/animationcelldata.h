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
#include <lcf/rpg/animationcelldata.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::AnimationCellData class.
 * Exposes lcf::rpg::AnimationCellData to QML.
 */
namespace Binding::Generated {
class AnimationCellData : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int valid READ valid WRITE set_valid NOTIFY valid_changed)
	Q_PROPERTY(int cell_id READ cell_id WRITE set_cell_id NOTIFY cell_id_changed)
	Q_PROPERTY(int x READ x WRITE set_x NOTIFY x_changed)
	Q_PROPERTY(int y READ y WRITE set_y NOTIFY y_changed)
	Q_PROPERTY(int zoom READ zoom WRITE set_zoom NOTIFY zoom_changed)
	Q_PROPERTY(int tone_red READ tone_red WRITE set_tone_red NOTIFY tone_red_changed)
	Q_PROPERTY(int tone_green READ tone_green WRITE set_tone_green NOTIFY tone_green_changed)
	Q_PROPERTY(int tone_blue READ tone_blue WRITE set_tone_blue NOTIFY tone_blue_changed)
	Q_PROPERTY(int tone_gray READ tone_gray WRITE set_tone_gray NOTIFY tone_gray_changed)
	Q_PROPERTY(int transparency READ transparency WRITE set_transparency NOTIFY transparency_changed)

public:
	AnimationCellData(ProjectData& project, lcf::rpg::AnimationCellData& data, QObject* parent = nullptr);

	lcf::rpg::AnimationCellData& data();
	int id();
	int valid();
	void set_valid(const int& new_valid);
	int cell_id();
	void set_cell_id(const int& new_cell_id);
	int x();
	void set_x(const int& new_x);
	int y();
	void set_y(const int& new_y);
	int zoom();
	void set_zoom(const int& new_zoom);
	int tone_red();
	void set_tone_red(const int& new_tone_red);
	int tone_green();
	void set_tone_green(const int& new_tone_green);
	int tone_blue();
	void set_tone_blue(const int& new_tone_blue);
	int tone_gray();
	void set_tone_gray(const int& new_tone_gray);
	int transparency();
	void set_transparency(const int& new_transparency);

signals:
	void valid_changed();
	void cell_id_changed();
	void x_changed();
	void y_changed();
	void zoom_changed();
	void tone_red_changed();
	void tone_green_changed();
	void tone_blue_changed();
	void tone_gray_changed();
	void transparency_changed();

protected:
	lcf::rpg::AnimationCellData& m_data;
};
} // namespace Binding::Generated
