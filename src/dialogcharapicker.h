#ifndef DIALOGCHARAPICKER_H
#define DIALOGCHARAPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "tools/QGraphicsCharaItem.h"

namespace Ui {
class DialogCharaPicker;
}

class DialogCharaPicker : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCharaPicker(QWidget *parent, bool tile_pick);
    ~DialogCharaPicker();

    void setAnimated(bool animated);

private slots:
    void on_toolUp_clicked();

    void on_toolRight_clicked();

    void on_toolDown_clicked();

    void on_toolLeft_clicked();

    void on_radioLeft_clicked();

    void on_radioMiddle_clicked();

    void on_radioRight_clicked();

private:
    void updateFrame();
    void updateFacing();

    Ui::DialogCharaPicker *ui;
    QGraphicsScene *m_scene;
    QGraphicsRectItem *m_selRect;
    QGraphicsCharaItem *m_chara;
    QTimer *m_timer;
};

#endif // DIALOGCHARAPICKER_H
