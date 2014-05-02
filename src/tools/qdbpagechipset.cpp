#include "qdbpagechipset.h"
#include "ui_qdbpagechipset.h"

qdbpagechipset::qdbpagechipset(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagechipset)
{
    ui->setupUi(this);
}

qdbpagechipset::~qdbpagechipset()
{
    delete ui;
}
