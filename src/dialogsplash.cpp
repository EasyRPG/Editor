#include "dialogsplash.h"
#include "ui_dialogsplash.h"

DialogSplash::DialogSplash(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogSplash)
{
	ui->setupUi(this);
	setModal(true);
	setWindowFlags(Qt::SplashScreen);

	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addPixmap(QPixmap(":/embedded/share/logo.svg"));
	ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
	ui->graphicsView->setScene(scene);


	ui->graphicsView->scroll(ui->graphicsView->width()/2, ui->graphicsView->height()/2);
}

DialogSplash::~DialogSplash()
{
	delete ui;
}

