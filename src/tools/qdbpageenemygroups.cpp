#include "qdbpageenemygroups.h"
#include "ui_qdbpageenemygroups.h"

QDbPageEnemyGroups::QDbPageEnemyGroups(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageEnemyGroups),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageEnemyGroups::~QDbPageEnemyGroups()
{
    delete ui;
}
