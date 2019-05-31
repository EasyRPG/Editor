#ifndef DIALOGIMPORTIMAGE_H
#define DIALOGIMPORTIMAGE_H

#include <QDialog>
#include <QGraphicsPixmapItem>

#include "import_item.h"

namespace Ui {
class ImportImageDialog;
}

class ImportImageDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit ImportImageDialog(QString n_filepath, QWidget *parent = nullptr);
	~ImportImageDialog();

	QImage image();
	
private slots:
	void on_pushZoomIn_clicked();

	void on_pushZoomOut_clicked();

	void image_clicked(QPointF pos, bool pressed);

private:
	Ui::ImportImageDialog *ui;

	qreal m_scale;
	QString m_filepath;
	QGraphicsScene *scene;
	ImportItem * m_pixmap;

};

#endif // DIALOGIMPORTIMAGE_H
