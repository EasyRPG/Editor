#include "qeventwidget.h"
#include "ui_qeventwidget.h"
#include <QDialogButtonBox>
#include <data.h>
#include "../dialogcharapicker.h"
#include "../core.h"

QMap<int, QString> QEventWidget::m_baseStrings = QMap<int, QString>();
QMap<int, std::vector<QEventWidget::ParameterType>> QEventWidget::m_interpreters =
        QMap<int, std::vector<QEventWidget::ParameterType>>();
bool QEventWidget::m_init = false;

QEventWidget::QEventWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QEventWidget),
    m_eventPage(0)
{
    ui->setupUi(this);
    for (unsigned int i = 0; i < Data::items.size(); i++)
        ui->comboItem->addItem(QString::fromStdString(Data::items[i].name));
    for (unsigned int i = 0; i < Data::actors.size(); i++)
        ui->comboHero->addItem(QString::fromStdString(Data::actors[i].name));
    m_charaItem = new QGraphicsCharaItem();
    m_tileItem = new QGraphicsPixmapItem();
    m_scene = new QGraphicsScene(this);
    m_effect = new QGraphicsOpacityEffect(this);
    m_charaItem->setGraphicsEffect(m_effect);
    m_tileItem->setGraphicsEffect(new QGraphicsOpacityEffect(m_effect));
    connect(m_effect,
            SIGNAL(enabledChanged(bool)),
            m_tileItem->graphicsEffect(),
            SLOT(setEnabled(bool)));
    m_charaItem->setScale(2.0);
    m_tileItem->setScale(2.0);
    m_scene->addItem(m_charaItem);
    m_scene->addItem(m_tileItem);
    m_scene->setBackgroundBrush(QBrush(QPixmap(":/embedded/share/old_grid.png")));
    ui->graphicsSprite->setScene(m_scene);
    ui->treeCommands->hideColumn(1);

    if (!m_init)
    {
        m_baseStrings[Cmd::END] = "<>";

        m_baseStrings[Cmd::CallCommonEvent] = "CallCommonEvent";
        m_baseStrings[Cmd::ForceFlee] = "ForceFlee";
        m_baseStrings[Cmd::EnableCombo] = "EnableCombo";
        m_baseStrings[Cmd::ChangeClass] = "ChangeClass";
        m_baseStrings[Cmd::ChangeBattleCommands] = "ChangeBattleCommands";

        m_baseStrings[Cmd::ShowMessage] = "Message: %s";

        m_baseStrings[Cmd::MessageOptions] = "MessageOptions [%1|%2|%3|%4]"
                                             "@Normal|Transparent"
                                             "@Top|Middle|Bottom"
                                             "@Fixed|Auto"
                                             "@Halt Process|Process Continue";
        m_interpreters[Cmd::MessageOptions].push_back(Enum);
        m_interpreters[Cmd::MessageOptions].push_back(Enum);
        m_interpreters[Cmd::MessageOptions].push_back(Enum);
        m_interpreters[Cmd::MessageOptions].push_back(Enum);

        m_baseStrings[Cmd::ChangeFaceGraphic] = "FaceGraphics: %s[%n0]@Left|Right@|Mirror";
        m_interpreters[Cmd::ChangeFaceGraphic].push_back(Id);
        m_interpreters[Cmd::ChangeFaceGraphic].push_back(Option);
        m_interpreters[Cmd::ChangeFaceGraphic].push_back(Option);

        m_baseStrings[Cmd::ShowChoice] = "ShowChoice";

        m_baseStrings[Cmd::InputNumber] = "InputNumber: %n0 Digit(s), V[%v1]";
        m_interpreters[Cmd::InputNumber].push_back(Id);
        m_interpreters[Cmd::InputNumber].push_back(Id);

        m_baseStrings[Cmd::ControlSwitches] = "%1 = %2"
                                              "@S[%b1]|S[%n1-%n2]|S[V[%v1]]"
                                              "@ON|OFF|Toggle";
        m_interpreters[Cmd::ControlSwitches].push_back(Enum);
        m_interpreters[Cmd::ControlSwitches].push_back(Id);
        m_interpreters[Cmd::ControlSwitches].push_back(Id);
        m_interpreters[Cmd::ControlSwitches].push_back(Enum);

        m_baseStrings[Cmd::ControlVars] = "%1 %3 %4"
                                          "@V[%v1]|V[%n1-%n2]|V[V[%v1]]"
                                          "@=|+=|-=|*=|/=|%="
                                          "@%n5|V[%v5]|V[V[%v5]]|Ramdom[%n5-%n6]|Item[%i5].%ic6|Hero[%h5].%hs6"
                                          "|Sprite[%sl5].%sp6|%o5";
        m_interpreters[Cmd::ControlVars].push_back(Enum);
        m_interpreters[Cmd::ControlVars].push_back(Id);
        m_interpreters[Cmd::ControlVars].push_back(Id);
        m_interpreters[Cmd::ControlVars].push_back(Enum);
        m_interpreters[Cmd::ControlVars].push_back(Enum);
        m_interpreters[Cmd::ControlVars].push_back(Id);
        m_interpreters[Cmd::ControlVars].push_back(Id);

        m_baseStrings[Cmd::TimerOperation] = "Timer[%3]%2"
                                             "@.Time = %1| starts| stops"
                                             "@%n2Sec(s)|V[%v2]"
                                             "@|ShowOnScreen"
                                             "@|RunInBattle"
                                             "@1|2";
        m_interpreters[Cmd::TimerOperation].push_back(Enum);
        m_interpreters[Cmd::TimerOperation].push_back(Enum);
        m_interpreters[Cmd::TimerOperation].push_back(Id);
        m_interpreters[Cmd::TimerOperation].push_back(Option);
        m_interpreters[Cmd::TimerOperation].push_back(Option);
        m_interpreters[Cmd::TimerOperation].push_back(Enum);

        m_baseStrings[Cmd::ChangeGold] = "%g %1 %2"
                                         "@+=|-="
                                         "@%n2|V[%v2]";
        m_interpreters[Cmd::ChangeGold].push_back(Enum);
        m_interpreters[Cmd::ChangeGold].push_back(Enum);
        m_interpreters[Cmd::ChangeGold].push_back(Id);

        m_baseStrings[Cmd::ChangeItems] = "Item[%2] %1 %3"
                                          "@+=|-="
                                          "@%i2|V[%v2]"
                                          "@%n4|V[%v4]";
        m_interpreters[Cmd::ChangeItems].push_back(Enum);
        m_interpreters[Cmd::ChangeItems].push_back(Enum);
        m_interpreters[Cmd::ChangeItems].push_back(Id);
        m_interpreters[Cmd::ChangeItems].push_back(Enum);
        m_interpreters[Cmd::ChangeItems].push_back(Id);

        m_baseStrings[Cmd::ChangePartyMembers] = "Hero[%2] %1 the party"
                                                 "@joins|leaves"
                                                 "@%h2|V[%v2]";
        m_interpreters[Cmd::ChangePartyMembers].push_back(Enum);
        m_interpreters[Cmd::ChangePartyMembers].push_back(Enum);
        m_interpreters[Cmd::ChangePartyMembers].push_back(Id);

        m_baseStrings[Cmd::ChangeExp] = "ChangeExp";
//        m_interpreters[Cmd::ChangeExp] = {?};

        m_baseStrings[Cmd::ChangeLevel] = "%1.Level %2 %3"
                                          "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                          "@+=|-="
                                          "@%n4|V[%v4]"
                                          "@|ShowMessage";
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Id);
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Id);
        m_interpreters[Cmd::ChangeExp].push_back(Option);

        m_baseStrings[Cmd::ChangeParameters] = "%1.%3 %2 %4"
                                               "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                               "@+=|-="
                                               "@MaxHP|MaxMP|Attack|Defense|Intelligence|Agility"
                                               "@%n5|V[v%5]";
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Id);
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Enum);
        m_interpreters[Cmd::ChangeExp].push_back(Id);

        m_baseStrings[Cmd::ChangeSkills] = "%1 %2 Skill[%3]"
                                           "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                           "@learns|forgets"
                                           "@%sk4|v[%v4]";
        m_interpreters[Cmd::ChangeSkills].push_back(Enum);
        m_interpreters[Cmd::ChangeSkills].push_back(Id);
        m_interpreters[Cmd::ChangeSkills].push_back(Enum);
        m_interpreters[Cmd::ChangeSkills].push_back(Enum);
        m_interpreters[Cmd::ChangeSkills].push_back(Id);

        m_baseStrings[Cmd::ChangeEquipment] = "%1 %2"
                                              "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                              "@equips Item[%3]|unequips %3"
                                              "@%i4|v[%v4]#Weapon|Shield|Armor|Helmet|Accesory|All";
        m_interpreters[Cmd::ChangeEquipment].push_back(Enum);
        m_interpreters[Cmd::ChangeEquipment].push_back(Id);
        m_interpreters[Cmd::ChangeEquipment].push_back(Enum);
        m_interpreters[Cmd::ChangeEquipment].push_back(Enum);
        m_interpreters[Cmd::ChangeEquipment].push_back(Id);

        m_baseStrings[Cmd::ChangeHP] = "%1.HP %2 %3"
                                       "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                       "@+=|-="
                                       "@%n4|V[%v4]"
                                       "@|CanKillTarget";
        m_interpreters[Cmd::ChangeHP].push_back(Enum);
        m_interpreters[Cmd::ChangeHP].push_back(Id);
        m_interpreters[Cmd::ChangeHP].push_back(Enum);
        m_interpreters[Cmd::ChangeHP].push_back(Enum);
        m_interpreters[Cmd::ChangeHP].push_back(Id);
        m_interpreters[Cmd::ChangeHP].push_back(Option);

        m_baseStrings[Cmd::ChangeSP] = "%1.MP %2 %3"
                                       "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                       "@+=|-="
                                       "@%n4|V[%v4]";
        m_interpreters[Cmd::ChangeSP].push_back(Enum);
        m_interpreters[Cmd::ChangeSP].push_back(Id);
        m_interpreters[Cmd::ChangeSP].push_back(Enum);
        m_interpreters[Cmd::ChangeSP].push_back(Enum);
        m_interpreters[Cmd::ChangeSP].push_back(Id);

        m_baseStrings[Cmd::ChangeCondition] = "%1.Conditions %2 Condition[%c3]"
                                              "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                              "@+=|-=";
        m_interpreters[Cmd::ChangeCondition].push_back(Enum);
        m_interpreters[Cmd::ChangeCondition].push_back(Id);
        m_interpreters[Cmd::ChangeCondition].push_back(Enum);
        m_interpreters[Cmd::ChangeCondition].push_back(Id);

        m_baseStrings[Cmd::FullHeal] = "%1 heals completely"
                                       "@EntireParty|Hero[%h1]|Hero[V[%v1]]";
        m_interpreters[Cmd::FullHeal].push_back(Enum);
        m_interpreters[Cmd::FullHeal].push_back(Id);

        m_baseStrings[Cmd::SimulatedAttack] = "%1 is takes damage by %n2%6"
                                              "@EntireParty|Hero[%h1]|Hero[V[%v1]]"
                                              "@| [V[%n7] = Damage]";
        m_interpreters[Cmd::SimulatedAttack].push_back(Enum);
        m_interpreters[Cmd::SimulatedAttack].push_back(Id);
        m_interpreters[Cmd::SimulatedAttack].push_back(Id);
        m_interpreters[Cmd::SimulatedAttack].push_back(Ignore);
        m_interpreters[Cmd::SimulatedAttack].push_back(Ignore);
        m_interpreters[Cmd::SimulatedAttack].push_back(Ignore);
        m_interpreters[Cmd::SimulatedAttack].push_back(Enum);
        m_interpreters[Cmd::SimulatedAttack].push_back(Id);

        m_baseStrings[Cmd::ChangeHeroName] = "Hero[%h0].Name = %s";
         m_interpreters[Cmd::ChangeHeroName].push_back(Id);

        m_baseStrings[Cmd::ChangeHeroTitle] = "ChangeHeroTitle";
        m_baseStrings[Cmd::ChangeSpriteAssociation] = "ChangeSpriteAssociation";
        m_baseStrings[Cmd::ChangeActorFace] = "ChangeActorFace";
        m_baseStrings[Cmd::ChangeVehicleGraphic] = "ChangeVehicleGraphic";
        m_baseStrings[Cmd::ChangeSystemBGM] = "ChangeSystemBGM";
        m_baseStrings[Cmd::ChangeSystemSFX] = "ChangeSystemSFX";
        m_baseStrings[Cmd::ChangeSystemGraphics] = "ChangeSystemGraphics";
        m_baseStrings[Cmd::ChangeScreenTransitions] = "ChangeScreenTransitions";
        m_baseStrings[Cmd::EnemyEncounter] = "EnemyEncounter";
        m_baseStrings[Cmd::OpenShop] = "OpenShop";
        m_baseStrings[Cmd::ShowInn] = "ShowInn";
        m_baseStrings[Cmd::EnterHeroName] = "EnterHeroName";
        m_baseStrings[Cmd::Teleport] = "Teleport";
        m_baseStrings[Cmd::MemorizeLocation] = "MemorizeLocation";
        m_baseStrings[Cmd::RecallToLocation] = "RecallToLocation";
        m_baseStrings[Cmd::EnterExitVehicle] = "EnterExitVehicle";
        m_baseStrings[Cmd::SetVehicleLocation] = "SetVehicleLocation";
        m_baseStrings[Cmd::ChangeEventLocation] = "ChangeEventLocation";
        m_baseStrings[Cmd::TradeEventLocations] = "TradeEventLocations";
        m_baseStrings[Cmd::StoreTerrainID] = "StoreTerrainID";
        m_baseStrings[Cmd::StoreEventID] = "StoreEventID";
        m_baseStrings[Cmd::EraseScreen] = "EraseScreen";
        m_baseStrings[Cmd::ShowScreen] = "ShowScreen";
        m_baseStrings[Cmd::TintScreen] = "TintScreen";
        m_baseStrings[Cmd::FlashScreen] = "FlashScreen";
        m_baseStrings[Cmd::ShakeScreen] = "ShakeScreen";
        m_baseStrings[Cmd::PanScreen] = "PanScreen";
        m_baseStrings[Cmd::WeatherEffects] = "WeatherEffects";
        m_baseStrings[Cmd::ShowPicture] = "ShowPicture";
        m_baseStrings[Cmd::MovePicture] = "MovePicture";
        m_baseStrings[Cmd::ErasePicture] = "ErasePicture";
        m_baseStrings[Cmd::ShowBattleAnimation] = "ShowBattleAnimation";
        m_baseStrings[Cmd::SpriteTransparency] = "SpriteTransparency";
        m_baseStrings[Cmd::FlashSprite] = "FlashSprite";
        m_baseStrings[Cmd::MoveEvent] = "MoveEvent";
        m_baseStrings[Cmd::ProceedWithMovement] = "ProceedWithMovement";
        m_baseStrings[Cmd::HaltAllMovement] = "HaltAllMovement";
        m_baseStrings[Cmd::Wait] = "Wait";
        m_baseStrings[Cmd::PlayBGM] = "PlayBGM";
        m_baseStrings[Cmd::FadeOutBGM] = "FadeOutBGM";
        m_baseStrings[Cmd::MemorizeBGM] = "MemorizeBGM";
        m_baseStrings[Cmd::PlayMemorizedBGM] = "PlayMemorizedBGM";
        m_baseStrings[Cmd::PlaySound] = "PlaySound";
        m_baseStrings[Cmd::PlayMovie] = "PlayMovie";
        m_baseStrings[Cmd::KeyInputProc] = "KeyInputProc";
        m_baseStrings[Cmd::ChangeMapTileset] = "ChangeMapTileset";
        m_baseStrings[Cmd::ChangePBG] = "ChangePBG";
        m_baseStrings[Cmd::ChangeEncounterRate] = "ChangeEncounterRate";
        m_baseStrings[Cmd::TileSubstitution] = "TileSubstitution";
        m_baseStrings[Cmd::TeleportTargets] = "TeleportTargets";
        m_baseStrings[Cmd::ChangeTeleportAccess] = "ChangeTeleportAccess";
        m_baseStrings[Cmd::EscapeTarget] = "EscapeTarget";
        m_baseStrings[Cmd::ChangeEscapeAccess] = "ChangeEscapeAccess";
        m_baseStrings[Cmd::OpenSaveMenu] = "OpenSaveMenu";
        m_baseStrings[Cmd::ChangeSaveAccess] = "ChangeSaveAccess";
        m_baseStrings[Cmd::OpenMainMenu] = "OpenMainMenu";
        m_baseStrings[Cmd::ChangeMainMenuAccess] = "ChangeMainMenuAccess";
        m_baseStrings[Cmd::ConditionalBranch] = "ConditionalBranch";
        m_baseStrings[Cmd::Label] = "Label";
        m_baseStrings[Cmd::JumpToLabel] = "JumpToLabel";
        m_baseStrings[Cmd::Loop] = "Loop";
        m_baseStrings[Cmd::BreakLoop] = "BreakLoop";
        m_baseStrings[Cmd::EndEventProcessing] = "EndEventProcessing";
        m_baseStrings[Cmd::EraseEvent] = "EraseEvent";
        m_baseStrings[Cmd::CallEvent] = "CallEvent";
        m_baseStrings[Cmd::Comment] = "Comment";
        m_baseStrings[Cmd::GameOver] = "GameOver";
        m_baseStrings[Cmd::ReturntoTitleScreen] = "ReturntoTitleScreen";

        m_baseStrings[Cmd::ChangeMonsterHP] = "ChangeMonsterHP";
        m_baseStrings[Cmd::ChangeMonsterMP] = "ChangeMonsterMP";
        m_baseStrings[Cmd::ChangeMonsterCondition] = "ChangeMonsterCondition";
        m_baseStrings[Cmd::ShowHiddenMonster] = "ShowHiddenMonster";
        m_baseStrings[Cmd::ChangeBattleBG] = "ChangeBattleBG";
        m_baseStrings[Cmd::ShowBattleAnimation_B] = "ShowBattleAnimation_B";
        m_baseStrings[Cmd::ConditionalBranch_B] = "ConditionalBranch_B";
        m_baseStrings[Cmd::TerminateBattle] = "TerminateBattle";

        m_baseStrings[Cmd::ShowMessage_2] = "          %s";

        m_baseStrings[Cmd::ShowChoiceOption] = "Case <%s>:";

        m_baseStrings[Cmd::ShowChoiceEnd] = "ShowChoiceEnd";
        m_baseStrings[Cmd::VictoryHandler] = "VictoryHandler";
        m_baseStrings[Cmd::EscapeHandler] = "EscapeHandler";
        m_baseStrings[Cmd::DefeatHandler] = "DefeatHandler";
        m_baseStrings[Cmd::EndBattle] = "EndBattle";
        m_baseStrings[Cmd::Transaction] = "Transaction";
        m_baseStrings[Cmd::NoTransaction] = "NoTransaction";
        m_baseStrings[Cmd::EndShop] = "EndShop";
        m_baseStrings[Cmd::Stay] = "Stay";
        m_baseStrings[Cmd::NoStay] = "NoStay";
        m_baseStrings[Cmd::EndInn] = "EndInn";
        m_baseStrings[Cmd::ElseBranch] = "ElseBranch";
        m_baseStrings[Cmd::EndBranch] = "EndBranch";
        m_baseStrings[Cmd::EndLoop] = "EndLoop";
        m_baseStrings[Cmd::Comment_2] = "Comment_2";

        m_baseStrings[Cmd::ElseBranch_B] = "ElseBranch_B";
        m_baseStrings[Cmd::EndBranch_B] = "EndBranch_B";

        m_baseStrings[Cmd::DUMMY] = "DUMMY";
        m_init = true;
    }
}

