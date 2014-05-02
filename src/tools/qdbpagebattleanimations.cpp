#include "qdbpagebattleanimations.h"
#include "ui_qdbpagebattleanimations.h"

QDbPageBattleAnimations::QDbPageBattleAnimations(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageBattleAnimations)
{
    ui->setupUi(this);
}

QDbPageBattleAnimations::~QDbPageBattleAnimations()
{
    delete ui;
}
