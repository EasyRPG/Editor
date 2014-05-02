#include "qdbpageherostatus.h"
#include "ui_qdbpageherostatus.h"

QDbPageHeroStatus::QDbPageHeroStatus(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageHeroStatus)
{
    ui->setupUi(this);
}

QDbPageHeroStatus::~QDbPageHeroStatus()
{
    delete ui;
}
