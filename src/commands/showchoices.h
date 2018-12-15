#ifndef SHOWCHOICES_H
#define SHOWCHOICES_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ShowChoices;
}

class ShowChoices : public QDialog
{
	Q_OBJECT

public:
	explicit ShowChoices(QWidget *parent, RPG::EventCommand &cmd);
	~ShowChoices();

private slots:

private:
	Ui::ShowChoices *ui;
	RPG::EventCommand &cmd;
};

#endif // SHOWCHOICES_H
