#include "qdbpageattibutes.h"
#include "ui_qdbpageattibutes.h"

qdbpageattibutes::qdbpageattibutes(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageattibutes)
{
    ui->setupUi(this);
}

qdbpageattibutes::~qdbpageattibutes()
{
    delete ui;
}
