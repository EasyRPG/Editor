#ifndef INPUTNUMBER_H
#define INPUTNUMBER_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class InputNumber;
}

class InputNumber : public QDialog
{
    Q_OBJECT

public:
    explicit InputNumber(QWidget *parent, RPG::EventCommand &cmd);
    ~InputNumber();

private slots:


private:
    Ui::InputNumber *ui;
    RPG::EventCommand &cmd;
};

#endif // INPUTNUMBER_H
