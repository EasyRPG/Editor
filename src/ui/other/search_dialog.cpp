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

#include "search_dialog.h"
#include "ui_search_dialog.h"
#include "ui/main_window.h"
#include "core.h"
#include "stringizer.h"

#include <command_codes.h>
#include <data.h>
#include <lmu_reader.h>
#include <functional>
#include <vector>
#include <tuple>
#include <QMessageBox>
#include <QCompleter>

SearchDialog::SearchDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SearchDialog)
{
	ui->setupUi(this);

	ui->list_result->setColumnCount(5);
	ui->list_result->setRowCount(0);
	ui->list_result->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->list_result->setEditTriggers(QAbstractItemView::NoEditTriggers);


	for (auto *box : {ui->combo_variable, ui->combo_switch, ui->combo_item, ui->combo_eventname})
	{
		box->completer()->setFilterMode(Qt::MatchContains);
		box->completer()->setCompletionMode(QCompleter::PopupCompletion);
	}

	enableCache(false);
}

SearchDialog::~SearchDialog()
{
	delete ui;
}

void SearchDialog::updateUI()
{
	const QString format("%1: %2");

	for (auto &v : core().project()->database().variables)
		ui->combo_variable->addItem(format.arg(QString::number(v.ID), QString::fromStdString(v.name)), v.ID);
	for (auto &s : core().project()->database().switches)
		ui->combo_switch->addItem(format.arg(QString::number(s.ID), QString::fromStdString(s.name)), s.ID);
	for (auto &i : core().project()->database().items)
		ui->combo_item->addItem(format.arg(QString::number(i.ID), QString::fromStdString(i.name)), i.ID);
	for (auto &e : core().project()->database().commonevents)
		ui->combo_eventname->addItem(format.arg(QString::number(e.ID), QString::fromStdString(e.name)), e.ID);
}

void SearchDialog::enableCache(bool enable)
{
	useCache = enable;

	if (enable)
		map_cache = std::vector<std::shared_ptr<RPG::Map>>(core().project()->treeMap().maps.size());
	else
		map_cache.clear();

}

void SearchDialog::on_button_search_clicked()
{
	objectData.clear();
	ui->list_result->clear();
	ui->list_result->setRowCount(0);
	QStringList sl;
	sl << "Map" << "Event" << "Event Page" << "Sourceline" << "Action";
	ui->list_result->setHorizontalHeaderLabels(sl);

	std::function<bool(const RPG::EventCommand&)> search_predicate;
	auto map_searcher = [&search_predicate](int mapID, const RPG::Map& map) {
		std::vector<command_info> res;
		for (auto& e : map.events)
			for (auto& p : e.pages)
				for (size_t line = 0; line < p.event_commands.size(); line++)
				{
					auto& com = p.event_commands[line];
					if (search_predicate(com))
						res.emplace_back(mapID, e.ID, p.ID, line+1, com);
				}

		return res;
	};
	auto common_searcher = [&search_predicate](const std::vector<RPG::CommonEvent> events) {
		std::vector<command_info> res;
		for (auto& e : events)
			for (size_t line = 0; line < e.event_commands.size(); line++)
			{
				auto& com = e.event_commands[line];
				if (search_predicate(com))
					res.emplace_back(0, e.ID, 0, line+1, com);
			}

		return res;
	};

	if (ui->radio_variable->isChecked())
	{
		int varID = ui->combo_variable->currentData().toInt();

		search_predicate = [varID](const RPG::EventCommand& com)
		{
			switch (com.code)
			{
				case Cmd::InputNumber:
					return com.parameters[1] == varID;
				case Cmd::ControlSwitches:
					return com.parameters[0] == 2 && com.parameters[1] == varID;
				case Cmd::ControlVars:
					return (com.parameters[4] == 1 && com.parameters[5] == varID) ||
						(com.parameters[4] == 2 && com.parameters[5] == varID) ||
						com.parameters[1] == varID || com.parameters[2] == varID;
				case Cmd::ChangeItems:
				case Cmd::ChangePartyMembers:
					return com.parameters[1] == 1 && com.parameters[2] == varID;
				case Cmd::EnemyEncounter:
					return com.parameters[0] == 1 && com.parameters[2] == varID;
				case Cmd::ChangeSkills:
				case Cmd::ChangeEquipment:
				case Cmd::ChangeHP:
				case Cmd::ChangeSP:
					return com.parameters[3] == 1 && com.parameters[4] == varID;
				case Cmd::SimulatedAttack:
					return com.parameters[6] != 0 && com.parameters[7] == varID;
				case Cmd::MemorizeLocation:
				case Cmd::RecallToLocation:
					return com.parameters[0] == varID || com.parameters[1] == varID ||
						com.parameters[2] == varID;
				case Cmd::SetVehicleLocation:
					return (com.parameters[1] == 1 && com.parameters[2] == varID) ||
						(com.parameters[1] == 1 && com.parameters[3] == varID) ||
						(com.parameters[1] == 1 && com.parameters[4] == varID);
				case Cmd::ChangeEventLocation:
				case Cmd::ShowPicture:
				case Cmd::MovePicture:
					return (com.parameters[1] == 1 && com.parameters[2] == varID) ||
						(com.parameters[1] == 1 && com.parameters[3] == varID);
				case Cmd::StoreTerrainID:
				case Cmd::StoreEventID:
					return (com.parameters[1] == 1 && com.parameters[2] == varID) ||
						(com.parameters[1] == 1 && com.parameters[3] == varID) ||
						(com.parameters[1] == 1 && com.parameters[4] == varID);
				case Cmd::KeyInputProc:
					return com.parameters[0] == varID ||
						(com.parameters.size() > 6 && com.parameters[7] == varID);
				case Cmd::ConditionalBranch:
					return com.parameters[0] == 1 &&
						(com.parameters[1] == varID || (com.parameters[2] != 0 && com.parameters[3] == varID));
				case Cmd::CallEvent:
					return com.parameters[0] == 2 && (com.parameters[1] == varID || com.parameters[2] == varID);
				case Cmd::PlayMovie:
					return (com.parameters[0] == 1 && com.parameters[1] == varID) ||
						(com.parameters[0] == 1 && com.parameters[2] == varID);
				default:
					return false;
			}
		};
	}
	else if (ui->radio_switch->isChecked())
	{
		int switchID = ui->combo_switch->currentData().toInt();

		search_predicate = [switchID](const RPG::EventCommand& com)
		{
			switch(com.code)
			{
				case Cmd::ControlSwitches:
					return (com.parameters[0] != 2 && com.parameters[1] == switchID) ||
						(com.parameters[0] == 1 && com.parameters[2] == switchID);
				case Cmd::ConditionalBranch:
					return com.parameters[0] == 0 && com.parameters[1] == switchID;
				default:
					return false;
			}
		};
	}
	else if (ui->radio_item->isChecked())
	{
		int itemID = ui->combo_item->currentData().toInt();

		search_predicate = [itemID](const RPG::EventCommand& com)
		{
			switch (com.code)
			{
				case Cmd::ChangeItems:
					return com.parameters[2] == itemID;
				case Cmd::ControlVars:
					return com.parameters[4] == 4 && com.parameters[5] == itemID;
				case Cmd::ChangeEquipment:
					return com.parameters[3] == 0 && com.parameters[4] == itemID;
				case Cmd::ConditionalBranch:
					return com.parameters[0] == 4 && com.parameters[1] == itemID;
				default:
					return false;
			}
		};
	}
	else //if (ui->radio_eventname->isChecked())
	{
		//TODO implement me
	}

	if (!search_predicate)
	{
		QMessageBox::warning(this, "", "This search parameter isn't supported yet.");
		return;
	}

	if (ui->scope_current->isChecked())
	{
		const auto mapID = static_cast<MainWindow*>(parent())->currentScene()->id();
		auto map = loadMap(mapID);

		auto res = map_searcher(mapID, *map);
		showResults(res);
	}
	else if (ui->scope_events->isChecked())
	{
		showResults(common_searcher(core().project()->database().commonevents));
	}
	else // if (ui->scope_project->isChecked())
	{
		for (auto &map : core().project()->treeMap().maps)
		{
			ui->label_status->setText(QString("Parsing Map %1 / %2").arg(QString::number(map.ID + 1), QString::number(core().project()->treeMap().maps.size())));
			QApplication::processEvents(); //FIXME: can this be done better?!

			auto mapp = loadMap(map.ID);

			if (!mapp) continue;

			auto res = map_searcher(map.ID, *mapp);
			showResults(res);
		}
	}
	ui->list_result->resizeColumnsToContents();
}

