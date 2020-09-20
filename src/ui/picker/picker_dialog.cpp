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

#include "picker_dialog.h"
#include "ui_picker_dialog.h"
#include "model/project.h"
#include "common/image_loader.h"
#include "picker_child_widget.h"
#include <QFileSystemModel>
#include <QGraphicsScene>
#include <QAbstractButton>
#include <QDialogButtonBox>

PickerDialog::PickerDialog(ProjectData &project, PickerChildWidget* wrappedWidget, QWidget *parent) :
		QDialog(parent),
		ui(new Ui::PickerDialog),
		m_project(project) {
	ui->setupUi(this);
	ui->wrappedWidget = wrappedWidget;
	m_model = new QFileSystemModel(this);
	m_model->setReadOnly(true);

	QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);
	ui->graphicsView->setScene(scene);

	QObject::connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &PickerDialog::buttonClicked);
	QObject::connect(ui->graphicsView, &ViewBase::clicked, this, &PickerDialog::viewClicked);
}

PickerDialog::~PickerDialog() {
	delete ui;
}

void PickerDialog::buttonClicked(QAbstractButton* button) {
	switch (ui->buttonBox->standardButton(button)) {
		case QDialogButtonBox::Ok:
			emit fileSelected(m_currentFile.baseName());
			QDialog::accept();
			break;
		case QDialogButtonBox::Cancel:
		case QDialogButtonBox::Close:
			QDialog::reject();
			break;
		case QDialogButtonBox::Apply:
			emit fileSelected(m_currentFile.baseName());
			break;
		case QDialogButtonBox::Help:
			// TODO
			break;
		default:
			break;
	}
}

void PickerDialog::setDirectoryAndFile(const QString &dir, const QString& initialFile, FileFinder::FileType file_type) {
	m_dir = QDir(dir);
	// FIXME: A directory FileFinder would be useful here
	QString path = m_project.project().findDirectory(dir);
	QString file = m_project.project().findFile(dir, initialFile, file_type);
	m_model->setRootPath(path);
	ui->filesystemView->setModel(m_model);
	ui->filesystemView->setRootIndex(m_model->index(path));
	ui->filesystemView->setCurrentIndex(m_model->index(file));

	m_currentFile = file;
	image = ImageLoader::Load(m_currentFile.absoluteFilePath());
	redraw();
}

void PickerDialog::on_filesystemView_clicked(const QModelIndex &index) {
	m_currentFile = m_model->fileInfo(index);
	image = ImageLoader::Load(m_currentFile.absoluteFilePath());
	redraw();
}

void PickerDialog::redraw() {
	QGraphicsScene* scene = ui->graphicsView->scene();
	auto* pixmap = new QGraphicsPixmapItem(image);
	ui->graphicsView->setItem(pixmap);
	if (ui->wrappedWidget) {
		ui->wrappedWidget->draw(scene);
	}
}

void PickerDialog::viewClicked(const QPointF& pos) {
	ui->wrappedWidget->clicked(pos);
	redraw();
}