QEventWidget::~QEventWidget()
{
    delete m_tileItem;
    delete m_charaItem;
    delete ui;
}
RPG::EventPage *QEventWidget::eventPage() const
{
    return m_eventPage;
}

void QEventWidget::setEventPage(RPG::EventPage *eventPage)
{
    m_eventPage = eventPage;
    ui->checkSwitchA->setChecked(eventPage->condition.flags.switch_a);
    ui->checkSwitchB->setChecked(eventPage->condition.flags.switch_b);
    ui->checkVar->setChecked(eventPage->condition.flags.variable);
    ui->comboVarOperation->setCurrentIndex(eventPage->condition.compare_operator);
    ui->spinVarValue->setValue(eventPage->condition.variable_value);
    ui->checkItem->setChecked(eventPage->condition.flags.item);
    ui->comboItem->setCurrentIndex(eventPage->condition.item_id-1);
    ui->checkHero->setChecked(eventPage->condition.flags.actor);
    ui->comboHero->setCurrentIndex(eventPage->condition.actor_id-1);
    ui->checkTimerA->setChecked(eventPage->condition.flags.timer);
    ui->spinTimerAMin->setValue(eventPage->condition.timer_sec/60);
    ui->spinTimerASec->setValue(eventPage->condition.timer_sec%60);
    ui->checkTimerB->setChecked(eventPage->condition.flags.timer2);
    ui->spinTimerBMin->setValue(eventPage->condition.timer2_sec/60);
    ui->spinTimerBSec->setValue(eventPage->condition.timer2_sec%60);
    ui->checkTransparent->setChecked(eventPage->translucent);
    ui->comboMoveType->setCurrentIndex(eventPage->move_type);
    ui->comboMoveSpeed->setCurrentIndex(eventPage->move_speed-1);
    ui->comboCondition->setCurrentIndex(eventPage->trigger);
    ui->comboLayer->setCurrentIndex(eventPage->layer);
    ui->checkOverlap->setChecked(eventPage->overlap);
    ui->comboAnimationType->setCurrentIndex(eventPage->animation_type);
    ui->comboMoveFrequency->setCurrentIndex(eventPage->move_frequency-1);
    m_effect->setEnabled(m_eventPage->translucent);
    updateGraphic();

    m_codeGen = 0;
    QTreeWidgetItem *parent = 0;
    for (unsigned int i = 0; i < m_eventPage->event_commands.size(); i++)
    {
        QStringList p;
        for (unsigned int j = 0; j < m_eventPage->event_commands[i].parameters.size(); j++)
            p << QString::number(m_eventPage->event_commands[i].parameters[j]);
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()
                                        << verbalize(m_eventPage->event_commands[i])
                                        << "0" //TODO: generate internal id
                                        << QString::fromStdString(m_eventPage->event_commands[i].string)
                                        << p.join("|"));
        if (m_eventPage->event_commands[i].code == Cmd::ShowChoiceOption &&
                m_eventPage->event_commands[i].parameters[0] != 0)
            parent = parent->parent();
        if (m_eventPage->event_commands[i].code == Cmd::ShowChoiceEnd)
        {
            parent = parent->parent()->parent();
            continue;
        }
        if (parent)
        {
            switch (m_eventPage->event_commands[i].code)
            {
            case (Cmd::ShowChoiceEnd):
            case (Cmd::EndBranch):
            case (Cmd::EndLoop):
            case (Cmd::EndBranch_B):
                parent = parent->parent();
            }
            if (!parent)
                ui->treeCommands->addTopLevelItem(item);
            else
                parent->addChild(item);
        }
        else
            ui->treeCommands->addTopLevelItem(item);
        switch (m_eventPage->event_commands[i].code)
        {
        case (Cmd::ShowChoice):
        case (Cmd::ConditionalBranch):
        case (Cmd::Loop):
        case (Cmd::ConditionalBranch_B):
        case (Cmd::ShowChoiceOption):
        case (Cmd::ElseBranch):
        case (Cmd::ElseBranch_B):
            parent = item;
            break;
        }
    }
    ui->treeCommands->expandAll();
}


