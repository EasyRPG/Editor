#include "changeitem.h"
#include "ui_changeitem.h"

ChangeItem::ChangeItem(QWidget *parent, RPG::EventCommand &cmd) :
    QDialog(parent),
    ui(new Ui::ChangeItem),
    cmd(cmd)
{
    ui->setupUi(this);

    (cmd.parameters[0] ? ui->op_rem : ui->op_add)->setChecked(true);

    if (cmd.parameters[1] == 0)
    {
        ui->item_item->setCurrentIndex(cmd.parameters[2]);
        ui->item_box_item->setChecked(true);
    }
    else
    {
        ui->item_variable->setCurrentIndex(cmd.parameters[2]);
        ui->item_box_variable->setChecked(true);
    }

    if (cmd.parameters[3] == 0)
    {
        ui->amount_amount->setValue(cmd.parameters[4]);
        ui->amount_box_fix->setChecked(true);
    }
    else
    {
        ui->amount_variable->setCurrentIndex(cmd.parameters[4]);
        ui->amount_box_variable->setChecked(true);
    }
}

ChangeItem::~ChangeItem()
{
    delete ui;
}

void ChangeItem::on_ChangeItem_accepted()
{
    cmd.parameters[0] = ui->op_rem->isChecked() ? 1 : 0;
    cmd.parameters[1] = ui->item_box_variable->isChecked() ? 1 : 0;
    cmd.parameters[2] = ui->item_box_variable->isChecked() ? ui->item_variable->currentIndex() : ui->item_item->currentIndex();
    cmd.parameters[3] = ui->amount_box_variable->isChecked() ? 1 : 0;
    cmd.parameters[4] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_amount->value();
}
