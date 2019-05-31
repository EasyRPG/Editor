#include "input_number_widget.h"
#include "ui_input_number_widget.h"

InputNumberWidget::InputNumberWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::InputNumberWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

InputNumberWidget::~InputNumberWidget()
{
	delete ui;
}
