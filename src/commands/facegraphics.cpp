#include "facegraphics.h"
#include "ui_facegraphics.h"

FaceGraphics::FaceGraphics(QWidget *parent, RPG::EventCommand &cmd) :
    QDialog(parent),
    ui(new Ui::FaceGraphics),
    cmd(cmd)
{
    ui->setupUi(this);

    //TODO
}

FaceGraphics::~FaceGraphics()
{
    delete ui;
}
