#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>

namespace Ui {
class DialogEvent;
}

class DialogEvent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvent(QWidget *parent = 0);
    ~DialogEvent();

private slots:
    void on_toolRtpPath_clicked();

    void on_ok();
private:
    Ui::DialogEvent *ui;
};
#endif // DIALOGEVENT_H
