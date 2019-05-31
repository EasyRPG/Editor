#ifndef QDBPAGEBATTLEANIMATIONS2_H
#define QDBPAGEBATTLEANIMATIONS2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class BattleAnimationWidget2;
}

class BattleAnimationWidget2 : public QWidget
{
	Q_OBJECT

public:
	explicit BattleAnimationWidget2(RPG::Database &database, QWidget *parent = nullptr);
	~BattleAnimationWidget2();

private:
	Ui::BattleAnimationWidget2 *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS2_H
