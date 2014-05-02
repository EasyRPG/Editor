#ifndef QDBPAGECHIPSET_H
#define QDBPAGECHIPSET_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagechipset;
}

class qdbpagechipset : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagechipset(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagechipset();

private:
    Ui::qdbpagechipset *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGECHIPSET_H
