#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"
#include <QPushButton>

DialogDataBase::DialogDataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDataBase)
{
    ui->setupUi(this);
}

DialogDataBase::~DialogDataBase()
{
    delete ui;
}
void DialogDataBase::on_toolSwitchStyle_clicked(bool checked)
{
    if (checked)
        ui->stackedStyle->setCurrentIndex(1);
    else
        ui->stackedStyle->setCurrentIndex(0);
}
