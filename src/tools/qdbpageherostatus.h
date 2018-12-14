#ifndef QDBPAGEHEROSTATUS_H
#define QDBPAGEHEROSTATUS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageHeroStatus;
}

class QDbPageHeroStatus : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageHeroStatus(RPG::Database &database, QWidget *parent = nullptr);
    ~QDbPageHeroStatus();

private:
    Ui::QDbPageHeroStatus *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEHEROSTATUS_H
