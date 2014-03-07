#include "dialogcharapicker.h"
#include "ui_dialogcharapicker.h"
#include <QDir>
#include "core.h"

DialogCharaPicker::DialogCharaPicker(QWidget *parent, bool tile_pick) :
    QDialog(parent),
    ui(new Ui::DialogCharaPicker)
{
    ui->setupUi(this);
    ui->stackedStatic->setCurrentWidget(tile_pick ? ui->pageStatic : ui->pageEmpty);
    ui->stackedMain->setCurrentWidget(tile_pick ? ui->pageTileset : ui->pageChara);
    if (tile_pick)
    {
        ui->listRess->addItem(tr("*Tileset"));
    }

    QDir dir(mCore->filePath(CHARSET));
    QStringList entry = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);

    foreach (QString file, entry)
    {

        QFileInfo info(QString("%1/%2").arg(dir.path()).arg(file));

        if (info.isSymLink())
            continue;
        if (QString("png").contains(info.suffix(), Qt::CaseInsensitive))
            ui->listRess->addItem(info.baseName());
    }



    m_scene = new QGraphicsScene(ui->viewChara);
    ui->viewChara->setScene(m_scene);
    m_chara = new QGraphicsCharaItem();
    m_chara->setBasePix("char1");
    m_chara->setScale(2.0);
    m_scene->addItem(m_chara);
    m_selRect = new QGraphicsRectItem(0,0,24,32);
    m_selRect->setScale(2.0);
    m_scene->addItem(m_selRect);

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));

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
    return m_chara->frame();
}

void DialogCharaPicker::setFrame(int frame)
{
    m_chara->setFrame(frame);
    updateFrame();
}

int DialogCharaPicker::facing()
{
    return m_chara->facing();
}

void DialogCharaPicker::setFacing(int facing)
{
    m_chara->setFacing(facing);
    updateFacing();
}

std::string DialogCharaPicker::name()
{
    QString name = ui->listRess->currentItem()->text();
    if (name.contains("*"))
        name = "";
    return name.toStdString();
}

void DialogCharaPicker::setName(std::string name)
{
    QList<QListWidgetItem*> items = ui->listRess->findItems(QString::fromStdString(name),
                                                            Qt::MatchFixedString);
    if (!items.empty())
        items[0]->setSelected(true);
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
    return m_index;
}

void DialogCharaPicker::setIndex(int index)
{
    m_index = index;
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

void DialogCharaPicker::on_listRess_currentRowChanged(int currentRow)
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
