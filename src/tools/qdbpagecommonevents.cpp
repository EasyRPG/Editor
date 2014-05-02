#include "qdbpagecommonevents.h"
#include "ui_qdbpagecommonevents.h"

QDbPageCommonEvents::QDbPageCommonEvents(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageCommonEvents)
{
    ui->setupUi(this);
}

QDbPageCommonEvents::~QDbPageCommonEvents()
{
    delete ui;
}
