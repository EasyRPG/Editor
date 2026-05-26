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

#include "charset_painted_item.h"

CharSetPaintedItem::CharSetPaintedItem(QQuickItem *parent) : SpritePaintedItem(parent) {
	m_directory = QStringLiteral("CharSet");
	m_cellWidth = 24;
	m_cellHeight = 32;
	m_skipCellsX = 2; // block width is 3 cells, so skip 2
	m_skipCellsY = 3; // block height is 4 cells, so skip 3
	setCellOffsetX(m_frame * m_cellWidth);
	setCellOffsetY(m_facing * m_cellHeight);

	// Animation timer ~30 fps
	m_timer.setInterval(1000 / 30);
	QObject::connect(&m_timer, &QTimer::timeout, this, &CharSetPaintedItem::tick);
}

int CharSetPaintedItem::facing() const {
	return m_facing;
}

void CharSetPaintedItem::setFacing(int facing) {
	if (m_facing == facing) {
		return;
	}
	m_facing = facing;
	setCellOffsetY(m_facing * m_cellHeight);
	emit facingChanged();
	update();
}

int CharSetPaintedItem::frame() const {
	return m_frame;
}

void CharSetPaintedItem::setFrame(int frame) {
	if (m_frame == frame) {
		return;
	}
	m_frame = frame;
	setCellOffsetX(m_frame * m_cellWidth);
	emit frameChanged();
	update();
}

bool CharSetPaintedItem::spin() const {
	return m_spin;
}

void CharSetPaintedItem::setSpin(bool spin) {
	if (m_spin == spin) {
		return;
	}
	m_spin = spin;
	emit spinChanged();

	if (m_spin || m_walk) {
		m_timer.start();
	} else {
		m_timer.stop();
	}
}

bool CharSetPaintedItem::walk() const {
	return m_walk;
}

void CharSetPaintedItem::setWalk(bool walk) {
	if (m_walk == walk) {
		return;
	}
	m_walk = walk;
	emit walkChanged();

	if (m_spin || m_walk) {
		m_timer.start();
	} else {
		m_timer.stop();
	}
}

QRectF CharSetPaintedItem::sourceRect() const {
	if (pickerMode()) {
		return SpritePaintedItem::sourceRect();
	}

	const int blockSizeX = 72;
	const int blockSizeY = 128;
	const int colsPerRow = 4;

	const int blockX = (m_cellIndex % colsPerRow) * blockSizeX;
	const int blockY = (m_cellIndex / colsPerRow) * blockSizeY;

	const int x = blockX + m_frame * m_cellWidth;
	const int y = blockY + m_facing * m_cellHeight;

	return QRectF(x, y, m_cellWidth, m_cellHeight);
}

void CharSetPaintedItem::tick() {
	static const int walkPatterns[4] = {Frame_middle, Frame_right, Frame_middle, Frame_left};

	frame_count++;

	if (frame_count == 90) {
		frame_count = 0;
		if (m_spin) {
			m_facing++;
			if (m_facing > Direction_left) {
				m_facing = Direction_up;
			}
			emit facingChanged();
		}
	}

	if (m_walk) {
		m_frame = walkPatterns[m_pattern];
		emit frameChanged();

		if (frame_count % 6 == 0) {
			m_pattern = (m_pattern + 1) % 4;
		}
	}

	update();
}
