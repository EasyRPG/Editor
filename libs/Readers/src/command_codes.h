/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _COMMAND_CODES_H_
#define _COMMAND_CODES_H_

namespace Cmd {
	enum CommandCodes {
		END						=    10,

		CallCommonEvent			=  1005,
		ForceFlee				=  1006,
		EnableCombo				=  1007,

		ChangeClass				=  1008,
		ChangeBattleCommands	=  1009,
		ShowMessage				= 10110,
		MessageOptions			= 10120,
		ChangeFaceGraphic		= 10130,
		ShowChoice				= 10140,
		InputNumber				= 10150,
		ControlSwitches			= 10210,
		ControlVars				= 10220,
		TimerOperation			= 10230,
		ChangeGold				= 10310,
		ChangeItems				= 10320,
		ChangePartyMembers		= 10330,
		ChangeExp				= 10410,
		ChangeLevel				= 10420,
		ChangeParameters		= 10430,
		ChangeSkills			= 10440,
		ChangeEquipment			= 10450,
		ChangeHP				= 10460,
		ChangeSP				= 10470,
		ChangeCondition			= 10480,
		FullHeal				= 10490,
		SimulatedAttack			= 10500,
		ChangeHeroName			= 10610,
		ChangeHeroTitle			= 10620,
		ChangeSpriteAssociation = 10630,
		ChangeActorFace			= 10640,
		ChangeVehicleGraphic	= 10650,
		ChangeSystemBGM			= 10660,
		ChangeSystemSFX			= 10670,
		ChangeSystemGraphics	= 10680,
		ChangeScreenTransitions = 10690,
		EnemyEncounter			= 10710,
		OpenShop				= 10720,
		ShowInn					= 10730,
		EnterHeroName			= 10740,
		Teleport				= 10810,
		MemorizeLocation		= 10820,
		RecallToLocation		= 10830,
		EnterExitVehicle		= 10840,
		SetVehicleLocation		= 10850,
		ChangeEventLocation		= 10860,
		TradeEventLocations		= 10870,
		StoreTerrainID			= 10910,
		StoreEventID			= 10920,
		EraseScreen				= 11010,
		ShowScreen				= 11020,
		TintScreen				= 11030,
		FlashScreen				= 11040,
		ShakeScreen				= 11050,
		PanScreen				= 11060,
		WeatherEffects			= 11070,
		ShowPicture				= 11110,
		MovePicture				= 11120,
		ErasePicture			= 11130,
		ShowBattleAnimation		= 11210,
		SpriteTransparency		= 11310,
		FlashSprite				= 11320,
		MoveEvent				= 11330,
		ProceedWithMovement		= 11340,
		HaltAllMovement			= 11350,
		Wait					= 11410,
		PlayBGM					= 11510,
		FadeOutBGM				= 11520,
		MemorizeBGM				= 11530,
		PlayMemorizedBGM		= 11540,
		PlaySound				= 11550,
		PlayMovie				= 11560,
		KeyInputProc			= 11610,
		ChangeMapTileset		= 11710,
		ChangePBG				= 11720,
		ChangeEncounterRate		= 11740,
		TileSubstitution		= 11750,
		TeleportTargets			= 11810,
		ChangeTeleportAccess	= 11820,
		EscapeTarget			= 11830,
		ChangeEscapeAccess		= 11840,
		OpenSaveMenu			= 11910,
		ChangeSaveAccess		= 11930,
		OpenMainMenu			= 11950,
		ChangeMainMenuAccess	= 11960,
		ConditionalBranch		= 12010,
		Label					= 12110,
		JumpToLabel				= 12120,
		Loop					= 12210,
		BreakLoop				= 12220,
		EndEventProcessing		= 12310,
		EraseEvent				= 12320,
		CallEvent				= 12330,
		Comment					= 12410,
		GameOver				= 12420,
		ReturntoTitleScreen		= 12510,

		ChangeMonsterHP			= 13110,
		ChangeMonsterMP			= 13120,
		ChangeMonsterCondition	= 13130,
		ShowHiddenMonster		= 13150,
		ChangeBattleBG			= 13210,
		ShowBattleAnimation_B	= 13260,
		ConditionalBranch_B		= 13310,
		TerminateBattle			= 13410,

		ShowMessage_2			= 20110,
		ShowChoiceOption		= 20140,
		ShowChoiceEnd			= 20141,
		VictoryHandler			= 20710,
		EscapeHandler			= 20711,
		DefeatHandler			= 20712,
		EndBattle				= 20713,
		Transaction				= 20720,
		NoTransaction			= 20721,
		EndShop					= 20722,
		Stay					= 20730,
		NoStay					= 20731,
		EndInn					= 20732,
		ElseBranch				= 22010,
		EndBranch				= 22011,
		EndLoop					= 22210,
		Comment_2				= 22410,

		ElseBranch_B			= 23310,
		EndBranch_B				= 23311,

		DUMMY					=    -1
	};
}

#endif

