#include "qdbpagebattleanimations2.h"
#include "ui_qdbpagebattleanimations2.h"

QDbPageBattleAnimations2::QDbPageBattleAnimations2(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageBattleAnimations2),
	m_data(database)
{
	ui->setupUi(this);
}

QDbPageBattleAnimations2::~QDbPageBattleAnimations2()
{
	delete ui;
}
