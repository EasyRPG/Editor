#include "switchoperations.h"
#include "ui_switchoperations.h"

SwitchOperations::SwitchOperations(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::SwitchOperations),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

SwitchOperations::~SwitchOperations()
{
	delete ui;
}
