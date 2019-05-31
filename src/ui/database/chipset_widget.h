#ifndef QDBPAGECHIPSET_H
#define QDBPAGECHIPSET_H

#include <QWidget>
#include <data.h>

namespace Ui {
class ChipSetWidget;
}

class ChipSetWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ChipSetWidget(RPG::Database &database, QWidget *parent = nullptr);
	~ChipSetWidget();

private:
	Ui::ChipSetWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGECHIPSET_H
