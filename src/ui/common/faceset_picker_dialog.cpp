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

#include "faceset_picker_dialog.h"
#include "ui_charset_picker_dialog.h"
#include <QDir>
#include <QPushButton>
#include "core.h"

faceset_picker_dialog::faceset_picker_dialog(QWidget *parent, bool tile_pick) :
	QDialog(parent),
	ui(new Ui::CharSetPickerDialog)
{
	ui->setupUi(this);

	QDir dir(mCore->filePath(FACESET));
	QStringList entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

	foreach (QString file, entry)
	{

		QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

		if (info.isSymLink())
			continue;
		if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
			ui->listRes->addItem(info.baseName());
	}

	dir = QDir(mCore->rtpPath(FACESET));
	entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

	foreach (QString file, entry)
	{

		QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

		if (info.isSymLink())
			continue;
		if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
			ui->listRes->addItem(info.baseName());
	}

	m_chara = new FaceSetItem();
	m_chara->setScale(1.0);
	ui->viewChara->resize(192,192);
	ui->viewChara->setMinimumHeight(196);
	m_charaScene = new PickerScene(ui->viewChara, m_chara, 4, 4);
	ui->viewChara->setScene(m_charaScene);

	m_timer = new QTimer(this);
	connect(m_timer,SIGNAL(timeout()),m_charaScene,SLOT(advance()));

	connect(ui->buttonBox->button(QDialogButtonBox::Ok),
			SIGNAL(clicked()),
			this,
			SLOT(ok()));

	setAnimated(!tile_pick);
	ui->groupFacing->hide();
	ui->groupFrame->hide();

}

faceset_picker_dialog::~faceset_picker_dialog()
{
	delete ui;
}

int faceset_picker_dialog::frame()
{
	return m_chara->frame();
}

void faceset_picker_dialog::setFrame(int frame)
{
	m_chara->setFrame(frame);
}

std::string faceset_picker_dialog::name()
{
	QString name = ui->listRes->currentItem()->text();
	if (name.contains("*"))
		name = "";
	return name.toStdString();
}

void faceset_picker_dialog::setName(std::string name)
{
	if (name.empty() && ui->listRes->count() > 0)
	{
		ui->listRes->setCurrentRow(0);
		return;
	}
	QList<QListWidgetItem*> items = ui->listRes->findItems(QString::fromStdString(name),
															Qt::MatchFixedString);
	if (!items.empty())
		ui->listRes->setCurrentItem(items[0]);
}

void faceset_picker_dialog::setAnimated(bool animated)
{
	if (animated)
		m_timer->start(200);
	else
		m_timer->stop();
}

int faceset_picker_dialog::index() const
{
	if (ui->listRes->currentItem()->text().contains("*"))
		return m_tileScene->index();
	return m_charaScene->index();
}

void faceset_picker_dialog::setIndex(int index)
{
	if (ui->listRes->currentItem()->text().contains("*"))
		m_tileScene->setIndex(index);
	else
		m_charaScene->setIndex(index);
}

void faceset_picker_dialog::on_listRes_currentRowChanged(int currentRow)
{
	Q_UNUSED(currentRow)
	if (ui->listRes->currentItem()->text().contains("*"))
	{
		ui->stackedMain->setCurrentWidget(ui->pageTileset);
		return;
	}
	else
	{
		ui->stackedMain->setCurrentWidget(ui->pageChara);
		m_chara->setBasePix(ui->listRes->currentItem()->text());
	}
}

void faceset_picker_dialog::ok()
{
	setResult(QDialogButtonBox::Ok);
}
