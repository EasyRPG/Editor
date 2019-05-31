#include "qdbpagebattlescreen.h"
#include "ui_qdbpagebattlescreen.h"

QDbPageBattleScreen::QDbPageBattleScreen(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageBattleScreen),
	m_data(database)
{
	ui->setupUi(this);
}

QDbPageBattleScreen::~QDbPageBattleScreen()
{
	delete ui;
}
