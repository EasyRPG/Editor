#include "dialogopenproject.h"
#include "ui_dialogopenproject.h"
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QStyle>

DialogOpenProject::DialogOpenProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpenProject)
{
    setModal(true);
    ui->setupUi(this);
}

DialogOpenProject::~DialogOpenProject()
{
    delete ui;
}

void DialogOpenProject::setDefDir(QString n_defDir)
{
    m_defDir = n_defDir;
    ui->lineProjectPath->setText(n_defDir);
    RefreshProjectList();
}

QString DialogOpenProject::getDefDir()
{
    return m_defDir;
}

QString DialogOpenProject::getProjectPath()
{
    return (ui->lineProjectPath->text()+ui->tableProjects->currentItem()->text()+"/");
}

void DialogOpenProject::RefreshProjectList()
{
    ui->tableProjects->setRowCount(0);
    QDir dir(m_defDir);
    if (!dir.exists())
        return;
    Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
    {
        if (info.isDir())
        {
            QFileInfo f_project(info.absoluteFilePath()+"/project.erp");
            if (f_project.exists())
            {
                ui->tableProjects->insertRow(ui->tableProjects->rowCount());
                QTableWidgetItem *item = new QTableWidgetItem(info.baseName());
                item->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
                item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                ui->tableProjects->setItem(ui->tableProjects->rowCount()-1,0,item);
            }
        }
    }
}

void DialogOpenProject::on_toolProjectPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Select destination forlder", m_defDir);
    if (path == QString())
        return;
    ui->lineProjectPath->setText(path+"/");
    m_defDir = ui->lineProjectPath->text();
    RefreshProjectList();
}

bool DialogOpenProject::removeDir(const QString & dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
        {
            if (info.isDir())
                result = removeDir(info.absoluteFilePath());
            else
                result = QFile::remove(info.absoluteFilePath());

            if (!result)
            {
                QMessageBox::warning(this,
                                     "An error ocurred",
                                     QString("Could't delete %1").arg(info.absoluteFilePath()),
                                     QMessageBox::Ok, 0);
                return false;
            }
        }
        result = dir.rmdir(dirName);
    }
    return result;
}

void DialogOpenProject::on_tableProjects_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    emit ui->buttonBox->accepted();
}
