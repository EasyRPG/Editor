#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"
#include <QPushButton>
#include <QInputDialog>

DialogDataBase::DialogDataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDataBase)
{
    ui->setupUi(this);
    m_data = Data::data;
    m_currentActor = 0;
    on_currentActorChanged(0);
    Old_PageActors = new QDbPageActors(m_data, this);
    ui->tabOld_Pages->insertTab(0, Old_PageActors, tr("Characters"));
    ui->tabOld_Pages->setCurrentWidget(Old_PageActors);
    ui->stackedStyle->setCurrentWidget(ui->pageOld);
    /* Fill Characters list */
    for (unsigned int i = 0; i < Data::actors.size(); i++)
        ui->listNew_Character->addItem(QString("%1:%2")
                                   .arg(QString::number(i+1), 4, QLatin1Char('0'))
                                   .arg(Data::actors[i].name.c_str()));
}

DialogDataBase::~DialogDataBase()
{
    delete ui;
}

void DialogDataBase::on_currentActorChanged(RPG::Actor *actor)
{
    m_currentActor = actor;
    if (actor == 0){
        /* Clear Table */
        for (int i = 0; i < ui->tableNew_CharacterProperties->rowCount(); i++)
            ui->tableNew_CharacterProperties->item(i,1)->setText("");
        /* Disable Table */
        ui->tableNew_CharacterProperties->setEnabled(false);
        return;
    }

    /* Fill Table */
    QString yes = tr("YES");
    QString no = tr("NO");
    ui->tableNew_CharacterProperties->item(0,1)->setText(actor->name.c_str());
    ui->tableNew_CharacterProperties->item(1,1)->setText(actor->title.c_str());
    ui->tableNew_CharacterProperties->item(2,1)->setText(QString::number(actor->initial_level));
    ui->tableNew_CharacterProperties->item(3,1)->setText(QString::number(actor->final_level));
    ui->tableNew_CharacterProperties->item(4,1)->setText(actor->critical_hit ? yes : no);
    ui->tableNew_CharacterProperties->item(5,1)->setText(tr("1 of %1 turns").arg(actor->critical_hit_chance));
    ui->tableNew_CharacterProperties->item(6,1)->setText(actor->two_swords_style ? yes :no);
    ui->tableNew_CharacterProperties->item(7,1)->setText(actor->fix_equipment ? yes :no);
    ui->tableNew_CharacterProperties->item(8,1)->setText(actor->auto_battle ? yes :no);
    ui->tableNew_CharacterProperties->item(9,1)->setText(actor->super_guard ? yes :no);
    ui->tableNew_CharacterProperties->item(10,1)->setText(actor->class_id < 1 ? tr("<none>") :
                                                          actor->class_id >= (int)m_data.classes.size() ?
                                                          tr("<%1?>").arg(actor->class_id) :
                                                          m_data.classes[actor->class_id-1].name.c_str());
    ui->tableNew_CharacterProperties->item(11,1)->setText(QString("%1[%2]")
                                                          .arg(actor->face_name.c_str())
                                                          .arg(actor->face_index));
    ui->tableNew_CharacterProperties->item(12,1)->setText(QString("%1[%2]%3")
                                                          .arg(actor->character_name.c_str())
                                                          .arg(actor->character_index)
                                                          .arg(actor->transparent ? " [Transparent]" : ""));
    ui->tableNew_CharacterProperties->item(13,1)->setText(actor->battler_animation < 1 ? tr("<none>") :
                                                          actor->battler_animation >= (int)m_data.battleranimations.size() ?
                                                          tr("<%1?>").arg(actor->battler_animation) :
                                                          m_data.battleranimations[actor->battler_animation-1].name.c_str());

    /* TODO: fill the following information */
    ui->tableNew_CharacterProperties->item(14,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(15,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(16,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(17,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(18,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(19,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(20,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(21,1)->setText("ItemName");
    ui->tableNew_CharacterProperties->item(22,1)->setText("ItemName");
    ui->tableNew_CharacterProperties->item(23,1)->setText("ItemName");
    ui->tableNew_CharacterProperties->item(24,1)->setText("ItemName");
    ui->tableNew_CharacterProperties->item(25,1)->setText("ItemName");
    ui->tableNew_CharacterProperties->item(26,1)->setText("AnimName");
    ui->tableNew_CharacterProperties->item(27,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(28,1)->setText("Click to Edit");
    ui->tableNew_CharacterProperties->item(29,1)->setText("Click to Edit");

    /* Enable Table */
    ui->tableNew_CharacterProperties->setEnabled(true);
}

void DialogDataBase::on_tabOld_Pages_currentChanged(int index)
{
    ui->listNew_Pages->setCurrentRow(index);
    emit ui->listNew_Pages->currentRowChanged(index);
}

void DialogDataBase::on_toolSwitchStyle_clicked(bool checked)
{
    ui->stackedStyle->setCurrentIndex((int)checked);
}

void DialogDataBase::on_pushNew_CharacterMax_clicked()
{
    /* TODO: resize characters */
}

void DialogDataBase::on_lineNew_CharacterFilter_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->listNew_Character->count(); i++)
        ui->listNew_Character->item(i)->setHidden(ui->listNew_Character->item(i)->text().contains(arg1,Qt::CaseInsensitive));
}

void DialogDataBase::on_listNew_Character_currentRowChanged(int currentRow)
{
    if (currentRow < 0 || currentRow >= (int)m_data.actors.size())
    {
        on_currentActorChanged(0);
        emit currentActorChanged(0);
        return; //invalid
    }

    on_currentActorChanged(&m_data.actors[currentRow]);
    emit currentActorChanged(&m_data.actors[currentRow]);
}
