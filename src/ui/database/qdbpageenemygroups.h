#ifndef QDBPAGEENEMYGROUPS_H
#define QDBPAGEENEMYGROUPS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageEnemyGroups;
}

class QDbPageEnemyGroups : public QWidget
{
	Q_OBJECT

public:
	explicit QDbPageEnemyGroups(RPG::Database &database, QWidget *parent = nullptr);
	~QDbPageEnemyGroups();

private:
	Ui::QDbPageEnemyGroups *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEENEMYGROUPS_H
