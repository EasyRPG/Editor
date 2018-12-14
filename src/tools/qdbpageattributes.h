#ifndef QDBPAGEATTIBUTES_H
#define QDBPAGEATTIBUTES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageAttributes;
}

class QDbPageAttributes : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageAttributes(RPG::Database &database, QWidget *parent = nullptr);
    ~QDbPageAttributes();

private:
    Ui::QDbPageAttributes *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEATTIBUTES_H
