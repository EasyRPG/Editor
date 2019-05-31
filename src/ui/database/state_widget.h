#ifndef QDBPAGEHEROSTATUS_H
#define QDBPAGEHEROSTATUS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class StateWidget;
}

class StateWidget : public QWidget
{
	Q_OBJECT

public:
	explicit StateWidget(RPG::Database &database, QWidget *parent = nullptr);
	~StateWidget();

private:
	Ui::StateWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEHEROSTATUS_H
