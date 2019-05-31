/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

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

