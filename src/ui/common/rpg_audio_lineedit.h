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

#pragma once

#include <QObject>
#include <QWidget>

class QLineEdit;
class QPushButton;
class ProjectData;

namespace lcf::rpg {
	class Music;
	class Sound;
}

class RpgAudioLineEdit : public QWidget {
	Q_OBJECT
public:
	explicit RpgAudioLineEdit(QWidget *parent = nullptr);

	void makeModel(ProjectData& project);

	QLineEdit* lineEdit() const;

	virtual void editPressed() = 0;

protected:
	QLineEdit* m_lineEdit = nullptr;
	QPushButton* m_editButton = nullptr;
	ProjectData* m_project = nullptr;
};

class RpgMusicLineEdit : public RpgAudioLineEdit {
public:
	explicit RpgMusicLineEdit(QWidget *parent = nullptr) : RpgAudioLineEdit(parent) {}

	void editPressed() override;
	void bindMusic(lcf::rpg::Music& music);

private:
	lcf::rpg::Music* m_music = nullptr;
};

class RpgSoundLineEdit : public RpgAudioLineEdit {
public:
	explicit RpgSoundLineEdit(QWidget *parent = nullptr) : RpgAudioLineEdit(parent) {}

	void editPressed() override;
	void bindSound(lcf::rpg::Sound& sound);

private:
	lcf::rpg::Sound* m_sound = nullptr;
};
