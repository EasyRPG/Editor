#include "qdbpagesystem.h"
#include "ui_qdbpagesystem.h"

qdbpagesystem::qdbpagesystem(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagesystem)
{
    ui->setupUi(this);
}

qdbpagesystem::~qdbpagesystem()
{
    delete ui;
}
