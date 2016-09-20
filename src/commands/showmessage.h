#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ShowMessage;
}

class ShowMessage : public QDialog
{
    Q_OBJECT

public:
    explicit ShowMessage(QWidget *parent, RPG::EventCommand &command);
    ~ShowMessage();

private:
    Ui::ShowMessage *ui;
    RPG::EventCommand &command;
};

#endif // SHOWMESSAGE_H
