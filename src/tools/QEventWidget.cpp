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
#define chkLenght(expected)\
    if (com.parameters.size() != expected)\
        return (str + QString("error: parameters size == %1 (expected %2)")\
                .arg(com.parameters.size()).arg(expected))
#define errorHandler(param)\
    default:\
    str = str.arg(QString("error: cmd.par[%1] == %2").arg(param).arg(com.parameters[param]))
#define fromList(param, stringlist)\
    if (com.parameters[param] < 0 || com.parameters[param] >= QString(stringlist).split("|").count())\
        str = str.arg(QString("error: cmd.par[%1] == %2").arg(param).arg(com.parameters[param]));\
    else\
        str = str.arg(QString(stringlist).split("|")[com.parameters[param]])
#define vars(param)\
    aux = QString("V[%1:%2]").arg(com.parameters[param]);\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::variables.size())\
        aux = aux.arg("<%1?>").arg(com.parameters[param]);\
    else\
        aux = aux.arg(QString::fromStdString(Data::variables[com.parameters[param]-1].name));\
    str = str.arg(aux)
#define indexedVar(param)\
    aux = QString("V[V[%1:%2]]").arg(com.parameters[param]);\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::variables.size())\
        aux = aux.arg("<%1?>").arg(com.parameters[param]);\
    else\
        aux = aux.arg(QString::fromStdString(Data::variables[com.parameters[param]-1].name));\
    str = str.arg(aux)
#define switches(param)\
    aux = QString("S[%1:%2]").arg(com.parameters[param]);\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::switches.size())\
        aux = aux.arg("<%1?>").arg(com.parameters[param]);\
    else\
        aux = aux.arg(QString::fromStdString(Data::switches[com.parameters[param]-1].name));\
    str = str.arg(aux)
#define indexedSwitch(param)\
    aux = QString("S[V[%1:%2]]").arg(com.parameters[param]);\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::variables.size())\
        aux = aux.arg("<%1?>").arg(com.parameters[param]);\
    else\
        aux = aux.arg(QString::fromStdString(Data::variables[com.parameters[param]-1].name));\
    str = str.arg(aux)
#define hero(param)\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::actors.size())\
        str = str.arg("<%1?>").arg(com.parameters[param]);\
    else\
        str = str.arg(QString::fromStdString(Data::actors[com.parameters[param]-1].name))
#define item(param)\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::items.size())\
        str = str.arg("<%1?>").arg(com.parameters[param]);\
    else\
        str = str.arg(QString::fromStdString(Data::items[com.parameters[param]-1].name))
#define skill(param)\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::skills.size())\
        str = str.arg("<%1?>").arg(com.parameters[param]);\
    else\
        str = str.arg(QString::fromStdString(Data::skills[com.parameters[param]-1].name))
