#include "switchoperations.h"
#include "ui_switchoperations.h"

SwitchOperationsWidget::SwitchOperationsWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::SwitchOperationsWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

SwitchOperationsWidget::~SwitchOperationsWidget()
{
	delete ui;
}
