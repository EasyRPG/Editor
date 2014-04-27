#include "qdbpageactors.h"
#include "ui_qdbpageactors.h"

QDbPageActors::QDbPageActors(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageActors),
    m_data(database)
{
    ui->setupUi(this);

    m_currentActor = 0;

    for (unsigned int i = 0; i < m_data.actors.size(); i++)
        ui->listCharacters->addItem(QString("%1: %2")
                               .arg(QString::number(i+1), 4, QLatin1Char('0'))
                               .arg(m_data.actors[i].name.c_str()));
    UpdateModels();
}

QDbPageActors::~QDbPageActors()
{
    delete ui;
}

void QDbPageActors::UpdateModels()
{
    /* Clear */
    ui->comboBattleset->clear();
    ui->comboProfession->clear();
    ui->comboUnarmedAnimation->clear();
    ui->listAttributeRanks->clear();
    ui->listStatusRanks->clear();
    /* Fill */
    ui->comboBattleset->addItem(tr("<none>"));
    for (unsigned int i = 0; i < m_data.battleranimations.size(); i++)
        ui->comboBattleset->addItem(m_data.battleranimations[i].name.c_str());
    ui->comboProfession->addItem(tr("<none>"));
    for (unsigned int i = 0; i < m_data.classes.size(); i++)
        ui->comboProfession->addItem(m_data.classes[i].name.c_str());
    ui->comboUnarmedAnimation->addItem(tr("<none>"));
    for (unsigned int i = 0; i < m_data.animations.size(); i++)
        ui->comboUnarmedAnimation->addItem(m_data.animations[i].name.c_str());
    for (unsigned int i = 0; i < m_data.attributes.size(); i++)
        ui->listAttributeRanks->addItem(m_data.attributes[i].name.c_str());
    for (unsigned int i = 0; i < m_data.states.size(); i++)
        ui->listStatusRanks->addItem(m_data.states[i].name.c_str());
}

