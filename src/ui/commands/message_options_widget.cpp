#include "message_options_widget.h"
#include "ui_message_options_widget.h"

MessageOptionsWidget::MessageOptionsWidget(QWidget *parent, RPG::EventCommand &command) :
	QDialog(parent),
	ui(new Ui::MessageOptionsWidget),
	command(command)
{
	ui->setupUi(this);

	//TODO
}

MessageOptionsWidget::~MessageOptionsWidget()
{
	delete ui;
}
