#ifndef DIALOGOPENPROJECT_H
#define DIALOGOPENPROJECT_H

#include <QDialog>

namespace Ui {
class OpenProjectDialog;
}

class OpenProjectDialog : public QDialog
{
	Q_OBJECT

public:
	explicit OpenProjectDialog(QWidget *parent = nullptr);
	~OpenProjectDialog();

	void setDefDir(QString n_defDir);
	QString getDefDir();

	QString getProjectFolder();

private slots:
	void on_toolProjectPath_clicked();

	void on_tableProjects_cellDoubleClicked(int row, int column);

	void on_tableProjects_itemSelectionChanged();

private:
	Ui::OpenProjectDialog *ui;
	QString m_defDir;
	bool removeDir(const QString &dirName);
	void RefreshProjectList();
};

#endif // DIALOGOPENPROJECT_H
