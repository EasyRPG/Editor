#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"
#include <QPushButton>
#include <QInputDialog>
#include <sstream>
#include <iomanip>

DialogDataBase::DialogDataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDataBase)
{
    ui->setupUi(this);
    current_character = 0;
    UpdateCharacterWidgets();
}

DialogDataBase::~DialogDataBase()
{
    delete ui;
}

void DialogDataBase::UpdateCharacterWidgets()
{
    if (current_character == 0){
        /* ClearWidgets */
        for (int i = 0; i < ui->tableNew_CharacterProperties->rowCount(); i++)
            ui->tableNew_CharacterProperties->item(i,1)->setText("");
        ui->lineOld_CharacterName->clear();
        ui->lineOld_CharacterTitle->clear();
        ui->spinOld_CharacterCritChance->setValue(30);
        ui->spinOld_CharacterMaxLv->setValue(99);
        ui->spinOld_CharacterMinLv->setValue(1);
        ui->checkOld_CharacterAI->setChecked(false);
        ui->checkOld_CharacterDualWeapon->setChecked(false);
        ui->checkOld_CharacterFixedEquip->setChecked(false);
        ui->checkOld_CharacterStrongDefense->setChecked(false);
        ui->checkOld_CharacterTranslucent->setChecked(false);
        ui->groupOld_CharacterCritChance->setChecked(false);
        ui->comboOld_CharacterBattleset->setCurrentIndex(0);
        ui->comboOld_CharacterInitialArmor->setCurrentIndex(0);
        ui->comboOld_CharacterInitialHelmet->setCurrentIndex(0);
        ui->comboOld_CharacterInitialMisc->setCurrentIndex(0);
        ui->comboOld_CharacterInitialWeapon->setCurrentIndex(0);
        ui->comboOld_CharacterInitialShield->setCurrentIndex(0);
        ui->comboOld_CharacterProfession->setCurrentIndex(0);
        ui->comboOld_CharacterUnarmedAnimation->setCurrentIndex(0);
        ui->tableOld_CharacterSkills->setRowCount(0);
        ui->listOld_CharacterAttributeRanks->clear();
        ui->listOld_CharacterStatusRanks->clear();
        /* Disable Widgets */
        ui->tableNew_CharacterProperties->setEnabled(false);
        ui->lineOld_CharacterName->setEnabled(false);
        ui->lineOld_CharacterTitle->setEnabled(false);
        ui->spinOld_CharacterMaxLv->setEnabled(false);
        ui->spinOld_CharacterMinLv->setEnabled(false);
        ui->checkOld_CharacterAI->setEnabled(false);
        ui->checkOld_CharacterDualWeapon->setEnabled(false);
        ui->checkOld_CharacterFixedEquip->setEnabled(false);
        ui->checkOld_CharacterStrongDefense->setEnabled(false);
        ui->checkOld_CharacterTranslucent->setEnabled(false);
        ui->groupOld_CharacterCritChance->setEnabled(false);
        ui->comboOld_CharacterBattleset->setEnabled(false);
        ui->comboOld_CharacterInitialArmor->setEnabled(false);
        ui->comboOld_CharacterInitialHelmet->setEnabled(false);
        ui->comboOld_CharacterInitialMisc->setEnabled(false);
        ui->comboOld_CharacterInitialWeapon->setEnabled(false);
        ui->comboOld_CharacterInitialShield->setEnabled(false);
        ui->comboOld_CharacterProfession->setEnabled(false);
        ui->comboOld_CharacterUnarmedAnimation->setEnabled(false);
        ui->tableOld_CharacterSkills->setEnabled(false);
        ui->listOld_CharacterAttributeRanks->setEnabled(false);
        ui->listOld_CharacterStatusRanks->setEnabled(false);
        ui->pushOld_CharacterApplyProfession->setEnabled(false);
        ui->pushOld_CharacterExpCurveEdit->setEnabled(false);
        ui->pushOld_CharacterSetCharset->setEnabled(false);
        ui->pushOld_CharacterSetFace->setEnabled(false);
        ui->pushOld_CharacterEditCustom->setEnabled(false);
        return;
    }

    ui->tableNew_CharacterProperties->item(0,1)->setText(current_character->name());
    ui->tableNew_CharacterProperties->item(1,1)->setText(current_character->title());
    ui->tableNew_CharacterProperties->item(2,1)->setText(QString::number(current_character->minlvl()));
    ui->tableNew_CharacterProperties->item(3,1)->setText(QString::number(current_character->maxlvl()));
    ui->tableNew_CharacterProperties->item(4,1)->setText(current_character->docritical() ? "YES" : "NO");
    ui->tableNew_CharacterProperties->item(5,1)->setText(tr("1 of ") + QString::number(current_character->critical())+ tr(" turns"));
    ui->tableNew_CharacterProperties->item(6,1)->setText(current_character->dualweapons() ? "YES" :"NO");
    ui->tableNew_CharacterProperties->item(7,1)->setText(current_character->fixedequip() ? "YES" :"NO");
    ui->tableNew_CharacterProperties->item(8,1)->setText(current_character->ai() ? "YES" :"NO");
    ui->tableNew_CharacterProperties->item(9,1)->setText(current_character->strongdefense() ? "YES" :"NO");
    ui->tableNew_CharacterProperties->item(10,1)->setText("PROFESSION NAME" /*profesions[current_character->profession()].name()*/);
    ui->tableNew_CharacterProperties->item(11,1)->setText("FaceName [Index]" /*facesets[current_character->face().faceset].name() + QString::number(current_character->face().faceindex)*/);
    ui->tableNew_CharacterProperties->item(12,1)->setText("CharaName [Index] [TRANSLUCENT: NO]");
    ui->tableNew_CharacterProperties->item(13,1)->setText("BattlerName");
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
    /* TODO: fill custom properties table values */
    ui->lineOld_CharacterName->setText(current_character->name());
    ui->lineOld_CharacterTitle->setText(current_character->title());
    ui->spinOld_CharacterCritChance->setValue(current_character->critical());
    ui->spinOld_CharacterMaxLv->setValue(current_character->maxlvl());
    ui->spinOld_CharacterMinLv->setValue(current_character->minlvl());
    ui->checkOld_CharacterAI->setChecked(current_character->ai());
    ui->checkOld_CharacterDualWeapon->setChecked(current_character->dualweapons());
    ui->checkOld_CharacterFixedEquip->setChecked(current_character->fixedequip());
    ui->checkOld_CharacterStrongDefense->setChecked(current_character->strongdefense());
    ui->checkOld_CharacterTranslucent->setChecked(current_character->charatranslucent());
    ui->groupOld_CharacterCritChance->setChecked(current_character->docritical());
    ui->comboOld_CharacterBattleset->setCurrentIndex(current_character->battleset() + 1);
    ui->comboOld_CharacterInitialArmor->setCurrentIndex(current_character->initialarmor() + 1);
    ui->comboOld_CharacterInitialHelmet->setCurrentIndex(current_character->initialhelmet() + 1);
    ui->comboOld_CharacterInitialMisc->setCurrentIndex(current_character->initialother() + 1);
    ui->comboOld_CharacterInitialWeapon->setCurrentIndex(current_character->initialweapon() + 1);
    ui->comboOld_CharacterInitialShield->setCurrentIndex(current_character->initialshield() + 1);
    ui->comboOld_CharacterProfession->setCurrentIndex(current_character->profession() + 1);
    ui->comboOld_CharacterUnarmedAnimation->setCurrentIndex(current_character->unarmedanimation() + 1);
    ui->tableOld_CharacterSkills->setRowCount(0);
    for (int i = 0; i < current_character->skilllist().count(); i++){
        ui->tableOld_CharacterSkills->insertRow(i);
        ui->tableOld_CharacterSkills->item(i, 0)->setText(QString::number(current_character->skills()->value(i)));
        ui->tableOld_CharacterSkills->item(i, 1)->setText("SKILL NAME" /*QString::number(current_character->skills()[i]->skill_id)*/);
    }
    ui->tableOld_CharacterSkills->insertRow(current_character->skilllist().count());
    ui->listOld_CharacterAttributeRanks->clear(); /*TODO: update this*/
    ui->listOld_CharacterStatusRanks->clear();
    /* Enable widgets */
    ui->tableNew_CharacterProperties->setEnabled(true);
    ui->lineOld_CharacterName->setEnabled(true);
    ui->lineOld_CharacterTitle->setEnabled(true);
    ui->spinOld_CharacterMaxLv->setEnabled(true);
    ui->spinOld_CharacterMinLv->setEnabled(true);
    ui->checkOld_CharacterAI->setEnabled(true);
    ui->checkOld_CharacterDualWeapon->setEnabled(true);
    ui->checkOld_CharacterFixedEquip->setEnabled(true);
    ui->checkOld_CharacterStrongDefense->setEnabled(true);
    ui->checkOld_CharacterTranslucent->setEnabled(true);
    ui->groupOld_CharacterCritChance->setEnabled(true);
    ui->comboOld_CharacterBattleset->setEnabled(true);
    ui->comboOld_CharacterInitialArmor->setEnabled(true);
    ui->comboOld_CharacterInitialHelmet->setEnabled(true);
    ui->comboOld_CharacterInitialMisc->setEnabled(true);
    ui->comboOld_CharacterInitialWeapon->setEnabled(true);
    ui->comboOld_CharacterInitialShield->setEnabled(true);
    ui->comboOld_CharacterProfession->setEnabled(true);
    ui->comboOld_CharacterUnarmedAnimation->setEnabled(true);
    ui->tableOld_CharacterSkills->setEnabled(true);
    ui->listOld_CharacterAttributeRanks->setEnabled(true);
    ui->listOld_CharacterStatusRanks->setEnabled(true);
    ui->pushOld_CharacterApplyProfession->setEnabled(true);
    ui->pushOld_CharacterExpCurveEdit->setEnabled(true);
    ui->pushOld_CharacterSetCharset->setEnabled(true);
    ui->pushOld_CharacterSetFace->setEnabled(true);
    ui->pushOld_CharacterEditCustom->setEnabled(true);
}
void DialogDataBase::on_toolSwitchStyle_clicked(bool checked)
{
    if (checked)
        ui->stackedStyle->setCurrentIndex(1);
    else
        ui->stackedStyle->setCurrentIndex(0);
}



