#ifndef QDBPAGEITEMS_H
#define QDBPAGEITEMS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ItemWidget(RPG::Database &database, QWidget *parent = nullptr);
	~ItemWidget();

private:
	Ui::ItemWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEITEMS_H
