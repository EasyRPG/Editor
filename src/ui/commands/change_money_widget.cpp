#include "change_money_widget.h"
#include "ui_change_money_widget.h"

ChangeMoneyWidgetWidget::ChangeMoneyWidgetWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangeMoneyWidgetWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	(cmd.parameters[0] ? ui->op_dec : ui->op_inc)->setChecked(true);
	if (cmd.parameters[1] == 0)
	{
		ui->amount_box_amount->setChecked(true);
		ui->amount_amount->setValue(cmd.parameters[2]);
	}
	else
	{
		ui->amount_box_variable->setChecked(true);
		ui->amount_variable->setCurrentIndex(cmd.parameters[2]);
	}
}

ChangeMoneyWidgetWidget::~ChangeMoneyWidgetWidget()
{
	delete ui;
}

void ChangeMoneyWidgetWidget::on_ChangeMoneyWidgetWidget_accepted()
{
	cmd.parameters[0] = ui->op_dec->isChecked() ? 1 : 0;
	cmd.parameters[1] = ui->amount_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[2] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_amount->value();
}
