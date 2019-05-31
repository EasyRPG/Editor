#ifndef DIALOGRTPPATH_H
#define DIALOGRTPPATH_H

#include <QDialog>

namespace Ui {
class DialogRtpPath;
}

class DialogRtpPath : public QDialog
{
	Q_OBJECT

public:
	explicit DialogRtpPath(QWidget *parent = nullptr);
	~DialogRtpPath();

private slots:
	void on_toolRtpPath_clicked();

	void on_ok();
private:
	Ui::DialogRtpPath *ui;
};

#endif // DIALOGRTPPATH_H
