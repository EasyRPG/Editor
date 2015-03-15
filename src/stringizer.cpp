#include "stringizer.h"
#include <data.h>
#include "core.h"

QString Stringizer::Stringize(RPG::EventCommand command)
{
    switch (command.code)
    {
    case RPG::EventCommand::Code::END:
         return StringizerEND::Stringize(command);
         break;
    case RPG::EventCommand::Code::CallCommonEvent:
         return StringizerCallCommonEvent::Stringize(command);
         break;
    case RPG::EventCommand::Code::ForceFlee:
         return StringizerForceFlee::Stringize(command);
         break;
    case RPG::EventCommand::Code::EnableCombo:
         return StringizerEnableCombo::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeClass:
         return StringizerChangeClass::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeBattleCommands:
         return StringizerChangeBattleCommands::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowMessage:
         return StringizerShowMessage::Stringize(command);
         break;
    case RPG::EventCommand::Code::MessageOptions:
         return StringizerMessageOptions::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeFaceGraphic:
         return StringizerChangeFaceGraphic::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowChoice:
         return StringizerShowChoice::Stringize(command);
         break;
    case RPG::EventCommand::Code::InputNumber:
         return StringizerInputNumber::Stringize(command);
         break;
    case RPG::EventCommand::Code::ControlSwitches:
         return StringizerControlSwitches::Stringize(command);
         break;
    case RPG::EventCommand::Code::ControlVars:
         return StringizerControlVars::Stringize(command);
         break;
    case RPG::EventCommand::Code::TimerOperation:
         return StringizerTimerOperation::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeGold:
         return StringizerChangeGold::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeItems:
         return StringizerChangeItems::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangePartyMembers:
         return StringizerChangePartyMembers::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeExp:
         return StringizerChangeExp::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeLevel:
         return StringizerChangeLevel::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeParameters:
         return StringizerChangeParameters::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSkills:
         return StringizerChangeSkills::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeEquipment:
         return StringizerChangeEquipment::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeHP:
         return StringizerChangeHP::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSP:
         return StringizerChangeSP::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeCondition:
         return StringizerChangeCondition::Stringize(command);
         break;
    case RPG::EventCommand::Code::FullHeal:
         return StringizerFullHeal::Stringize(command);
         break;
    case RPG::EventCommand::Code::SimulatedAttack:
         return StringizerSimulatedAttack::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeHeroName:
         return StringizerChangeHeroName::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeHeroTitle:
         return StringizerChangeHeroTitle::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSpriteAssociation:
         return StringizerChangeSpriteAssociation::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeActorFace:
         return StringizerChangeActorFace::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeVehicleGraphic:
         return StringizerChangeVehicleGraphic::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSystemBGM:
         return StringizerChangeSystemBGM::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSystemSFX:
         return StringizerChangeSystemSFX::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSystemGraphics:
         return StringizerChangeSystemGraphics::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeScreenTransitions:
         return StringizerChangeScreenTransitions::Stringize(command);
         break;
    case RPG::EventCommand::Code::EnemyEncounter:
         return StringizerEnemyEncounter::Stringize(command);
         break;
    case RPG::EventCommand::Code::OpenShop:
         return StringizerOpenShop::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowInn:
         return StringizerShowInn::Stringize(command);
         break;
    case RPG::EventCommand::Code::EnterHeroName:
         return StringizerEnterHeroName::Stringize(command);
         break;
    case RPG::EventCommand::Code::Teleport:
         return StringizerTeleport::Stringize(command);
         break;
    case RPG::EventCommand::Code::MemorizeLocation:
         return StringizerMemorizeLocation::Stringize(command);
         break;
    case RPG::EventCommand::Code::RecallToLocation:
         return StringizerRecallToLocation::Stringize(command);
         break;
    case RPG::EventCommand::Code::EnterExitVehicle:
         return StringizerEnterExitVehicle::Stringize(command);
         break;
    case RPG::EventCommand::Code::SetVehicleLocation:
         return StringizerSetVehicleLocation::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeEventLocation:
         return StringizerChangeEventLocation::Stringize(command);
         break;
    case RPG::EventCommand::Code::TradeEventLocations:
         return StringizerTradeEventLocations::Stringize(command);
         break;
    case RPG::EventCommand::Code::StoreTerrainID:
         return StringizerStoreTerrainID::Stringize(command);
         break;
    case RPG::EventCommand::Code::StoreEventID:
         return StringizerStoreEventID::Stringize(command);
         break;
    case RPG::EventCommand::Code::EraseScreen:
         return StringizerEraseScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowScreen:
         return StringizerShowScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::TintScreen:
         return StringizerTintScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::FlashScreen:
         return StringizerFlashScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShakeScreen:
         return StringizerShakeScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::PanScreen:
         return StringizerPanScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::WeatherEffects:
         return StringizerWeatherEffects::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowPicture:
         return StringizerShowPicture::Stringize(command);
         break;
    case RPG::EventCommand::Code::MovePicture:
         return StringizerMovePicture::Stringize(command);
         break;
    case RPG::EventCommand::Code::ErasePicture:
         return StringizerErasePicture::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowBattleAnimation:
         return StringizerShowBattleAnimation::Stringize(command);
         break;
    case RPG::EventCommand::Code::SpriteTransparency:
         return StringizerSpriteTransparency::Stringize(command);
         break;
    case RPG::EventCommand::Code::FlashSprite:
         return StringizerFlashSprite::Stringize(command);
         break;
    case RPG::EventCommand::Code::MoveEvent:
         return StringizerMoveEvent::Stringize(command);
         break;
    case RPG::EventCommand::Code::ProceedWithMovement:
         return StringizerProceedWithMovement::Stringize(command);
         break;
    case RPG::EventCommand::Code::HaltAllMovement:
         return StringizerHaltAllMovement::Stringize(command);
         break;
    case RPG::EventCommand::Code::Wait:
         return StringizerWait::Stringize(command);
         break;
    case RPG::EventCommand::Code::PlayBGM:
         return StringizerPlayBGM::Stringize(command);
         break;
    case RPG::EventCommand::Code::FadeOutBGM:
         return StringizerFadeOutBGM::Stringize(command);
         break;
    case RPG::EventCommand::Code::MemorizeBGM:
         return StringizerMemorizeBGM::Stringize(command);
         break;
    case RPG::EventCommand::Code::PlayMemorizedBGM:
         return StringizerPlayMemorizedBGM::Stringize(command);
         break;
    case RPG::EventCommand::Code::PlaySound:
         return StringizerPlaySound::Stringize(command);
         break;
    case RPG::EventCommand::Code::PlayMovie:
         return StringizerPlayMovie::Stringize(command);
         break;
    case RPG::EventCommand::Code::KeyInputProc:
         return StringizerKeyInputProc::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeMapTileset:
         return StringizerChangeMapTileset::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangePBG:
         return StringizerChangePBG::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeEncounterRate:
         return StringizerChangeEncounterRate::Stringize(command);
         break;
    case RPG::EventCommand::Code::TileSubstitution:
         return StringizerTileSubstitution::Stringize(command);
         break;
    case RPG::EventCommand::Code::TeleportTargets:
         return StringizerTeleportTargets::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeTeleportAccess:
         return StringizerChangeTeleportAccess::Stringize(command);
         break;
    case RPG::EventCommand::Code::EscapeTarget:
         return StringizerEscapeTarget::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeEscapeAccess:
         return StringizerChangeEscapeAccess::Stringize(command);
         break;
    case RPG::EventCommand::Code::OpenSaveMenu:
         return StringizerOpenSaveMenu::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeSaveAccess:
         return StringizerChangeSaveAccess::Stringize(command);
         break;
    case RPG::EventCommand::Code::OpenMainMenu:
         return StringizerOpenMainMenu::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeMainMenuAccess:
         return StringizerChangeMainMenuAccess::Stringize(command);
         break;
    case RPG::EventCommand::Code::ConditionalBranch:
         return StringizerConditionalBranch::Stringize(command);
         break;
    case RPG::EventCommand::Code::Label:
         return StringizerLabel::Stringize(command);
         break;
    case RPG::EventCommand::Code::JumpToLabel:
         return StringizerJumpToLabel::Stringize(command);
         break;
    case RPG::EventCommand::Code::Loop:
         return StringizerLoop::Stringize(command);
         break;
    case RPG::EventCommand::Code::BreakLoop:
         return StringizerBreakLoop::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndEventProcessing:
         return StringizerEndEventProcessing::Stringize(command);
         break;
    case RPG::EventCommand::Code::EraseEvent:
         return StringizerEraseEvent::Stringize(command);
         break;
    case RPG::EventCommand::Code::CallEvent:
         return StringizerCallEvent::Stringize(command);
         break;
    case RPG::EventCommand::Code::Comment:
         return StringizerComment::Stringize(command);
         break;
    case RPG::EventCommand::Code::GameOver:
         return StringizerGameOver::Stringize(command);
         break;
    case RPG::EventCommand::Code::ReturntoTitleScreen:
         return StringizerReturntoTitleScreen::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeMonsterHP:
         return StringizerChangeMonsterHP::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeMonsterMP:
         return StringizerChangeMonsterMP::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeMonsterCondition:
         return StringizerChangeMonsterCondition::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowHiddenMonster:
         return StringizerShowHiddenMonster::Stringize(command);
         break;
    case RPG::EventCommand::Code::ChangeBattleBG:
         return StringizerChangeBattleBG::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowBattleAnimation_B:
         return StringizerShowBattleAnimation_B::Stringize(command);
         break;
    case RPG::EventCommand::Code::ConditionalBranch_B:
         return StringizerConditionalBranch_B::Stringize(command);
         break;
    case RPG::EventCommand::Code::TerminateBattle:
         return StringizerTerminateBattle::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowMessage_2:
         return StringizerShowMessage_2::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowChoiceOption:
         return StringizerShowChoiceOption::Stringize(command);
         break;
    case RPG::EventCommand::Code::ShowChoiceEnd:
         return StringizerShowChoiceEnd::Stringize(command);
         break;
    case RPG::EventCommand::Code::VictoryHandler:
         return StringizerVictoryHandler::Stringize(command);
         break;
    case RPG::EventCommand::Code::EscapeHandler:
         return StringizerEscapeHandler::Stringize(command);
         break;
    case RPG::EventCommand::Code::DefeatHandler:
         return StringizerDefeatHandler::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndBattle:
         return StringizerEndBattle::Stringize(command);
         break;
    case RPG::EventCommand::Code::Transaction:
         return StringizerTransaction::Stringize(command);
         break;
    case RPG::EventCommand::Code::NoTransaction:
         return StringizerNoTransaction::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndShop:
         return StringizerEndShop::Stringize(command);
         break;
    case RPG::EventCommand::Code::Stay:
         return StringizerStay::Stringize(command);
         break;
    case RPG::EventCommand::Code::NoStay:
         return StringizerNoStay::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndInn:
         return StringizerEndInn::Stringize(command);
         break;
    case RPG::EventCommand::Code::ElseBranch:
         return StringizerElseBranch::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndBranch:
         return StringizerEndBranch::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndLoop:
         return StringizerEndLoop::Stringize(command);
         break;
    case RPG::EventCommand::Code::Comment_2:
         return StringizerComment_2::Stringize(command);
         break;
    case RPG::EventCommand::Code::ElseBranch_B:
         return StringizerElseBranch_B::Stringize(command);
         break;
    case RPG::EventCommand::Code::EndBranch_B:
         return StringizerEndBranch_B::Stringize(command);
         break;
    default:
        return QString("UnknownCommand");
    }
}

