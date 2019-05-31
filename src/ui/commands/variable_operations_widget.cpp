#include "variable_operations_widget.h"
#include "ui_variable_operations_widget.h"

VariableOperationsWidget::VariableOperationsWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::VariableOperationsWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

VariableOperationsWidget::~VariableOperationsWidget()
{
	delete ui;
}
