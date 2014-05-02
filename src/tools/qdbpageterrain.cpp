#include "qdbpageterrain.h"
#include "ui_qdbpageterrain.h"

QDbPageTerrain::QDbPageTerrain(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageTerrain)
{
    ui->setupUi(this);
}

QDbPageTerrain::~QDbPageTerrain()
{
    delete ui;
}
