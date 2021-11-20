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

#include "picker_audio_widget.h"
#include "ui_picker_audio_widget.h"

#include <lcf/rpg/music.h>
#include <lcf/rpg/sound.h>

PickerAudioWidget::PickerAudioWidget(const lcf::rpg::Music& music, QWidget *parent) :
	PickerChildWidget(parent),
	ui(new Ui::PickerAudioWidget) {
	ui->setupUi(this);

	ui->sliderFadeIn->setValue(music.fadein / 1000);
	ui->sliderVolume->setValue(music.volume);
	ui->sliderTempo->setValue(music.tempo);
	ui->sliderBalance->setValue(music.balance);
}

PickerAudioWidget::PickerAudioWidget(const lcf::rpg::Sound& sound, QWidget *parent) :
	PickerChildWidget(parent),
	ui(new Ui::PickerAudioWidget) {
	ui->setupUi(this);

	ui->sliderVolume->setValue(sound.volume);
	ui->sliderTempo->setValue(sound.tempo);
	ui->sliderBalance->setValue(sound.balance);

	ui->groupFadeIn->hide();
}

PickerAudioWidget::~PickerAudioWidget() {
	delete ui;
}

void PickerAudioWidget::fileChanged(const QString& filename) {
	m_filename = filename;
}

int PickerAudioWidget::fadeInTime() const {
	return ui->sliderFadeIn->value() * 1000;
}

int PickerAudioWidget::volume() const {
	return ui->sliderVolume->value();
}

int PickerAudioWidget::tempo() const {
	return ui->sliderTempo->value();
}

int PickerAudioWidget::balance() const {
	return ui->sliderBalance->value();
}

void PickerAudioWidget::on_sliderFadeIn_valueChanged(int value) {
	ui->labelFadeIn->setText(QString("%1s").arg(value));
}

void PickerAudioWidget::on_sliderVolume_valueChanged(int value) {
	ui->labelVolume->setText(QString("%1%").arg(value));
}

void PickerAudioWidget::on_sliderTempo_valueChanged(int value) {
	ui->labelTempo->setText(QString("%1%").arg(value));
}

void PickerAudioWidget::on_sliderBalance_valueChanged(int value) {
	ui->labelBalance->setText(QString("%1:%2").arg(100 - value).arg(value));
}
