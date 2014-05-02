#include "qdbpageitems.h"
#include "ui_qdbpageitems.h"

QDbPageItems::QDbPageItems(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageItems)
{
    ui->setupUi(this);
}

QDbPageItems::~QDbPageItems()
{
    delete ui;
}
