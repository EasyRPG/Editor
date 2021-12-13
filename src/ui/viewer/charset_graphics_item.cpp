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

#include "charset_graphics_item.h"
#include "core.h"
#include "common/dbstring.h"
#include "common/image_loader.h"

#include <lcf/rpg/actor.h>

CharSetGraphicsItem::CharSetGraphicsItem(ProjectData& project, const QPixmap pix) :
	QGraphicsItem(), m_project(project), m_image(pix) {
	if (pix.isNull()) {
		m_image = QPixmap(24, 32);
		m_image.fill(QColor(255, 255, 255, 0));
	}
}

void setBasePix(const QString &n_pixName);

QRectF CharSetGraphicsItem::boundingRect() const {
	return {0., 0., 24., 32.};
}

void CharSetGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
	int x = (m_index % 4) * 72 + m_frame * 24;
	int y = (m_index / 4) * 128 + m_facing * 32;
	painter->drawPixmap(boundingRect(), m_image, QRect(x, y, 24, 32));
}

void CharSetGraphicsItem::advance(int phase) {
	static int patterns[4] = {Frame_middle, Frame_right, Frame_middle,Frame_left};
	if (!phase)	{
		frame_count++;
		if (frame_count == 90) {
			frame_count = 0;
			if (m_spin)	{
				m_facing++;
				if (m_facing > Direction_left)
					m_facing = Direction_up;
			}
		}
		if (m_walk) {
			m_frame = patterns[m_pattern];

			if (frame_count % 6 == 0) {
				m_pattern = (m_pattern + 1) % 4;
			}
		}
	} else {
		update();
	}
}

void CharSetGraphicsItem::refresh(const lcf::rpg::Actor& actor) {
	refresh(ToQString(actor.character_name), actor.character_index);
}

void CharSetGraphicsItem::refresh(QString filename, int index) {
	if (m_filename != filename) {
		m_filename = filename;
		QString path = m_project.project().findFile(CHARSET, filename, FileFinder::FileType::Image);
		if (!path.isEmpty()) {
			m_image = ImageLoader::Load(path);
		} else {
			m_image = QPixmap(48, 48);
			m_image.fill(QColor(255, 255, 255, 0));
		}
	}
	setIndex(index);
	update();
}

int CharSetGraphicsItem::index() const {
	return m_index;
}

void CharSetGraphicsItem::setIndex(int index) {
	m_index = index;
	update();
}

int CharSetGraphicsItem::facing() const {
	return m_facing;
}

void CharSetGraphicsItem::setFacing(int facing) {
	m_facing = facing;
	update();
}

int CharSetGraphicsItem::frame() const {
	return m_frame;
}

void CharSetGraphicsItem::setFrame(int frame) {
	m_frame = frame;
	update();
}

bool CharSetGraphicsItem::walk() const {
	return m_walk;
}

void CharSetGraphicsItem::setWalk(bool walk) {
	m_walk = walk;
	update();
}

bool CharSetGraphicsItem::spin() const {
	return m_spin;
}

void CharSetGraphicsItem::setSpin(bool spin) {
	m_spin = spin;
	update();
}
