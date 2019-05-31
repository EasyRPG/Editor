#ifndef QDBPAGEATTIBUTES_H
#define QDBPAGEATTIBUTES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class AttributeWidget;
}

class AttributeWidget : public QWidget
{
	Q_OBJECT

public:
	explicit AttributeWidget(RPG::Database &database, QWidget *parent = nullptr);
	~AttributeWidget();

private:
	Ui::AttributeWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEATTIBUTES_H
