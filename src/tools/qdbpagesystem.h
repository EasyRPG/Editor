#ifndef QDBPAGESYSTEM_H
#define QDBPAGESYSTEM_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagesystem;
}

class qdbpagesystem : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagesystem(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagesystem();

private:
    Ui::qdbpagesystem *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGESYSTEM_H
