#include "battle_animation_item.h"

BattleAnimationItem::BattleAnimationItem(const QPixmap pix) :
	QGraphicsPixmapItem(pix)
{
	m_demo = false;
	m_index = -1;
	m_frame = 1;
	connect(this, SIGNAL(demoAdvance()), this, SLOT(on_demoAdvance()));
}

void BattleAnimationItem::setDemoAnimation(const RPG::BattlerAnimation &demoAnimation)
{
	m_demo = true;
	m_index = 0;
	m_frame = 1;
	m_demoIndex = -1;
	m_demoAnimation = demoAnimation;
	on_demoAdvance();
}

void BattleAnimationItem::setBasePix(Type type, const QString &pixName)
{
	m_type = type;
	if (pixName.isEmpty())
	{
		m_pix = QPixmap(144,384);
		m_pix.fill(Qt::black);
	}
	else
	{
		QString dir;
		if (type == Weapon)
			dir = BATTLEWEAPON;
		else
			dir = BATTLECHARSET;
		m_pix = QPixmap(mCore->filePath(dir, pixName));
		if (m_pix.isNull())
			m_pix = QPixmap(mCore->rtpPath(dir, pixName));
	}
	updatePix();
}

int BattleAnimationItem::index() const
{
	return m_index;
}

void BattleAnimationItem::setIndex(int index)
{
	m_index = index;
	updatePix();
}

void BattleAnimationItem::updatePix()
{
	if (m_pix.isNull())
		return;
	if (m_index == -1)
	{
		QPixmap n_pix = QPixmap(QSize(frameSize()*4,frameSize()*2));
		QPainter p(&n_pix);
		for (int index = 0; index < 8; index++)
		{
			int src_x = m_frame * frameSize();
			int src_y = index * frameSize();
			p.drawPixmap((index%4)*frameSize(), (index/4)*frameSize(), frameSize(),
						 frameSize(), m_pix.copy(src_x, src_y, frameSize(), frameSize()));
		}
		p.end();
		this->setPixmap(n_pix);
	}
	else
	{
		int x = m_frame * frameSize();
		int y = m_index * frameSize();
		this->setPixmap(m_pix.copy(x,y,frameSize(),frameSize()));
	}
}

void BattleAnimationItem::on_demoAdvance()
{
	if (!m_demo)
		return;
	m_demoIndex++;
	if (m_demoIndex > 11)
		m_demoIndex = 0;
	RPG::BattlerAnimationExtension anim = m_demoAnimation.base_data[static_cast<size_t>(m_demoIndex)];
	setBasePix(Battler, QString::fromStdString(anim.battler_name));
	m_index = anim.battler_index;
	updatePix();
}

void BattleAnimationItem::advance(int phase)
{
	static int frame_count = 0;
	static int patterns[4] = {1, 0, 1, 2}; /* Mid, Left, Mid, Right*/
	if (!phase)
	{
		frame_count++;
		m_frame = patterns[frame_count%4];
		if (frame_count >= 16)
		{
			frame_count = 0;
			emit demoAdvance();
		}
	}
	else
		updatePix();
}
