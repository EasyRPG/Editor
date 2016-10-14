#ifndef CHANGEPARTY_H
#define CHANGEPARTY_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangeParty;
}

class ChangeParty : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeParty(QWidget *parent, RPG::EventCommand &cmd);
    ~ChangeParty();

private slots:
    void on_ChangeParty_accepted();

private:
    Ui::ChangeParty *ui;
    RPG::EventCommand &cmd;
};

#endif // CHANGEPARTY_H
