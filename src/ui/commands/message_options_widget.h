#ifndef MESSAGEOPTIONS_H
#define MESSAGEOPTIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class MessageOptionsWidget;
}

class MessageOptionsWidget : public QDialog
{
	Q_OBJECT

public:
	explicit MessageOptionsWidget(QWidget *parent, RPG::EventCommand &command);
	~MessageOptionsWidget();

private:
	Ui::MessageOptionsWidget *ui;
	RPG::EventCommand &command;
};

#endif // MESSAGEOPTIONS_H
