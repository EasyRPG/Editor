#include "qdbpagesystem.h"
#include "ui_qdbpagesystem.h"

QDbPageSystem::QDbPageSystem(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageSystem),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageSystem::~QDbPageSystem()
{
    delete ui;
}
