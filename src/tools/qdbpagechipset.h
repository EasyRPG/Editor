#ifndef QDBPAGECHIPSET_H
#define QDBPAGECHIPSET_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageChipset;
}

class QDbPageChipset : public QWidget
{
	Q_OBJECT

public:
	explicit QDbPageChipset(RPG::Database &database, QWidget *parent = nullptr);
	~QDbPageChipset();

private:
	Ui::QDbPageChipset *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGECHIPSET_H
