#include "dialogimportproject.h"
#include "ui_dialogimportproject.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>

DialogImportProject::DialogImportProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogImportProject)
{
    ui->setupUi(this);
    setModal(true);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

DialogImportProject::~DialogImportProject()
{
    delete ui;
}

QString DialogImportProject::getProjectFolder() const
{
    return ui->lineGameFolder->text();
}

QString DialogImportProject::getSourceFolder() const
{
    return ui->lineSourcePath->text();
}

void DialogImportProject::setDefDir(QString n_defDir)
{
    ui->lineProjectPath->setText(n_defDir);
    m_defDir = n_defDir;
}

QString DialogImportProject::getDefDir()
{
    return ui->lineProjectPath->text();
}

void DialogImportProject::on_lineGameFolder_textChanged(const QString &arg1)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!arg1.isEmpty());
}

void DialogImportProject::on_toolProjectPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,
                                                     "Select destination forlder",
                                                     m_defDir);
    if (path == QString())
        return;
    ui->lineProjectPath->setText(path+"/");
    m_defDir = ui->lineProjectPath->text();
}

void DialogImportProject::on_toolSourcePath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,
                                                     "Select destination forlder",
                                                     m_defDir);
    if (path == QString())
        return;
    if (!QFileInfo(path+"/RPG_RT.ldb").exists())
    {
        QMessageBox::critical(this,
                              "Error",
                              "This folder does not contain a valid RPG Maker project");
        return;
    }
    ui->lineSourcePath->setText(path+"/");
    ui->lineGameFolder->setText(QDir(path).dirName());
}
