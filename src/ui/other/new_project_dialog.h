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

#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit NewProjectDialog(QWidget *parent = nullptr);
	~NewProjectDialog();

	QString getGameTitle() const;
	QString getProjectFolder() const;
	int getTileSize() const;

	//TODO: generate RTP template code.

	void setDefDir(QString n_defDir);
	QString getDefDir();


private slots:
	void on_toolProjectPath_clicked();

	void on_lineGameFolder_textChanged(const QString &arg1);

private:
	Ui::NewProjectDialog *ui;
	QString m_defDir;
};

#endif // DIALOGNEWPROJECT_H
