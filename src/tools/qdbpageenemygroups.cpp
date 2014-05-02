#include "qdbpageenemygroups.h"
#include "ui_qdbpageenemygroups.h"

QDbPageEnemyGroups::QDbPageEnemyGroups(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageEnemyGroups)
{
    ui->setupUi(this);
}

QDbPageEnemyGroups::~QDbPageEnemyGroups()
{
    delete ui;
}
