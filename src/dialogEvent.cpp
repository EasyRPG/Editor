#include "DialogEvent.h"
#include "ui_dialogevent.h"
#include <QFileDialog>
#include <QSettings>
#include "core.h"

DialogEvent::DialogEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvent)
{
    ui->setupUi(this);
    connect(this,SIGNAL(accepted()),this,SLOT(on_ok()));
    exec();
}

DialogEvent::~DialogEvent()
{
    delete ui;
}

void DialogEvent::on_toolRtpPath_clicked()
{

}

void DialogEvent::on_ok()
{

}
