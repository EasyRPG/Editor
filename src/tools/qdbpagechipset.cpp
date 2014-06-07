#include "qdbpagechipset.h"
#include "ui_qdbpagechipset.h"

QDbPageChipset::QDbPageChipset(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDbPageChipset),
    m_data(database)
{
    ui->setupUi(this);
}

QDbPageChipset::~QDbPageChipset()
{
    delete ui;
}
