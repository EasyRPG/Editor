#include "qdbpagechipset.h"
#include "ui_qdbpagechipset.h"

QDbPageChipset::QDbPageChipset(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageChipset)
{
    ui->setupUi(this);
}

QDbPageChipset::~QDbPageChipset()
{
    delete ui;
}
