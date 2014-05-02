#ifndef QDBPAGEBATTLESCREEN_H
#define QDBPAGEBATTLESCREEN_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagebattlescreen;
}

class qdbpagebattlescreen : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagebattlescreen(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagebattlescreen();

private:
    Ui::qdbpagebattlescreen *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEBATTLESCREEN_H