void DialogDataBase::on_tabOld_Pages_currentChanged(int index)
{
    ui->listNew_Pages->setCurrentRow(index);
    emit ui->listNew_Pages->currentRowChanged(index);
}

void DialogDataBase::on_pushOld_CharacterMax_clicked()
{
    bool b_ok;
    int n_num = QInputDialog::getInt(this,"Change Maximum Number", "Maximum Number", ui->listOld_Character->count(), 1, 5000,1, &b_ok);
    if (b_ok){
        if (n_num < ui->listOld_Character->count())
            for (int i = ui->listOld_Character->count() - 1; i >= n_num; i--){
                QListWidgetItem *itm = ui->listOld_Character->takeItem(i);
                delete itm;
                itm = ui->listNew_Character->takeItem(i);
                delete itm;
                characters.remove(i);
            }
        else{
            std::stringstream ss;
            for (int i = ui->listOld_Character->count(); i < n_num; i++){
                ss.str("");
                ss << std::setfill('0') << std::setw(4) << i + 1 << ": ";
                ui->listOld_Character->insertItem(i, QString::fromStdString(ss.str()));
                ui->listNew_Character->insertItem(i, QString::fromStdString(ss.str()));
                characters.append(GameCharacter());
            }
        }
    }
}

void DialogDataBase::on_pushNew_CharacterMax_clicked()
{
    emit ui->pushOld_CharacterMax->clicked();
}

