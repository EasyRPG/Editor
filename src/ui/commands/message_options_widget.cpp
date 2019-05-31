#include "messageoptions.h"
#include "ui_messageoptions.h"

MessageOptions::MessageOptions(QWidget *parent, RPG::EventCommand &command) :
	QDialog(parent),
	ui(new Ui::MessageOptions),
	command(command)
{
	ui->setupUi(this);

	//TODO
}

MessageOptions::~MessageOptions()
{
	delete ui;
}
