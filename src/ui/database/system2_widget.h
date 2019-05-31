#ifndef QDBPAGESYSTEM2_H
#define QDBPAGESYSTEM2_H

#include <QWidget>
#include <data.h>

namespace Ui {
class SystemWidget2;
}

class SystemWidget2 : public QWidget
{
	Q_OBJECT

public:
	explicit SystemWidget2(RPG::Database &database, QWidget *parent = nullptr);
	~SystemWidget2();

private:
	Ui::SystemWidget2 *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGESYSTEM2_H
