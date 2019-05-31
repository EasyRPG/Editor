#ifndef CHANGEMONEY_H
#define CHANGEMONEY_H

#include <QDialog>
#include <rpg_commonevent.h>

namespace Ui {
class ChangeMoneyWidgetWidget;
}

class ChangeMoneyWidgetWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeMoneyWidgetWidget(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeMoneyWidgetWidget();

private slots:
	void on_ChangeMoneyWidgetWidget_accepted();

private:
	Ui::ChangeMoneyWidgetWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // CHANGEMONEY_H
