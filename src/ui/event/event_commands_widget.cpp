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
#include "model/event_command_list.h"
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

template<typename T>
WidgetAsDialogWrapper<T, EventCommandList>* make_complex_evt_dialog(ProjectData* prj, EventCommandList& commands, EventCommandsWidget* self) {
	return new WidgetAsDialogWrapper<T, EventCommandList>(*prj, commands, self);
}

void EventCommandsWidget::editEvent(QTreeWidgetItem* item, int column) {
	assert(column == 0);

	using Cmd = lcf::rpg::EventCommand::Code;

	auto& cmd = *static_cast<lcf::rpg::EventCommand*>(item->data(column, Qt::UserRole).value<void*>());

	// Commands with no configuration
	switch (static_cast<Cmd>(cmd.code))	{
		case Cmd::END:
		case Cmd::EnterExitVehicle:
		case Cmd::ProceedWithMovement:
		case Cmd::HaltAllMovement:
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
		case Cmd::TerminateBattle:
		case Cmd::ShowChoiceOption:
		case Cmd::ShowChoiceEnd:
		case Cmd::ElseBranch:
		case Cmd::EndBranch:
		case Cmd::EndLoop:
		case Cmd::EndBattle:
		case Cmd::EndShop:
		case Cmd::VictoryHandler:
		case Cmd::EscapeHandler:
		case Cmd::DefeatHandler:
		case Cmd::Transaction:
		case Cmd::NoTransaction:
		case Cmd::Stay:
		case Cmd::NoStay:
		case Cmd::EndInn:
		case Cmd::ElseBranch_B:
		case Cmd::EndBranch_B:
			return;
		default:
			break;
	}

	std::unique_ptr<QDialog> evt_dialog;

	int index = item->text(1).toInt();

	// Event commands that need special handling
	// FIXME: Causes a visual glitch because the wrong item is updated in the Tree
	switch (static_cast<Cmd>(cmd.code)) {
		case Cmd::ShowMessage_2: {
			// Search for a ShowMessage command above and invoke it instead
			for (int i = index - 1; i >= 0; --i) {
				auto& cur_cmd = (*m_commands)[i];
				auto code = static_cast<Cmd>(cur_cmd.code);
				if (code == Cmd::ShowMessage_2) {
					continue;
				} else if (static_cast<Cmd>(cur_cmd.code) == Cmd::ShowMessage) {
					index = i;
					cmd = cur_cmd;
					break;
				} else {
					Q_ASSERT(false && "Event list corrupted: ShowMessage_2 without ShowMessage");
				}
			}
		}
		default: break;
	}

	EventCommandList evt_lst(*m_commands, index);

	switch (static_cast<Cmd>(cmd.code))	{
		//case Cmd::CallCommonEvent: evt_dialog.reset(make_evt_dialog<CallCommonEventWidget>(m_project, cmd, this)); break;
		//case Cmd::ForceFlee: evt_dialog.reset(make_evt_dialog<ForceFleeWidget>(m_project, cmd, this)); break;
		//case Cmd::EnableCombo: evt_dialog.reset(make_evt_dialog<EnableComboWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeClass: evt_dialog.reset(make_evt_dialog<ChangeClassWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeBattleCommands: evt_dialog.reset(make_evt_dialog<ChangeBattleCommandsWidget>(m_project, cmd, this)); break;
		case Cmd::ShowMessage: evt_dialog.reset(make_complex_evt_dialog<ShowMessageWidget>(m_project, evt_lst, this)); break;
		case Cmd::MessageOptions: evt_dialog.reset(make_evt_dialog<MessageOptionsWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeFaceGraphic: evt_dialog.reset(make_evt_dialog<ChangeFaceGraphicWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowChoice: evt_dialog.reset(make_evt_dialog<ShowChoiceWidget>(m_project, cmd, this)); break;
		//case Cmd::InputNumber: evt_dialog.reset(make_evt_dialog<InputNumberWidget>(m_project, cmd, this)); break;
		//case Cmd::ControlSwitches: evt_dialog.reset(make_evt_dialog<ControlSwitchesWidget>(m_project, cmd, this)); break;
		//case Cmd::ControlVars: evt_dialog.reset(make_evt_dialog<ControlVarsWidget>(m_project, cmd, this)); break;
		//case Cmd::TimerOperation: evt_dialog.reset(make_evt_dialog<TimerOperationWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeGold: evt_dialog.reset(make_evt_dialog<ChangeGoldWidget>(m_project, cmd, this)); break;
		case Cmd::ChangeItems: evt_dialog.reset(make_evt_dialog<ChangeItemWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangePartyMembers: evt_dialog.reset(make_evt_dialog<ChangePartyMembersWidget>(m_project, cmd, this)); break;
		case Cmd::ChangeExp: evt_dialog.reset(make_evt_dialog<ChangeExperienceWidget>(m_project, cmd, this)); break;
		case Cmd::ChangeLevel: evt_dialog.reset(make_evt_dialog<ChangeLevelWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeParameters: evt_dialog.reset(make_evt_dialog<ChangeParametersWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSkills: evt_dialog.reset(make_evt_dialog<ChangeSkillsWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeEquipment: evt_dialog.reset(make_evt_dialog<ChangeEquipmentWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeHP: evt_dialog.reset(make_evt_dialog<ChangeHPWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSP: evt_dialog.reset(make_evt_dialog<ChangeSPWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeCondition: evt_dialog.reset(make_evt_dialog<ChangeConditionWidget>(m_project, cmd, this)); break;
		case Cmd::FullHeal: evt_dialog.reset(make_evt_dialog<FullHealWidget>(m_project, cmd, this)); break;
		//case Cmd::SimulatedAttack: evt_dialog.reset(make_evt_dialog<SimulatedAttackWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeHeroName: evt_dialog.reset(make_evt_dialog<ChangeHeroNameWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeHeroTitle: evt_dialog.reset(make_evt_dialog<ChangeHeroTitleWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSpriteAssociation: evt_dialog.reset(make_evt_dialog<ChangeSpriteAssociationWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeActorFace: evt_dialog.reset(make_evt_dialog<ChangeActorFaceWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeVehicleGraphic: evt_dialog.reset(make_evt_dialog<ChangeVehicleGraphicWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSystemBGM: evt_dialog.reset(make_evt_dialog<ChangeSystemBgmWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSystemSFX: evt_dialog.reset(make_evt_dialog<ChangeSystemSfxWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSystemGraphics: evt_dialog.reset(make_evt_dialog<ChangeSystemGraphicsWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeScreenTransitions: evt_dialog.reset(make_evt_dialog<ChangeScreenTransitionsWidget>(m_project, cmd, this)); break;
		//case Cmd::EnemyEncounter: evt_dialog.reset(make_evt_dialog<EnemyEncounterWidget>(m_project, cmd, this)); break;
		//case Cmd::OpenShop: evt_dialog.reset(make_evt_dialog<OpenShopWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowInn: evt_dialog.reset(make_evt_dialog<ShowInnWidget>(m_project, cmd, this)); break;
		//case Cmd::EnterHeroName: evt_dialog.reset(make_evt_dialog<EnterHeroNameWidget>(m_project, cmd, this)); break;
		//case Cmd::Teleport: evt_dialog.reset(make_evt_dialog<TeleportWidget>(m_project, cmd, this)); break;
		//case Cmd::MemorizeLocation: evt_dialog.reset(make_evt_dialog<MemorizeLocationWidget>(m_project, cmd, this)); break;
		//case Cmd::RecallToLocation: evt_dialog.reset(make_evt_dialog<RecallToLocationWidget>(m_project, cmd, this)); break;
		//case Cmd::EnterExitVehicle: evt_dialog.reset(make_evt_dialog<EnterExitVehicleWidget>(m_project, cmd, this)); break;
		//case Cmd::SetVehicleLocation: evt_dialog.reset(make_evt_dialog<SetVehicleLocationWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeEventLocation: evt_dialog.reset(make_evt_dialog<ChangeEventLocationWidget>(m_project, cmd, this)); break;
		//case Cmd::TradeEventLocations: evt_dialog.reset(make_evt_dialog<TradeEventLocationsWidget>(m_project, cmd, this)); break;
		//case Cmd::StoreTerrainID: evt_dialog.reset(make_evt_dialog<StoreTerrainIdWidget>(m_project, cmd, this)); break;
		//case Cmd::StoreEventID: evt_dialog.reset(make_evt_dialog<StoreEventIdWidget>(m_project, cmd, this)); break;
		//case Cmd::EraseScreen: evt_dialog.reset(make_evt_dialog<EraseScreenWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowScreen: evt_dialog.reset(make_evt_dialog<ShowScreenWidget>(m_project, cmd, this)); break;
		case Cmd::TintScreen: evt_dialog.reset(make_evt_dialog<TintScreenWidget>(m_project, cmd, this)); break;
		case Cmd::FlashScreen: evt_dialog.reset(make_evt_dialog<FlashScreenWidget>(m_project, cmd, this)); break;
		case Cmd::ShakeScreen: evt_dialog.reset(make_evt_dialog<ShakeScreenWidget>(m_project, cmd, this)); break;
		//case Cmd::PanScreen: evt_dialog.reset(make_evt_dialog<PanScreenWidget>(m_project, cmd, this)); break;
		case Cmd::WeatherEffects: evt_dialog.reset(make_evt_dialog<WeatherEffectsWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowPicture: evt_dialog.reset(make_evt_dialog<ShowPictureWidget>(m_project, cmd, this)); break;
		//case Cmd::MovePicture: evt_dialog.reset(make_evt_dialog<MovePictureWidget>(m_project, cmd, this)); break;
		//case Cmd::ErasePicture: evt_dialog.reset(make_evt_dialog<ErasePictureWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowBattleAnimation: evt_dialog.reset(make_evt_dialog<ShowBattleAnimationWidget>(m_project, cmd, this)); break;
		//case Cmd::SpriteTransparency: evt_dialog.reset(make_evt_dialog<SpriteTransparencyWidget>(m_project, cmd, this)); break;
		//case Cmd::FlashSprite: evt_dialog.reset(make_evt_dialog<FlashSpriteWidget>(m_project, cmd, this)); break;
		//case Cmd::MoveEvent: evt_dialog.reset(make_evt_dialog<MoveEventWidget>(m_project, cmd, this)); break;
		//case Cmd::Wait: evt_dialog.reset(make_evt_dialog<WaitWidget>(m_project, cmd, this)); break;
		//case Cmd::PlayBGM: evt_dialog.reset(make_evt_dialog<PlayBgmWidget>(m_project, cmd, this)); break;
		//case Cmd::FadeOutBGM: evt_dialog.reset(make_evt_dialog<FadeOutBgmWidget>(m_project, cmd, this)); break;
		//case Cmd::PlaySound: evt_dialog.reset(make_evt_dialog<PlaySoundWidget>(m_project, cmd, this)); break;
		//case Cmd::PlayMovie: evt_dialog.reset(make_evt_dialog<PlayMovieWidget>(m_project, cmd, this)); break;
		//case Cmd::KeyInputProc: evt_dialog.reset(make_evt_dialog<KeyInputProcWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeMapTileset: evt_dialog.reset(make_evt_dialog<ChangeMapTilesetWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangePBG: evt_dialog.reset(make_evt_dialog<ChangePBGWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeEncounterRate: evt_dialog.reset(make_evt_dialog<ChangeEncounterRateWidget>(m_project, cmd, this)); break;
		//case Cmd::TileSubstitution: evt_dialog.reset(make_evt_dialog<TileSubstitutionWidget>(m_project, cmd, this)); break;
		//case Cmd::TeleportTargets: evt_dialog.reset(make_evt_dialog<TeleportTargetsWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeTeleportAccess: evt_dialog.reset(make_evt_dialog<ChangeTeleportAccessWidget>(m_project, cmd, this)); break;
		//case Cmd::EscapeTarget: evt_dialog.reset(make_evt_dialog<EscapeTargetWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeEscapeAccess: evt_dialog.reset(make_evt_dialog<ChangeEscapeAccessWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeSaveAccess: evt_dialog.reset(make_evt_dialog<ChangeSaveAccessWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeMainMenuAccess: evt_dialog.reset(make_evt_dialog<ChangeMainMenuAccessWidget>(m_project, cmd, this)); break;
		//case Cmd::ConditionalBranch: evt_dialog.reset(make_evt_dialog<ConditionalBranchWidget>(m_project, cmd, this)); break;
		//case Cmd::Label: evt_dialog.reset(make_evt_dialog<LabelWidget>(m_project, cmd, this)); break;
		//case Cmd::JumpToLabel: evt_dialog.reset(make_evt_dialog<JumpToLabelWidget>(m_project, cmd, this)); break;
		//case Cmd::CallEvent: evt_dialog.reset(make_evt_dialog<CallEventWidget>(m_project, cmd, this)); break;
		//case Cmd::Comment: evt_dialog.reset(make_evt_dialog<CommentWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeMonsterHP: evt_dialog.reset(make_evt_dialog<ChangeMonsterHPWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeMonsterMP: evt_dialog.reset(make_evt_dialog<ChangeMonsterMPWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeMonsterCondition: evt_dialog.reset(make_evt_dialog<ChangeMonsterConditionWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowHiddenMonster: evt_dialog.reset(make_evt_dialog<ShowHiddenMonsterWidget>(m_project, cmd, this)); break;
		//case Cmd::ChangeBattleBG: evt_dialog.reset(make_evt_dialog<ChangeBattleBGWidget>(m_project, cmd, this)); break;
		//case Cmd::ShowBattleAnimation_B: evt_dialog.reset(make_evt_dialog<ShowBattleAnimation_BWidget>(m_project, cmd, this)); break;
		//case Cmd::ConditionalBranch_B: evt_dialog.reset(make_evt_dialog<ConditionalBranch_BWidget>(m_project, cmd, this)); break;
		//case Cmd::Comment_2: evt_dialog.reset(make_evt_dialog<Comment_2Widget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_GetSaveInfo: evt_dialog.reset(make_evt_dialog<Maniac_GetSaveInfoWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_Save: evt_dialog.reset(make_evt_dialog<Maniac_SaveWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_Load: evt_dialog.reset(make_evt_dialog<Maniac_LoadWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_EndLoadProcess: evt_dialog.reset(make_evt_dialog<Maniac_EndLoadProcessWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_GetMousePosition: evt_dialog.reset(make_evt_dialog<Maniac_GetMousePositionWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_SetMousePosition: evt_dialog.reset(make_evt_dialog<Maniac_SetMousePositionWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ShowStringPicture: evt_dialog.reset(make_evt_dialog<Maniac_ShowStringPictureWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_GetPictureInfo: evt_dialog.reset(make_evt_dialog<Maniac_GetPictureInfoWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ControlBattle: evt_dialog.reset(make_evt_dialog<Maniac_ControlBattleWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ControlAtbGauge: evt_dialog.reset(make_evt_dialog<Maniac_ControlAtbGaugeWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ChangeBattleCommandEx: evt_dialog.reset(make_evt_dialog<Maniac_ChangeBattleCommandExWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_GetBattleInfo: evt_dialog.reset(make_evt_dialog<Maniac_GetBattleInfoWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ControlVarArray: evt_dialog.reset(make_evt_dialog<Maniac_ControlVarArrayWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_KeyInputProcEx: evt_dialog.reset(make_evt_dialog<Maniac_KeyInputProcExWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_RewriteMap: evt_dialog.reset(make_evt_dialog<Maniac_RewriteMapWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ControlGlobalSave: evt_dialog.reset(make_evt_dialog<Maniac_ControlGlobalSaveWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_ChangePictureId: evt_dialog.reset(make_evt_dialog<Maniac_ChangePictureIdWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_SetGameOption: evt_dialog.reset(make_evt_dialog<Maniac_SetGameOptionWidget>(m_project, cmd, this)); break;
		//case Cmd::Maniac_CallCommand: evt_dialog.reset(make_evt_dialog<Maniac_CallCommandWidget>(m_project, cmd, this)); break;
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
