#include "face_graphics_widget.h"
#include "ui_face_graphics_widget.h"

FaceGraphicsWidget::FaceGraphicsWidget(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::FaceGraphicsWidget),
	cmd(cmd)
{
	ui->setupUi(this);

	//TODO
}

FaceGraphicsWidget::~FaceGraphicsWidget()
{
	delete ui;
}
