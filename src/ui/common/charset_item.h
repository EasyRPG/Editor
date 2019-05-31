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

#ifndef QGRAPHICSCHARAITEM_H
#define QGRAPHICSCHARAITEM_H

#include <QGraphicsPixmapItem>

class CharSetItem : public QGraphicsPixmapItem
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

	explicit CharSetItem(const QPixmap pix = QPixmap(96,64));

	void setBasePix(const QString &n_pixName);

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

signals:

public slots:

protected:
	void advance(int phase);

private:
	QScopedPointer<QPixmap> m_pix;
	int frame_count;
	int m_index;
	int m_facing;
	int m_frame;
	bool m_spin;
	bool m_walk;
};

#endif // QGRAPHICSCHARAITEM_H
