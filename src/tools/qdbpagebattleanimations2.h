#ifndef QDBPAGEBATTLEANIMATIONS2_H
#define QDBPAGEBATTLEANIMATIONS2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageBattleAnimations2;
}

class QDbPageBattleAnimations2 : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageBattleAnimations2(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageBattleAnimations2();

private:
    Ui::QDbPageBattleAnimations2 *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS2_H
