#ifndef QDBPAGEENEMYGROUPS_H
#define QDBPAGEENEMYGROUPS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpageenemygroups;
}

class qdbpageenemygroups : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpageenemygroups(RPG::Database &database, QWidget *parent = 0);
    ~qdbpageenemygroups();

private:
    Ui::qdbpageenemygroups *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEENEMYGROUPS_H
