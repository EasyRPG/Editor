#ifndef QDBPAGEACTORS_H
#define QDBPAGEACTORS_H

#include <QWidget>
#include <data.h>
#include <rpg_actor.h>
#include <QDialogButtonBox>
#include "qgraphicscharaitem.h"
#include "qgraphicsfaceitem.h"
#include "qgraphicsbattleanimationitem.h"

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
    void on_checkTranslucent_toggled(bool checked);

    void on_comboBattleset_currentIndexChanged(int index);

signals:
    void currentActorChanged(RPG::Actor *actor);

private:
    Ui::QDbPageActors *ui;

    void UpdateModels();

    QGraphicsCharaItem *m_charaItem;
    QGraphicsFaceItem *m_faceItem;
    QGraphicsBattleAnimationItem *m_battlerItem;

    RPG::Actor *m_currentActor;
    RPG::Database &m_data;
};

#endif // QDBPAGEACTORS_H
