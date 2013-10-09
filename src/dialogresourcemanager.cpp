#include "dialogresourcemanager.h"
#include "ui_dialogresourcemanager.h"

DialogResourceManager::DialogResourceManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResourceManager)
{
    ui->setupUi(this);
}

DialogResourceManager::~DialogResourceManager()
{
    delete ui;
}
