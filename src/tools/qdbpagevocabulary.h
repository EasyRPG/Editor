#ifndef QDBPAGEVOCABULARY_H
#define QDBPAGEVOCABULARY_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageVocabulary;
}

class QDbPageVocabulary : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageVocabulary(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageVocabulary();

private:
    Ui::QDbPageVocabulary *ui;
    RPG::Database &m_data;
};

#endif // QDBPAGEVOCABULARY_H
