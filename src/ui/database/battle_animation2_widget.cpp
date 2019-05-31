#include "battle_animation_widget2.h"
#include "ui_battle_animation_widget2.h"

BattleAnimationWidget2::BattleAnimationWidget2(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BattleAnimationWidget2),
	m_data(database)
{
	ui->setupUi(this);
}

BattleAnimationWidget2::~BattleAnimationWidget2()
{
	delete ui;
}
