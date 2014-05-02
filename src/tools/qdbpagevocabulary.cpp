#include "qdbpagevocabulary.h"
#include "ui_qdbpagevocabulary.h"

qdbpagevocabulary::qdbpagevocabulary(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::qdbpagevocabulary)
{
    ui->setupUi(this);
}

qdbpagevocabulary::~qdbpagevocabulary()
{
    delete ui;
}
