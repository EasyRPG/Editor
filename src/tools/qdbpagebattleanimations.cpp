#include "qdbpagebattleanimations.h"
#include "ui_qdbpagebattleanimations.h"

qdbpagebattleanimations::qdbpagebattleanimations(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagebattleanimations)
{
    ui->setupUi(this);
}

qdbpagebattleanimations::~qdbpagebattleanimations()
{
    delete ui;
}
