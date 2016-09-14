#include "qeventpagewidget.h"
#include "ui_qeventpagewidget.h"
#include <QDialogButtonBox>
#include <data.h>
#include "../dialogcharapicker.h"
#include "../core.h"
#include "../stringizer.h"

QEventPageWidget::QEventPageWidget(QWidget *parent) :
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
    ui->treeCommands->header()->hide();
    ui->treeCommands->setMouseTracking(true);
}

QEventPageWidget::~QEventPageWidget()
{
    delete m_tileItem;
    delete m_charaItem;
    delete ui;
}
RPG::EventPage *QEventPageWidget::eventPage() const
{
    return m_eventPage;
}

void QEventPageWidget::setEventPage(RPG::EventPage *eventPage)
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
    ui->checkOverlapForbidden->setChecked(eventPage->overlap_forbidden);
    ui->comboAnimationType->setCurrentIndex(eventPage->animation_type);
    ui->comboMoveFrequency->setCurrentIndex(eventPage->move_frequency-1);
    m_effect->setEnabled(m_eventPage->translucent);
    updateGraphic();

    m_codeGen = 0;
    QTreeWidgetItem *parent = 0;
    for (unsigned int i = 0; i < m_eventPage->event_commands.size(); i++)
    {
        const RPG::EventCommand& command = m_eventPage->event_commands[i];
        QTreeWidgetItem *item = new QTreeWidgetItem({Stringizer::stringize(command),
                                                     QString::number(m_codeGen)});
        item->setToolTip(0, tr("Line") + ": " + QString::number(m_codeGen+1));

        if (command.code == Cmd::ShowChoiceOption && command.parameters[0] != 0)
            parent = parent->parent();
        if (command.code == Cmd::ShowChoiceEnd)
        {
            parent = parent->parent()->parent();
            continue;
        }
        if (parent)
        {
            switch (command.code)
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
        switch (command.code)
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


void QEventPageWidget::on_comboMoveType_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    ui->label->setEnabled(index != 0);
    ui->comboMoveSpeed->setEnabled(index != 0);
    m_eventPage->move_type = index;
}

void QEventPageWidget::on_checkSwitchA_toggled(bool checked)
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

void QEventPageWidget::on_checkSwitchB_toggled(bool checked)
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

void QEventPageWidget::on_checkVar_toggled(bool checked)
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

void QEventPageWidget::on_checkItem_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.item = checked;
}

void QEventPageWidget::on_comboVarOperation_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.compare_operator = index;
}

void QEventPageWidget::on_spinVarValue_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.variable_value = arg1;
}

void QEventPageWidget::on_comboItem_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.item_id = index+1;
}

void QEventPageWidget::on_comboHero_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.actor_id = index+1;
}

void QEventPageWidget::on_checkHero_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.item = checked;
}

void QEventPageWidget::on_checkTimerA_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.timer = checked;
}

void QEventPageWidget::on_spinTimerAMin_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer_sec = arg1*60 + ui->spinTimerASec->value();
}

void QEventPageWidget::on_spinTimerASec_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer_sec = ui->spinTimerAMin->value()*60 + arg1;
}

void QEventPageWidget::on_checkTimerB_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.flags.timer2 = checked;
}

void QEventPageWidget::on_spinTimerBMin_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer2_sec = arg1*60 + ui->spinTimerBSec->value();
}

void QEventPageWidget::on_spinTimerBSec_valueChanged(int arg1)
{
    if (!m_eventPage)
        return;
    m_eventPage->condition.timer2_sec = ui->spinTimerBMin->value()*60 + arg1;
}

void QEventPageWidget::on_checkTransparent_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->translucent = checked;
    m_effect->setEnabled(checked);
}

void QEventPageWidget::on_comboMoveSpeed_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->move_speed = index+1;
}

void QEventPageWidget::on_comboCondition_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->trigger = index;
}

void QEventPageWidget::on_comboLayer_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->layer = index;
}

void QEventPageWidget::on_checkOverlapForbidden_toggled(bool checked)
{
    if (!m_eventPage)
        return;
    m_eventPage->overlap_forbidden = checked;
}

void QEventPageWidget::on_comboAnimationType_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->animation_type = index;
}

void QEventPageWidget::on_comboMoveFrequency_currentIndexChanged(int index)
{
    if (!m_eventPage)
        return;
    m_eventPage->move_frequency = index+1;
}

void QEventPageWidget::on_pushSetSprite_clicked()
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



void QEventPageWidget::updateGraphic()
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
