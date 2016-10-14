#ifndef SWITCHOPERATIONS_H
#define SWITCHOPERATIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class SwitchOperations;
}

class SwitchOperations : public QDialog
{
    Q_OBJECT

public:
    explicit SwitchOperations(QWidget *parent, RPG::EventCommand &cmd);
    ~SwitchOperations();

private slots:

private:
    Ui::SwitchOperations *ui;
    RPG::EventCommand &cmd;
};

#endif // SWITCHOPERATIONS_H
