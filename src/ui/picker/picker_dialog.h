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

#pragma once

#include <QDialog>
#include <QDir>
#include <QMouseEvent>

#include "common/filefinder.h"

class ProjectData;
class QFileSystemModel;
class QAbstractButton;
class PickerChildWidget;

namespace Ui {
class PickerDialog;
}

class PickerDialog : public QDialog {
	Q_OBJECT

public:
	explicit PickerDialog(ProjectData& project, PickerChildWidget* wrappedWidget = nullptr, QWidget *parent = nullptr);
	~PickerDialog() override;

	void setDirectoryAndFile(const QString& dir, const QString& initialFile, FileFinder::FileType file_type);

signals:
	void fileSelected(QString baseName);

private slots:
	void on_filesystemView_clicked(const QModelIndex &index);
	void buttonClicked(QAbstractButton* button);
	void redraw();
	void viewClicked(const QPointF& pos);

protected:
	Ui::PickerDialog *ui;

private:
	ProjectData& m_project;
	QPixmap image;
	QDir m_dir;
	QFileInfo m_currentFile;
	QFileSystemModel* m_model = nullptr;
};
