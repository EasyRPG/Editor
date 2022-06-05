/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

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
													 tr("Select destination folder"),
													 m_defDir);
	if (path.isEmpty())
		return;
	ui->lineProjectPath->setText(path+"/");
	m_defDir = ui->lineProjectPath->text();
}

void ImportProjectDialog::on_toolSourcePath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this,
													 tr("Select origin folder"),
													 m_defDir);
	if (path.isEmpty())
		return;
	if (!QFileInfo(path+"/RPG_RT.ldb").exists())
	{
		QMessageBox::critical(this,
							  tr("Error"),
							  tr("This folder does not contain a valid RPG Maker project"));
		return;
	}
	ui->lineSourcePath->setText(path+"/");
	ui->lineGameFolder->setText(QDir(path).dirName());
}
