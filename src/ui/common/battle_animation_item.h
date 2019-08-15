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
#include "core.h"
#include "rpg_battleranimation.h"

class BattleAnimationItem : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	enum Type{
		Battler,
		Weapon
	};

	explicit BattleAnimationItem(const QPixmap pix = QPixmap());

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

