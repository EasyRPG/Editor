#include "qeventwidget.h"
#include <QTimer>

QMap<int, QList<QStringList>> QEventWidget::m_strCache = QMap<int, QList<QStringList>>();

void QEventWidget::Init(DialogSplash *s, QProgressBar *progressBar, QLabel *label)
{
#define reg(command, templ)\
    main = tr(templ).split("@");\
    list = QList<QStringList>();\
    for (int i = 0; i < main.count(); i++)\
        list << main[i].split("|");\
    m_strCache[Cmd::command] = list;\
    progressBar->setValue(count);\
    label->setText(QString("Loading string templates (%1 of 123)").arg(count));\
    count++

    progressBar->setMaximum(123);
    static bool init = false;
    if (init)
    {
        progressBar->setValue(progressBar->maximum());
        label->setText(tr("Done!"));
        return;
    }
    int count = 1;
    QStringList main;
    QList<QStringList> list;

    reg(END, "<>");

    reg(CallCommonEvent, "CallCommonEvent");
    reg(ForceFlee, "ForceFlee");
    reg(EnableCombo, "EnableCombo");
    reg(ChangeClass, "ChangeClass");
    reg(ChangeBattleCommands, "ChangeBattleCommands");

    reg(ShowMessage, "Message: %s");

    reg(MessageOptions, "MessageOptions [%e0|%e1|%e2|%e3]"
                        "@Normal|Transparent"
                        "@Top|Middle|Bottom"
                        "@Fixed|Auto"
                        "@Halt Process|Process Continue");

    reg(ChangeFaceGraphic,  "FaceGraphics: %s[%n0]%op1%op2"
                            "@Left|Right"
                            "@|Mirror");

    reg(ShowChoice, "ShowChoice");

    reg(InputNumber, "InputNumber: %n0 Digit(s), V[%v1]");

    reg(ControlSwitches,  "%e0 = %e3"
                          "@S[%b1]|S[%n1-%n2]|S[V[%v1]]"
                          "@ON|OFF|Toggle");

    reg(ControlVars,  "%e0 %e3 %e4"
                      "@V[%v1]|V[%n1-%n2]|V[V[%v1]]"
                      "@=|+=|-=|*=|/=|%="
                      "@%n5|V[%v5]|V[V[%v5]]|Ramdom[%n5-%n6]|Item[%i5].%ic6|Hero[%h5].%hs6"
                      "|Sprite[%sl5].%sp6|%o5");

    reg(TimerOperation,  "Timer[%e5]%e0%op3%op4"
                         "@.Time = %e1| starts| stops"
                         "@%n2Sec(s)|V[%v2]"
                         "@|ShowOnScreen"
                         "@|RunInBattle"
                         "@1|2");

    reg(ChangeGold,  "%g %e0 %e1"
                     "@+=|-="
                     "@%n2|V[%v2]");

    reg(ChangeItems,  "Item[%e1] %e0 %e3"
                      "@+=|-="
                      "@%i2|V[%v2]"
                      "@%n4|V[%v4]");

    reg(ChangePartyMembers,  "Hero[%e1] %e0 the party"
                             "@joins|leaves"
                             "@%h2|V[%v2]");

    reg(ChangeExp, "ChangeExp");

    reg(ChangeLevel,  "%e0.Level %e2 %e3%op5"
                      "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                      "@+=|-="
                      "@%n4|V[%v4]"
                      "@|ShowMessage");

    reg(ChangeParameters,  "%e0.%e3 %e2 %e4"
                           "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                           "@+=|-="
                           "@MaxHP|MaxMP|Attack|Defense|Intelligence|Agility"
                           "@%n5|V[v%5]");

    reg(ChangeSkills,  "%e0 %e2 Skill[%e3]"
                       "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                       "@learns|forgets"
                       "@%sk4|v[%v4]");

    reg(ChangeEquipment,  "%e0 %e2"
                          "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                          "@equips Item[%e3]|unequips %e3"
                          "@%i4#Weapon|v[%v4]#Shield|#Armor|#Helmet|#Accesory|#All");

    reg(ChangeHP,  "%e0.HP %e2 %e3%op5"
                   "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                   "@+=|-="
                   "@%n4|V[%v4]"
                   "@|CanKillTarget");

    reg(ChangeSP,  "%e0.MP %e2 %e3"
                   "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                   "@+=|-="
                   "@%n4|V[%v4]");

    reg(ChangeCondition,  "%e0.Conditions %e2 Condition[%c3]"
                          "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                          "@+=|-=");

    reg(FullHeal, "%e0 heals completely"
                  "@EntireParty|Hero[%h1]|Hero[V[%v1]]");

    reg(SimulatedAttack,  "%e0 takes damage by %n2%e6"
                          "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                          "@| [V[%n7, Damage]");

    reg(ChangeHeroName, "Hero[%h0].Name = %s");

    reg(ChangeHeroTitle, "Hero[%h0].Title = %s");

    reg(ChangeSpriteAssociation, "Hero[%h0].Sprite = %s[%n1]%op2"
                                 "@|Transparent");

    reg(ChangeActorFace, "Hero[%h0].Face = %s[%n1]");

    reg(ChangeVehicleGraphic, "Vehicle[%e0].Sprite = %s[%n1]"
                              "@Skiff|Ship|Airship");

    reg(ChangeSystemBGM,  "System.BGM[%e0, %s"
                          "@Battle|Victory|Inn|Skiff|Ship|Airship|GameOver");

    reg(ChangeSystemSFX,  "System.SFX[%e0, %s"
                          "@Cursor|Decision|Cancel|Buzzer|StartBattle|Escape|EnemyAttack"
                          "|EnemyDamage|AllyDamage|Evasion|EnemyDefeated|UseItem");

    reg(ChangeSystemGraphics,  "System.Graphics = %s%op0%op1"
                               "@StretchToFit|TiledDisplay"
                               "@FontA|FontB");

    reg(ChangeScreenTransitions,  "System.Transition[%e0 = %e1"
                                  "@Teleport].Erase|Teleport].Show|BattleStarts].Erase"
                                  "|BattleStart].Show|BattleEnd].Erase|BattleEnd].Show"
                                  "@FadeIn|ReconstituteBlocks|UnwipeDownward|UnwipeUpward"
                                  "|VenetianBlinds|VerticalBlinds|HorizontalBlinds|RecedingSquare"
                                  "|ExpandingSquare|ScreenMovesDown|ScreenMovesUp|ScreenMovesRight"
                                  "|ScreenMovesLeft|VerticalUnify|HorizontalUnify|UnifyQuadrants"
                                  "|ZoomOut|Mosaic|WaverScreen|Instantaneous");

    reg(EnemyEncounter, "BattleStarts! Troop[%e0] Background[%e2]%op5%op6"
        "@%tr1|V[%v1]"
        "@FromMap|%s|FromTerrain[%gr8]"
        "@|FirstStrike"
        "@|Initiative|BackAttack|Surround|Pincers");

    reg(OpenShop, "OpenShop");
    reg(ShowInn, "ShowInn");
    reg(EnterHeroName, "EnterHeroName");
    reg(Teleport, "Teleport");
    reg(MemorizeLocation, "MemorizeLocation");
    reg(RecallToLocation, "RecallToLocation");
    reg(EnterExitVehicle, "EnterExitVehicle");
    reg(SetVehicleLocation, "SetVehicleLocation");
    reg(ChangeEventLocation, "ChangeEventLocation");
    reg(TradeEventLocations, "TradeEventLocations");
    reg(StoreTerrainID, "StoreTerrainID");
    reg(StoreEventID, "StoreEventID");
    reg(EraseScreen, "EraseScreen");
    reg(ShowScreen, "ShowScreen");
    reg(TintScreen, "TintScreen");
    reg(FlashScreen, "FlashScreen");
    reg(ShakeScreen, "ShakeScreen");
    reg(PanScreen, "PanScreen");
    reg(WeatherEffects, "WeatherEffects");
    reg(ShowPicture, "ShowPicture");
    reg(MovePicture, "MovePicture");
    reg(ErasePicture, "ErasePicture");
    reg(ShowBattleAnimation, "ShowBattleAnimation");
    reg(SpriteTransparency, "SpriteTransparency");
    reg(FlashSprite, "FlashSprite");
    reg(MoveEvent, "MoveEvent");
    reg(ProceedWithMovement, "ProceedWithMovement");
    reg(HaltAllMovement, "HaltAllMovement");
    reg(Wait, "Wait");
    reg(PlayBGM, "PlayBGM");
    reg(FadeOutBGM, "FadeOutBGM");
    reg(MemorizeBGM, "MemorizeBGM");
    reg(PlayMemorizedBGM, "PlayMemorizedBGM");
    reg(PlaySound, "PlaySound");
    reg(PlayMovie, "PlayMovie");
    reg(KeyInputProc, "KeyInputProc");
    reg(ChangeMapTileset, "ChangeMapTileset");
    reg(ChangePBG, "ChangePBG");
    reg(ChangeEncounterRate, "ChangeEncounterRate");
    reg(TileSubstitution, "TileSubstitution");
    reg(TeleportTargets, "TeleportTargets");
    reg(ChangeTeleportAccess, "ChangeTeleportAccess");
    reg(EscapeTarget, "EscapeTarget");
    reg(ChangeEscapeAccess, "ChangeEscapeAccess");
    reg(OpenSaveMenu, "OpenSaveMenu");
    reg(ChangeSaveAccess, "ChangeSaveAccess");
    reg(OpenMainMenu, "OpenMainMenu");
    reg(ChangeMainMenuAccess, "ChangeMainMenuAccess");
    reg(ConditionalBranch, "ConditionalBranch");
    reg(Label, "Label");
    reg(JumpToLabel, "JumpToLabel");
    reg(Loop, "Loop");
    reg(BreakLoop, "BreakLoop");
    reg(EndEventProcessing, "EndEventProcessing");
    reg(EraseEvent, "EraseEvent");
    reg(CallEvent, "CallEvent");
    reg(Comment, "Comment");
    reg(GameOver, "GameOver");
    reg(ReturntoTitleScreen, "ReturntoTitleScreen");

    reg(ChangeMonsterHP, "ChangeMonsterHP");
    reg(ChangeMonsterMP, "ChangeMonsterMP");
    reg(ChangeMonsterCondition, "ChangeMonsterCondition");
    reg(ShowHiddenMonster, "ShowHiddenMonster");
    reg(ChangeBattleBG, "ChangeBattleBG");
    reg(ShowBattleAnimation_B, "ShowBattleAnimation_B");
    reg(ConditionalBranch_B, "ConditionalBranch_B");
    reg(TerminateBattle, "TerminateBattle");

    reg(ShowMessage_2, "          %s");

    reg(ShowChoiceOption, "Case <%s>:");

    reg(ShowChoiceEnd, "ShowChoiceEnd");
    reg(VictoryHandler, "VictoryHandler");
    reg(EscapeHandler, "EscapeHandler");
    reg(DefeatHandler, "DefeatHandler");
    reg(EndBattle, "EndBattle");
    reg(Transaction, "Transaction");
    reg(NoTransaction, "NoTransaction");
    reg(EndShop, "EndShop");
    reg(Stay, "Stay");
    reg(NoStay, "NoStay");
    reg(EndInn, "EndInn");
    reg(ElseBranch, "ElseBranch");
    reg(EndBranch, "EndBranch");
    reg(EndLoop, "EndLoop");
    reg(Comment_2, "Comment_2");

    reg(ElseBranch_B, "ElseBranch_B");
    reg(EndBranch_B, "EndBranch_B");

//    reg(DUMMY, "DUMMY");

    label->setText("Done!");

    static QTimer t;
    connect(&t,SIGNAL(timeout()),s,SLOT(close()));
    connect(&t,SIGNAL(timeout()),&t,SLOT(stop()));
    t.start(7000);
    init = true;

#undef reg
}
