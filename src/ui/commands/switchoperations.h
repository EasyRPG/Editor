#ifndef SWITCHOPERATIONS_H
#define SWITCHOPERATIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class SwitchOperationsWidget;
}

class SwitchOperationsWidget : public QDialog
{
	Q_OBJECT

public:
	explicit SwitchOperationsWidget(QWidget *parent, RPG::EventCommand &cmd);
	~SwitchOperationsWidget();

private slots:

private:
	Ui::SwitchOperationsWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // SWITCHOPERATIONS_H
