#ifndef DIALOGFACEPICKER_H
#define DIALOGFACEPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "faceset_item.h"
#include "picker_scene.h"

namespace Ui {
class CharSetPickerDialog;
}

class faceset_picker_dialog: public QDialog
{
	Q_OBJECT

public:
	explicit faceset_picker_dialog(QWidget *parent, bool tile_pick);
	~faceset_picker_dialog();

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

	void on_listRes_currentRowChanged(int currentRow);

	void ok();

private:

	Ui::CharSetPickerDialog *ui;
	PickerScene *m_charaScene;
	PickerScene *m_tileScene;
	FaceSetItem *m_chara;
	QTimer *m_timer;
	int m_tileIndex;
	int m_charaIndex;
};

#endif // DIALOGFACEPICKER_H
