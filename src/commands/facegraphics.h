#ifndef FACEGRAPHICS_H
#define FACEGRAPHICS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class FaceGraphics;
}

class FaceGraphics : public QDialog
{
    Q_OBJECT

public:
    explicit FaceGraphics(QWidget *parent, RPG::EventCommand &cmd);
    ~FaceGraphics();

private slots:


private:
    Ui::FaceGraphics *ui;
    RPG::EventCommand &cmd;
};

#endif // FACEGRAPHICS_H
