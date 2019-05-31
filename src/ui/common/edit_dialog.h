#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
class EditDialog;
}

template <class DATA>
class EditDialog : public QDialog
{
	//Q_OBJECT

public:
	EditDialog(QWidget *parent, DATA &data);
	~EditDialog() = default;

private:
	Ui::EditDialog *ui;
	DATA _data;
};

template <class DATA>
EditDialog<DATA>::EditDialog(QWidget *parent, DATA& data) :
	QDialog(parent),
	_data(data)
{
	//TODO put in data and stuff
}

#endif // DIALOGEDIT_H
