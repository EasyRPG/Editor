#ifndef QDBPAGEENEMIES_H
#define QDBPAGEENEMIES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageenemies;
}

class qdbpageenemies : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageenemies(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageenemies();

private:
    Ui::qdbpageenemies *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEENEMIES_H