#define condition(param)\
    if (com.parameters[param] < 1 || com.parameters[param] > (int)Data::states.size())\
        str = str.arg("<%1?>").arg(com.parameters[param]);\
    else\
        str = str.arg(QString::fromStdString(Data::states[com.parameters[param]-1].name))

    QString aux;
    aux = "";
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
        chkLenght(0);
        str = str.arg(QString::fromStdString(com.string));
        break;
    case (Cmd::MessageOptions):
        str = "MessageOptions [%1|%2|%3|%4]";
        chkLenght(4);
        fromList(0, "Normal|Transparent");
        fromList(1, "Top|Middle|Bottom");
        fromList(2, "Fixed|Auto");
        fromList(3, "Halt Process|Process Continue");
        break;
    case (Cmd::ChangeFaceGraphic):
        str = "FaceGraphics: ";
        chkLenght(3);
        if (com.string.empty())
            str += tr("Erase");
        else
        {
            str += "%1[%2] [%3%4]";
            str = str.arg(QString::fromStdString(com.string));
            str = str.arg(QString::number(com.parameters[0]));
            fromList(1,"Left|Right");
            if (com.parameters[2] == 0)
                str = str.arg("");
            else if (com.parameters[2] == 1)
                str = str.arg("|Mirror");
            else
                str = str.arg("error: cmd.par[2] == %1").arg(com.parameters[2]);
        }
        break;
    case (Cmd::ShowChoice):
        str = "ShowChoice";
        break;
    case (Cmd::InputNumber):
        str = "InputNumber: %1 Digit(s), %2";
        chkLenght(2);
        str = str.arg(com.parameters[0]);
        vars(1);
        break;
    case (Cmd::ControlSwitches):
        str = "%1 = %2";
        chkLenght(4);
        switch (com.parameters[0])
        {
        case 0: //Single Switch
            switches(1);
            break;
        case 1: //Switch Range
            str = str.arg(QString("S[%1-%2]")
                    .arg(com.parameters[1])
                    .arg(com.parameters[2]));
            break;
        case 2: //Variable Reference
            indexedSwitch(1);
            break;
        errorHandler(0);
        }
        fromList(3, "ON|OFF|Toggle");
        break;
    case (Cmd::ControlVars):
        str = "%1 %2 %3";
        chkLenght(7);
        switch (com.parameters[0])
        {
        case 0:
            vars(1);
            break;
        case 1:
            str = str.arg(QString("V[%1-%2]").arg(com.parameters[1]).arg(com.parameters[2]));
            break;
        case 2:
            indexedVar(1);
            break;
        }
        fromList(3, "=|+=|-=|*=|/=|%=");
        switch (com.parameters[4])
        {
        case 0:
            str = str.arg(com.parameters[5]);
            break;
        case 1:
            vars(5);
            break;
        case 2:
            indexedVar(5);
            break;
        case 3:
            str = str.arg(QString("Random[%1-%2]")
                            .arg(com.parameters[5])
                            .arg(com.parameters[6]));
            break;
        case 4:
            str = str.arg("Item[%1].%2");
            item(5);
            fromList(6, "InPosession|Equiped");
            break;
        case 5:
            str = str.arg("Hero[%1].%2");
            hero(5);
            fromList(6, "Level|Experience|Hp|Mp|MaxHp|MaxMp|Attack|Defense|Intelligence"
                        "|Agility|WeaponID|ShieldID|ArmorID|HelmetID|AccesoryID");
            break;
        case 6:
            str = str.arg("Sprite[%1].%2");
            if (com.parameters[5] > 10000)
                str = str.arg(QString("Hero|Skiff|Ship|AirShip|ThisEvent")
                              .split("|")[com.parameters[5]-10001]);
            else
                str = str.arg(QString::fromStdString("EV[%1]")
                              .arg(QString::fromStdString
                                   (mCore->currentMapEvent(com.parameters[5])->name)));
            fromList(6, "MapID|X|Y|Facing|ScreenX|ScreenY");
            break;
        case 7:
            fromList(5, "Money|Timer[1].SecondsLeft|Timer[2].SecondsLeft|PartySize|SaveCount"
                        "|BattleCount|VictoryCount|DefeatCount|EscapeCount|MidiPosition (ticks)");
            break;
        errorHandler(4);
        }
        break;
    case (Cmd::TimerOperation):
        str = "Timer%1%2";
        chkLenght(6);
        str = str.arg(com.parameters[5]+1);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(".Time = %1");
            switch (com.parameters[1])
            {
            case 0:
                str = str.arg("%1Min(s) %2Sec(s)");
                str = str.arg(com.parameters[2]/60).arg(com.parameters[2]%60);
                break;
            case 1:
                vars(2);
                break;
            errorHandler(1);
            }
            break;
        case 1:
            str = str.arg(tr(" Start"));
            break;
        case 2:
            str = str.arg(tr(" Stop"));
            break;
        switch (com.parameters[3])
        {
        case 0:
            break;
        case 1:
            aux = "[ShowOnScreen]";
            break;
        errorHandler(3);
        }
        switch (com.parameters[4])
        {
        case 0:
            break;
        case 1:
            if (aux.isEmpty())
                aux = "[RunInBattle]";
            else
                aux = "[ShowOnScreen|RunInBattle]";
            break;
        errorHandler(4);
        }
        str += aux;
        errorHandler(0);
        }
        break;
    case (Cmd::ChangeGold):
        str = QString("%1 %2 %3").arg(QString::fromStdString(Data::terms.gold));
        chkLenght(3);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg("+=");
            break;
        case 1:
            str = str.arg("-=");
            break;
        errorHandler(0);
        }
        switch (com.parameters[1])
        {
        case 0:
            str = str.arg(com.parameters[2]);
            break;
        case 1:
            vars(2);
            break;
        errorHandler(1);
        }
        break;
    case (Cmd::ChangeItems):
        str = "Item[%1] %2 %3";
        chkLenght(5);
        switch (com.parameters[1])
        {
        case 0:
            item(2);
            break;
        case 1:
            vars(2);
            break;
        errorHandler(1);
        }
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg("+=");
            break;
        case 1:
            str = str.arg("-=");
            break;
        errorHandler(0);
        }
        switch (com.parameters[3])
        {
        case 0:
            str = str.arg(com.parameters[4]);
            break;
        case 1:
            vars(4);
            break;
        errorHandler(3);
        }
        break;
    case (Cmd::ChangePartyMembers):
        str = tr("Hero[%2] %1 the party");
        chkLenght(3);
        fromList(0, "joins|leaves");
        switch (com.parameters[1])
        {
        case 0:
            hero(2);
            break;
        case 1:
            vars(2);
            break;
        errorHandler(1);
        }
        break;
    case (Cmd::ChangeExp):
        str = "ChangeExp";
        break;
    case (Cmd::ChangeLevel):
        str = tr("%1.Level %2 %3%4");
        chkLenght(6);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            hero(1);
            break;
        case 3:
            str = str.arg("Hero[%1]");
            vars(1);
            break;
        }
        switch (com.parameters[2])
        {
        case 0:
            str = str.arg("+=");
            break;
        case 1:
            str = str.arg("-=");
            break;
        errorHandler(2);
        }
        switch (com.parameters[3])
        {
        case 0:
            str = str.arg(com.parameters[4]);
            break;
        case 1:
            vars(4);
            break;
        errorHandler(3);
        }
        switch (com.parameters[5])
        {
        case 0:
            str = str.arg("");
            break;
        case 1:
            str = str.arg(" [ShowMessage]");
            break;
        errorHandler(5);
        }
        break;
    case (Cmd::ChangeParameters):
        str = "%1.%2 %3 %4";
        chkLenght(6);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(3, tr("MaxHP|MaxMP|Attack|Defense|Intelligence|Agility"));
        switch (com.parameters[2])
        {
        case 0:
            str = str.arg("+=");
            break;
        case 1:
            str = str.arg("-=");
            break;
        errorHandler(2);
        }
        switch (com.parameters[4])
        {
        case 0:
            str = str.arg(com.parameters[5]);
            break;
        case 1:
            vars(5);
            break;
        errorHandler(4);
        }
        break;
    case (Cmd::ChangeSkills):
        str = "%1 %2 Skill[%3]";
        chkLenght(5);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(2, tr("learns|forgets"));
        switch (com.parameters[3])
        {
        case 0:
            skill(4);
            break;
        case 1:
            vars(4);
            break;
        errorHandler(3);
        }
        break;
    case (Cmd::ChangeEquipment):
        str = "%1 %2 Item[%3]";
        chkLenght(5);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(2, tr("equips|unequips"));
        switch (com.parameters[2])
        {
        case 0:
        {
            switch (com.parameters[3])
            {
            case 0:
                item(4);
                break;
            case 1:
                vars(4);
                break;
                errorHandler(3);
            }
        }
            break;
        case 1:
            fromList(3,"Weapon|Shield|Armor|Helmet|Accesory|All");
            break;
        errorHandler(2);
        }
        break;
    case (Cmd::ChangeHP):
        str = "%1.HP %2 %3";
        chkLenght(6);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(2, "+=|-=");
        switch (com.parameters[3])
        {
        case 0:
            str = str.arg(com.parameters[4]);
            break;
        case 1:
            vars(4);
            break;
        errorHandler(3);
        }
        switch (com.parameters[5])
        {
        case 0:
            break;
        case 1:
            if (com.parameters[2] == 1)
                str += tr(" [CanKillTarget]");
            break;
        errorHandler(5);
        }
        break;
    case (Cmd::ChangeSP):
        str = "%1.MP %2 %3";
        chkLenght(5);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(2, "+=|-=");
        switch (com.parameters[3])
        {
        case 0:
            str = str.arg(com.parameters[4]);
            break;
        case 1:
            vars(4);
            break;
        errorHandler(3);
        }
        break;
    case (Cmd::ChangeCondition):
        str = tr("%1.Conditions %2 Condition[%3]");
        chkLenght(4);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
        fromList(2, "+=|-=");
        condition(3);
        break;
    case (Cmd::FullHeal):
        str = tr("%1 heals completely");
        chkLenght(2);
        switch (com.parameters[0])
        {
        case 0:
            str = str.arg(tr("EntireParty"));
            break;
        case 1:
            str = str.arg(tr("Hero[%1]"));
            hero(1);
            break;
        case 2:
            str = str.arg(tr("Hero[%1]"));
            vars(1);
            break;
        errorHandler(0);
        }
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
        chkLenght(0);
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
#undef chkLenght
#undef errorHandler
#undef fromList
#undef vars
#undef indexedVar
#undef switches
#undef indexedSwitch
#undef hero
#undef item
}
