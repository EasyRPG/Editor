#include "showchoices.h"
#include "ui_showchoices.h"

ShowChoices::ShowChoices(QWidget *parent, RPG::EventCommand &cmd) :
    QDialog(parent),
    ui(new Ui::ShowChoices),
    cmd(cmd)
{
    ui->setupUi(this);

    //TODO
}

ShowChoices::~ShowChoices()
{
    delete ui;
}
