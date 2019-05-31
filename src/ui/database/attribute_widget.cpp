#include "attribute_widget.h"
#include "ui_attribute_widget.h"

AttributeWidget::AttributeWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AttributeWidget),
	m_data(database)
{
	ui->setupUi(this);
}

AttributeWidget::~AttributeWidget()
{
	delete ui;
}
