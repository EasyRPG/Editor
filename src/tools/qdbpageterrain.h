#ifndef QDBPAGETERRAIN_H
#define QDBPAGETERRAIN_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageterrain;
}

class qdbpageterrain : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageterrain(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageterrain();

private:
    Ui::qdbpageterrain *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGETERRAIN_H
