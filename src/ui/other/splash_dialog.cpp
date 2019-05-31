#include "splash_dialog.h"
#include "ui_splash_dialog.h"

SplashDialog::SplashDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SplashDialog)
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

SplashDialog::~SplashDialog()
{
	delete ui;
}