QString Stringizer::varName(int id)
{
    if (id < 1 || id > (int)Data::variables.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::variables[id-1].name);
}

QString Stringizer::switchName(int id)
{
    if (id < 1 || id > (int)Data::switches.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::switches[id-1].name);
}

QString Stringizer::itemName(int id)
{
    if (id < 1 || id > (int)Data::items.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::items[id-1].name);
}

QString Stringizer::heroName(int id)
{
    if (id < 1 || id > (int)Data::actors.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::actors[id-1].name);
}

QString Stringizer::skillName(int id)
{
    if (id < 1 || id > (int)Data::skills.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::skills[id-1].name);
}

QString Stringizer::conditionName(int id)
{
    if (id < 1 || id > (int)Data::states.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::states[id-1].name);
}

QString Stringizer::eventName(int id)
{
    if (!mCore->currentMapEvent(id))
        return QString("<%1?>").arg(id);
    return QString::fromStdString(mCore->currentMapEvent(id)->name);
}

QString Stringizer::troopName(int id)
{
    if (id < 1 || id > (int)Data::troops.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::troops[id-1].name);
}

QString Stringizer::terrainName(int id)
{
    if (id < 1 || id > (int)Data::terrains.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::terrains[id-1].name);
}

QString Stringizer::mapName(int id)
{
    if (id < 1 || id > (int)Data::treemap.maps.size())
        return QString("<%1?>").arg(id);
    for (unsigned int i = 0; i < Data::treemap.maps.size(); i++)
        if (Data::treemap.maps[i].ID == id)
        {
            return QString::fromStdString(Data::treemap.maps[i].name);
        }
    return QString("<NotFound:%1?>").arg(id);
}

