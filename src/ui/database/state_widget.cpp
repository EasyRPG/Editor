#include "state_widget.h"
#include "ui_state_widget.h"

StateWidget::StateWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StateWidget),
	m_data(database)
{
	ui->setupUi(this);
}

StateWidget::~StateWidget()
{
	delete ui;
}
