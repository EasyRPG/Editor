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

#include "event_commands_widget.h"
#include "stringizer.h"
#include "ui/commands/all_commands.h"
#include "ui/event/event_raw_widget.h"
#include "ui/common/widget_as_dialog_wrapper.h"
#include <iostream>
#include <QMenu>
#include <QAction>
#include <memory>


EventCommandsWidget::EventCommandsWidget(QWidget* parent) :
	QTreeWidget(parent)
{
	setHeaderHidden(true);

	setContextMenuPolicy(Qt::CustomContextMenu);

	connect(this, &QTreeWidget::itemDoubleClicked, this, &EventCommandsWidget::editEvent);
	connect(this, &QTreeWidget::customContextMenuRequested, this, &EventCommandsWidget::showContextMenu);
}

void EventCommandsWidget::setData(ProjectData& project, lcf::rpg::CommonEvent* event) {
	setDataInternal(project, event);
}

void EventCommandsWidget::setData(ProjectData& project, lcf::rpg::TroopPage* event) {
	setDataInternal(project, event);
}

void EventCommandsWidget::setData(ProjectData& project, lcf::rpg::EventPage* event) {
	setDataInternal(project, event);
}

template<typename T>
void EventCommandsWidget::setDataInternal(ProjectData& project, T* event) {
	assert(event);
	m_project = &project;
	m_commands = &event->event_commands;
	clear();

	// Populate event command list
	int32_t prev_indent = -1;
	std::vector<QTreeWidgetItem*> parent_stack;
	parent_stack.reserve(10);

	for (size_t i = 0; i < m_commands->size(); ++i) {
		auto& cmd = (*m_commands)[i];

		auto indent = cmd.indent;

		auto* item = new QTreeWidgetItem({Stringizer::stringize(cmd), QString::number(i)});
		item->setToolTip(0, tr("Line") + ": " + QString::number(i + 1));
		item->setData(0, Qt::UserRole, QVariant::fromValue(reinterpret_cast<void*>(&cmd)));

		if (indent == 0 || prev_indent == -1) {
			addTopLevelItem(item);
			parent_stack = {item};
		} else {
			if (indent != prev_indent) {
				parent_stack.resize(indent + 1);
			}
			if (!parent_stack[indent - 1]) {
				std::cerr << QString("Event Command %1 (Line %2) has bad indent").arg(cmd.code).arg(i+1).toStdString() << "\n";
				for (auto j = indent - 1; j >= 0; --j) {
					if (parent_stack[j]) {
						indent = j + 1;
						break;
					}
				}
				parent_stack.resize(indent + 1);
			}

			parent_stack[indent - 1]->addChild(item);
			parent_stack[indent] = item;
		}

		prev_indent = indent;
	}

	expandAll();
}

template<typename T>
WidgetAsDialogWrapper<T, lcf::rpg::EventCommand>* make_evt_dialog(ProjectData* prj, lcf::rpg::EventCommand& cmd, EventCommandsWidget* self) {
	return new WidgetAsDialogWrapper<T, lcf::rpg::EventCommand>(*prj, cmd, self);
}

