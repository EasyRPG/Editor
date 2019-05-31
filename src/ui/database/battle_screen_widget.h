#ifndef QDBPAGEBATTLESCREEN_H
#define QDBPAGEBATTLESCREEN_H

#include <QWidget>
#include <data.h>

namespace Ui {
class BattleScreenWidget;
}

class BattleScreenWidget : public QWidget
{
	Q_OBJECT

public:
	explicit BattleScreenWidget(RPG::Database &database, QWidget *parent = nullptr);
	~BattleScreenWidget();

private:
	Ui::BattleScreenWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEBATTLESCREEN_H
