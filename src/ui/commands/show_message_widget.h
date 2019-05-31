#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ShowMessageWidget;
}

class ShowMessageWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ShowMessageWidget(QWidget *parent, RPG::EventCommand &command);
	~ShowMessageWidget();

private:
	Ui::ShowMessageWidget *ui;
	RPG::EventCommand &command;
};

#endif // SHOWMESSAGE_H
