#include "qdbpageskills.h"
#include "ui_qdbpageskills.h"

QDbPageSkills::QDbPageSkills(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageSkills)
{
    ui->setupUi(this);
}

QDbPageSkills::~QDbPageSkills()
{
    delete ui;
}
