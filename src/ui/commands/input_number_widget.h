#ifndef INPUTNUMBER_H
#define INPUTNUMBER_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class InputNumberWidget;
}

class InputNumberWidget : public QDialog
{
	Q_OBJECT

public:
	explicit InputNumberWidget(QWidget *parent, RPG::EventCommand &cmd);
	~InputNumberWidget();

private slots:


private:
	Ui::InputNumberWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // INPUTNUMBER_H
