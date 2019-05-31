#include "qdbpageenemies.h"
#include "ui_qdbpageenemies.h"

QDbPageEnemies::QDbPageEnemies(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageEnemies),
	m_data(database)
{
	ui->setupUi(this);
}

QDbPageEnemies::~QDbPageEnemies()
{
	delete ui;
}
