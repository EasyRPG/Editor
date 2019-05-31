#ifndef QGRAPHICSFACEITEM_H
#define QGRAPHICSFACEITEM_H

#include <QGraphicsPixmapItem>

class FaceSetItem : public QGraphicsPixmapItem
{
public:
	  explicit FaceSetItem(const QPixmap pix = QPixmap(192,192));

		void setBasePix(const QString &n_pixName);

		int index() const;
		void setIndex(int index);

		int facing() const;
		void setFacing(int facing);

		int frame() const;
		void setFrame(int frame);

		void updatePix();

	signals:

	public slots:

	private:
		QPixmap m_pix;
		int m_index;
		int m_facing;
		int m_frame;
};

#endif // QGRAPHICSFACEITEM_H
