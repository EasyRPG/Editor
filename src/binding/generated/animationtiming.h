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
#include <lcf/rpg/animationtiming.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/sound.h"

class ProjectData;

/**
 * Binding::Generated::AnimationTiming class.
 * Exposes lcf::rpg::AnimationTiming to QML.
 */
namespace Binding::Generated {
class AnimationTiming : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int frame READ frame WRITE set_frame NOTIFY frame_changed)
	Q_PROPERTY(Binding::Sound* se READ se CONSTANT)
	Q_PROPERTY(int flash_scope READ flash_scope WRITE set_flash_scope NOTIFY flash_scope_changed)
	Q_PROPERTY(int flash_red READ flash_red WRITE set_flash_red NOTIFY flash_red_changed)
	Q_PROPERTY(int flash_green READ flash_green WRITE set_flash_green NOTIFY flash_green_changed)
	Q_PROPERTY(int flash_blue READ flash_blue WRITE set_flash_blue NOTIFY flash_blue_changed)
	Q_PROPERTY(int flash_power READ flash_power WRITE set_flash_power NOTIFY flash_power_changed)
	Q_PROPERTY(int screen_shake READ screen_shake WRITE set_screen_shake NOTIFY screen_shake_changed)

public:
	AnimationTiming(ProjectData& project, lcf::rpg::AnimationTiming& data, QObject* parent = nullptr);

	lcf::rpg::AnimationTiming& data();
	int id();
	int frame();
	void set_frame(const int& new_frame);
	Binding::Sound* se();
	int flash_scope();
	void set_flash_scope(const int& new_flash_scope);
	int flash_red();
	void set_flash_red(const int& new_flash_red);
	int flash_green();
	void set_flash_green(const int& new_flash_green);
	int flash_blue();
	void set_flash_blue(const int& new_flash_blue);
	int flash_power();
	void set_flash_power(const int& new_flash_power);
	int screen_shake();
	void set_screen_shake(const int& new_screen_shake);

signals:
	void frame_changed();
	void flash_scope_changed();
	void flash_red_changed();
	void flash_green_changed();
	void flash_blue_changed();
	void flash_power_changed();
	void screen_shake_changed();

protected:
	lcf::rpg::AnimationTiming& m_data;
	Binding::Sound* m_se;
};
} // namespace Binding::Generated
