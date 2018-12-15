#ifndef QGRAPHICSBATTLERITEM_H
#define QGRAPHICSBATTLERITEM_H

#include <QGraphicsPixmapItem>
#include "../core.h"
#include "rpg_battleranimation.h"

class QGraphicsBattleAnimationItem : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	enum Type{
		Battler,
		Weapon
	};

	explicit QGraphicsBattleAnimationItem(const QPixmap pix = QPixmap());

	void setDemoAnimation(const RPG::BattlerAnimation &demoAnimation);

	void setBasePix(Type type, const QString &pixName);

	int index() const;
	void setIndex(int index);

	void updatePix();

	inline int frameSize(){return (m_type == Battler) ? 48 : 64;}

signals:
	void demoAdvance();

private slots:
	void on_demoAdvance();

protected:
	void advance(int phase);

private:
	QPixmap m_pix;
	Type m_type;
	int m_index;
	int m_frame;
	bool m_demo;
	int m_demoIndex;
	RPG::BattlerAnimation m_demoAnimation;
};

#endif // QGRAPHICSBATTLERITEM_H
