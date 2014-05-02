#ifndef QDBPAGECOMMONEVENTS_H
#define QDBPAGECOMMONEVENTS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageCommonEvents;
}

class QDbPageCommonEvents : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageCommonEvents(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageCommonEvents();

private:
    Ui::QDbPageCommonEvents *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGECOMMONEVENTS_H
