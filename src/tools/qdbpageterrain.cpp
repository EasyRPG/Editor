#include "qdbpageterrain.h"
#include "ui_qdbpageterrain.h"

qdbpageterrain::qdbpageterrain(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpageterrain)
{
    ui->setupUi(this);
}

qdbpageterrain::~qdbpageterrain()
{
    delete ui;
}
