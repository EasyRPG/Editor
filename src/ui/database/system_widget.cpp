#include "system_widget.h"
#include "ui_system_widget.h"

SystemWidget::SystemWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SystemWidget),
	m_data(database)
{
	ui->setupUi(this);
}

SystemWidget::~SystemWidget()
{
	delete ui;
}
