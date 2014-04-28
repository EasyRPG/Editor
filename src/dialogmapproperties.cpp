#include "dialogmapproperties.h"
#include "ui_dialogmapproperties.h"

DialogMapProperties::DialogMapProperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMapProperties)
{
    ui->setupUi(this);
}

DialogMapProperties::~DialogMapProperties()
{
    delete ui;
}
