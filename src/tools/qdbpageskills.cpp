#include "qdbpageskills.h"
#include "ui_qdbpageskills.h"

qdbpageskills::qdbpageskills(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageskills)
{
    ui->setupUi(this);
}

qdbpageskills::~qdbpageskills()
{
    delete ui;
}
