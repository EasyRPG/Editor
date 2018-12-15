#include "dialogfacepicker.h"
#include "ui_dialogcharapicker.h"
#include <QDir>
#include <QPushButton>
#include "core.h"

dialogfacepicker::dialogfacepicker(QWidget *parent, bool tile_pick) :
	QDialog(parent),
	ui(new Ui::DialogCharaPicker)
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
			ui->listRess->addItem(info.baseName());
	}

	dir = QDir(mCore->rtpPath(FACESET));
	entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

	foreach (QString file, entry)
	{

		QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

		if (info.isSymLink())
			continue;
		if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
			ui->listRess->addItem(info.baseName());
	}

	m_chara = new QGraphicsFaceItem();
	m_chara->setScale(1.0);
	ui->viewChara->resize(192,192);
	ui->viewChara->setMinimumHeight(196);
	m_charaScene = new QGraphicsPickerScene(ui->viewChara, m_chara, 4, 4);
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

dialogfacepicker::~dialogfacepicker()
{
	delete ui;
}

int dialogfacepicker::frame()
{
	return m_chara->frame();
}

void dialogfacepicker::setFrame(int frame)
{
	m_chara->setFrame(frame);
}

std::string dialogfacepicker::name()
{
	QString name = ui->listRess->currentItem()->text();
	if (name.contains("*"))
		name = "";
	return name.toStdString();
}

void dialogfacepicker::setName(std::string name)
{
	if (name.empty() && ui->listRess->count() > 0)
	{
		ui->listRess->setCurrentRow(0);
		return;
	}
	QList<QListWidgetItem*> items = ui->listRess->findItems(QString::fromStdString(name),
															Qt::MatchFixedString);
	if (!items.empty())
		ui->listRess->setCurrentItem(items[0]);
}

void dialogfacepicker::setAnimated(bool animated)
{
	if (animated)
		m_timer->start(200);
	else
		m_timer->stop();
}

int dialogfacepicker::index() const
{
	if (ui->listRess->currentItem()->text().contains("*"))
		return m_tileScene->index();
	return m_charaScene->index();
}

void dialogfacepicker::setIndex(int index)
{
	if (ui->listRess->currentItem()->text().contains("*"))
		m_tileScene->setIndex(index);
	else
		m_charaScene->setIndex(index);
}

void dialogfacepicker::on_listRess_currentRowChanged(int currentRow)
{
	Q_UNUSED(currentRow)
	if (ui->listRess->currentItem()->text().contains("*"))
	{
		ui->stackedMain->setCurrentWidget(ui->pageTileset);
		return;
	}
	else
	{
		ui->stackedMain->setCurrentWidget(ui->pageChara);
		m_chara->setBasePix(ui->listRess->currentItem()->text());
	}
}

void dialogfacepicker::ok()
{
	setResult(QDialogButtonBox::Ok);
}
