#include "dialogcharapicker.h"
#include "ui_dialogcharapicker.h"
#include <QDir>
#include <QPushButton>
#include "core.h"

DialogCharaPicker::DialogCharaPicker(QWidget *parent, bool tile_pick) :
	QDialog(parent),
	ui(new Ui::DialogCharaPicker),
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
		m_tileScene = new QGraphicsPickerScene(ui->graphicsTile, tileItem, 24, 6);
		m_tileScene->setBackgroundBrush(QBrush(QPixmap(":/embedded/share/old_grid.png")));
		ui->graphicsTile->setScene(m_tileScene);
	}

	QDir dir(mCore->filePath(CHARSET));
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

	m_chara = new QGraphicsCharaItem();
	m_chara->setWalk(!tile_pick);
	m_chara->setScale(2.0);
	m_charaScene = new QGraphicsPickerScene(ui->viewChara, m_chara, 2, 4);
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

DialogCharaPicker::~DialogCharaPicker()
{
	delete ui;
}

int DialogCharaPicker::frame()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return 0;
	return m_chara->frame();
}

void DialogCharaPicker::setFrame(int frame)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return;
	m_chara->setFrame(frame);
	updateFrame();
}

int DialogCharaPicker::facing()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return 0;
	return m_chara->facing();
}

void DialogCharaPicker::setFacing(int facing)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return;
	m_chara->setFacing(facing);
	updateFacing();
}

std::string DialogCharaPicker::name()
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return "";
	return ui->listRes->currentItem()->text().toStdString();
}

void DialogCharaPicker::setName(std::string name)
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

void DialogCharaPicker::setAnimated(bool animated)
{
	if (animated)
		m_timer->start(200);
	else
		m_timer->stop();
}

void DialogCharaPicker::updateFrame()
{
	ui->radioLeft->setChecked(m_chara->frame() == QGraphicsCharaItem::Frame_left);
	ui->radioMiddle->setChecked(m_chara->frame() == QGraphicsCharaItem::Frame_middle);
	ui->radioRight->setChecked(m_chara->frame() == QGraphicsCharaItem::Frame_right);
}

void DialogCharaPicker::updateFacing()
{
	ui->toolDown->setChecked(m_chara->facing() == QGraphicsCharaItem::Direction_down);
	ui->toolLeft->setChecked(m_chara->facing() == QGraphicsCharaItem::Direction_left);
	ui->toolUp->setChecked(m_chara->facing() == QGraphicsCharaItem::Direction_up);
	ui->toolRight->setChecked(m_chara->facing() == QGraphicsCharaItem::Direction_right);
}
int DialogCharaPicker::index() const
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		return m_tileScene->index();
	return m_charaScene->index();
}

void DialogCharaPicker::setIndex(int index)
{
	if (m_tilePick && ui->listRes->currentRow() == 0)
		m_tileScene->setIndex(index);
	else
		m_charaScene->setIndex(index);
}



void DialogCharaPicker::on_toolUp_clicked()
{
	m_chara->setFacing(QGraphicsCharaItem::Direction_up);
	updateFacing();
}

void DialogCharaPicker::on_toolRight_clicked()
{
	m_chara->setFacing(QGraphicsCharaItem::Direction_right);
	updateFacing();
}

void DialogCharaPicker::on_toolDown_clicked()
{
	m_chara->setFacing(QGraphicsCharaItem::Direction_down);
	updateFacing();
}

void DialogCharaPicker::on_toolLeft_clicked()
{
	m_chara->setFacing(QGraphicsCharaItem::Direction_left);
	updateFacing();
}

void DialogCharaPicker::on_radioLeft_clicked()
{
	m_chara->setFrame(QGraphicsCharaItem::Frame_left);
}

void DialogCharaPicker::on_radioMiddle_clicked()
{
	m_chara->setFrame(QGraphicsCharaItem::Frame_middle);
}

void DialogCharaPicker::on_radioRight_clicked()
{
	m_chara->setFrame(QGraphicsCharaItem::Frame_right);
}

void DialogCharaPicker::on_listRes_currentRowChanged(int currentRow)
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

void DialogCharaPicker::ok()
{
	setResult(QDialogButtonBox::Ok);
}
