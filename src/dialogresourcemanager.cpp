#include "dialogresourcemanager.h"
#include "ui_dialogresourcemanager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDebug>
#include "dialogimportimage.h"
#include "EasyRPGCore.h"

DialogResourceManager::DialogResourceManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResourceManager)
{
    ui->setupUi(this);
    m_model = new QStringListModel(this);
    if (!project())
        m_model->setStringList(QStringList());
    else{
        m_model->setStringList(QStringList(project()->backdroplist()));
    }
    ui->listResources->setModel(m_model);
}

DialogResourceManager::~DialogResourceManager()
{
    delete ui;
}

void DialogResourceManager::on_listResourceType_currentRowChanged(int currentRow)
{
    if (!project())
        return;
    switch (currentRow)
    {
    case 0:
        m_model->setStringList(project()->backdroplist());
        break;
    case 1:
        m_model->setStringList(project()->battlelist());
        break;
    case 2:
        m_model->setStringList(project()->battle2list());
        break;
    case 3:
        m_model->setStringList(project()->battlecharsetlist());
        break;
    case 4:
        m_model->setStringList(project()->battleweaponlist());
        break;
    case 5:
        m_model->setStringList(project()->charsetlist());
        break;
    case 6:
        m_model->setStringList(project()->chipsetlist());
        break;
    case 7:
        m_model->setStringList(project()->facesetlist());
        break;
    case 8:
        m_model->setStringList(project()->framelist());
        break;
    case 9:
        m_model->setStringList(project()->gameoverlist());
        break;
    case 10:
        m_model->setStringList(project()->monsterlist());
        break;
    case 11:
        m_model->setStringList(project()->movielist());
        break;
    case 12:
        m_model->setStringList(project()->musiclist());
        break;
    case 13:
        m_model->setStringList(project()->backgroundlist());
        break;
    case 14:
        m_model->setStringList(project()->picturelist());
        break;
    case 15:
        m_model->setStringList(project()->soundlist());
        break;
    case 16:
        m_model->setStringList(project()->systemlist());
        break;
    case 17:
        m_model->setStringList(project()->system2list());
        break;
    case 18:
        m_model->setStringList(project()->titlelist());
        break;
    default:
        m_model->setStringList(QStringList());
    }
}

void DialogResourceManager::on_pushImport_clicked()
{
    if (ui->listResourceType->currentIndex().row() < 0 ||
        ui->listResourceType->currentIndex().row() > 18)
            return;

    QString filename;
    if (ui->listResourceType->currentIndex().row() == 11) //Movie
        filename = QFileDialog::getOpenFileName(this,tr("Select a file to import"), m_lastmoviepath == QString() ? QStandardPaths::standardLocations(QStandardPaths::MoviesLocation)[0] : m_lastmoviepath, tr("Video formats (*.avi *.mpg)"));
    else if (ui->listResourceType->currentIndex().row() == 12) //Music
        filename = QFileDialog::getOpenFileName(this, tr("Select a file to import"), m_lastmusicpath == QString() ? QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0] : m_lastmusicpath, tr("All formats (*.mid *.mp3 *.ogg *.wav);;MID (*.mid);;MP3 (*.mp3);;OGG (*.ogg);;WAV (*.wav)"));
    else if (ui->listResourceType->currentIndex().row() == 15) //Sound
        filename = QFileDialog::getOpenFileName(this, tr("Select a file to import"),m_lastsoundpath == QString() ? QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)[0] : m_lastsoundpath, tr("WAV (*.wav)"));
    else //Picture
        filename = QFileDialog::getOpenFileName(this,tr("Select a file to import"), m_lastpicturepath == QString() ? QStandardPaths::standardLocations(QStandardPaths::PicturesLocation)[0] : m_lastpicturepath, tr("All formats (*.bmp *.png *.xyz);;BMP (*.bmp);;PNG (*.png);;XYZ (*.xyz)"));

    //Check file
    QSize size;
    QImage image;
    QFileInfo info(filename);
    if (!info.exists() || info.isDir())
        return;

    DialogImportImage *dialog;

    switch (ui->listResourceType->currentIndex().row())
    {
    case 0:
        image = QImage(filename);
        size = image.size();
        if (size != QSize(320,240)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Backdrop images's size should be 320x240."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        image.save(EasyRPGCore::pathBackdrop()+info.baseName()+".PNG");
        break;
    case 1:
        size = QImage(filename).size();
        if (size.width() < 96 || size.width() > 480 || size.height() < 96 || size.height() > 480 || size.width()%96 != 0 || size.height()%96 != 0) {
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Battle images's size should be beatwhen 96x96 and 480x480 and be a multiple of 96."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        dialog = new DialogImportImage(filename,this);
        dialog->exec();
        if (dialog->result() == QDialog::Accepted)
            image = dialog->image();
        image.save(EasyRPGCore::pathBattle()+info.baseName()+".PNG");
        break;
    case 2:
        size = QImage(filename).size();
        if ((size.width() >= 128 || size.width() <= 640 || size.height() >= 128 || size.height() <=640) && (size.width()%128 == 0 && size.height()%128 == 0)) {
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Battle2 images's size should be beatwhen 128x128 and 640x640 and be a multiple of 128"), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 3:
        size = QImage(filename).size();
        if (size != QSize(144,384)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("BattleCharset images's size should be 144x384."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 4:
        size = QImage(filename).size();
        if (size != QSize(192,512)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("BattleWeapon images's size should be 192x512."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 5:
        size = QImage(filename).size();
        if (size != QSize(288,256)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Charset images's size should be 288x256."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        dialog = new DialogImportImage(filename,this);
        dialog->exec();
        if (dialog->result() == QDialog::Accepted)
            image = dialog->image();
        image.save(EasyRPGCore::pathCharSet()+info.baseName()+".PNG");
        break;
    case 6:
        size = QImage(filename).size();
        if (size != QSize(480,256)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Chipset images's size should be 480x256."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 7:
        size = QImage(filename).size();
        if (size != QSize(192,192)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Faceset images's size should be 192x192."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 8:
        size = QImage(filename).size();
        if (size != QSize(320,240)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Frame images's size should be 320x240."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 9:
        size = QImage(filename).size();
        if (size != QSize(320,240)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("GameOver images's size should be 320x240."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 10:
        size = QImage(filename).size();
        if (size.width() < 16 || size.width() > 240 || size.height() < 16 || size.height() > 240){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Monster images's size should be beatwhen 16x16 and 240x240."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        size = QImage(filename).size();
        if (size.width() < 80 || size.width() > 640 || size.height() < 80 || size.height() > 640){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Background images's size should be beatwhen 80x80 and 640x640."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        size = QImage(filename).size();
        if (size != QSize(160,80)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("System images's size should be 160x80."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 17:
        size = QImage(filename).size();
        if (size != QSize(80,96)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("System2 images's size should be 80x96."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    case 18:
        size = QImage(filename).size();
        if (size != QSize(320,240)){
            QMessageBox msg(QMessageBox::Critical, "Error", tr("Title images's size should be 320x240."), QMessageBox::Ok);
            msg.exec();
            return;
        }
        break;
    default:
        break;
    }
}