QString StringizerEND::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "END";
}

QString StringizerCallCommonEvent::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "CallCommonEvent";
}

QString StringizerForceFlee::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ForceFlee";
}

QString StringizerEnableCombo::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EnableCombo";
}

QString StringizerChangeClass::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeClass";
}

QString StringizerChangeBattleCommands::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeBattleCommands";
}

QString StringizerShowMessage::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowMessage";
}

QString StringizerMessageOptions::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "MessageOptions";
}

QString StringizerChangeFaceGraphic::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeFaceGraphic";
}

QString StringizerShowChoice::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowChoice";
}

QString StringizerInputNumber::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "InputNumber";
}

QString StringizerControlSwitches::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ControlSwitches";
}

QString StringizerControlVars::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ControlVars";
}

QString StringizerTimerOperation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TimerOperation";
}

QString StringizerChangeGold::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeGold";
}

QString StringizerChangeItems::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeItems";
}

QString StringizerChangePartyMembers::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangePartyMembers";
}

QString StringizerChangeExp::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeExp";
}

QString StringizerChangeLevel::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeLevel";
}

QString StringizerChangeParameters::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeParameters";
}

QString StringizerChangeSkills::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSkills";
}

QString StringizerChangeEquipment::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeEquipment";
}

QString StringizerChangeHP::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeHP";
}

