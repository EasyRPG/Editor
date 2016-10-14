#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
class DialogEdit;
}

template <class DATA>
class DialogEdit : public QDialog
{
    //Q_OBJECT

public:
    DialogEdit(QWidget *parent, DATA &data);
    ~DialogEdit() = default;

private:
    Ui::DialogEdit *ui;
    DATA _data;
};

template <class DATA>
DialogEdit<DATA>::DialogEdit(QWidget *parent, DATA& data) :
    QDialog(parent),
    _data(data)
{
    //TODO put in data and stuff
}

#endif // DIALOGEDIT_H
