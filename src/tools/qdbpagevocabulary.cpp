#include "qdbpagevocabulary.h"
#include "ui_qdbpagevocabulary.h"

QDbPageVocabulary::QDbPageVocabulary(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageVocabulary)
{
    ui->setupUi(this);
}

QDbPageVocabulary::~QDbPageVocabulary()
{
    delete ui;
}
