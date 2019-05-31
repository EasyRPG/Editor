#ifndef QDBPAGECOMMONEVENTS_H
#define QDBPAGECOMMONEVENTS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class CommonEventWidget;
}

class CommonEventWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CommonEventWidget(RPG::Database &database, QWidget *parent = nullptr);
	~CommonEventWidget();

private:
	Ui::CommonEventWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGECOMMONEVENTS_H
