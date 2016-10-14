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
        ui->amount_box_amount->setChecked(true);
        ui->amount_amount->setValue(cmd.parameters[2]);
    }
    else
    {
        ui->amount_box_variable->setChecked(true);
        ui->amount_variable->setCurrentIndex(cmd.parameters[2]);
    }
}

ChangeMoney::~ChangeMoney()
{
    delete ui;
}

void ChangeMoney::on_ChangeMoney_accepted()
{
    cmd.parameters[0] = ui->op_dec->isChecked() ? 1 : 0;
    cmd.parameters[1] = ui->amount_box_variable->isChecked() ? 1 : 0;
    cmd.parameters[2] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_amount->value();
}
