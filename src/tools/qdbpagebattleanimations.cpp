#include "qdbpagebattleanimations.h"
#include "ui_qdbpagebattleanimations.h"

QDbPageBattleAnimations::QDbPageBattleAnimations(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageBattleAnimations),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageBattleAnimations::~QDbPageBattleAnimations()
{
    delete ui;
}
