#include "qdbpageattributes.h"
#include "ui_qdbpageattributes.h"

QDbPageAttributes::QDbPageAttributes(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageAttributes)
{
    ui->setupUi(this);
}

QDbPageAttributes::~QDbPageAttributes()
{
    delete ui;
}
