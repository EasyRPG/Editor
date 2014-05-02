#ifndef QDBPAGEBATTLESCREEN_H
#define QDBPAGEBATTLESCREEN_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageBattleScreen;
}

class QDbPageBattleScreen : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageBattleScreen(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageBattleScreen();

private:
    Ui::QDbPageBattleScreen *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEBATTLESCREEN_H
