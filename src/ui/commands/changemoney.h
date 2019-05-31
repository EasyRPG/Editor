#ifndef CHANGEMONEY_H
#define CHANGEMONEY_H

#include <QDialog>
#include <rpg_commonevent.h>

namespace Ui {
class ChangeMoney;
}

class ChangeMoney : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeMoney(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeMoney();

private slots:
	void on_ChangeMoney_accepted();

private:
	Ui::ChangeMoney *ui;
	RPG::EventCommand &cmd;
};

#endif // CHANGEMONEY_H
