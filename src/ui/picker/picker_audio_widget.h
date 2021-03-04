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

#include <QWidget>

#include "picker_child_widget.h"

namespace Ui {
class PickerAudioWidget;
}

namespace lcf::rpg {
	class Music;
	class Sound;
}

class PickerAudioWidget : public PickerChildWidget {
	Q_OBJECT

public:
	enum class Type {
		Music,
		Sound
	};

	explicit PickerAudioWidget(const lcf::rpg::Music& music, QWidget *parent = nullptr);
	explicit PickerAudioWidget(const lcf::rpg::Sound& sound, QWidget *parent = nullptr);
	~PickerAudioWidget();

	void fileChanged(const QString&) override;

	int fadeInTime() const;
	int volume() const;
	int tempo() const;
	int balance() const;

private:
	Ui::PickerAudioWidget *ui;

	Type m_type;
	QString m_filename;
};

