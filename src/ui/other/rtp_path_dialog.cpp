#include "rtp_path_dialog.h"
#include "ui_rtp_path_dialog.h"
#include <QFileDialog>
#include <QSettings>
#include "core.h"

RtpPathDialog::RtpPathDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::RtpPathDialog)
{
	ui->setupUi(this);
	ui->lineRtpPath->setText(mCore->rtpPath(ROOT));
	connect(this,SIGNAL(accepted()),this,SLOT(on_ok()));
	exec();
}

RtpPathDialog::~RtpPathDialog()
{
	delete ui;
}

void RtpPathDialog::on_toolRtpPath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this,
													 "Select Rtp forlder",
													 ui->lineRtpPath->text());
	if (path == QString())
		return;
	ui->lineRtpPath->setText(path+"/");
}

void RtpPathDialog::on_ok()
{
	mCore->setRtpDir(ui->lineRtpPath->text());
	QSettings m_settings;
	m_settings.setValue(RTP_KEY, ui->lineRtpPath->text());
}
