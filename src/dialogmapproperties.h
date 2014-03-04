#ifndef DIALOGMAPPROPERTIES_H
#define DIALOGMAPPROPERTIES_H

#include <QDialog>

namespace Ui {
class DialogMapProperties;
}

class DialogMapProperties : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMapProperties(QWidget *parent = 0);
    ~DialogMapProperties();

private:
    Ui::DialogMapProperties *ui;
};

#endif // DIALOGMAPPROPERTIES_H
