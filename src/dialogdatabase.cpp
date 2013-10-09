#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"
#include <QPushButton>
#include <QInputDialog>
#include <sstream>
#include <iomanip>

DialogDataBase::DialogDataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDataBase)
{
    ui->setupUi(this);

}

DialogDataBase::~DialogDataBase()
{
    delete ui;
}
void DialogDataBase::on_toolSwitchStyle_clicked(bool checked)
{
    if (checked)
        ui->stackedStyle->setCurrentIndex(1);
    else
        ui->stackedStyle->setCurrentIndex(0);
}

void DialogDataBase::on_tabOld_Pages_currentChanged(int index)
{
    ui->listNew_Pages->setCurrentRow(index);
}

void DialogDataBase::on_pushOld_CharacterMax_clicked()
{
    bool b_ok;
    int n_num = QInputDialog::getInt(this,"Change Maximum Number", "Maximum Number", ui->listOld_Character->currentRow(), 1, 5000,1, &b_ok);
    if (b_ok){
        if (n_num < ui->listOld_Character->count())
            for (int i = ui->listOld_Character->count(); i > n_num; i--){
                QListWidgetItem *itm = ui->listOld_Character->takeItem(i-1);
                delete itm;
            }
        else{
            std::stringstream ss;
            for (int i = ui->listOld_Character->count(); i < n_num; i++){
                ss.str("");
                ss << std::setfill('0') << std::setw(4) << i + 1 << ": ";
                ui->listOld_Character->insertItem(i, QString::fromStdString(ss.str()));
            }
        }
    }
}
