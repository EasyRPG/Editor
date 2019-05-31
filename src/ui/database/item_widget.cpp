#include "item_widget.h"
#include "ui_item_widget.h"

ItemWidget::ItemWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ItemWidget),
	m_data(database)
{
	ui->setupUi(this);
}

ItemWidget::~ItemWidget()
{
	delete ui;
}
