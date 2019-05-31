#ifndef QDBPAGESYSTEM_H
#define QDBPAGESYSTEM_H

#include <QWidget>
#include <data.h>

namespace Ui {
class SystemWidget;
}

class SystemWidget : public QWidget
{
	Q_OBJECT

public:
	explicit SystemWidget(RPG::Database &database, QWidget *parent = nullptr);
	~SystemWidget();

private:
	Ui::SystemWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGESYSTEM_H