void QEventWidget::on_comboMoveType_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    ui->label->setEnabled(index != 0);
    ui->comboMoveSpeed->setEnabled(index != 0);
    m_eventPage->move_type = index;
}

void QEventWidget::on_checkSwitchA_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    if (checked)
    ui->lineSwitchA->setText(QString("%1: %2").arg
            (m_eventPage->condition.switch_a_id)
            .arg(QString::fromStdString
                 (Data::switches[m_eventPage->condition.switch_a_id-1].name)));
    else
        ui->lineSwitchA->setText("");
    m_eventPage->condition.flags.switch_a = checked;
}

void QEventWidget::on_checkSwitchB_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    if (checked)
    ui->lineSwitchB->setText(QString("%1: %2").arg
            (m_eventPage->condition.switch_b_id)
            .arg(QString::fromStdString
                 (Data::switches[m_eventPage->condition.switch_b_id-1].name)));
    else
        ui->lineSwitchB->setText("");
    m_eventPage->condition.flags.switch_b = checked;
}

void QEventWidget::on_checkVar_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    if (checked)
    ui->lineVar->setText(QString("%1: %2").arg
            (m_eventPage->condition.variable_id)
            .arg(QString::fromStdString
                 (Data::variables[m_eventPage->condition.variable_id-1].name)));
    else
        ui->lineVar->setText("");
    m_eventPage->condition.flags.variable = checked;
}

