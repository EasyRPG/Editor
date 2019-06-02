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

#include "faceset_item.h"
#include "core.h"
#include "src/common/image_loader.h"

FaceSetItem::FaceSetItem(const QPixmap pix) :
	QGraphicsPixmapItem(pix)
{
	m_index = -1;
}

void FaceSetItem::setBasePix(const QString &n_pixName)
{
	m_pix = ImageLoader::Load(core().project()->findFile(FACESET, n_pixName, FileFinder::FileType::Image));
	if (!m_pix)
		m_pix = QPixmap(core().rtpPath(FACESET,n_pixName));
	updatePix();
}

int FaceSetItem::index() const
{
	return m_index;
}

void FaceSetItem::setIndex(int index)
{
	m_index = index;
	updatePix();
}

int FaceSetItem::facing() const
{
	return m_facing;
}

void FaceSetItem::setFacing(int facing)
{
	m_facing = facing;
	updatePix();
}
int FaceSetItem::frame() const
{
	return m_frame;
}

void FaceSetItem::setFrame(int frame)
{
	m_frame = frame;
	updatePix();
}

void FaceSetItem::updatePix()
{
	if (!m_pix)
		return;
	if (m_index == -1)
	{
		QPixmap n_pix = QPixmap(QSize(192,192));
		QPainter p(&n_pix);
		for (int index = 0; index < 16; index++)
		{
			int src_x = (index%4)* 48;
			int src_y = (index/4)* 48;
			p.drawPixmap((index%4)*48, (index/4)*48, 48, 48, m_pix.copy(src_x,src_y,48,48));
		}
		p.end();
		this->setPixmap(n_pix);
	}
	else
	{
		int x = (m_index%4)* 48;
		int y = (m_index/4)* 48;
		this->setPixmap(m_pix.copy(x,y,48,48));
	}
}



