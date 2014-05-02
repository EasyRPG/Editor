#include "qdbpageitems.h"
#include "ui_qdbpageitems.h"

qdbpageitems::qdbpageitems(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageitems)
{
    ui->setupUi(this);
}

qdbpageitems::~qdbpageitems()
{
    delete ui;
}
