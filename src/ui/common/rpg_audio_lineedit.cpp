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

#include "rpg_audio_lineedit.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <lcf/rpg/music.h>
#include <lcf/rpg/sound.h>

#include "defines.h"
#include "model/project_data.h"
#include "ui/picker/picker_audio_widget.h"
#include "ui/picker/picker_dialog.h"

RpgAudioLineEdit::RpgAudioLineEdit(QWidget *parent) : QWidget(parent) {
	m_lineEdit = new QLineEdit(this);
	m_lineEdit->setReadOnly(true);
	m_editButton = new QPushButton("...", this);

	auto* layout = new QHBoxLayout(this);
	layout->addWidget(m_lineEdit);
	layout->addWidget(m_editButton);

	QSizePolicy policy;
	policy.setHorizontalPolicy(QSizePolicy::Maximum);
	m_editButton->setSizePolicy(policy);
}

QLineEdit* RpgAudioLineEdit::lineEdit() const {
	return m_lineEdit;
}

void RpgAudioLineEdit::makeModel(ProjectData& project) {
	m_project = &project;

	QObject::connect(m_editButton, &QPushButton::pressed, [&] {
		editPressed();
	});
}

void RpgMusicLineEdit::editPressed() {
	Q_ASSERT_X(m_music, "RpgMusicLineEdit::editPressed", "bindMusic not called");

	auto* widget = new PickerAudioWidget(*m_music, this);
	PickerDialog dialog(*m_project, FileFinder::FileType::Music, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_lineEdit->setText(baseName);
		m_music->name = baseName.toStdString();
		m_music->fadein = widget->fadeInTime();
		m_music->volume = widget->volume();
		m_music->tempo = widget->tempo();
		m_music->balance = widget->balance();
	});
	dialog.setDirectoryAndFile(MUSIC, m_lineEdit->text());
	dialog.exec();
}

void RpgMusicLineEdit::bindMusic(lcf::rpg::Music& music) {
	m_music = &music;
	m_lineEdit->setText(QString::fromStdString(music.name));
}

void RpgSoundLineEdit::editPressed() {
	Q_ASSERT_X(m_sound, "RpgSoundLineEdit::editPressed", "bindSound not called");

	auto* widget = new PickerAudioWidget(*m_sound, this);
	PickerDialog dialog(*m_project, FileFinder::FileType::Sound, widget, this);
	QObject::connect(&dialog, &PickerDialog::fileSelected, [&](const QString& baseName) {
		m_lineEdit->setText(baseName);
		m_sound->name = baseName.toStdString();
		m_sound->volume = widget->volume();
		m_sound->tempo = widget->tempo();
		m_sound->balance = widget->balance();
	});
	dialog.setDirectoryAndFile(SOUND, m_lineEdit->text());
	dialog.exec();
}

void RpgSoundLineEdit::bindSound(lcf::rpg::Sound& sound) {
	m_sound = &sound;
	m_lineEdit->setText(QString::fromStdString(sound.name));
}