void EventCommandsWidget::editEvent(QTreeWidgetItem* item, int column) {
	assert(column == 0);

	using Cmd = lcf::rpg::EventCommand::Code;

	auto& cmd = *static_cast<lcf::rpg::EventCommand*>(item->data(column, Qt::UserRole).value<void*>());

	// Commands with no configuration
	switch (static_cast<Cmd>(cmd.code))	{
		case Cmd::EnterExitVehicle:
		case Cmd::MemorizeBGM:
		case Cmd::PlayMemorizedBGM:
		case Cmd::OpenSaveMenu:
		case Cmd::OpenMainMenu:
		case Cmd::Loop:
		case Cmd::BreakLoop:
		case Cmd::EndEventProcessing:
		case Cmd::EraseEvent:
		case Cmd::GameOver:
		case Cmd::ReturntoTitleScreen:
		case Cmd::OpenLoadMenu:
		case Cmd::ExitGame:
		case Cmd::ToggleAtbMode:
		case Cmd::ToggleFullscreen:
		case Cmd::OpenVideoOptions:
			return;
		default:
			break;
	}

/*
	switch (static_cast<Cmd>(cmd.code))	{
		case Cmd::ChangeGold: dialog = std::make_unique<ChangeMoneyWidgetWidget>(this, cmd); break;
		case Cmd::ChangeItems: dialog = std::make_unique<ChangeItemWidget>(this, cmd); break;
		case Cmd::ChangePartyMembers: dialog = std::make_unique<ChangePartyWidget>(this, cmd); break;
		case Cmd::ChangeExp: dialog = std::make_unique<ChangeExperienceWidget>(this, cmd); break;
		case Cmd::ChangeFaceGraphic: dialog = std::make_unique<FaceGraphicsWidget>(this, cmd); break;
		case Cmd::InputNumber: dialog = std::make_unique<InputNumberWidget>(this, cmd); break;
		case Cmd::MessageOptions: dialog = std::make_unique<MessageOptionsWidget>(this, cmd); break;
		case Cmd::ShowChoice: dialog = std::make_unique<ShowChoicesWidget>(this, cmd); break;
		case Cmd::ShowMessage: dialog = std::make_unique<ShowMessageWidget>(this, cmd); break;
		case Cmd::ControlSwitches: dialog = std::make_unique<SwitchOperationsWidget>(this, cmd); break;
		case Cmd::ControlVars: dialog = std::make_unique<VariableOperationsWidget>(this, cmd); break;
		default: editRawEvent(item, column, true); return;
	}
*/
	std::unique_ptr<QDialog> evt_dialog;

	switch (static_cast<Cmd>(cmd.code))	{
		case Cmd::MessageOptions: evt_dialog.reset(make_evt_dialog<MessageOptionsWidget>(m_project, cmd, this)); break;
		case Cmd::InputNumber: evt_dialog.reset(make_evt_dialog<InputNumberWidget>(m_project, cmd, this)); break;
		case Cmd::ChangeItems: evt_dialog.reset(make_evt_dialog<ChangeItemWidget>(m_project, cmd, this)); break;
		case Cmd::FullHeal: evt_dialog.reset(make_evt_dialog<FullHealWidget>(m_project, cmd, this)); break;
		default: editRawEvent(item, column, true); return;
	}

	evt_dialog->exec();

	currentItem()->setData(column, Qt::DisplayRole, Stringizer::stringize(cmd));
}

void EventCommandsWidget::editRawEvent(QTreeWidgetItem *item, int column, bool show_warning) {
	assert(column == 0);

	auto& cmd = *static_cast<lcf::rpg::EventCommand*>(item->data(column, Qt::UserRole).value<void*>());

	auto* wrapper = new WidgetAsDialogWrapper<EventRawWidget, lcf::rpg::EventCommand>(*m_project, cmd, this);
	wrapper->widget()->setShowWarning(show_warning);

	std::unique_ptr<QDialog> dialog;
	dialog.reset(wrapper);

	dialog->exec();
	currentItem()->setData(column, Qt::DisplayRole, Stringizer::stringize(cmd));
}

void EventCommandsWidget::showContextMenu(const QPoint& pos) {
	auto* item = this->itemAt(pos);
	if (!item) {
		return;
	}

	auto* editAct = new QAction("Edit...", this);
	auto* editRawAct = new QAction("Edit raw...", this);

	connect(editAct, &QAction::triggered, this, [&]{ editEvent(item, 0); });
	connect(editRawAct, &QAction::triggered, this, [&]{ editRawEvent(item, 0, false); });

	QMenu menu(this);
	menu.addAction(editAct);
	menu.addAction(editRawAct);

	menu.exec(mapToGlobal(pos));
}
