#ifndef QDBPAGEHEROSTATUS_H
#define QDBPAGEHEROSTATUS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageherostatus;
}

class qdbpageherostatus : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageherostatus(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageherostatus();

private:
    Ui::qdbpageherostatus *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEHEROSTATUS_H
