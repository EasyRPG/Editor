#ifndef DIALOGFACEPICKER_H
#define DIALOGFACEPICKER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "tools/QGraphicsFaceItem.h"
#include "tools/QGraphicsPickerScene.h"

namespace Ui {
class DialogCharaPicker;
}

class dialogfacepicker: public QDialog
{
    Q_OBJECT

public:
    explicit dialogfacepicker(QWidget *parent, bool tile_pick);
    ~dialogfacepicker();

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

    void on_listRess_currentRowChanged(int currentRow);

    void ok();

private:

    Ui::DialogCharaPicker *ui;
    QGraphicsPickerScene *m_charaScene;
    QGraphicsPickerScene *m_tileScene;
    QGraphicsFaceItem *m_chara;
    QTimer *m_timer;
    int m_tileIndex;
    int m_charaIndex;
};

#endif // DIALOGFACEPICKER_H
