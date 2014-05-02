#ifndef QDBPAGEBATTLEANIMATIONS_H
#define QDBPAGEBATTLEANIMATIONS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagebattleanimations;
}

class qdbpagebattleanimations : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagebattleanimations(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagebattleanimations();

private:
    Ui::qdbpagebattleanimations *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEBATTLEANIMATIONS_H
