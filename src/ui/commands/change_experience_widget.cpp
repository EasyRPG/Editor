#include "change_experience_widget.h"
#include "ui_change_experience_widget.h"

ChangeExperienceWidget::ChangeExperienceWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangeExperienceWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	if (cmd.parameters[0] == 0)
		ui->target_box_entire->setChecked(true);
	else if (cmd.parameters[0] == 1)
	{
		ui->target_box_specific->setChecked(true);
		ui->target_specific->setCurrentIndex(cmd.parameters[1]);
	}
	else if (cmd.parameters[0] == 2)
	{
		ui->target_box_variable->setChecked(true);
		ui->target_variable->setCurrentIndex(cmd.parameters[1]);
	}

	(cmd.parameters[2] ? ui->op_dec : ui->op_inc)->setChecked(true);

	if (cmd.parameters[3] == 0)
	{
		ui->amount_fixed->setValue(cmd.parameters[4]);
		ui->amount_box_fixed->setChecked(true);
	}
	else
	{
		ui->amount_variable->setCurrentIndex(cmd.parameters[4]);
		ui->amount_box_variable->setChecked(true);
	}

	ui->option_show->setChecked(cmd.parameters[5]);
}

ChangeExperienceWidget::~ChangeExperienceWidget()
{
	delete ui;
}

void ChangeExperienceWidget::on_ChangeExperienceWidget_accepted()
{
	if (ui->target_box_entire->isChecked())
		cmd.parameters[0] = 0;
	else if (ui->target_box_specific->isChecked())
	{
		cmd.parameters[0] = 1;
		cmd.parameters[1] = ui->target_specific->currentIndex();
	}
	else
	{
		cmd.parameters[0] = 2;
		cmd.parameters[1] = ui->target_variable->currentIndex();
	}

	cmd.parameters[2] = ui->op_dec->isChecked();
	cmd.parameters[3] = ui->amount_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[4] = ui->amount_box_variable->isChecked() ? ui->amount_variable->currentIndex() : ui->amount_fixed->value();
	cmd.parameters[5] = ui->option_show->isChecked();
}
