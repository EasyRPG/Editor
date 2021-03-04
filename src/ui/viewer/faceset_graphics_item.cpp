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

#include "faceset_graphics_item.h"
#include "core.h"
#include "common/image_loader.h"
#include "common/dbstring.h"
#include "model/project_data.h"

#include <lcf/rpg/actor.h>

FaceSetGraphicsItem::FaceSetGraphicsItem(ProjectData& project, const QPixmap pix) :
	QGraphicsItem(), m_project(project), m_image(pix) {
}

QRect FaceSetGraphicsItem::faceRect() const {
	return {
			(m_index % 4) * 48,
			m_index / 4 * 48,
			48,
			48
	};
}

QRectF FaceSetGraphicsItem::boundingRect() const {
	return {0., 0., 48., 48.};
}

void FaceSetGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
	painter->drawPixmap(boundingRect(), m_image, faceRect());
}

void FaceSetGraphicsItem::refresh(const lcf::rpg::Actor& actor) {
	refresh(ToQString(actor.face_name), actor.face_index);
}

void FaceSetGraphicsItem::refresh(QString filename, int index) {
	if (m_filename != filename) {
		m_filename = filename;
		m_image = ImageLoader::Load(m_project.project().findFile(FACESET, filename, FileFinder::FileType::Image));
	}
	setIndex(index);
	update();
}

int FaceSetGraphicsItem::index() const {
	return m_index;
}

void FaceSetGraphicsItem::setIndex(int index) {
	m_index = index;
	update();
}
