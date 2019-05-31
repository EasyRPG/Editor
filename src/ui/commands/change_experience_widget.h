#ifndef CHANGEEXPERIENCE_H
#define CHANGEEXPERIENCE_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class ChangeExperienceWidget;
}

class ChangeExperienceWidget : public QDialog
{
	Q_OBJECT

public:
	explicit ChangeExperienceWidget(QWidget *parent, RPG::EventCommand &cmd);
	~ChangeExperienceWidget();

private slots:
	void on_ChangeExperienceWidget_accepted();

private:
	Ui::ChangeExperienceWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // CHANGEEXPERIENCE_H
