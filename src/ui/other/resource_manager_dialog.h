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
