#ifndef QDBPAGESYSTEM_H
#define QDBPAGESYSTEM_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageSystem;
}

class QDbPageSystem : public QWidget
{
	Q_OBJECT

public:
	explicit QDbPageSystem(RPG::Database &database, QWidget *parent = nullptr);
	~QDbPageSystem();

private:
	Ui::QDbPageSystem *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGESYSTEM_H
