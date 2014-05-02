#ifndef QDBPAGEATTIBUTES_H
#define QDBPAGEATTIBUTES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageattibutes;
}

class qdbpageattibutes : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageattibutes(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageattibutes();

private:
    Ui::qdbpageattibutes *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEATTIBUTES_H
