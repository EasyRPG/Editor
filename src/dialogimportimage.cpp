#include "dialogimportimage.h"
#include "ui_dialogimportimage.h"
#include <QFileInfo>
#include <QMessageBox>



DialogImportImage::DialogImportImage(QString n_filepath, QWidget *parent) :
    QDialog(parent),
    m_filepath(n_filepath),
    m_scale(1.0),
    ui(new Ui::DialogImportImage)
{
    ui->setupUi(this);

    m_pixmap = new QImportElement(QPixmap(m_filepath));


    scene = new QGraphicsScene(this);
    scene->addItem(m_pixmap);
    scene->setBackgroundBrush(QBrush(QColor(Qt::gray),Qt::DiagCrossPattern));
    ui->graphicsView->setScene(scene);
}

DialogImportImage::~DialogImportImage()
{
    delete ui;
    delete scene;
}

QImage DialogImportImage::image()
{
    return m_pixmap->pixmap().toImage();
}

void DialogImportImage::image_clicked(QPointF pos, bool pressed)
{
    ui->label->setText(QString("%1, %2, " + pressed?"yes":"no").arg(pos.toPoint().x()).arg(pos.toPoint().y()));
}

void DialogImportImage::on_pushZoomIn_clicked()
{
    m_scale += 1.0;
    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(m_scale,m_scale);
    if (m_scale == 4)
        ui->pushZoomIn->setEnabled(false);
    ui->pushZoomOut->setEnabled(true);

}

void DialogImportImage::on_pushZoomOut_clicked()
{
    m_scale -= 1.0;
    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(m_scale,m_scale);
    if (m_scale == 1)
        ui->pushZoomOut->setEnabled(false);
    ui->pushZoomIn->setEnabled(true);
}
