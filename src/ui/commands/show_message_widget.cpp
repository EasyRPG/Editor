#include "show_message_widget.h"
#include "ui_show_message_widget.h"

ShowMessageWidget::ShowMessageWidget(QWidget *parent, RPG::EventCommand &command) :
	QDialog(parent),
	ui(new Ui::ShowMessageWidget),
	command(command)
{
	ui->setupUi(this);

	//TODO
}

ShowMessageWidget::~ShowMessageWidget()
{
	delete ui;
}
