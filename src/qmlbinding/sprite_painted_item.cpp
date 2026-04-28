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

#include "sprite_painted_item.h"
#include <QPainter>

SpritePaintedItem::SpritePaintedItem(QQuickItem *parent) {

}

QString SpritePaintedItem::filename() const {
	return m_filename;
}

void SpritePaintedItem::setFilename(const QString& filename) {
	if (m_filename == filename) {
		return;
	}
	m_filename = filename;
	m_image = {};
	emit filenameChanged();
	reload();
}

QString SpritePaintedItem::directory() const {
	return m_directory;
}

void SpritePaintedItem::setDirectory(const QString& directory) {
	if (m_directory == directory) {
		return;
	}
	m_directory = directory;
	m_image = {};
	emit filenameChanged();
	reload();
}

ProjectDataGadget* SpritePaintedItem::projectData() const { return m_projectData; }

void SpritePaintedItem::setProjectData(ProjectDataGadget* projectData) {
	m_projectData = projectData;
	m_image = {};
	emit projectDataChanged();
	reload();
}

void SpritePaintedItem::paint(QPainter* painter) {
	const QSize targetSize(qMax(1, int(width())), qMax(1, int(height())));
	const QPixmap scaled = m_image.scaled(targetSize, Qt::KeepAspectRatio, Qt::FastTransformation);

	painter->drawPixmap(0, 0, scaled);
}

void SpritePaintedItem::reload() {
	if (!projectData()) {
		return;
	}

	if (m_image.isNull()) {
		m_image = projectData()->loadImage(m_directory, m_filename);

		if (!m_image.isNull()) {
			setImplicitSize(m_image.width(), m_image.height());
		} else {
			return;
		}
	}

	update();
}
