#include "battle_animation_widget.h"
#include "ui_battle_animation_widget.h"

BattleAnimationWidget::BattleAnimationWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BattleAnimationWidget),
	m_data(database)
{
	ui->setupUi(this);
}

BattleAnimationWidget::~BattleAnimationWidget()
{
	delete ui;
}
