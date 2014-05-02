#ifndef QDBPAGESKILLS_H
#define QDBPAGESKILLS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageskills;
}

class qdbpageskills : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageskills(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageskills();

private:
    Ui::qdbpageskills *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGESKILLS_H
