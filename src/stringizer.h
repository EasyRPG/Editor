#ifndef STRINGIZER_H
#define STRINGIZER_H

#include <QString>
#include "rpg_eventcommand.h"


class Stringizer
{
public:

    static QString Stringize(RPG::EventCommand command);

private:
    // Common stringize operations
    QString varName(int id);
    QString switchName(int id);
    QString itemName(int id);
    QString heroName(int id);
    QString skillName(int id);
    QString conditionName(int id);
    QString eventName(int id);
    QString troopName(int id);
    QString terrainName(int id);
    QString mapName(int id);
};

class StringizerEND : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerCallCommonEvent : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerForceFlee : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEnableCombo : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeClass : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeBattleCommands : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowMessage : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerMessageOptions : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeFaceGraphic : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowChoice : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerInputNumber : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerControlSwitches : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerControlVars : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTimerOperation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeGold : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeItems : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangePartyMembers : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeExp : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeLevel : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeParameters : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSkills : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeEquipment : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeHP : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSP : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeCondition : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerFullHeal : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerSimulatedAttack : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeHeroName : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeHeroTitle : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSpriteAssociation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeActorFace : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeVehicleGraphic : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSystemBGM : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSystemSFX : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSystemGraphics : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeScreenTransitions : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEnemyEncounter : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerOpenShop : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowInn : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEnterHeroName : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTeleport : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerMemorizeLocation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerRecallToLocation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEnterExitVehicle : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerSetVehicleLocation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeEventLocation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTradeEventLocations : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerStoreTerrainID : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerStoreEventID : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEraseScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTintScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerFlashScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShakeScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerPanScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerWeatherEffects : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowPicture : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerMovePicture : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerErasePicture : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowBattleAnimation : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerSpriteTransparency : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerFlashSprite : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerMoveEvent : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerProceedWithMovement : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerHaltAllMovement : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerWait : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerPlayBGM : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerFadeOutBGM : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerMemorizeBGM : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerPlayMemorizedBGM : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerPlaySound : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerPlayMovie : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerKeyInputProc : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeMapTileset : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangePBG : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeEncounterRate : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTileSubstitution : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTeleportTargets : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeTeleportAccess : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEscapeTarget : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeEscapeAccess : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerOpenSaveMenu : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeSaveAccess : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerOpenMainMenu : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeMainMenuAccess : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerConditionalBranch : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerLabel : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerJumpToLabel : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerLoop : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerBreakLoop : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndEventProcessing : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEraseEvent : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerCallEvent : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerComment : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerGameOver : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerReturntoTitleScreen : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeMonsterHP : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeMonsterMP : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeMonsterCondition : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowHiddenMonster : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerChangeBattleBG : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowBattleAnimation_B : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerConditionalBranch_B : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTerminateBattle : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowMessage_2 : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowChoiceOption : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerShowChoiceEnd : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerVictoryHandler : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEscapeHandler : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerDefeatHandler : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndBattle : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerTransaction : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerNoTransaction : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndShop : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerStay : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerNoStay : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndInn : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerElseBranch : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndBranch : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndLoop : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerComment_2 : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerElseBranch_B : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};

class StringizerEndBranch_B : Stringizer
{
public:
    static QString Stringize(RPG::EventCommand command);
};



#endif // STRINGIZER_H
