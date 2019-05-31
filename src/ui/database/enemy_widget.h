#ifndef QDBPAGEENEMIES_H
#define QDBPAGEENEMIES_H

#include <QWidget>
#include <data.h>

namespace Ui {
class EnemyWidget;
}

class EnemyWidget : public QWidget
{
	Q_OBJECT

public:
	explicit EnemyWidget(RPG::Database &database, QWidget *parent = nullptr);
	~EnemyWidget();

private:
	Ui::EnemyWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGEENEMIES_H
