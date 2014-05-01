#ifndef QDBPAGEACTORS_H
#define QDBPAGEACTORS_H

#include <QWidget>
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "qgraphicscharaitem.h"
#include "qgraphicsfaceitem.h"
#include "../dialogcharapicker.h"
#include "../dialogfacepicker.h"

namespace Ui {
class QDbPageActors;
}

class QDbPageActors : public QWidget
{
    Q_OBJECT

public:
    explicit QDbPageActors(RPG::Database &database, QWidget *parent = 0);
    ~QDbPageActors();

public slots:
    void on_currentActorChanged(RPG::Actor *actor);

private slots:
    void on_listCharacters_currentRowChanged(int currentRow);
    void on_lineName_textChanged(const QString &arg1);
    void on_lineTitle_textChanged(const QString &arg1);
    void on_checkTranslucent_toggled(bool checked);
    void on_spinMinLv_valueChanged(const QString &arg1);
    void on_spinMaxLv_valueChanged(const QString &arg1);
    void on_checkDualWeapon_stateChanged(int state);
    void on_checkAI_stateChanged(int state);
    void on_checkFixedEquip_stateChanged(int state);
    void on_checkStrongDefense_stateChanged(int state);
    void on_groupCritChance_toggled(bool on);
    void on_spinCritChance_valueChanged(const QString &arg1);
    void on_comboInitialWeapon_currentIndexChanged(int index);
    void on_comboInitialShield_currentIndexChanged(int index);
    void on_comboInitialArmor_currentIndexChanged(int index);
    void on_comboInitialHelmet_currentIndexChanged(int index);
    void on_comboInitialMisc_currentIndexChanged(int index);
    void on_comboUnarmedAnimation_currentIndexChanged(int index);
    void on_comboProfession_currentIndexChanged(int index);
    void on_pushSetCharset_clicked();
    void on_pushSetFace_clicked();

signals:
    void currentActorChanged(RPG::Actor *actor);

private:
    Ui::QDbPageActors *ui;

    void UpdateModels();

    QGraphicsCharaItem *m_charaItem;
    QGraphicsFaceItem *m_faceItem;

    RPG::Actor *m_currentActor;
    RPG::Database &m_data;
};

#endif // QDBPAGEACTORS_H
