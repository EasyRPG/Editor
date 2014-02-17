#include "dialogrtppath.h"
#include "ui_dialogrtppath.h"
#include <QFileDialog>
#include <QSettings>
#include "core.h"

DialogRtpPath::DialogRtpPath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRtpPath)
{
    ui->setupUi(this);
    ui->lineRtpPath->setText(mCore()->rtpPath(ROOT));
    connect(this,SIGNAL(accepted()),this,SLOT(on_ok()));
    exec();
}

DialogRtpPath::~DialogRtpPath()
{
    delete ui;
}

void DialogRtpPath::on_toolRtpPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,
                                                     "Select Rtp forlder",
                                                     ui->lineRtpPath->text());
    if (path == QString())
        return;
    ui->lineRtpPath->setText(path+"/");
}

void DialogRtpPath::on_ok()
{
    mCore()->setRtpDir(ui->lineRtpPath->text());
    QSettings m_settings;
    m_settings.setValue(RTP_KEY, ui->lineRtpPath->text());
}
