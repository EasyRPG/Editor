#include "import_image_dialog.h"
#include "ui_import_image_dialog.h"
#include <QFileInfo>
#include <QMessageBox>



ImportImageDialog::ImportImageDialog(QString n_filepath, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ImportImageDialog),
	m_scale(1.0),
	m_filepath(n_filepath)
{
	ui->setupUi(this);

	m_pixmap = new ImportItem(QPixmap(m_filepath));


	scene = new QGraphicsScene(this);
	scene->addItem(m_pixmap);
	scene->setBackgroundBrush(QBrush(QColor(Qt::gray),Qt::DiagCrossPattern));
	ui->graphicsView->setScene(scene);
}

ImportImageDialog::~ImportImageDialog()
{
	delete ui;
	delete scene;
}

QImage ImportImageDialog::image()
{
	return m_pixmap->pixmap().toImage();
}

void ImportImageDialog::image_clicked(QPointF pos, bool pressed)
{
	ui->label->setText(QString("%1, %2, ").arg(pos.toPoint().x()).arg(pos.toPoint().y())
					   + (pressed ? "yes" : "no"));
}

void ImportImageDialog::on_pushZoomIn_clicked()
{
	m_scale += 1.0;
	ui->graphicsView->resetTransform();
	ui->graphicsView->scale(m_scale,m_scale);
	if (static_cast<int>(m_scale) == 4)
		ui->pushZoomIn->setEnabled(false);
	ui->pushZoomOut->setEnabled(true);

}

void ImportImageDialog::on_pushZoomOut_clicked()
{
	m_scale -= 1.0;
	ui->graphicsView->resetTransform();
	ui->graphicsView->scale(m_scale,m_scale);
	if (static_cast<int>(m_scale) == 1)
		ui->pushZoomOut->setEnabled(false);
	ui->pushZoomIn->setEnabled(true);
}
