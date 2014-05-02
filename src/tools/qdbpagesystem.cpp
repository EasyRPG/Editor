#include "qdbpagesystem.h"
#include "ui_qdbpagesystem.h"

QDbPageSystem::QDbPageSystem(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageSystem)
{
    ui->setupUi(this);
}

QDbPageSystem::~QDbPageSystem()
{
    delete ui;
}
