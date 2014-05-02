#include "qdbpagebattlescreen.h"
#include "ui_qdbpagebattlescreen.h"

QDbPageBattleScreen::QDbPageBattleScreen(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageBattleScreen)
{
    ui->setupUi(this);
}

QDbPageBattleScreen::~QDbPageBattleScreen()
{
    delete ui;
}
