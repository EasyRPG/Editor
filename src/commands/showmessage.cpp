#include "showmessage.h"
#include "ui_showmessage.h"

ShowMessage::ShowMessage(QWidget *parent, RPG::EventCommand &command) :
    QDialog(parent),
    ui(new Ui::ShowMessage),
    command(command)
{
    ui->setupUi(this);

    //TODO
}

ShowMessage::~ShowMessage()
{
    delete ui;
}
