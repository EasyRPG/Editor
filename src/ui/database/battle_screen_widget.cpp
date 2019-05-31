#include "battle_screen_widget.h"
#include "ui_battle_screen_widget.h"

BattleScreenWidget::BattleScreenWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BattleScreenWidget),
	m_data(database)
{
	ui->setupUi(this);
}

BattleScreenWidget::~BattleScreenWidget()
{
	delete ui;
}
