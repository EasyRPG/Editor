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

#include "charset_item.h"
#include "core.h"
#include "common/image_loader.h"

CharSetItem::CharSetItem(const QPixmap pix) :
	QGraphicsPixmapItem(pix)
{
	m_index = -1;
	m_facing = Direction_down;
	m_frame = Frame_middle;
	m_walk = false;
	m_spin = false;
	frame_count = 0;
}

void CharSetItem::setBasePix(const QString &n_pixName)
{
	m_pix.reset(ImageLoader::Load(mCore->project()->findFile(CHARSET, n_pixName, FileFinder::FileType::Image)));
	if (m_pix->isNull())
		m_pix.reset(ImageLoader::Load(mCore->rtpPath(CHARSET, n_pixName)));
	if (m_pix->isNull())
		m_pix.reset(mCore->createDummyPixmap(288,256));
	updatePix();
}

int CharSetItem::index() const
{
	return m_index;
}

void CharSetItem::setIndex(int index)
{
	m_index = index;
	updatePix();
}

int CharSetItem::facing() const
{
	return m_facing;
}

void CharSetItem::setFacing(int facing)
{
	m_facing = facing;
	updatePix();
}
int CharSetItem::frame() const
{
	return m_frame;
}

void CharSetItem::setFrame(int frame)
{
	m_frame = frame;
	updatePix();
}

void CharSetItem::updatePix()
{
	if (m_pix->isNull())
		return;
	if (m_index == -1)
	{
		QPixmap n_pix = QPixmap(QSize(96,64));
		QPainter p(&n_pix);
		for (int index = 0; index < 8; index++)
		{
			int src_x = (index%4)*72 + m_frame * 24;
			int src_y = (index/4)*128 + m_facing * 32;
			p.drawPixmap((index%4)*24, (index/4)*32, 24, 32, m_pix->copy(src_x,src_y,24,32));
		}
		p.end();
		this->setPixmap(n_pix);
	}
	else
	{
		int x = (m_index%4)*72 + m_frame * 24;
		int y = (m_index/4)*128 + m_facing * 32;
		this->setPixmap(m_pix->copy(x,y,24,32));
	}
}

void CharSetItem::advance(int phase)
{
	static int patterns[4] = {Frame_middle, Frame_right, Frame_middle,Frame_left};
	if (!phase)
	{

		frame_count++;
		if (frame_count == 20)
		{
			frame_count = 0;
			if (m_spin)
			{
				m_facing++;
				if (m_facing > Direction_left)
					m_facing = Direction_up;
			}
		}
		if (m_walk)
			m_frame = patterns[frame_count%4];
	}
	else
		updatePix();
}
bool CharSetItem::walk() const
{
	return m_walk;
}

void CharSetItem::setWalk(bool walk)
{
	m_walk = walk;
}

bool CharSetItem::spin() const
{
	return m_spin;
}

void CharSetItem::setSpin(bool spin)
{
	m_spin = spin;
}
