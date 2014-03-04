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
    explicit DialogEvent(QWidget *parent = 0);
    ~DialogEvent();

    static void edit(QWidget *parent, RPG::Event *event);

    RPG::Event event() const;
    void setEvent(const RPG::Event &event);

private slots:

private:
    Ui::DialogEvent *ui;
    RPG::Event m_event;
};
#endif // DIALOGEVENT_H
