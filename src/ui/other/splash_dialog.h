#ifndef DIALOGSPLASH_H
#define DIALOGSPLASH_H

#include <QDialog>
#include <QProgressBar>
#include <QLabel>

namespace Ui {
class SplashDialog;
}

class SplashDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SplashDialog(QWidget *parent = nullptr);
	~SplashDialog();

private:
	Ui::SplashDialog *ui;
};

#endif // DIALOGSPLASH_H
