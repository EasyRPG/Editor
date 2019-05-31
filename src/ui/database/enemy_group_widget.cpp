#include "enemy_group_widget.h"
#include "ui_enemy_group_widget.h"

EnemyGroupWidget::EnemyGroupWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EnemyGroupWidget),
	m_data(database)
{
	ui->setupUi(this);
}

EnemyGroupWidget::~EnemyGroupWidget()
{
	delete ui;
}
