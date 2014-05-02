#include "qdbpageenemies.h"
#include "ui_qdbpageenemies.h"

QDbPageEnemies::QDbPageEnemies(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageEnemies)
{
    ui->setupUi(this);
}

QDbPageEnemies::~QDbPageEnemies()
{
    delete ui;
}
