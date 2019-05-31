#ifndef CHANGEEXPERIENCE_H
#define CHANGEEXPERIENCE_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangeExperience;
}

class ChangeExperience : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeExperience(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeExperience();

private slots:
	void on_ChangeExperience_accepted();

private:
	Ui::ChangeExperience *ui;
	RPG::EventCommand &cmd;
};

#endif // CHANGEEXPERIENCE_H
