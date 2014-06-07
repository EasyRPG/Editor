#include "qdbpageitems.h"
#include "ui_qdbpageitems.h"

QDbPageItems::QDbPageItems(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageItems),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageItems::~QDbPageItems()
{
    delete ui;
}
