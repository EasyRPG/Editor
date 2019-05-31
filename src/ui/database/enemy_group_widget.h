#ifndef QDBPAGEENEMYGROUPS_H
#define QDBPAGEENEMYGROUPS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class EnemyGroupWidget;
}

class EnemyGroupWidget : public QWidget
{
	Q_OBJECT

public:
	explicit EnemyGroupWidget(RPG::Database &database, QWidget *parent = nullptr);
	~EnemyGroupWidget();

private:
	Ui::EnemyGroupWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEENEMYGROUPS_H
