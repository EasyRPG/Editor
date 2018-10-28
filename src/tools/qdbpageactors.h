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
#include "qgraphicsbattleanimationitem.h"
#include "qgraphicscurveitem.h"

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
    void on_checkDualWeapon_toggled(bool checked);
    void on_checkAI_toggled(bool checked);
    void on_checkFixedEquip_toggled(bool checked);
    void on_checkStrongDefense_toggled(bool checked);
    void on_spinMinLv_valueChanged(int arg1);
    void on_spinMaxLv_valueChanged(int arg1);
    void on_groupCritChance_toggled(bool on);
    void on_comboInitialWeapon_currentIndexChanged(int index);
    void on_comboInitialShield_currentIndexChanged(int index);
    void on_comboInitialArmor_currentIndexChanged(int index);
    void on_comboInitialHelmet_currentIndexChanged(int index);
    void on_comboInitialMisc_currentIndexChanged(int index);
    void on_comboUnarmedAnimation_currentIndexChanged(int index);
    void on_pushSetCharset_clicked();
    void on_pushSetFace_clicked();
    void on_comboBattleset_currentIndexChanged(int index);
    void on_spinCritChance_valueChanged(int arg1);
    void on_pushApplyProfession_clicked();

signals:
    void currentActorChanged(RPG::Actor *actor);

protected:
    void resizeEvent(QResizeEvent * event);

private:
    Ui::QDbPageActors *ui;

    void UpdateModels();

    QGraphicsCharaItem *m_charaItem;
    QGraphicsFaceItem *m_faceItem;
    QGraphicsBattleAnimationItem *m_battlerItem;
    QGraphicsCurveItem *m_hpItem;
    QGraphicsCurveItem *m_mpItem;
    QGraphicsCurveItem *m_attItem;
    QGraphicsCurveItem *m_defItem;
    QGraphicsCurveItem *m_intItem;
    QGraphicsCurveItem *m_agyItem;
    std::vector<short> m_dummyCurve;

    RPG::Actor *m_currentActor;
    RPG::Database &m_data;
};

#endif // QDBPAGEACTORS_H
