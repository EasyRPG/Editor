#include "common_event_widget.h"
#include "ui_common_event_widget.h"

CommonEventWidget::CommonEventWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CommonEventWidget),
	m_data(database)
{
	ui->setupUi(this);
}

CommonEventWidget::~CommonEventWidget()
{
	delete ui;
}
