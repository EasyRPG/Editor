#ifndef QDBPAGESKILLS_H
#define QDBPAGESKILLS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageSkills;
}

class QDbPageSkills : public QWidget
{
	Q_OBJECT

public:
	explicit QDbPageSkills(RPG::Database &database, QWidget *parent = nullptr);
	~QDbPageSkills();

private:
	Ui::QDbPageSkills *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGESKILLS_H
