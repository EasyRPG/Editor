#ifndef DIALOGRTPPATH_H
#define DIALOGRTPPATH_H

#include <QDialog>

namespace Ui {
class RtpPathDialog;
}

class RtpPathDialog : public QDialog
{
	Q_OBJECT

public:
	explicit RtpPathDialog(QWidget *parent = nullptr);
	~RtpPathDialog();

private slots:
	void on_toolRtpPath_clicked();

	void on_ok();
private:
	Ui::RtpPathDialog *ui;
};

#endif // DIALOGRTPPATH_H
