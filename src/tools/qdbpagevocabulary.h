#ifndef QDBPAGEVOCABULARY_H
#define QDBPAGEVOCABULARY_H

#include <QWidget>
#include <data.h>

namespace Ui {
class qdbpagevocabulary;
}

class qdbpagevocabulary : public QWidget
{
    Q_OBJECT

public:
    explicit qdbpagevocabulary(RPG::Database &database, QWidget *parent = 0);
    ~qdbpagevocabulary();

private:
    Ui::qdbpagevocabulary *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEVOCABULARY_H
