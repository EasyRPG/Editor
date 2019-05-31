#ifndef DIALOGRESOURCEMANAGER_H
#define DIALOGRESOURCEMANAGER_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class ResourceManagerDialog;
}

class ResourceManagerDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit ResourceManagerDialog(QWidget *parent = nullptr);
	~ResourceManagerDialog();

private slots:
	void on_listResourceType_currentRowChanged(int currentRow);

	void on_pushImport_clicked();

private:
	Ui::ResourceManagerDialog *ui;
	QStringListModel *m_model;

	QString m_lastmusicpath;
	QString m_lastsoundpath;
	QString m_lastmoviepath;
	QString m_lastpicturepath;

};

#endif // DIALOGRESOURCEMANAGER_H