void QEventWidget::on_checkItem_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.item = checked;
}

void QEventWidget::on_comboVarOperation_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.compare_operator = index;
}

void QEventWidget::on_spinVarValue_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.variable_value = arg1;
}

void QEventWidget::on_comboItem_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.item_id = index+1;
}

void QEventWidget::on_comboHero_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.actor_id = index+1;
}

void QEventWidget::on_checkHero_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.item = checked;
}

void QEventWidget::on_checkTimerA_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.timer = checked;
}

void QEventWidget::on_spinTimerAMin_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer_sec = arg1*60 + ui->spinTimerASec->value();
}

void QEventWidget::on_spinTimerASec_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer_sec = ui->spinTimerAMin->value()*60 + arg1;
}

void QEventWidget::on_checkTimerB_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.timer2 = checked;
}

void QEventWidget::on_spinTimerBMin_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer2_sec = arg1*60 + ui->spinTimerBSec->value();
}

void QEventWidget::on_spinTimerBSec_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer2_sec = ui->spinTimerBMin->value()*60 + arg1;
}

void QEventWidget::on_checkTransparent_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->translucent = checked;
    m_effect->setEnabled(checked);
}

void QEventWidget::on_comboMoveSpeed_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->move_speed = index+1;
}

void QEventWidget::on_comboCondition_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->trigger = index;
}