QString StringizerChangeSP::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSP";
}

QString StringizerChangeCondition::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeCondition";
}

QString StringizerFullHeal::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "FullHeal";
}

QString StringizerSimulatedAttack::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "SimulatedAttack";
}

QString StringizerChangeHeroName::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeHeroName";
}

QString StringizerChangeHeroTitle::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeHeroTitle";
}

QString StringizerChangeSpriteAssociation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSpriteAssociation";
}

QString StringizerChangeActorFace::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeActorFace";
}

QString StringizerChangeVehicleGraphic::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeVehicleGraphic";
}

QString StringizerChangeSystemBGM::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSystemBGM";
}

QString StringizerChangeSystemSFX::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSystemSFX";
}

QString StringizerChangeSystemGraphics::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSystemGraphics";
}

QString StringizerChangeScreenTransitions::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeScreenTransitions";
}

QString StringizerEnemyEncounter::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EnemyEncounter";
}

QString StringizerOpenShop::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "OpenShop";
}

QString StringizerShowInn::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowInn";
}

QString StringizerEnterHeroName::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EnterHeroName";
}

QString StringizerTeleport::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Teleport";
}

QString StringizerMemorizeLocation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "MemorizeLocation";
}

QString StringizerRecallToLocation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "RecallToLocation";
}

QString StringizerEnterExitVehicle::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EnterExitVehicle";
}

QString StringizerSetVehicleLocation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "SetVehicleLocation";
}

QString StringizerChangeEventLocation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeEventLocation";
}

QString StringizerTradeEventLocations::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TradeEventLocations";
}

QString StringizerStoreTerrainID::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "StoreTerrainID";
}

QString StringizerStoreEventID::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "StoreEventID";
}

QString StringizerEraseScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EraseScreen";
}

QString StringizerShowScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowScreen";
}

QString StringizerTintScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TintScreen";
}

QString StringizerFlashScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "FlashScreen";
}

QString StringizerShakeScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShakeScreen";
}

QString StringizerPanScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "PanScreen";
}

QString StringizerWeatherEffects::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "WeatherEffects";
}

QString StringizerShowPicture::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowPicture";
}

QString StringizerMovePicture::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "MovePicture";
}

QString StringizerErasePicture::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ErasePicture";
}

