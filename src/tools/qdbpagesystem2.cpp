#include "qdbpagesystem2.h"
#include "ui_qdbpagesystem2.h"

QDbPageSystem2::QDbPageSystem2(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageSystem2),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageSystem2::~QDbPageSystem2()
{
    delete ui;
}
