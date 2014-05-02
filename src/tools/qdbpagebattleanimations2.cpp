#include "qdbpagebattleanimations2.h"
#include "ui_qdbpagebattleanimations2.h"

qdbpagebattleanimations2::qdbpagebattleanimations2(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagebattleanimations2)
{
    ui->setupUi(this);
}

qdbpagebattleanimations2::~qdbpagebattleanimations2()
{
    delete ui;
}
