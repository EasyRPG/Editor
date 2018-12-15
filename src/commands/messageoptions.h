#ifndef MESSAGEOPTIONS_H
#define MESSAGEOPTIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class MessageOptions;
}

class MessageOptions : public QDialog
{
	Q_OBJECT

public:
	explicit MessageOptions(QWidget *parent, RPG::EventCommand &command);
	~MessageOptions();

private:
	Ui::MessageOptions *ui;
	RPG::EventCommand &command;
};

#endif // MESSAGEOPTIONS_H
