#include "qdbpagecommonevents.h"
#include "ui_qdbpagecommonevents.h"

QDbPageCommonEvents::QDbPageCommonEvents(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageCommonEvents),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageCommonEvents::~QDbPageCommonEvents()
{
    delete ui;
}
