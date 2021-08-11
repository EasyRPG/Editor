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

#include "open_project_dialog.h"
#include "ui_open_project_dialog.h"
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QStyle>
#include "core.h"
#include "model/project.h"

OpenProjectDialog::OpenProjectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::OpenProjectDialog)
{
	setModal(true);
	ui->setupUi(this);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	ui->tableProjects->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

OpenProjectDialog::~OpenProjectDialog()
{
	delete ui;
}

void OpenProjectDialog::setDefaultDir(const QString& n_defDir)
{
	m_defaultDir = n_defDir;
	ui->lineProjectPath->setText(n_defDir);
	refreshProjectList();
}

QString OpenProjectDialog::getDefaultDir()
{
	return m_defaultDir;
}

std::shared_ptr<Project> OpenProjectDialog::getProject() {
	if (ui->tableProjects->currentRow() >= 0) {
		return prjList[static_cast<size_t>(ui->tableProjects->currentRow())];
	}

	return nullptr;
}

void OpenProjectDialog::refreshProjectList()
{
	ui->tableProjects->setRowCount(0);

	prjList = Project::enumerate(m_defaultDir);

	for (const auto& prj: prjList) {
		ui->tableProjects->insertRow(ui->tableProjects->rowCount());
		QTableWidgetItem* item = new QTableWidgetItem(prj->projectDir().dirName());
		item->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
		item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui->tableProjects->setItem(ui->tableProjects->rowCount() - 1, 0, item);

		item = new QTableWidgetItem(prj->gameTitle());
		item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui->tableProjects->setItem(ui->tableProjects->rowCount() - 1, 1, item);
	}

	if (ui->tableProjects->rowCount() > 0) {
		ui->tableProjects->setCurrentItem(ui->tableProjects->item(0, 1));
	}
}

void OpenProjectDialog::on_toolProjectPath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this, "Select destination folder", m_defaultDir);
	if (path == QString())
		return;
	ui->lineProjectPath->setText(path+"/");
	m_defaultDir = ui->lineProjectPath->text();
	refreshProjectList();
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
	Q_UNUSED(row)
	Q_UNUSED(column)
	emit ui->buttonBox->accepted();
}

void OpenProjectDialog::on_tableProjects_itemSelectionChanged()
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->tableProjects->selectedItems().empty());
}
