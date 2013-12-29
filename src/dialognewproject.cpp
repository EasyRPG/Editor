#include "dialognewproject.h"
#include "ui_dialognewproject.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

DialogNewProject::DialogNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewProject)
{

    m_defDir = QString();
    ui->setupUi(this);
    setModal(true);
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

QString DialogNewProject::getProjectPath()
{
    return ui->lineProjectPath->text()+getGameTitle()+"/";
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

void DialogNewProject::setDefDir(QString n_defDir) {ui->lineProjectPath->setText(n_defDir);
                                                    m_defDir = n_defDir;}

QString DialogNewProject::getDefDir() {return ui->lineProjectPath->text();}

void DialogNewProject::on_toolProjectPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Select destination forlder", m_defDir);
    if (path == QString())
        return;
    ui->lineProjectPath->setText(path+"/");
}

//TODO: generate RTP template code.