void QEventWidget::on_comboLayer_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->layer = index;
}

void QEventWidget::on_checkOverlap_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->overlap = checked;
}

void QEventWidget::on_comboAnimationType_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->animation_type = index;
}

void QEventWidget::on_comboMoveFrequency_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->move_frequency = index+1;
}

void QEventWidget::on_pushSetSprite_clicked()
{
    DialogCharaPicker dlg(this, true);
    dlg.setName(m_eventPage->character_name);
    dlg.setFrame(m_eventPage->character_pattern);
    dlg.setFacing(m_eventPage->character_direction);
    dlg.setIndex(m_eventPage->character_index);
    dlg.exec();
    if (dlg.result() == QDialogButtonBox::Ok)
    {
        m_eventPage->character_name = dlg.name();
        m_eventPage->character_pattern = dlg.frame();
        m_eventPage->character_direction = dlg.facing();
        m_eventPage->character_index = dlg.index();
        updateGraphic();
    }
}

void QEventWidget::updateGraphic()
{
    if (m_eventPage->character_name.empty())
    {
        QPixmap pix(16,16);
        pix.fill(QColor(0,0,0,0));
        mCore->beginPainting(pix);
        mCore->renderTile(10000+m_eventPage->character_index,QRect(0,0,16,16));
        mCore->endPainting();
        m_tileItem->setPixmap(pix);
        m_tileItem->setVisible(true);
        m_charaItem->setVisible(false);
        m_scene->setSceneRect(0,0,32,32);
    }
    else
    {
        m_charaItem->setBasePix(QString::fromStdString(m_eventPage->character_name));
        m_charaItem->setIndex(m_eventPage->character_index);
        m_charaItem->setFrame(m_eventPage->character_pattern);
        m_charaItem->setFacing(m_eventPage->character_direction);
        m_tileItem->setVisible(false);
        m_charaItem->setVisible(true);
        m_scene->setSceneRect(0,0,48,64);
    }
}

