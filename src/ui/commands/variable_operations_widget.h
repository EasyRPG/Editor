#ifndef VARIABLEOPERATIONS_H
#define VARIABLEOPERATIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class VariableOperationsWidget;
}

class VariableOperationsWidget : public QDialog
{
	Q_OBJECT

public:
	explicit VariableOperationsWidget(QWidget *parent, RPG::EventCommand &cmd);
	~VariableOperationsWidget();

private slots:

private:
	Ui::VariableOperationsWidget *ui;
	RPG::EventCommand &cmd;
};


#endif // VARIABLEOPERATIONS_H
