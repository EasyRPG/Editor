#include "qdbpageherostatus.h"
#include "ui_qdbpageherostatus.h"

qdbpageherostatus::qdbpageherostatus(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageherostatus)
{
    ui->setupUi(this);
}

qdbpageherostatus::~qdbpageherostatus()
{
    delete ui;
}
