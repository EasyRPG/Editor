#ifndef ITEMMANAGEMENT_H
#define ITEMMANAGEMENT_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangeItemWidget;
}

class ChangeItemWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeItemWidget(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeItemWidget();

private slots:
	void on_ChangeItemWidget_accepted();

private:
	Ui::ChangeItemWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // ITEMMANAGEMENT_H
