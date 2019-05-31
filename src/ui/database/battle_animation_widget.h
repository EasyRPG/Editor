#ifndef QDBPAGEBATTLEANIMATIONS_H
#define QDBPAGEBATTLEANIMATIONS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class BattleAnimationWidget;
}

class BattleAnimationWidget : public QWidget
{
	Q_OBJECT

public:
	explicit BattleAnimationWidget(RPG::Database &database, QWidget *parent = nullptr);
	~BattleAnimationWidget();

private:
	Ui::BattleAnimationWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS_H