void SearchDialog::on_list_result_doubleClicked(const QModelIndex &index)
{
	auto *par = static_cast<MainWindow*>(parent());
	par->openScene(std::get<0>(objectData[static_cast<size_t>(index.row())]));
	auto *event = (*par->currentScene()->mapEvents())[std::get<1>(objectData[static_cast<size_t>(index.row())])];
	par->selectTile(event->x, event->y);
	par->currentScene()->centerOnTile(event->x, event->y);
}

std::shared_ptr<RPG::Map> SearchDialog::loadMap(int mapID)
{
	if (!(useCache && map_cache[static_cast<size_t>(mapID)]))
	{
		const std::shared_ptr<RPG::Map> res_map{core().project()->loadMap(mapID)};

		if (useCache)
			map_cache[static_cast<size_t>(mapID)] = res_map;

		return res_map;
	}

	return map_cache[static_cast<size_t>(mapID)];
}

void SearchDialog::showResults(const std::vector<command_info>& results) {
	for (auto &r : results)
	{
		int mapID, eventID, eventPage,	sourceLine;
		const RPG::EventCommand& command = std::get<4>(r);
		std::tie(mapID, eventID, eventPage, sourceLine, std::ignore) = r;

		auto mm = mapID;
		QStringList maps_rev;
		if (mm == 0) // Common Event
		{
			maps_rev << "Common";
		}
		else
		{
			do
			{
				auto& mapinfo = core().project()->treeMap().maps[static_cast<size_t>(mm)];
				maps_rev << QString::fromStdString(mapinfo.name);
				mm = mapinfo.parent_map;
			} while (mm != 0);
		}

		const auto descr = Stringizer::stringize(command);

		const int rows = ui->list_result->rowCount();
		ui->list_result->setRowCount(rows+1);
		ui->list_result->setItem(rows, 0, new QTableWidgetItem(maps_rev.join(" > ")));
		ui->list_result->setItem(rows, 1, new QTableWidgetItem(QString::number(eventID)));
		ui->list_result->setItem(rows, 2, new QTableWidgetItem(QString::number(eventPage)));
		ui->list_result->setItem(rows, 3, new QTableWidgetItem(QString::number(sourceLine)));
		ui->list_result->setItem(rows, 4, new QTableWidgetItem(descr));

		objectData.push_back(r);
	}
}
