#include "changemoney.h"
#include "ui_changemoney.h"

ChangeMoney::ChangeMoney(QWidget *parent, RPG::EventCommand &cmd) :
    QDialog(parent),
    ui(new Ui::ChangeMoney),
    cmd(cmd)
{
    ui->setupUi(this);

    (cmd.parameters[0] ? ui->op_dec : ui->op_inc)->setChecked(true);
    if (cmd.parameters[1] == 0)
    {
        ui->amount->setValue(cmd.parameters[2]);
        ui->op_fixed->setChecked(true);
    }
    else
    {
        ui->box_variable->setCurrentIndex(cmd.parameters[2]);
        ui->op_variable->setChecked(true);
    }
}

ChangeMoney::~ChangeMoney()
{
    delete ui;
}

void ChangeMoney::on_ChangeMoney_accepted()
{
    cmd.parameters[0] = ui->op_dec->isChecked() ? 1 : 0;
    cmd.parameters[1] = ui->op_variable->isChecked() ? 1 : 0;
    cmd.parameters[2] = ui->op_variable->isChecked() ? ui->box_variable->currentIndex() : ui->amount->value();
}
