#ifndef QDBPAGEITEMS_H
#define QDBPAGEITEMS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageItems;
}

class QDbPageItems : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageItems(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageItems();

private:
    Ui::QDbPageItems *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEITEMS_H
