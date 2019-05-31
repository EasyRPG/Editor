#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>
#include <rpg_event.h>

namespace Ui {
class DialogEvent;
}

class DialogEvent : public QDialog
{
	Q_OBJECT

public:
	explicit DialogEvent(QWidget *parent = nullptr);
	~DialogEvent();

	static int edit(QWidget *parent, RPG::Event *event);

	static bool equalEvents(const RPG::Event &e1,
							const RPG::Event &e2);

	RPG::Event getEvent() const;
	void setEvent(RPG::Event *event);

private slots:
	void apply();

	void ok();

private:
	Ui::DialogEvent *ui;
	RPG::Event m_event;
	RPG::Event r_event;
	RPG::Event a_event;
	int lst_result;
};
#endif // DIALOGEVENT_H
