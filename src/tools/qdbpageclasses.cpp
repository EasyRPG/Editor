#include "qdbpageclasses.h"
#include "ui_qdbpageclasses.h"
#include <QTimer>
#include <QGraphicsOpacityEffect>

qdbpageclasses::qdbpageclasses(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qdbpageclasses),
    m_data(database)
{
    ui->setupUi(this);
}

qdbpageclasses::~qdbpageclasses()
{
    delete ui;
}