void DialogDataBase::on_lineNew_CharacterFilter_textChanged(const QString &arg1)
{
    ui->lineOld_CharacterFilter->setText(arg1);
    emit ui->lineOld_CharacterFilter->textChanged(arg1);
}

void DialogDataBase::on_lineOld_CharacterFilter_textChanged(const QString &arg1)
{
    ui->lineNew_CharacterFilter->setText(arg1);

    for (int i = 0; i < ui->listNew_Character->count(); i++){
        if (ui->listNew_Character->item(i)->text().contains(arg1)){
            ui->listNew_Character->item(i)->setHidden(false);
            ui->listOld_Character->item(i)->setHidden(false);
        }
        else {
            ui->listNew_Character->item(i)->setHidden(true);
            ui->listOld_Character->item(i)->setHidden(true);
        }

    }
}

void DialogDataBase::on_lineOld_CharacterName_textChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    int id  = ui->listOld_Character->currentRow();
    current_character->name(arg1);
    ui->tableNew_CharacterProperties->item(0, 1)->setText(arg1);
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << id+1 << ": " << characters[id].name().toStdString();
    ui->listNew_Character->item(id)->setText(QString::fromStdString(ss.str()));
    ui->listOld_Character->item(id)->setText(QString::fromStdString(ss.str()));
}

