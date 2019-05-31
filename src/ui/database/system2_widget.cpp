#include "system_widget2.h"
#include "ui_system_widget2.h"

SystemWidget2::SystemWidget2(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SystemWidget2),
	m_data(database)
{
	ui->setupUi(this);
}

SystemWidget2::~SystemWidget2()
{
	delete ui;
}