QString StringizerShowBattleAnimation::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowBattleAnimation";
}

QString StringizerSpriteTransparency::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "SpriteTransparency";
}

QString StringizerFlashSprite::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "FlashSprite";
}

QString StringizerMoveEvent::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "MoveEvent";
}

QString StringizerProceedWithMovement::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ProceedWithMovement";
}

QString StringizerHaltAllMovement::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "HaltAllMovement";
}

QString StringizerWait::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Wait";
}

QString StringizerPlayBGM::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "PlayBGM";
}

QString StringizerFadeOutBGM::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "FadeOutBGM";
}

QString StringizerMemorizeBGM::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "MemorizeBGM";
}

QString StringizerPlayMemorizedBGM::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "PlayMemorizedBGM";
}

QString StringizerPlaySound::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "PlaySound";
}

QString StringizerPlayMovie::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "PlayMovie";
}

QString StringizerKeyInputProc::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "KeyInputProc";
}

QString StringizerChangeMapTileset::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeMapTileset";
}

QString StringizerChangePBG::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangePBG";
}

QString StringizerChangeEncounterRate::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeEncounterRate";
}

QString StringizerTileSubstitution::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TileSubstitution";
}

QString StringizerTeleportTargets::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TeleportTargets";
}

QString StringizerChangeTeleportAccess::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeTeleportAccess";
}

QString StringizerEscapeTarget::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EscapeTarget";
}

QString StringizerChangeEscapeAccess::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeEscapeAccess";
}

QString StringizerOpenSaveMenu::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "OpenSaveMenu";
}

QString StringizerChangeSaveAccess::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeSaveAccess";
}

QString StringizerOpenMainMenu::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "OpenMainMenu";
}

QString StringizerChangeMainMenuAccess::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeMainMenuAccess";
}

QString StringizerConditionalBranch::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ConditionalBranch";
}

QString StringizerLabel::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Label";
}

QString StringizerJumpToLabel::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "JumpToLabel";
}

QString StringizerLoop::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Loop";
}

QString StringizerBreakLoop::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "BreakLoop";
}

QString StringizerEndEventProcessing::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndEventProcessing";
}

QString StringizerEraseEvent::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EraseEvent";
}

QString StringizerCallEvent::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "CallEvent";
}

QString StringizerComment::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Comment";
}

QString StringizerGameOver::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "GameOver";
}

QString StringizerReturntoTitleScreen::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ReturntoTitleScreen";
}

QString StringizerChangeMonsterHP::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeMonsterHP";
}

QString StringizerChangeMonsterMP::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeMonsterMP";
}

QString StringizerChangeMonsterCondition::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeMonsterCondition";
}

QString StringizerShowHiddenMonster::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowHiddenMonster";
}

QString StringizerChangeBattleBG::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ChangeBattleBG";
}

QString StringizerShowBattleAnimation_B::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowBattleAnimation_B";
}

QString StringizerConditionalBranch_B::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ConditionalBranch_B";
}

QString StringizerTerminateBattle::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "TerminateBattle";
}

QString StringizerShowMessage_2::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowMessage_2";
}

QString StringizerShowChoiceOption::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowChoiceOption";
}

QString StringizerShowChoiceEnd::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ShowChoiceEnd";
}

QString StringizerVictoryHandler::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "VictoryHandler";
}

QString StringizerEscapeHandler::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EscapeHandler";
}

QString StringizerDefeatHandler::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "DefeatHandler";
}

QString StringizerEndBattle::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndBattle";
}

QString StringizerTransaction::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Transaction";
}

QString StringizerNoTransaction::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "NoTransaction";
}

QString StringizerEndShop::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndShop";
}

QString StringizerStay::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Stay";
}

QString StringizerNoStay::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "NoStay";
}

QString StringizerEndInn::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndInn";
}

QString StringizerElseBranch::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ElseBranch";
}

QString StringizerEndBranch::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndBranch";
}

QString StringizerEndLoop::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndLoop";
}

QString StringizerComment_2::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "Comment_2";
}

QString StringizerElseBranch_B::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "ElseBranch_B";
}

QString StringizerEndBranch_B::Stringize(RPG::EventCommand command)
{
    Q_UNUSED(command);
    return "EndBranch_B";
}

