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

#include "new_project_dialog.h"
#include "ui_new_project_dialog.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NewProjectDialog)
{
	ui->setupUi(this);
	setModal(true);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewProjectDialog::~NewProjectDialog()
{
	delete ui;
}

QString NewProjectDialog::getProjectFolder() const
{
	return ui->lineGameFolder->text();
}

QString NewProjectDialog::getGameTitle() const
{
	if (ui->lineGameTitle->text().isEmpty())
		return (tr("Untitled"));
	return ui->lineGameTitle->text();
}

int NewProjectDialog::getTileSize() const
{
	bool *ok = new bool;
	int val = ui->comboTileSize->currentText().toInt(ok);
	if (!*ok)
		val = 16;
	return val;
}

void NewProjectDialog::setDefDir(QString n_defDir)
{
	if (!n_defDir.endsWith('/'))
		n_defDir.append("/");
	ui->lineProjectPath->setText(n_defDir);
	m_defDir = n_defDir;
}

QString NewProjectDialog::getDefDir()
{
	return ui->lineProjectPath->text();
}

void NewProjectDialog::on_toolProjectPath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this,
													 "Select destination forlder",
													 m_defDir);
	if (path == QString())
		return;
	ui->lineProjectPath->setText(path+"/");
	m_defDir = ui->lineProjectPath->text();
}

//TODO: generate RTP template code.

void NewProjectDialog::on_lineGameFolder_textChanged(const QString &arg1)
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!arg1.isEmpty());
}
