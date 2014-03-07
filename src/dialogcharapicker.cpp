#include "dialogcharapicker.h"
#include "ui_dialogcharapicker.h"

DialogCharaPicker::DialogCharaPicker(QWidget *parent, bool tile_pick) :
    QDialog(parent),
    ui(new Ui::DialogCharaPicker)
{
    ui->setupUi(this);
    QStringList charas;
    ui->stacked->setCurrentIndex(1);
    if (tile_pick)
    {
        ui->stacked->setCurrentIndex(0);
        charas.push_back(tr("*Tileset"));
    }
    m_scene = new QGraphicsScene(ui->view);
    ui->view->setScene(m_scene);
    m_chara = new QGraphicsCharaItem();
    m_chara->setBasePix("char1");
    m_chara->setScale(2.0);
    m_scene->addItem(m_chara);
    m_selRect = new QGraphicsRectItem(0,0,24,32);
    m_selRect->setScale(2.0);
    m_scene->addItem(m_selRect);

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));

    updateFacing();
    updateFrame();
}

DialogCharaPicker::~DialogCharaPicker()
{
    delete ui;
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
