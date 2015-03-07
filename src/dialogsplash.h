#ifndef DIALOGSPLASH_H
#define DIALOGSPLASH_H

#include <QDialog>
#include <QProgressBar>
#include <QLabel>

namespace Ui {
class DialogSplash;
}

class DialogSplash : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSplash(QWidget *parent = 0);
    ~DialogSplash();

private:
    Ui::DialogSplash *ui;
};

#endif // DIALOGSPLASH_H
