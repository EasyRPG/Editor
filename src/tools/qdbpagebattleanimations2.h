#ifndef QDBPAGEBATTLEANIMATIONS2_H
#define QDBPAGEBATTLEANIMATIONS2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagebattleanimations2;
}

class qdbpagebattleanimations2 : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagebattleanimations2(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagebattleanimations2();

private:
    Ui::qdbpagebattleanimations2 *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS2_H