void QDbPageActors::on_currentActorChanged(RPG::Actor *actor)
{
    m_currentActor = actor;
    if (actor == 0){
        /* Clear widgets */
        ui->lineName->clear();
        ui->lineTitle->clear();
        ui->spinCritChance->setValue(30);
        ui->spinMaxLv->setValue(99);
        ui->spinMinLv->setValue(1);
        ui->checkAI->setChecked(false);
        ui->checkDualWeapon->setChecked(false);
        ui->checkFixedEquip->setChecked(false);
        ui->checkStrongDefense->setChecked(false);
        ui->checkTranslucent->setChecked(false);
        ui->groupCritChance->setChecked(false);
        ui->comboBattleset->setCurrentIndex(0);
        ui->comboInitialArmor->clear();
        ui->comboInitialHelmet->clear();
        ui->comboInitialMisc->clear();
        ui->comboInitialWeapon->clear();
        ui->comboInitialShield->clear();
        ui->comboProfession->setCurrentIndex(0);
        ui->comboUnarmedAnimation->setCurrentIndex(0);
        ui->tableSkills->setRowCount(0);
        for (int i = 0; i < ui->listAttributeRanks->count(); i++)
            ui->listAttributeRanks->item(i)->setIcon(QIcon());
        for (int i = 0; i < ui->listStatusRanks->count(); i++)
            ui->listStatusRanks->item(i)->setIcon(QIcon());
        /* Disable widgets */
        ui->lineName->setEnabled(false);
        ui->lineTitle->setEnabled(false);
        ui->spinMaxLv->setEnabled(false);
        ui->spinMinLv->setEnabled(false);
        ui->checkAI->setEnabled(false);
        ui->checkDualWeapon->setEnabled(false);
        ui->checkFixedEquip->setEnabled(false);
        ui->checkStrongDefense->setEnabled(false);
        ui->checkTranslucent->setEnabled(false);
        ui->groupCritChance->setEnabled(false);
        ui->comboBattleset->setEnabled(false);
        ui->comboInitialArmor->setEnabled(false);
        ui->comboInitialHelmet->setEnabled(false);
        ui->comboInitialMisc->setEnabled(false);
        ui->comboInitialWeapon->setEnabled(false);
        ui->comboInitialShield->setEnabled(false);
        ui->comboProfession->setEnabled(false);
        ui->comboUnarmedAnimation->setEnabled(false);
        ui->tableSkills->setEnabled(false);
        ui->listAttributeRanks->setEnabled(false);
        ui->listStatusRanks->setEnabled(false);
        ui->pushApplyProfession->setEnabled(false);
        ui->pushExpCurveEdit->setEnabled(false);
        ui->pushSetCharset->setEnabled(false);
        ui->pushSetFace->setEnabled(false);
        ui->pushEditCustom->setEnabled(false);
        return;
    }

    /* Fill widgets data */
    ui->lineName->setText(actor->name.c_str());
    ui->lineTitle->setText(actor->title.c_str());
    ui->spinCritChance->setValue(actor->critical_hit_chance);
    ui->spinMaxLv->setValue(actor->final_level);
    ui->spinMinLv->setValue(actor->initial_level);
    ui->checkAI->setChecked(actor->auto_battle);
    ui->checkDualWeapon->setChecked(actor->two_swords_style);
    ui->checkFixedEquip->setChecked(actor->fix_equipment);
    ui->checkStrongDefense->setChecked(actor->super_guard);
    ui->checkTranslucent->setChecked(actor->transparent);
    ui->groupCritChance->setChecked(actor->critical_hit);
    ui->comboBattleset->setCurrentIndex(actor->battler_animation);
    ui->comboInitialArmor->clear();
    ui->comboInitialHelmet->clear();
    ui->comboInitialMisc->clear();
    ui->comboInitialShield->clear();
    ui->comboInitialWeapon->clear();
    ui->comboInitialArmor->addItem(tr("<none>"), 0);
    ui->comboInitialHelmet->addItem(tr("<none>"), 0);
    ui->comboInitialMisc->addItem(tr("<none>"), 0);
    ui->comboInitialShield->addItem(tr("<none>"), 0);
    ui->comboInitialWeapon->addItem(tr("<none>"), 0);
    for (unsigned int i = 0; i < m_data.items.size(); i++)
    {
        /* Check if hero can use item*/
        if (actor->ID <= (int) m_data.items[i].actor_set.size() &&
                !m_data.items[i].actor_set[actor->ID-1])
            if (actor->class_id <= 0 ||
                    (actor->class_id >= (int) m_data.items[i].class_set.size() &&
                     !m_data.items[i].class_set[actor->class_id-1]))
                continue;

        switch (m_data.items[i].type)
        {
        case RPG::Item::Type_armor:
            ui->comboInitialArmor->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
            if (actor->initial_equipment.armor_id == m_data.items[i].ID)
                ui->comboInitialArmor->setCurrentIndex(ui->comboInitialArmor->count()-1);
            break;
        case RPG::Item::Type_helmet:
            ui->comboInitialHelmet->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
            if (actor->initial_equipment.helmet_id == m_data.items[i].ID)
                ui->comboInitialHelmet->setCurrentIndex(ui->comboInitialHelmet->count()-1);
            break;
        case RPG::Item::Type_accessory:
            ui->comboInitialMisc->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
            if (actor->initial_equipment.accessory_id == m_data.items[i].ID)
                ui->comboInitialMisc->setCurrentIndex(ui->comboInitialMisc->count()-1);
            break;
        case RPG::Item::Type_shield:
            ui->comboInitialShield->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
            if (actor->initial_equipment.shield_id == m_data.items[i].ID)
                ui->comboInitialShield->setCurrentIndex(ui->comboInitialShield->count()-1);
            break;
        case RPG::Item::Type_weapon:
            ui->comboInitialWeapon->addItem(m_data.items[i].name.c_str(), m_data.items[i].ID);
            if (actor->initial_equipment.weapon_id == m_data.items[i].ID)
                ui->comboInitialWeapon->setCurrentIndex(ui->comboInitialWeapon->count()-1);
            break;
        }
    }
    ui->comboProfession->setCurrentIndex(actor->class_id);
    ui->comboUnarmedAnimation->setCurrentIndex(actor->unarmed_animation);
    ui->tableSkills->setRowCount(0);
    for (unsigned int i = 0; i < actor->skills.size(); i++){
        ui->tableSkills->insertRow(i);
        ui->tableSkills->setItem(i,0,new QTableWidgetItem());
        ui->tableSkills->setItem(i,1,new QTableWidgetItem());
        ui->tableSkills->item(i, 0)->setText(QString::number(actor->skills[i].level));
        // TODO: move getSkillName to Core
        QString name = QString("<%1?>").arg(actor->skills[i].skill_id);
        if (i < m_data.skills.size())
            name = m_data.skills[i].name.c_str();
        // TODO/
        ui->tableSkills->item(i, 1)->setText(name);
    }
    ui->tableSkills->insertRow((int)actor->skills.size());
    for (int i = 0; i < ui->listAttributeRanks->count(); i++)
    {
        if (i >= (int)actor->attribute_ranks.size())
            ui->listAttributeRanks->item(i)->setIcon(QIcon(":/embedded/share/old_rank2.png"));
        else
            ui->listAttributeRanks->item(i)->setIcon(QIcon(QString(":/embedded/share/old_rank%1.png").arg((int)actor->attribute_ranks[i])));
    }
    for (int i = 0; i < ui->listStatusRanks->count(); i++)
    {
        if (i >= (int)actor->state_ranks.size())
            ui->listStatusRanks->item(i)->setIcon(QIcon(":/embedded/share/old_rank2.png"));
        else
            ui->listStatusRanks->item(i)->setIcon(QIcon(QString(":/embedded/share/old_rank%1.png").arg((int)actor->state_ranks[i])));
    }

    /* Enable widgets */
    ui->lineName->setEnabled(true);
    ui->lineTitle->setEnabled(true);
    ui->spinMaxLv->setEnabled(true);
    ui->spinMinLv->setEnabled(true);
    ui->checkAI->setEnabled(true);
    ui->checkDualWeapon->setEnabled(true);
    ui->checkFixedEquip->setEnabled(true);
    ui->checkStrongDefense->setEnabled(true);
    ui->checkTranslucent->setEnabled(true);
    ui->groupCritChance->setEnabled(true);
    ui->comboBattleset->setEnabled(true);
    ui->comboInitialArmor->setEnabled(true);
    ui->comboInitialHelmet->setEnabled(true);
    ui->comboInitialMisc->setEnabled(true);
    ui->comboInitialWeapon->setEnabled(true);
    ui->comboInitialShield->setEnabled(true);
    ui->comboProfession->setEnabled(true);
    ui->comboUnarmedAnimation->setEnabled(true);
    ui->tableSkills->setEnabled(true);
    ui->listAttributeRanks->setEnabled(true);
    ui->listStatusRanks->setEnabled(true);
    ui->pushApplyProfession->setEnabled(true);
    ui->pushExpCurveEdit->setEnabled(true);
    ui->pushSetCharset->setEnabled(true);
    ui->pushSetFace->setEnabled(true);
    ui->pushEditCustom->setEnabled(true);
}

void QDbPageActors::on_listCharacters_currentRowChanged(int currentRow)
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
