#include "qdbpagebattleanimations2.h"
#include "ui_qdbpagebattleanimations2.h"

QDbPageBattleAnimations2::QDbPageBattleAnimations2(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageBattleAnimations2)
{
    ui->setupUi(this);
}

QDbPageBattleAnimations2::~QDbPageBattleAnimations2()
{
    delete ui;
}
