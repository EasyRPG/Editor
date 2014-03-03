#ifndef DIALOGMAPPROPERTIES_H
#define DIALOGMAPPROPERTIES_H

#include <QDialog>

namespace Ui {
class dialogmapproperties;
}

class dialogmapproperties : public QDialog
{
    Q_OBJECT

public:
    explicit dialogmapproperties(QWidget *parent = 0);
    ~dialogmapproperties();

private:
    Ui::dialogmapproperties *ui;
};

#endif // DIALOGMAPPROPERTIES_H
