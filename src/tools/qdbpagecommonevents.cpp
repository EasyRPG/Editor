#include "qdbpagecommonevents.h"
#include "ui_qdbpagecommonevents.h"

qdbpagecommonevents::qdbpagecommonevents(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagecommonevents)
{
    ui->setupUi(this);
}

qdbpagecommonevents::~qdbpagecommonevents()
{
    delete ui;
}
