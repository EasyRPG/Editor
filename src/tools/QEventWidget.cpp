#include "qeventwidget.h"
#include "ui_qeventwidget.h"
#include <QDialogButtonBox>
#include <data.h>
#include "../dialogcharapicker.h"
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
                                        << QString::number(m_codeGen)
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
        m_codeGen++;
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
    QStringList options;

    QString str = m_strCache[com.code][0][0];
    QString aux;
    QString i_str;
    int enum_id = 1;
    for (unsigned int i = 0; i < com.parameters.size(); i++)
    {
        i_str = QString::number(i);
        if (str.contains("%e"+i_str))
        {
            if (com.parameters[i] < 0 || com.parameters[i] >= m_strCache[com.code][enum_id].count())
                str = str.arg(QString("error: cmd.par[%1] == %2").arg(i).arg(com.parameters[i]));
            else
            {
                aux = m_strCache[com.code][enum_id][com.parameters[i]];
                if (aux.contains("#"))
                    aux = aux.split("#")[com.parameters[i-1]];
                str.replace("%e"+i_str, aux);
            }
            enum_id++;
            continue;
        }
        if (str.contains("%op"+i_str))
        {
            str.remove("%op"+i_str);
            if (!m_strCache[com.code][enum_id][com.parameters[i]].isEmpty())
                options << m_strCache[com.code][enum_id][com.parameters[i]];
            enum_id++;
            continue;
        }
        if (str.contains("%n"+i_str))
        {
            str.replace("%n"+i_str, QString::number(com.parameters[i]));
            continue;
        }
        if (str.contains("%v"+i_str))
        {
            aux = varName(com.parameters[i]);
            if (aux.isEmpty())
                str.replace("%v"+i_str, QString::number(com.parameters[i]));
            else
                str.replace("%v"+i_str, QString("%1:%2").arg(com.parameters[i]).arg(aux));
            continue;
        }
        if (str.contains("%b"+i_str))
        {
            aux = switchName(com.parameters[i]);
            if (aux.isEmpty())
                str.replace("%b"+i_str, QString::number(com.parameters[i]));
            else
                str.replace("%b"+i_str, QString("%1:%2").arg(com.parameters[i]).arg(aux));
            continue;
        }
        if (str.contains("%i"+i_str))
        {
            str.replace("%i"+i_str, itemName(com.parameters[i]));
            continue;
        }
        if (str.contains("%h"+i_str))
        {
            str.replace("%h"+i_str, heroName(com.parameters[i]));
            continue;
        }
        if (str.contains("%hs"+i_str))
        {
            str.replace("%hs"+i_str, heroStats[com.parameters[i]]);
            continue;
        }
        if (str.contains("%ic"+i_str))
        {
            str.replace("%ic"+i_str, itemCount[com.parameters[i]]);
            continue;
        }
        if (str.contains("%sk"+i_str))
        {
            str.replace("%sk"+i_str, skillName(com.parameters[i]));
            continue;
        }
        if (str.contains("%tr"+i_str))
        {
            str.replace("%tr"+i_str, troopName(com.parameters[i]));
            continue;
        }
        if (str.contains("%gr"+i_str))
        {
            str.replace("%gr"+i_str, terrainName(com.parameters[i]));
            continue;
        }
        if (str.contains("%m"+i_str))
        {
            str.replace("%m"+i_str, mapName(com.parameters[i]));
            continue;
        }
        if (str.contains("%sl"+i_str) && com.parameters[i] > 10000)
        {
            str.replace("%sl"+i_str, spriteList[com.parameters[i]-10001]);
            continue;
        }
        else if (str.contains("%sl%1"+i_str) && com.parameters[i] < 10001)
        {
            str.replace("%sl"+i_str, eventName(com.parameters[i]));
            continue;
        }
        if (str.contains("%sp"+i_str))
        {
            str.replace("%sp"+i_str, spriteParameters[com.parameters[i]]);
            continue;
        }
        if (str.contains("%o"+i_str))
        {
            str.replace("%o"+i_str, others[com.parameters[i]]);
            continue;
        }
        if (str.contains("%c"+i_str))
        {
            str.replace("%c"+i_str, conditionName(com.parameters[i]));
            continue;
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

QString QEventWidget::troopName(int id)
{
    if (id < 1 || id > (int)Data::troops.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::troops[id-1].name);
}

QString QEventWidget::terrainName(int id)
{
    if (id < 1 || id > (int)Data::terrains.size())
        return QString("<%1?>").arg(id);
    return QString::fromStdString(Data::terrains[id-1].name);
}

QString QEventWidget::mapName(int id)
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

