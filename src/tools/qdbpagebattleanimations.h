#ifndef QDBPAGEBATTLEANIMATIONS_H
#define QDBPAGEBATTLEANIMATIONS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageBattleAnimations;
}

class QDbPageBattleAnimations : public QWidget
{
	Q_OBJECT

public:
	explicit QDbPageBattleAnimations(RPG::Database &database, QWidget *parent = nullptr);
	~QDbPageBattleAnimations();

private:
	Ui::QDbPageBattleAnimations *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS_H
