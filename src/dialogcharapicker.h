#ifndef DIALOGCHARAPICKER_H
#define DIALOGCHARAPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "tools/qgraphicscharaitem.h"
#include "tools/qgraphicspickerscene.h"

namespace Ui {
class DialogCharaPicker;
}

class DialogCharaPicker : public QDialog
{
	Q_OBJECT

public:
	explicit DialogCharaPicker(QWidget *parent, bool tile_pick);
	~DialogCharaPicker();

	int frame();
	void setFrame(int frame);

	int facing();
	void setFacing(int facing);

	std::string name();
	void setName(std::string name);

	void setAnimated(bool animated);

	int index() const;
	void setIndex(int index);

private slots:
	void on_toolUp_clicked();

	void on_toolRight_clicked();

	void on_toolDown_clicked();

	void on_toolLeft_clicked();

	void on_radioLeft_clicked();

	void on_radioMiddle_clicked();

	void on_radioRight_clicked();

	void on_listRess_currentRowChanged(int currentRow);

	void ok();

private:
	void updateFrame();
	void updateFacing();

	Ui::DialogCharaPicker *ui;
	QGraphicsPickerScene *m_charaScene;
	QGraphicsPickerScene *m_tileScene;
	QGraphicsCharaItem *m_chara;
	bool m_tilePick;
	QTimer *m_timer;
	int m_tileIndex;
	int m_charaIndex;
};

#endif // DIALOGCHARAPICKER_H
