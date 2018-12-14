#ifndef QDBPAGEENEMIES_H
#define QDBPAGEENEMIES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageEnemies;
}

class QDbPageEnemies : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageEnemies(RPG::Database &database, QWidget *parent = nullptr);
    ~QDbPageEnemies();

private:
    Ui::QDbPageEnemies *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEENEMIES_H
