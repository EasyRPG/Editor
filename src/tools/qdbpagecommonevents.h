#ifndef QDBPAGECOMMONEVENTS_H
#define QDBPAGECOMMONEVENTS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagecommonevents;
}

class qdbpagecommonevents : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagecommonevents(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagecommonevents();

private:
    Ui::qdbpagecommonevents *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGECOMMONEVENTS_H
