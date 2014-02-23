#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>
#include "gamecharacter.h"

namespace Ui {
class DialogDataBase;
}

class DialogDataBase : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDataBase(QWidget *parent = 0);
    ~DialogDataBase();

    void UpdateCharacterWidgets();
    
private slots:

    void on_toolSwitchStyle_clicked(bool checked);

    void on_tabOld_Pages_currentChanged(int index);

    void on_pushOld_CharacterMax_clicked();

    void on_lineNew_CharacterFilter_textChanged(const QString &arg1);

    void on_lineOld_CharacterFilter_textChanged(const QString &arg1);

    void on_pushNew_CharacterMax_clicked();

    void on_lineOld_CharacterName_textChanged(const QString &arg1);

    void on_listOld_Character_currentRowChanged(int currentRow);

    void on_lineOld_CharacterTitle_textChanged(const QString &arg1);

    void on_checkOld_CharacterAI_toggled(bool checked);

    void on_checkOld_CharacterDualWeapon_toggled(bool checked);

    void on_checkOld_CharacterFixedEquip_toggled(bool checked);

    void on_checkOld_CharacterStrongDefense_toggled(bool checked);

    void on_groupOld_CharacterCritChance_toggled(bool arg1);

    void on_spinOld_CharacterCritChance_valueChanged(int arg1);

    void on_comboOld_CharacterProfession_currentIndexChanged(int index);

    void on_comboOld_CharacterProfession_currentIndexChanged(const QString &arg1);

    void on_spinOld_CharacterMinLv_valueChanged(int arg1);

    void on_spinOld_CharacterMaxLv_valueChanged(int arg1);

    void on_comboOld_CharacterInitialWeapon_currentIndexChanged(int index);

    void on_comboOld_CharacterInitialWeapon_currentIndexChanged(const QString &arg1);

    void on_comboOld_CharacterInitialShield_currentIndexChanged(int index);

    void on_comboOld_CharacterInitialShield_currentIndexChanged(const QString &arg1);

    void on_comboOld_CharacterInitialArmor_currentIndexChanged(int index);

    void on_comboOld_CharacterInitialArmor_currentIndexChanged(const QString &arg1);

    void on_comboOld_CharacterInitialHelmet_currentIndexChanged(int index);

    void on_comboOld_CharacterInitialHelmet_currentIndexChanged(const QString &arg1);

    void on_comboOld_CharacterInitialMisc_currentIndexChanged(int index);

    void on_comboOld_CharacterInitialMisc_currentIndexChanged(const QString &arg1);

    void on_comboOld_CharacterUnarmedAnimation_currentIndexChanged(int index);

    void on_comboOld_CharacterUnarmedAnimation_currentIndexChanged(const QString &arg1);

private:
    Ui::DialogDataBase *ui;

    GameCharacter *current_character;
    QVector<GameCharacter> characters;
};

#endif // DIALOGDATABASE_H
