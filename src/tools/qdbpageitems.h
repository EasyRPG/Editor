#ifndef QDBPAGEITEMS_H
#define QDBPAGEITEMS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageitems;
}

class qdbpageitems : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageitems(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageitems();

private:
    Ui::qdbpageitems *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEITEMS_H
