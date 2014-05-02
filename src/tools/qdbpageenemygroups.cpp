#include "qdbpageenemygroups.h"
#include "ui_qdbpageenemygroups.h"

qdbpageenemygroups::qdbpageenemygroups(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageenemygroups)
{
    ui->setupUi(this);
}

qdbpageenemygroups::~qdbpageenemygroups()
{
    delete ui;
}
