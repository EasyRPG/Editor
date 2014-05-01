#include "qdbpagebattlescreen.h"
#include "ui_qdbpagebattlescreen.h"

qdbpagebattlescreen::qdbpagebattlescreen(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagebattlescreen)
{
    ui->setupUi(this);
}

qdbpagebattlescreen::~qdbpagebattlescreen()
{
    delete ui;
}
