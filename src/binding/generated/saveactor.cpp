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
#include "saveactor.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveActor::SaveActor(ProjectData& project, lcf::rpg::SaveActor& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SaveActor::id() {
		return m_data.ID;
	}
	QString SaveActor::name() {
		return QString::fromStdString(m_data.name);
	}
	void SaveActor::set_name(const QString& new_name) {
		if (QString::fromStdString(m_data.name) == new_name)
			return;
		m_data.name = new_name.toStdString();
		emit name_changed();
	}

	QString SaveActor::title() {
		return QString::fromStdString(m_data.title);
	}
	void SaveActor::set_title(const QString& new_title) {
		if (QString::fromStdString(m_data.title) == new_title)
			return;
		m_data.title = new_title.toStdString();
		emit title_changed();
	}

	QString SaveActor::sprite_name() {
		return QString::fromStdString(m_data.sprite_name);
	}
	void SaveActor::set_sprite_name(const QString& new_sprite_name) {
		if (QString::fromStdString(m_data.sprite_name) == new_sprite_name)
			return;
		m_data.sprite_name = new_sprite_name.toStdString();
		emit sprite_name_changed();
	}

	int SaveActor::sprite_id() {
		return m_data.sprite_id;
	}
	void SaveActor::set_sprite_id(const int& new_sprite_id) {
		if (m_data.sprite_id == new_sprite_id)
			return;
		m_data.sprite_id = new_sprite_id;
		emit sprite_id_changed();
	}

	int SaveActor::transparency() {
		return m_data.transparency;
	}
	void SaveActor::set_transparency(const int& new_transparency) {
		if (m_data.transparency == new_transparency)
			return;
		m_data.transparency = new_transparency;
		emit transparency_changed();
	}

	QString SaveActor::face_name() {
		return QString::fromStdString(m_data.face_name);
	}
	void SaveActor::set_face_name(const QString& new_face_name) {
		if (QString::fromStdString(m_data.face_name) == new_face_name)
			return;
		m_data.face_name = new_face_name.toStdString();
		emit face_name_changed();
	}

	int SaveActor::face_id() {
		return m_data.face_id;
	}
	void SaveActor::set_face_id(const int& new_face_id) {
		if (m_data.face_id == new_face_id)
			return;
		m_data.face_id = new_face_id;
		emit face_id_changed();
	}

	int SaveActor::level() {
		return m_data.level;
	}
	void SaveActor::set_level(const int& new_level) {
		if (m_data.level == new_level)
			return;
		m_data.level = new_level;
		emit level_changed();
	}

	int SaveActor::exp() {
		return m_data.exp;
	}
	void SaveActor::set_exp(const int& new_exp) {
		if (m_data.exp == new_exp)
			return;
		m_data.exp = new_exp;
		emit exp_changed();
	}

	int SaveActor::hp_mod() {
		return m_data.hp_mod;
	}
	void SaveActor::set_hp_mod(const int& new_hp_mod) {
		if (m_data.hp_mod == new_hp_mod)
			return;
		m_data.hp_mod = new_hp_mod;
		emit hp_mod_changed();
	}

	int SaveActor::sp_mod() {
		return m_data.sp_mod;
	}
	void SaveActor::set_sp_mod(const int& new_sp_mod) {
		if (m_data.sp_mod == new_sp_mod)
			return;
		m_data.sp_mod = new_sp_mod;
		emit sp_mod_changed();
	}

	int SaveActor::attack_mod() {
		return m_data.attack_mod;
	}
	void SaveActor::set_attack_mod(const int& new_attack_mod) {
		if (m_data.attack_mod == new_attack_mod)
			return;
		m_data.attack_mod = new_attack_mod;
		emit attack_mod_changed();
	}

	int SaveActor::defense_mod() {
		return m_data.defense_mod;
	}
	void SaveActor::set_defense_mod(const int& new_defense_mod) {
		if (m_data.defense_mod == new_defense_mod)
			return;
		m_data.defense_mod = new_defense_mod;
		emit defense_mod_changed();
	}

	int SaveActor::spirit_mod() {
		return m_data.spirit_mod;
	}
	void SaveActor::set_spirit_mod(const int& new_spirit_mod) {
		if (m_data.spirit_mod == new_spirit_mod)
			return;
		m_data.spirit_mod = new_spirit_mod;
		emit spirit_mod_changed();
	}

	int SaveActor::agility_mod() {
		return m_data.agility_mod;
	}
	void SaveActor::set_agility_mod(const int& new_agility_mod) {
		if (m_data.agility_mod == new_agility_mod)
			return;
		m_data.agility_mod = new_agility_mod;
		emit agility_mod_changed();
	}

	QVector<int> SaveActor::skills() {
		return QVector<int>(m_data.skills.begin(), m_data.skills.end());
	}
	void SaveActor::set_skills(const QVector<int>& new_skills) {
		if (QVector<int>(m_data.skills.begin(), m_data.skills.end()) == new_skills)
			return;
		m_data.skills = decltype(m_data.skills)(new_skills.begin(), new_skills.end());
		emit skills_changed();
	}

	QVector<int> SaveActor::equipped() {
		return QVector<int>(m_data.equipped.begin(), m_data.equipped.end());
	}
	void SaveActor::set_equipped(const QVector<int>& new_equipped) {
		if (QVector<int>(m_data.equipped.begin(), m_data.equipped.end()) == new_equipped)
			return;
		m_data.equipped = decltype(m_data.equipped)(new_equipped.begin(), new_equipped.end());
		emit equipped_changed();
	}

	int SaveActor::current_hp() {
		return m_data.current_hp;
	}
	void SaveActor::set_current_hp(const int& new_current_hp) {
		if (m_data.current_hp == new_current_hp)
			return;
		m_data.current_hp = new_current_hp;
		emit current_hp_changed();
	}

	int SaveActor::current_sp() {
		return m_data.current_sp;
	}
	void SaveActor::set_current_sp(const int& new_current_sp) {
		if (m_data.current_sp == new_current_sp)
			return;
		m_data.current_sp = new_current_sp;
		emit current_sp_changed();
	}

	QVector<int> SaveActor::battle_commands() {
		return QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end());
	}
	void SaveActor::set_battle_commands(const QVector<int>& new_battle_commands) {
		if (QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end()) == new_battle_commands)
			return;
		m_data.battle_commands = decltype(m_data.battle_commands)(new_battle_commands.begin(), new_battle_commands.end());
		emit battle_commands_changed();
	}

	QVector<int> SaveActor::status() {
		return QVector<int>(m_data.status.begin(), m_data.status.end());
	}
	void SaveActor::set_status(const QVector<int>& new_status) {
		if (QVector<int>(m_data.status.begin(), m_data.status.end()) == new_status)
			return;
		m_data.status = decltype(m_data.status)(new_status.begin(), new_status.end());
		emit status_changed();
	}

	bool SaveActor::changed_battle_commands() {
		return m_data.changed_battle_commands;
	}
	void SaveActor::set_changed_battle_commands(const bool& new_changed_battle_commands) {
		if (m_data.changed_battle_commands == new_changed_battle_commands)
			return;
		m_data.changed_battle_commands = new_changed_battle_commands;
		emit changed_battle_commands_changed();
	}

	int SaveActor::class_id() {
		return m_data.class_id;
	}
	void SaveActor::set_class_id(const int& new_class_id) {
		if (m_data.class_id == new_class_id)
			return;
		m_data.class_id = new_class_id;
		emit class_id_changed();
	}

	int SaveActor::row() {
		return m_data.row;
	}
	void SaveActor::set_row(const int& new_row) {
		if (m_data.row == new_row)
			return;
		m_data.row = new_row;
		emit row_changed();
	}

	bool SaveActor::two_weapon() {
		return m_data.two_weapon;
	}
	void SaveActor::set_two_weapon(const bool& new_two_weapon) {
		if (m_data.two_weapon == new_two_weapon)
			return;
		m_data.two_weapon = new_two_weapon;
		emit two_weapon_changed();
	}

	bool SaveActor::lock_equipment() {
		return m_data.lock_equipment;
	}
	void SaveActor::set_lock_equipment(const bool& new_lock_equipment) {
		if (m_data.lock_equipment == new_lock_equipment)
			return;
		m_data.lock_equipment = new_lock_equipment;
		emit lock_equipment_changed();
	}

	bool SaveActor::auto_battle() {
		return m_data.auto_battle;
	}
	void SaveActor::set_auto_battle(const bool& new_auto_battle) {
		if (m_data.auto_battle == new_auto_battle)
			return;
		m_data.auto_battle = new_auto_battle;
		emit auto_battle_changed();
	}

	bool SaveActor::super_guard() {
		return m_data.super_guard;
	}
	void SaveActor::set_super_guard(const bool& new_super_guard) {
		if (m_data.super_guard == new_super_guard)
			return;
		m_data.super_guard = new_super_guard;
		emit super_guard_changed();
	}

	int SaveActor::battler_animation() {
		return m_data.battler_animation;
	}
	void SaveActor::set_battler_animation(const int& new_battler_animation) {
		if (m_data.battler_animation == new_battler_animation)
			return;
		m_data.battler_animation = new_battler_animation;
		emit battler_animation_changed();
	}

} // namespace Binding::Generated
