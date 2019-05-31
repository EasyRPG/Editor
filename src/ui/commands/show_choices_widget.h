#ifndef SHOWCHOICES_H
#define SHOWCHOICES_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ShowChoicesWidget;
}

class ShowChoicesWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ShowChoicesWidget(QWidget *parent, RPG::EventCommand &cmd);
	~ShowChoicesWidget();

private slots:

private:
	Ui::ShowChoicesWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // SHOWCHOICES_H
