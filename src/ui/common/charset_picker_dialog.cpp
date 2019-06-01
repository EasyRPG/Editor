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

#include "charset_picker_dialog.h"
#include "ui_charset_picker_dialog.h"
#include <QDir>
#include <QPushButton>
#include "core.h"

CharSetPickerDialog::CharSetPickerDialog(QWidget *parent, bool tile_pick) :
	QDialog(parent),
	ui(new Ui::CharSetPickerDialog),
	m_tilePick(tile_pick)
{
	ui->setupUi(this);
	ui->stackedStatic->setCurrentWidget(tile_pick ? ui->pageStatic : ui->pageEmpty);
	ui->stackedMain->setCurrentWidget(tile_pick ? ui->pageTileset : ui->pageChara);
	if (tile_pick)
	{
		ui->listRes->addItem(tr("*Tileset"));
		QGraphicsPixmapItem *tileItem = new QGraphicsPixmapItem();
		QPixmap pix(96, 384);
		pix.fill(QColor(0,0,0,0));
		mCore->beginPainting(pix);
		for (short i = 0; i < 144; i++)
			mCore->renderTile(10000+i, QRect((i%6)*16,i/6*16,16,16));
		mCore->endPainting();
		tileItem->setPixmap(pix);
		tileItem->setScale(2.0);
		m_tileScene = new PickerScene(ui->graphicsTile, tileItem, 24, 6);
		m_tileScene->setBackgroundBrush(QBrush(QPixmap(":/embedded/share/old_grid.png")));
		ui->graphicsTile->setScene(m_tileScene);
	}

	QDir dir(mCore->project()->findFile(CHARSET));
	QStringList entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

	foreach (QString file, entry)
	{

		QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

		if (info.isSymLink())
			continue;
		if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
			ui->listRes->addItem(info.baseName());
	}

	dir = QDir(mCore->rtpPath(CHARSET));
	entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

	foreach (QString file, entry)
	{

		QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

		if (info.isSymLink())
			continue;
		if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
			ui->listRes->addItem(info.baseName());
	}

	m_chara = new CharSetItem();
	m_chara->setWalk(!tile_pick);
	m_chara->setScale(2.0);
	m_charaScene = new PickerScene(ui->viewChara, m_chara, 2, 4);
	ui->viewChara->setScene(m_charaScene);

	m_timer = new QTimer(this);
	connect(m_timer,SIGNAL(timeout()),m_charaScene,SLOT(advance()));

	connect(ui->buttonBox->button(QDialogButtonBox::Ok),
			SIGNAL(clicked()),
			this,
			SLOT(ok()));

	setAnimated(!tile_pick);

	updateFacing();
	updateFrame();
}

CharSetPickerDialog::~CharSetPickerDialog()
{
	delete ui;
}

int CharSetPickerDialog::frame()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return 0;
	return m_chara->frame();
}

void CharSetPickerDialog::setFrame(int frame)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return;
	m_chara->setFrame(frame);
	updateFrame();
}

int CharSetPickerDialog::facing()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return 0;
	return m_chara->facing();
}

void CharSetPickerDialog::setFacing(int facing)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return;
	m_chara->setFacing(facing);
	updateFacing();
}

std::string CharSetPickerDialog::name()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return "";
	return ui->listRes->currentItem()->text().toStdString();
}

void CharSetPickerDialog::setName(std::string name)
{
	if (m_tilePick && name.empty())
	{
		ui->listRes->setCurrentRow(0);
		return;
	}
	QList<QListWidgetItem*> items = ui->listRes->findItems(QString::fromStdString(name),
															Qt::MatchFixedString);
	ui->listRes->setCurrentItem(items.empty() ? ui->listRes->item(0) : items[0]);
}

void CharSetPickerDialog::setAnimated(bool animated)
{
	if (animated)
		m_timer->start(200);
	else
		m_timer->stop();
}

void CharSetPickerDialog::updateFrame()
{
	ui->radioLeft->setChecked(m_chara->frame() == CharSetItem::Frame_left);
	ui->radioMiddle->setChecked(m_chara->frame() == CharSetItem::Frame_middle);
	ui->radioRight->setChecked(m_chara->frame() == CharSetItem::Frame_right);
}

void CharSetPickerDialog::updateFacing()
{
	ui->toolDown->setChecked(m_chara->facing() == CharSetItem::Direction_down);
	ui->toolLeft->setChecked(m_chara->facing() == CharSetItem::Direction_left);
	ui->toolUp->setChecked(m_chara->facing() == CharSetItem::Direction_up);
	ui->toolRight->setChecked(m_chara->facing() == CharSetItem::Direction_right);
}
int CharSetPickerDialog::index() const
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return m_tileScene->index();
	return m_charaScene->index();
}

void CharSetPickerDialog::setIndex(int index)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		m_tileScene->setIndex(index);
	else
		m_charaScene->setIndex(index);
}



void CharSetPickerDialog::on_toolUp_clicked()
{
	m_chara->setFacing(CharSetItem::Direction_up);
	updateFacing();
}

void CharSetPickerDialog::on_toolRight_clicked()
{
	m_chara->setFacing(CharSetItem::Direction_right);
	updateFacing();
}

void CharSetPickerDialog::on_toolDown_clicked()
{
	m_chara->setFacing(CharSetItem::Direction_down);
	updateFacing();
}

void CharSetPickerDialog::on_toolLeft_clicked()
{
	m_chara->setFacing(CharSetItem::Direction_left);
	updateFacing();
}

void CharSetPickerDialog::on_radioLeft_clicked()
{
	m_chara->setFrame(CharSetItem::Frame_left);
}

void CharSetPickerDialog::on_radioMiddle_clicked()
{
	m_chara->setFrame(CharSetItem::Frame_middle);
}

void CharSetPickerDialog::on_radioRight_clicked()
{
	m_chara->setFrame(CharSetItem::Frame_right);
}

void CharSetPickerDialog::on_listRes_currentRowChanged(int currentRow)
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

void CharSetPickerDialog::ok()
{
	setResult(QDialogButtonBox::Ok);
}
