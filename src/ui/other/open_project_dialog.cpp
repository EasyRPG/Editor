#include "open_project_dialog.h"
#include "ui_open_project_dialog.h"
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QStyle>
#include "core.h"

OpenProjectDialog::OpenProjectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::OpenProjectDialog)
{
	setModal(true);
	ui->setupUi(this);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

OpenProjectDialog::~OpenProjectDialog()
{
	delete ui;
}

void OpenProjectDialog::setDefDir(QString n_defDir)
{
	if (!n_defDir.endsWith('/'))
		n_defDir.append("/");
	m_defDir = n_defDir;
	ui->lineProjectPath->setText(n_defDir);
	RefreshProjectList();
}

QString OpenProjectDialog::getDefDir()
{
	return m_defDir;
}

QString OpenProjectDialog::getProjectFolder()
{
	return (ui->tableProjects->item(ui->tableProjects->currentRow(),0)->text());
}

void OpenProjectDialog::RefreshProjectList()
{
	ui->tableProjects->clearContents();
	QDir dir(m_defDir);
	if (!dir.exists())
		return;
	Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden	| QDir::AllDirs | QDir::Files, QDir::DirsFirst))
	{
		if (info.isDir())
		{
			QFileInfo f_project(info.absoluteFilePath()+"/"+EASY_DB);
			if (f_project.exists())
			{
				ui->tableProjects->insertRow(ui->tableProjects->rowCount());
				QTableWidgetItem *item = new QTableWidgetItem(info.baseName());
				item->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
				item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
				ui->tableProjects->setItem(ui->tableProjects->rowCount()-1,0,item);
				QSettings settings(m_defDir+info.baseName()+"/"+EASY_CFG,
									QSettings::IniFormat,
									this);
				item = new QTableWidgetItem(settings.value(GAMETITLE, "Untitled").toString());
				item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
				ui->tableProjects->setItem(ui->tableProjects->rowCount()-1,1,item);
			}
		}
	}
	if (ui->tableProjects->rowCount() > 0) {
		ui->tableProjects->setCurrentItem(ui->tableProjects->item(0,1));
	}
}

void OpenProjectDialog::on_toolProjectPath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this, "Select destination forlder", m_defDir);
	if (path == QString())
		return;
	ui->lineProjectPath->setText(path+"/");
	m_defDir = ui->lineProjectPath->text();
	RefreshProjectList();
}

bool OpenProjectDialog::removeDir(const QString & dirName)
{
	bool result = true;
	QDir dir(dirName);

	if (dir.exists(dirName)) {
		Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden	| QDir::AllDirs | QDir::Files, QDir::DirsFirst))
		{
			if (info.isDir())
				result = removeDir(info.absoluteFilePath());
			else
				result = QFile::remove(info.absoluteFilePath());

			if (!result)
			{
				QMessageBox::warning(this,
									 "An error ocurred",
									 QString("Could't delete %1").arg(info.absoluteFilePath()),
									 QMessageBox::Ok, 0);
				return false;
			}
		}
		result = dir.rmdir(dirName);
	}
	return result;
}

void OpenProjectDialog::on_tableProjects_cellDoubleClicked(int row, int column)
{
	Q_UNUSED(row);
	Q_UNUSED(column);
	emit ui->buttonBox->accepted();
}

void OpenProjectDialog::on_tableProjects_itemSelectionChanged()
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->tableProjects->selectedItems().empty());
}
