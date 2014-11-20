#include "dialogrungame.h"
#include "ui_dialogrungame.h"
#include "tools/qactordelegate.h"
#include <data.h>

DialogRunGame::DialogRunGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRunGame)
{
    ui->setupUi(this);

    ui->tableInitialParty->setItemDelegate(new QActorDelegate(this));
    on_comboMode_currentIndexChanged(0);

    UpdateModels();
}

DialogRunGame::~DialogRunGame()
{
    delete ui;
}

void DialogRunGame::runHere(int map_id, int x, int y)
{
    UpdateModels();
    ui->comboMode->setCurrentIndex(1);
    ui->groupInitialPosition->setChecked(true);
    for (int i = 0; i < ui->comboMapId->count(); i++)
    {
        if (ui->comboMapId->itemData(i).toInt() == map_id)
        {
            ui->comboMapId->setCurrentIndex(i);
            break;
        }
    }
    ui->spinX->setValue(x);
    ui->spinY->setValue(y);
    this->exec();
}

void DialogRunGame::runBattle(int troop_id)
{
    UpdateModels();
    ui->comboMode->setCurrentIndex(3);
    ui->comboTroop->setCurrentIndex(troop_id-1);
}

void DialogRunGame::on_comboMode_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
    case 1:
        ui->groupSave->setEnabled(false);
        ui->groupInitialPosition->setEnabled(true);
        ui->groupBattleOptions->setEnabled(false);
        ui->groupInitialParty->setEnabled(true);
        break;
    case 2:
        ui->groupSave->setEnabled(true);
        ui->groupInitialPosition->setEnabled(false);
        ui->groupBattleOptions->setEnabled(false);
        ui->groupInitialParty->setEnabled(false);
        break;
    case 3:
        ui->groupSave->setEnabled(false);
        ui->groupInitialPosition->setEnabled(false);
        ui->groupBattleOptions->setEnabled(true);
        ui->groupInitialParty->setEnabled(true);
        break;
    }
}

void DialogRunGame::UpdateModels()
{
    // Maps
    ui->comboMapId->clear();
    for (int i = 1; i < (int)Data::treemap.maps.size(); i++)
    {
        if (Data::treemap.maps[i].type == 1)
        {
            ui->comboMapId->addItem(QString::fromStdString(Data::treemap.maps[i].name),
                                    Data::treemap.maps[i].ID);
        }
    }

    // Troops
    ui->comboTroop->clear();
    ui->comboTroop->addItem(tr("<Test Troop>"));
    for (int i = 1; i < (int)Data::troops.size(); i++)
        ui->comboTroop->addItem(QString::fromStdString(Data::troops[i].name));

    bool auto_placement = (bool)Data::data.battlecommands.placement;
    ui->groupPartyFormation->setEnabled(auto_placement);
    ui->comboBattleCondition->clear();
    QStringList conditions;
    conditions << tr("No condition") << tr("Initiative") << tr("Back attack");
    if (auto_placement)
        conditions << tr("Surround attack") << tr("Pincers attack");
    ui->comboBattleCondition->addItems(conditions);

    ui->comboCustomFormation->clear();
    for (int i = 0; i < (int)Data::terrains.size(); i++)
        ui->comboCustomFormation->addItem(QString::fromStdString(Data::terrains[i].name));

    battletest_data = Data::system.battletest_data;
    for (int i = 0; i < (int)battletest_data.size(); i++)
        ui->tableInitialParty->item(i,0)->setData(Qt::UserRole, battletest_data[i].actor_id);
}

void DialogRunGame::on_tableInitialParty_itemChanged(QTableWidgetItem *item)
{
    if (item->data(Qt::UserRole).toInt() == 0)
    {
        while (ui->tableInitialParty->rowCount() > item->row()+1)
        {
            ui->tableInitialParty->removeRow(item->row()+1);
        }
    }
    else if (item->row() == ui->tableInitialParty->rowCount()-1 &&
             ui->tableInitialParty->rowCount() < 4)
    {
        QTableWidgetItem *n_item = new QTableWidgetItem(tr("<None>"));
        n_item->setData(Qt::UserRole, 0);
        ui->tableInitialParty->insertRow(item->row()+1);
        ui->tableInitialParty->setItem(item->row()+1, 0, n_item);
    }
}
