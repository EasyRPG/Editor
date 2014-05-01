#include "qdbpagesystem2.h"
#include "ui_qdbpagesystem2.h"

qdbpagesystem2::qdbpagesystem2(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagesystem2)
{
    ui->setupUi(this);
}

qdbpagesystem2::~qdbpagesystem2()
{
    delete ui;
}