void DialogDataBase::on_listOld_Character_currentRowChanged(int currentRow)
{
    ui->listNew_Character->setCurrentRow(currentRow);
    current_character = &characters[currentRow];
    UpdateCharacterWidgets();
}

void DialogDataBase::on_lineOld_CharacterTitle_textChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    current_character->title(arg1);
    ui->tableNew_CharacterProperties->item(1,1)->setText(arg1);
}

void DialogDataBase::on_checkOld_CharacterAI_toggled(bool checked)
{
    if (current_character == 0)
        return;
    current_character->ai(checked);
    ui->tableNew_CharacterProperties->item(8,1)->setText(checked ? "YES" : "NO");
}

void DialogDataBase::on_checkOld_CharacterDualWeapon_toggled(bool checked)
{
    if (current_character == 0)
        return;
    current_character->dualweapons(checked);
    ui->tableNew_CharacterProperties->item(6,1)->setText(checked ? "YES" : "NO");
}

void DialogDataBase::on_checkOld_CharacterFixedEquip_toggled(bool checked)
{
    if (current_character == 0)
        return;
    current_character->fixedequip(checked);
    ui->tableNew_CharacterProperties->item(7,1)->setText(checked ? "YES" : "NO");
}

void DialogDataBase::on_checkOld_CharacterStrongDefense_toggled(bool checked)
{
    if (current_character == 0)
        return;
    current_character->strongdefense(checked);
    ui->tableNew_CharacterProperties->item(9,1)->setText(checked ? "YES" : "NO");
}

void DialogDataBase::on_groupOld_CharacterCritChance_toggled(bool arg1)
{
    if (current_character == 0)
        return;
    current_character->docritical(arg1);
    ui->tableNew_CharacterProperties->item(4,1)->setText(arg1 ? "YES" : "NO");
}

void DialogDataBase::on_spinOld_CharacterCritChance_valueChanged(int arg1)
{
    if (current_character == 0)
        return;
    current_character->critical(arg1);
    ui->tableNew_CharacterProperties->item(5,1)->setText(tr("1 of ") + QString::number(arg1)+ tr(" turns"));
}


void DialogDataBase::on_comboOld_CharacterProfession_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->profession(index);

}

void DialogDataBase::on_comboOld_CharacterProfession_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(10,1)->setText(arg1);
}

void DialogDataBase::on_spinOld_CharacterMinLv_valueChanged(int arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(2,1)->setText(QString::number(arg1));
    current_character->minlvl(arg1);
}

void DialogDataBase::on_spinOld_CharacterMaxLv_valueChanged(int arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(3,1)->setText(QString::number(arg1));
    current_character->maxlvl(arg1);
}

void DialogDataBase::on_comboOld_CharacterInitialWeapon_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->initialweapon(index);
}

void DialogDataBase::on_comboOld_CharacterInitialWeapon_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(21,1)->setText(arg1);
}



void DialogDataBase::on_comboOld_CharacterInitialShield_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->initialshield(index);
}

void DialogDataBase::on_comboOld_CharacterInitialShield_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(22,1)->setText(arg1);
}

void DialogDataBase::on_comboOld_CharacterInitialArmor_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->initialarmor(index);
}

void DialogDataBase::on_comboOld_CharacterInitialArmor_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(23,1)->setText(arg1);
}

void DialogDataBase::on_comboOld_CharacterInitialHelmet_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->initialhelmet(index);
}

void DialogDataBase::on_comboOld_CharacterInitialHelmet_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(24,1)->setText(arg1);
}

void DialogDataBase::on_comboOld_CharacterInitialMisc_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->initialother(index);

}

void DialogDataBase::on_comboOld_CharacterInitialMisc_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(25,1)->setText(arg1);
}

void DialogDataBase::on_comboOld_CharacterUnarmedAnimation_currentIndexChanged(int index)
{
    if (current_character == 0)
        return;
    index--;
    current_character->unarmedanimation(index);
}

void DialogDataBase::on_comboOld_CharacterUnarmedAnimation_currentIndexChanged(const QString &arg1)
{
    if (current_character == 0)
        return;
    ui->tableNew_CharacterProperties->item(26,1)->setText(arg1);
}
