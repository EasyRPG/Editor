#ifndef QDBPAGECLASSES_H
#define QDBPAGECLASSES_H

#include <QWidget>
#include <data.h>
#include <rpg_actor.h>

namespace Ui {
class qdbpageclasses;
}

class qdbpageclasses : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageclasses(RPG::Database &database,QWidget *parent = 0);
    ~qdbpageclasses();

private:
    Ui::qdbpageclasses *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGECLASSES_H
