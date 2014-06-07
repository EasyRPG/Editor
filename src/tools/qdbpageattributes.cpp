#include "qdbpageattributes.h"
#include "ui_qdbpageattributes.h"

QDbPageAttributes::QDbPageAttributes(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageAttributes),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageAttributes::~QDbPageAttributes()
{
    delete ui;
}
