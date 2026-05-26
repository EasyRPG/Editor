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

#include "sprite_painted_item.h"
#include <QTimer>

/**
 * Displays an animated character from a CharSet spritesheet.
 */
class CharSetPaintedItem : public SpritePaintedItem {
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(int facing READ facing WRITE setFacing NOTIFY facingChanged)
	Q_PROPERTY(int frame READ frame WRITE setFrame NOTIFY frameChanged)
	Q_PROPERTY(bool spin READ spin WRITE setSpin NOTIFY spinChanged)
	Q_PROPERTY(bool walk READ walk WRITE setWalk NOTIFY walkChanged)

public:
	enum Direction {
		Direction_up = 0,
		Direction_right = 1,
		Direction_down = 2,
		Direction_left = 3
	};
	Q_ENUM(Direction)

	enum Frame {
		Frame_left = 0,
		Frame_middle = 1,
		Frame_right = 2
	};
	Q_ENUM(Frame)

	explicit CharSetPaintedItem(QQuickItem* parent = nullptr);

	int facing() const;
	void setFacing(int facing);

	int frame() const;
	void setFrame(int frame);

	bool spin() const;
	void setSpin(bool spin);

	bool walk() const;
	void setWalk(bool walk);

signals:
	void characterIndexChanged();
	void facingChanged();
	void frameChanged();
	void spinChanged();
	void walkChanged();

protected:
	QRectF sourceRect() const override;

private:
	void tick();

	QTimer m_timer;

	int m_facing = Direction_down;
	int m_frame = Frame_middle;
	bool m_spin = false;
	bool m_walk = false;

	int m_pattern = 0;
	int frame_count = 0;
};
