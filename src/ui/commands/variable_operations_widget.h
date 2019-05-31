#ifndef VARIABLEOPERATIONS_H
#define VARIABLEOPERATIONS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class VariableOperations;
}

class VariableOperations : public QDialog
{
	Q_OBJECT

public:
	explicit VariableOperations(QWidget *parent, RPG::EventCommand &cmd);
	~VariableOperations();

private slots:

private:
	Ui::VariableOperations *ui;
	RPG::EventCommand &cmd;
};


#endif // VARIABLEOPERATIONS_H
