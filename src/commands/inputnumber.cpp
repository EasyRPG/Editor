#include "inputnumber.h"
#include "ui_inputnumber.h"

InputNumber::InputNumber(QWidget *parent, RPG::EventCommand &cmd) :
    QDialog(parent),
    ui(new Ui::InputNumber),
    cmd(cmd)
{
    ui->setupUi(this);

    //TODO
}

InputNumber::~InputNumber()
{
    delete ui;
}
