#include "dialogmapproperties.h"
#include "ui_dialogmapproperties.h"

dialogmapproperties::dialogmapproperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogmapproperties)
{
    ui->setupUi(this);
}

dialogmapproperties::~dialogmapproperties()
{
    delete ui;
}
