#ifndef CHANGEPARTY_H
#define CHANGEPARTY_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangePartyWidget;
}

class ChangePartyWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ChangePartyWidget(QWidget *parent, RPG::EventCommand &cmd);
	~ChangePartyWidget();

private slots:
	void on_ChangePartyWidget_accepted();

private:
	Ui::ChangePartyWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // CHANGEPARTY_H
