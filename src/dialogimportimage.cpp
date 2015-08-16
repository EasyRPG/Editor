#include "dialogimportimage.h"
#include "ui_dialogimportimage.h"
#include <QFileInfo>
#include <QMessageBox>



DialogImportImage::DialogImportImage(QString n_filepath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogImportImage),
    m_scale(1.0),
    m_filepath(n_filepath)
{
    ui->setupUi(this);

    m_pixmap = new QGraphicsImportItem(QPixmap(m_filepath));


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
    ui->label->setText(QString("%1, %2, ").arg(pos.toPoint().x()).arg(pos.toPoint().y())
                       + (pressed ? "yes" : "no"));
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
