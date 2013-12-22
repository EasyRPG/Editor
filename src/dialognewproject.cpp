#include "dialognewproject.h"
#include "ui_dialognewproject.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

DialogNewProject::DialogNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewProject)
{
    ui->setupUi(this);
    setModal(true);
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

QString DialogNewProject::getProjectPath()
{
    return ui->lineProjectPath->text();
}

QString DialogNewProject::getGameTitle()
{
    return ui->lineGameTitle->text();
}

int DialogNewProject::getTileSize()
{
    bool *ok = new bool;
    int val = ui->comboTileSize->currentText().toInt(ok);
    if (!*ok)
        val = 16;
    return val;
}

void DialogNewProject::on_toolProjectPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Select destination forlder");
    if (path == QString())
        return;
    QDir dir(path);
    QStringList list = dir.entryList();
    int count = 0;
    for(int x=0;x<list.count(); x++)
    {
        if(list.at(x) != "." && list.at(x) != "..")
        {
            count++;
        }
    }
    if (count == 0)
        ui->lineProjectPath->setText(path);
    else{
        QMessageBox box(QMessageBox::Warning, "Wrong folder selected", "Please select an empty folder",QMessageBox::Ok);
        box.exec();
        on_toolProjectPath_clicked();
    }
}
