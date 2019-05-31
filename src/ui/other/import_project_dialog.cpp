#include "import_project_dialog.h"
#include "ui_import_project_dialog.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>

ImportProjectDialog::ImportProjectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ImportProjectDialog)
{
	ui->setupUi(this);
	setModal(true);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

ImportProjectDialog::~ImportProjectDialog()
{
	delete ui;
}

QString ImportProjectDialog::getProjectFolder() const
{
	return ui->lineGameFolder->text();
}

QString ImportProjectDialog::getSourceFolder() const
{
	return ui->lineSourcePath->text();
}

void ImportProjectDialog::setDefDir(QString n_defDir)
{
	if (!n_defDir.endsWith('/'))
		n_defDir.append("/");
	ui->lineProjectPath->setText(n_defDir);
	m_defDir = n_defDir;
}

QString ImportProjectDialog::getDefDir()
{
	return ui->lineProjectPath->text();
}

bool ImportProjectDialog::getConvertXYZ() const {
	return ui->checkConvertXYZ->isChecked();
}

void ImportProjectDialog::on_lineGameFolder_textChanged(const QString &arg1)
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!arg1.isEmpty());
}

void ImportProjectDialog::on_toolProjectPath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this,
													 "Select destination folder",
													 m_defDir);
	if (path.isEmpty())
		return;
	ui->lineProjectPath->setText(path+"/");
	m_defDir = ui->lineProjectPath->text();
}

void ImportProjectDialog::on_toolSourcePath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this,
													 "Select origin folder",
													 m_defDir);
	if (path.isEmpty())
		return;
	if (!QFileInfo(path+"/RPG_RT.ldb").exists())
	{
		QMessageBox::critical(this,
							  "Error",
							  "This folder does not contain a valid RPG Maker project");
		return;
	}
	ui->lineSourcePath->setText(path+"/");
	ui->lineGameFolder->setText(QDir(path).dirName());
}