QString QEventWidget::verbalize(const RPG::EventCommand &com)
{
    static QStringList heroStats = QString("Level|Experience|Hp|Mp|MaxHp|MaxMp|Attack|Defense|Intelligence"
                                                "|Agility|WeaponID|ShieldID|ArmorID|HelmetID|AccesoryID").split("|");
    static QStringList itemCount = QString("InPosession|Equiped").split("|");
    static QStringList spriteList = QString("Hero|Skiff|Ship|AirShip|ThisEvent").split("|");
    static QStringList spriteParameters = QString("MapID|X|Y|Facing|ScreenX|ScreenY").split("|");
    static QStringList others = QString("Money|Timer[1].SecondsLeft|Timer[2].SecondsLeft|PartySize|SaveCount"
                                        "|BattleCount|VictoryCount|DefeatCount|EscapeCount|MidiPosition (ticks)").split("|");


    if (com.code == Cmd::ChangeFaceGraphic && com.string.empty())
        return tr("FaceGraphics: Erase");
    QStringList strings = m_baseStrings[com.code].split("@");
    QStringList options;

    QString str = strings[0];    if (com.parameters.size() != m_interpreters[com.code].size())
        return str + QString(" [Invalid parameter count %1 (expected %2)]")
                .arg(com.parameters.size()).arg(m_interpreters[com.code].size());
    QString aux;
    QString i_str;
    int enum_id = 1;
    for (unsigned int i = 0; i < m_interpreters[com.code].size(); i++)
    {
        switch (m_interpreters[com.code][i])
        {
        case Enum:
            if (com.parameters[i] < 0 || com.parameters[i] >= strings[enum_id].split("|").count())
                str = str.arg(QString("error: cmd.par[%1] == %2").arg(i).arg(com.parameters[i]));
            else
            {
                aux = strings[enum_id];
                if (aux.contains("#"))
                    str = str.arg(aux.split("#")[com.parameters[i-1]].split("|")[com.parameters[i]]);
                else
                    str = str.arg(aux.split("|")[com.parameters[i]]);
            }
            enum_id++;
            break;
        case Option:
            if (!strings[enum_id].split("|")[com.parameters[i]].isEmpty())
                options << strings[enum_id].split("|")[com.parameters[i]];
            enum_id++;
            break;
        case Id:
            i_str = QString::number(i);
            if (str.contains("%n"+i_str))
                str.replace("%n"+i_str, QString::number(com.parameters[i]));
            if (str.contains("%v"+i_str))
                str.replace("%v"+i_str, QString("%1:%2").arg(com.parameters[i]).arg(varName(com.parameters[i])));
            if (str.contains("%b"+i_str))
                str.replace("%b"+i_str, QString("%1:%2").arg(com.parameters[i]).arg(switchName(com.parameters[i])));
            if (str.contains("%i"+i_str))
                str.replace("%i"+i_str, itemName(com.parameters[i]));
            if (str.contains("%h"+i_str))
                str.replace("%h"+i_str, heroName(com.parameters[i]));
            if (str.contains("%hs"+i_str))
                str.replace("%hs"+i_str, heroStats[com.parameters[i]]);
            if (str.contains("%ic"+i_str))
                str.replace("%ic"+i_str, itemCount[com.parameters[i]]);
            if (str.contains("%sk"+i_str))
                str.replace("%sk"+i_str, skillName(com.parameters[i]));
            if (str.contains("%sl"+i_str) && com.parameters[i] > 10000)
                str.replace("%sl"+i_str, spriteList[com.parameters[i]-10001]);
            else if (str.contains("%sl%1"+i_str) && com.parameters[i] < 10001)
                str.replace("%sl"+i_str, eventName(com.parameters[i]));
            if (str.contains("%sp"+i_str))
                str.replace("%sp"+i_str, spriteParameters[com.parameters[i]]);
            if (str.contains("%o"+i_str))
                str.replace("%o"+i_str, others[com.parameters[i]]);
            if (str.contains("%c"+i_str))
                str.replace("%c"+i_str, conditionName(com.parameters[i]));
            break;
        }
    }
    str.replace("%g", QString::fromStdString(Data::terms.gold));
    if (options.count() > 0)
    {
        str += QString(" [%1]").arg(options.join("|"));
    }
    str.replace("%s", QString::fromStdString(com.string));

    return str;
}

QString QEventWidget::varName(int id)
{
    if (id < 1 || id > (int)Data::variables.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::variables[id-1].name);
}

QString QEventWidget::switchName(int id)
{
    if (id < 1 || id > (int)Data::switches.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::switches[id-1].name);
}

QString QEventWidget::itemName(int id)
{
    if (id < 1 || id > (int)Data::items.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::items[id-1].name);
}

QString QEventWidget::heroName(int id)
{
    if (id < 1 || id > (int)Data::actors.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::actors[id-1].name);
}

QString QEventWidget::skillName(int id)
{
    if (id < 1 || id > (int)Data::skills.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::skills[id-1].name);
}

QString QEventWidget::conditionName(int id)
{
    if (id < 1 || id > (int)Data::states.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::states[id-1].name);
}

QString QEventWidget::eventName(int id)
{
    if (!mCore->currentMapEvent(id))
        return QString("<%1?>").arg(id);
    return QString::fromStdString(mCore->currentMapEvent(id)->name);
}
