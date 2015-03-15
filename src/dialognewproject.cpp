#include "dialognewproject.h"
#include "ui_dialognewproject.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>

DialogNewProject::DialogNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewProject)
{
    ui->setupUi(this);
    setModal(true);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

QString DialogNewProject::getProjectFolder() const
{
    return ui->lineGameFolder->text();
}

QString DialogNewProject::getGameTitle() const
{
    if (ui->lineGameTitle->text().isEmpty())
        return (tr("Untitled"));
    return ui->lineGameTitle->text();
}

int DialogNewProject::getTileSize() const
{
    bool *ok = new bool;
    int val = ui->comboTileSize->currentText().toInt(ok);
    if (!*ok)
        val = 16;
    return val;
}

void DialogNewProject::setDefDir(QString n_defDir)
{
    if (!n_defDir.endsWith('/'))
        n_defDir.append("/");
    ui->lineProjectPath->setText(n_defDir);
    m_defDir = n_defDir;
}

QString DialogNewProject::getDefDir()
{
    return ui->lineProjectPath->text();
}

void DialogNewProject::on_toolProjectPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,
                                                     "Select destination forlder",
                                                     m_defDir);
    if (path == QString())
        return;
    ui->lineProjectPath->setText(path+"/");
    m_defDir = ui->lineProjectPath->text();
}

//TODO: generate RTP template code.

void DialogNewProject::on_lineGameFolder_textChanged(const QString &arg1)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!arg1.isEmpty());
}
