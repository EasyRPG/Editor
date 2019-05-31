#ifndef DIALOGCHARAPICKER_H
#define DIALOGCHARAPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "charset_item.h"
#include "picker_scene.h"

namespace Ui {
class CharSetPickerDialog;
}

class CharSetPickerDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CharSetPickerDialog(QWidget *parent, bool tile_pick);
	~CharSetPickerDialog();

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

	void on_listRes_currentRowChanged(int currentRow);

	void ok();

private:
	void updateFrame();
	void updateFacing();

	Ui::CharSetPickerDialog *ui;
	PickerScene *m_charaScene;
	PickerScene *m_tileScene;
	CharSetItem *m_chara;
	bool m_tilePick;
	QTimer *m_timer;
	int m_tileIndex;
	int m_charaIndex;
};

#endif // DIALOGCHARAPICKER_H
