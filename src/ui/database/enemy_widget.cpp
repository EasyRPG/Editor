#include "enemy_widget.h"
#include "ui_enemy_widget.h"

EnemyWidget::EnemyWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EnemyWidget),
	m_data(database)
{
	ui->setupUi(this);
}

EnemyWidget::~EnemyWidget()
{
	delete ui;
}
