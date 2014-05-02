#include "qdbpageenemies.h"
#include "ui_qdbpageenemies.h"

qdbpageenemies::qdbpageenemies(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageenemies)
{
    ui->setupUi(this);
}

qdbpageenemies::~qdbpageenemies()
{
    delete ui;
}
