#include "qdbpageherostatus.h"
#include "ui_qdbpageherostatus.h"

QDbPageHeroStatus::QDbPageHeroStatus(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageHeroStatus),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageHeroStatus::~QDbPageHeroStatus()
{
    delete ui;
}
