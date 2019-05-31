#ifndef ITEMMANAGEMENT_H
#define ITEMMANAGEMENT_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangeItem;
}

class ChangeItem : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeItem(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeItem();

private slots:
	void on_ChangeItem_accepted();

private:
	Ui::ChangeItem *ui;
	RPG::EventCommand &cmd;
};

#endif // ITEMMANAGEMENT_H
