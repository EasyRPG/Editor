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

class CharSetGraphicsItem : public QGraphicsItem
{
public:
	enum Direction {
		Direction_up = 0,
		Direction_right = 1,
		Direction_down = 2,
		Direction_left = 3
	};

	enum Frame {
		Frame_left = 0,
		Frame_middle = 1,
		Frame_right = 2
	};

	explicit CharSetGraphicsItem(ProjectData& project, const QPixmap pix = QPixmap());

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	void refresh(const lcf::rpg::Actor& actor);
	void refresh(QString filename, int index);

	int index() const;
	void setIndex(int index);

	int facing() const;
	void setFacing(int facing);

	int frame() const;
	void setFrame(int frame);

	void updatePix();

	bool spin() const;
	void setSpin(bool spin);

	bool walk() const;
	void setWalk(bool walk);

protected:
	void advance(int phase) override;

private:
	ProjectData& m_project;
	int frame_count = 0;
	int m_index = 0;
	int m_facing = Direction_down;
	int m_frame = Frame_middle;
	bool m_spin = false;
	bool m_walk = false;
	int m_pattern = 0;
	QString m_filename;
	QPixmap m_image;
};
