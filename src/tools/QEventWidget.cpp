#include "qeventwidget.h"
#include "ui_qeventwidget.h"
#include <QDialogButtonBox>
#include <data.h>
#include "../dialogcharapicker.h"
#include "command_codes.h"
#include "../core.h"

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
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << verbalize(m_eventPage->event_commands[i]));
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
    QString str = "Unknown String";
    switch (com.code)
    {
    case (Cmd::END):
        str = "<>";
        break;

    case (Cmd::CallCommonEvent):
        str = "CallCommonEvent";
        break;
    case (Cmd::ForceFlee):
        str = "ForceFlee";
        break;
    case (Cmd::EnableCombo):
        str = "EnableCombo";
        break;

    case (Cmd::ChangeClass):
        str = "ChangeClass";
        break;
    case (Cmd::ChangeBattleCommands):
        str = "ChangeBattleCommands";
        break;
    case (Cmd::ShowMessage):
        str = "Message: %1";
        str = str.arg(QString::fromStdString(com.string));
        break;
    case (Cmd::MessageOptions):
        str = "MessageOptions: %1, %2, %3, %4";
        str = str.arg((QStringList()
                 <<tr("Normal")
                 <<tr("Transparent")).at(com.parameters[0]));
        str = str.arg((QStringList()
                 <<tr("Top")
                 <<tr("Middle")
                 <<tr("Bottom")).at(com.parameters[1]));
        str = str.arg((QStringList()
                 <<tr("Fixed")
                 <<tr("Auto")).at(com.parameters[2]));
        str = str.arg((QStringList()
                 <<tr("Halt Process")
                 <<tr("Process Continue")).at(com.parameters[3]));
        break;
    case (Cmd::ChangeFaceGraphic):
        str = "Change Face Graphics: ";
        if (com.string.empty())
            str += tr("Erase");
        else
        {
            str += "%1, %2, %3";
            str = str.arg(QString::fromStdString(com.string));
            str = str.arg(QString::number(com.parameters[0]+1));
            str = str.arg((QStringList()
                     <<tr("Left")
                     <<tr("Right")).at(com.parameters[1]));
            if (com.parameters[2])
                str += tr(", Mirror");
        }
        break;
    case (Cmd::ShowChoice):
        str = "ShowChoice";
        break;
    case (Cmd::InputNumber):
        str = "Input Number: %1 Digit(s), V[%2]";
        str = str.arg(com.parameters[0]).arg(com.parameters[1]);
        break;
    case (Cmd::ControlSwitches):
        str = "Switch Operation: [%1] %2";
        switch (com.parameters[0])
        {
        case 0: //Single Switch
            str = str.arg(QString::number(com.parameters[1]));
            break;
        case 1: //Switch Range
            str = str.arg(QString("%1 - %2")
                    .arg(com.parameters[1])
                    .arg(com.parameters[2]));
            break;
        case 2: //Variable Reference
            str = str.arg(QString("V[%1]").arg(com.parameters[1]));
            break;
        }
        str = str.arg((QStringList()
                <<tr("ON")
                <<tr("OFF")
                <<tr("On/OFF Toggle")).at(com.parameters[3]));
        break;
    case (Cmd::ControlVars):
        str = "V[%1] %2 %3";
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(com.parameters[1]);
            break;
        case 1:
            str = str.arg(QString("%1-%2").arg(com.parameters[1]).arg(com.parameters[2]));
            break;
        case 2:
            str = str.arg(QString("V[%1]").arg(com.parameters[1]));
            break;
        }
        str = str.arg((QStringList()
                       <<tr("=")
                       <<tr("+=")
                       <<tr("-=")
                       <<tr("*=")
                       <<tr("/=")
                       <<tr("%=")).at(com.parameters[3]));
        switch (com.parameters[4])
        {
        case 0:
            str = str.arg(com.parameters[5]);
            break;
        case 1:
            str = str.arg(QString("V[%1]").arg(com.parameters[5]));
            break;
        case 2:
            str = str.arg(QString("V[V[%1]]").arg(com.parameters[5]));
            break;
        case 3:
            str = str.arg(QString("Random[%1-%2]").arg(com.parameters[5]).arg(com.parameters[6]));
            break;
        case 4:
            str = str.arg(QString("Item[%1].%2")
                          .arg(QString::fromStdString(Data::items[com.parameters[5]-1].name))
                          .arg((QStringList()
                                << tr("count")
                                << tr("equiped")).at(com.parameters[6])));
            break;
        case 5:
            str = str.arg(QString("Hero[%1].%2")
                          .arg(QString::fromStdString(Data::actors[com.parameters[5]-1].name))
                          .arg((QStringList()
                                << tr("Level")
                                << tr("Experience")
                                << tr("Hp")
                                << tr("Mp")
                                << tr("MaxHp")
                                << tr("MaxMp")
                                << tr("Attack")
                                << tr("Defense")
                                << tr("Intelligence")
                                << tr("Agility")
                                << tr("WeaponID")
                                << tr("ShieldID")
                                << tr("ArmorID")
                                << tr("HelmetID")
                                << tr("AccesoryID")).at(com.parameters[6])));
            break;
        case 6:
            str = str.arg("Sprite[%1].%2");
            if (com.parameters[5] > 10000)
                str = str.arg((QStringList()
                                      << tr("Hero")
                                      << tr("Skiff")
                                      << tr("Ship")
                                      << tr("AirShip")
                                      << tr("ThisEvent")).at(com.parameters[5]-10001));
            else
                str = str.arg(QString::fromStdString("EV[%1]")
                              .arg(QString::fromStdString
                                   (mCore->currentMapEvent(com.parameters[5])->name)));
                //TODO CORRECT EVENT NAME
            str = str.arg((QStringList()
                                  << tr("MapID")
                                  << tr("X")
                                  << tr("Y")
                                  << tr("Facing")
                                  << tr("ScreenX")
                                  << tr("ScreenY")).at(com.parameters[6]));
            break;
        case 7:
            str = str.arg((QStringList()
                           << tr("Money")
                           << tr("Timer[1].SecondsLeft")
                           << tr("Timer[2].SecondsLeft")
                           << tr("PartySize")
                           << tr("SaveCount")
                           << tr("BattleCount")
                           << tr("VictoryCount")
                           << tr("DefeatCount")
                           << tr("EscapeCount")
                           << tr("MidiPosition (ticks)")).at(com.parameters[5]));
            break;
        }
        break;
    case (Cmd::TimerOperation):
        str = "Timer%1%2";
        str = str.arg(com.parameters[5]+1);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(".Time = %1");
            if (!com.parameters[1])
                str = str.arg(QString("%1Min(s) %2Sec(s)")
                                        .arg(com.parameters[2]/60)
                                        .arg(com.parameters[2]%2));
            else
                str = str.arg(QString("V[%1]").arg(com.parameters[2]));
            break;
        case 1:
            str = str.arg(tr(" Start"));
            break;
        case 2:
            str = str.arg(tr(" Stop"));
            break;
        }

        break;
    case (Cmd::ChangeGold):
        str = QString("%1 %2 %3").arg(QString::fromStdString(Data::terms.gold));
        if (com.parameters[0])
            str = str.arg("-=");
        else
            str = str.arg("+=");
        if (com.parameters[1])
            str = str.arg(QString("V[%1]").arg(com.parameters[2]));
        else
            str = str.arg(com.parameters[2]);
        break;
    case (Cmd::ChangeItems):
        str = "Item[%1] %2 %3";
        if (com.parameters[1])
            str = str.arg(QString("V[%1]").arg(com.parameters[2]));
        else
        {
            if (com.parameters[2] > (int)Data::items.size())
                str = str.arg("<?>");
            else
                str = str.arg(QString::fromStdString(Data::items[com.parameters[2]-1].name));
        }
        if (com.parameters[0])
            str = str.arg("-=");
        else
            str = str.arg("+=");
        if (com.parameters[3])
            str = str.arg(QString("V[%1]").arg(com.parameters[4]));
        else
            str = str.arg(com.parameters[4]);
        break;
    case (Cmd::ChangePartyMembers):
        str = tr("Hero[%2] %1 the party");
        str = str.arg(com.parameters[0] ? tr("leaves") : tr("joins"));
        if (com.parameters[1])
            str = str.arg(QString("V[%1]").arg(com.parameters[2]));
        else
        {
            if (com.parameters[2] > (int)Data::actors.size())
                str = str.arg("<?>");
            else
                str = str.arg(QString::fromStdString(Data::actors[com.parameters[2]-1].name));
        }
        break;
    case (Cmd::ChangeExp):
        str = "ChangeExp";
        break;
    case (Cmd::ChangeLevel):
        str = "ChangeLevel";
        break;
    case (Cmd::ChangeParameters):
        str = "ChangeParameters";
        break;
    case (Cmd::ChangeSkills):
        str = "ChangeSkills";
        break;
    case (Cmd::ChangeEquipment):
        str = "ChangeEquipment";
        break;
    case (Cmd::ChangeHP):
        str = "ChangeHP";
        break;
    case (Cmd::ChangeSP):
        str = "ChangeSP";
        break;
    case (Cmd::ChangeCondition):
        str = "ChangeCondition";
        break;
    case (Cmd::FullHeal):
        str = "FullHeal";
        break;
    case (Cmd::SimulatedAttack):
        str = "SimulatedAttack";
        break;
    case (Cmd::ChangeHeroName):
        str = "ChangeHeroName";
        break;
    case (Cmd::ChangeHeroTitle):
        str = "ChangeHeroTitle";
        break;
    case (Cmd::ChangeSpriteAssociation):
        str = "ChangeSpriteAssociation";
        break;
    case (Cmd::ChangeActorFace):
        str = "ChangeActorFace";
        break;
    case (Cmd::ChangeVehicleGraphic):
        str = "ChangeVehicleGraphic";
        break;
    case (Cmd::ChangeSystemBGM):
        str = "ChangeSystemBGM";
        break;
    case (Cmd::ChangeSystemSFX):
        str = "ChangeSystemSFX";
        break;
    case (Cmd::ChangeSystemGraphics):
        str = "ChangeSystemGraphics";
        break;
    case (Cmd::ChangeScreenTransitions):
        str = "ChangeScreenTransitions";
        break;
    case (Cmd::EnemyEncounter):
        str = "EnemyEncounter";
        break;
    case (Cmd::OpenShop):
        str = "OpenShop";
        break;
    case (Cmd::ShowInn):
        str = "ShowInn";
        break;
    case (Cmd::EnterHeroName):
        str = "EnterHeroName";
        break;
    case (Cmd::Teleport):
        str = "Teleport";
        break;
    case (Cmd::MemorizeLocation):
        str = "MemorizeLocation";
        break;
    case (Cmd::RecallToLocation):
        str = "RecallToLocation";
        break;
    case (Cmd::EnterExitVehicle):
        str = "EnterExitVehicle";
        break;
    case (Cmd::SetVehicleLocation):
        str = "SetVehicleLocation";
        break;
    case (Cmd::ChangeEventLocation):
        str = "ChangeEventLocation";
        break;
    case (Cmd::TradeEventLocations):
        str = "TradeEventLocations";
        break;
    case (Cmd::StoreTerrainID):
        str = "StoreTerrainID";
        break;
    case (Cmd::StoreEventID):
        str = "StoreEventID";
        break;
    case (Cmd::EraseScreen):
        str = "EraseScreen";
        break;
    case (Cmd::ShowScreen):
        str = "ShowScreen";
        break;
    case (Cmd::TintScreen):
        str = "TintScreen";
        break;
    case (Cmd::FlashScreen):
        str = "FlashScreen";
        break;
    case (Cmd::ShakeScreen):
        str = "ShakeScreen";
        break;
    case (Cmd::PanScreen):
        str = "PanScreen";
        break;
    case (Cmd::WeatherEffects):
        str = "WeatherEffects";
        break;
    case (Cmd::ShowPicture):
        str = "ShowPicture";
        break;
    case (Cmd::MovePicture):
        str = "MovePicture";
        break;
    case (Cmd::ErasePicture):
        str = "ErasePicture";
        break;
    case (Cmd::ShowBattleAnimation):
        str = "ShowBattleAnimation";
        break;
    case (Cmd::SpriteTransparency):
        str = "SpriteTransparency";
        break;
    case (Cmd::FlashSprite):
        str = "FlashSprite";
        break;
    case (Cmd::MoveEvent):
        str = "MoveEvent";
        break;
    case (Cmd::ProceedWithMovement):
        str = "ProceedWithMovement";
        break;
    case (Cmd::HaltAllMovement):
        str = "HaltAllMovement";
        break;
    case (Cmd::Wait):
        str = "Wait";
        break;
    case (Cmd::PlayBGM):
        str = "PlayBGM";
        break;
    case (Cmd::FadeOutBGM):
        str = "FadeOutBGM";
        break;
    case (Cmd::MemorizeBGM):
        str = "MemorizeBGM";
        break;
    case (Cmd::PlayMemorizedBGM):
        str = "PlayMemorizedBGM";
        break;
    case (Cmd::PlaySound):
        str = "PlaySound";
        break;
    case (Cmd::PlayMovie):
        str = "PlayMovie";
        break;
    case (Cmd::KeyInputProc):
        str = "KeyInputProc";
        break;
    case (Cmd::ChangeMapTileset):
        str = "ChangeMapTileset";
        break;
    case (Cmd::ChangePBG):
        str = "ChangePBG";
        break;
    case (Cmd::ChangeEncounterRate):
        str = "ChangeEncounterRate";
        break;
    case (Cmd::TileSubstitution):
        str = "TileSubstitution";
        break;
    case (Cmd::TeleportTargets):
        str = "TeleportTargets";
        break;
    case (Cmd::ChangeTeleportAccess):
        str = "ChangeTeleportAccess";
        break;
    case (Cmd::EscapeTarget):
        str = "EscapeTarget";
        break;
    case (Cmd::ChangeEscapeAccess):
        str = "ChangeEscapeAccess";
        break;
    case (Cmd::OpenSaveMenu):
        str = "OpenSaveMenu";
        break;
    case (Cmd::ChangeSaveAccess):
        str = "ChangeSaveAccess";
        break;
    case (Cmd::OpenMainMenu):
        str = "OpenMainMenu";
        break;
    case (Cmd::ChangeMainMenuAccess):
        str = "ChangeMainMenuAccess";
        break;
    case (Cmd::ConditionalBranch):
        str = "ConditionalBranch";
        break;
    case (Cmd::Label):
        str = "Label";
        break;
    case (Cmd::JumpToLabel):
        str = "JumpToLabel";
        break;
    case (Cmd::Loop):
        str = "Loop";
        break;
    case (Cmd::BreakLoop):
        str = "BreakLoop";
        break;
    case (Cmd::EndEventProcessing):
        str = "EndEventProcessing";
        break;
    case (Cmd::EraseEvent):
        str = "EraseEvent";
        break;
    case (Cmd::CallEvent):
        str = "CallEvent";
        break;
    case (Cmd::Comment):
        str = "Comment";
        break;
    case (Cmd::GameOver):
        str = "GameOver";
        break;
    case (Cmd::ReturntoTitleScreen):
        str = "ReturntoTitleScreen";
        break;

    case (Cmd::ChangeMonsterHP):
        str = "ChangeMonsterHP";
        break;
    case (Cmd::ChangeMonsterMP):
        str = "ChangeMonsterMP";
        break;
    case (Cmd::ChangeMonsterCondition):
        str = "ChangeMonsterCondition";
        break;
    case (Cmd::ShowHiddenMonster):
        str = "ShowHiddenMonster";
        break;
    case (Cmd::ChangeBattleBG):
        str = "ChangeBattleBG";
        break;
    case (Cmd::ShowBattleAnimation_B):
        str = "ShowBattleAnimation_B";
        break;
    case (Cmd::ConditionalBranch_B):
        str = "ConditionalBranch_B";
        break;
    case (Cmd::TerminateBattle):
        str = "TerminateBattle";
        break;

    case (Cmd::ShowMessage_2):
        str = "          %1";
        str = str.arg(QString::fromStdString(com.string));
        break;
    case (Cmd::ShowChoiceOption):
        str = "Case <%1>:";
        str = str.arg(QString::fromStdString(com.string));
        break;
    case (Cmd::ShowChoiceEnd):
        str = "ShowChoiceEnd";
        break;
    case (Cmd::VictoryHandler):
        str = "VictoryHandler";
        break;
    case (Cmd::EscapeHandler):
        str = "EscapeHandler";
        break;
    case (Cmd::DefeatHandler):
        str = "DefeatHandler";
        break;
    case (Cmd::EndBattle):
        str = "EndBattle";
        break;
    case (Cmd::Transaction):
        str = "Transaction";
        break;
    case (Cmd::NoTransaction):
        str = "NoTransaction";
        break;
    case (Cmd::EndShop):
        str = "EndShop";
        break;
    case (Cmd::Stay):
        str = "Stay";
        break;
    case (Cmd::NoStay):
        str = "NoStay";
        break;
    case (Cmd::EndInn):
        str = "EndInn";
        break;
    case (Cmd::ElseBranch):
        str = "ElseBranch";
        break;
    case (Cmd::EndBranch):
        str = "EndBranch";
        break;
    case (Cmd::EndLoop):
        str = "EndLoop";
        break;
    case (Cmd::Comment_2):
        str = "Comment_2";
        break;

    case (Cmd::ElseBranch_B):
        str = "ElseBranch_B";
        break;
    case (Cmd::EndBranch_B):
        str = "EndBranch_B";
        break;

    case (Cmd::DUMMY):
        str = "DUMMY";
        break;
    }
    return str;
}
