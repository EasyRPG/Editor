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

#include <QGraphicsPixmapItem>

namespace lcf::rpg {
	class Actor;
}

class ProjectData;

class FaceSetGraphicsItem : public QGraphicsItem {
public:
	explicit FaceSetGraphicsItem(ProjectData& m_project, const QPixmap pix = QPixmap(192,192));

	QRect faceRect() const;
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	void refresh(const lcf::rpg::Actor& actor);
	void refresh(QString filename, int index);

	int index() const;
	void setIndex(int index);

private:
	ProjectData& m_project;
	int m_index = 0;
	bool m_flip = false;
	QString m_filename;
	QPixmap m_image;
};
