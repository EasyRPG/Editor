#include "show_choices_widget.h"
#include "ui_show_choices_widget.h"

ShowChoicesWidget::ShowChoicesWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ShowChoicesWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

ShowChoicesWidget::~ShowChoicesWidget()
{
	delete ui;
}
