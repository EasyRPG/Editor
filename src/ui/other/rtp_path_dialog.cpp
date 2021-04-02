/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

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
	ui->lineRtpPath->setText(core().rtpPath(""));
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
													 "Select Rtp folder",
													 ui->lineRtpPath->text());
	if (path == QString())
		return;
	ui->lineRtpPath->setText(path+"/");
}

void RtpPathDialog::on_ok()
{
	core().setRtpDir(ui->lineRtpPath->text());
	QSettings m_settings;
	m_settings.setValue(RTP_KEY, ui->lineRtpPath->text());
}
