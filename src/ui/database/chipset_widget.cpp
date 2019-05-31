#include "chipset_widget.h"
#include "ui_chipset_widget.h"

ChipSetWidget::ChipSetWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChipSetWidget),
	m_data(database)
{
	ui->setupUi(this);
}

ChipSetWidget::~ChipSetWidget()
{
	delete ui;
}
