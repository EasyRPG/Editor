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
#include <memory>
#include <lcf/rpg/map.h>
#include <vector>

class ProjectData;

namespace Ui {
	class SearchDialog;
}

class SearchDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SearchDialog(ProjectData& project, QWidget *parent = nullptr);
	~SearchDialog();

	void updateUI();
	void enableCache(bool enable);

private slots:
	void on_button_search_clicked();

	void on_list_result_doubleClicked(const QModelIndex &index);

private:
	std::shared_ptr<lcf::rpg::Map> loadMap(int mapID);

	Ui::SearchDialog *ui;
	using command_info = std::tuple<int, int, int, int, const lcf::rpg::EventCommand&>; // map id, event id, page index, line, event command
	std::vector<command_info> objectData;
	std::vector<std::shared_ptr<lcf::rpg::Map>> map_cache;
	bool useCache;
	void showResults(const std::vector<command_info>& results);
	ProjectData& m_project;
};

