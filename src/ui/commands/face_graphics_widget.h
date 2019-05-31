#ifndef FACEGRAPHICS_H
#define FACEGRAPHICS_H

#include <QDialog>
#include <rpg_eventcommand.h>

namespace Ui {
class FaceGraphicsWidget;
}

class FaceGraphicsWidget : public QDialog
{
	Q_OBJECT

public:
	explicit FaceGraphicsWidget(QWidget *parent, RPG::EventCommand &cmd);
	~FaceGraphicsWidget();

private slots:


private:
	Ui::FaceGraphicsWidget *ui;
	RPG::EventCommand &cmd;
};

#endif // FACEGRAPHICS_H
