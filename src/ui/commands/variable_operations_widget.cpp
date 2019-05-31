#include "variableoperations.h"
#include "ui_variableoperations.h"

VariableOperations::VariableOperations(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::VariableOperations),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

VariableOperations::~VariableOperations()
{
	delete ui;
}
