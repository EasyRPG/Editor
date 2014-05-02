#ifndef QDBPAGESYSTEM2_H
#define QDBPAGESYSTEM2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagesystem2;
}

class qdbpagesystem2 : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagesystem2(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagesystem2();

private:
    Ui::qdbpagesystem2 *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGESYSTEM2_H
