#ifndef QDBPAGEPROFESSIONS_H
#define QDBPAGEPROFESSIONS_H

#include <QWidget>
#include <rpg_database.h>
#include <rpg_class.h>
#include "ui/common/battle_animation_item.h"

namespace Ui {
class ClassWidget;
}

class ClassWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ClassWidget(RPG::Database &database, QWidget *parent = nullptr);
	~ClassWidget();

	void UpdateModels();

public slots:
	void on_currentClassChanged(RPG::Class *_class);

signals:
	void currentClassChanged(RPG::Class *_class);

private:
	Ui::ClassWidget *ui;

	BattleAnimationItem *m_battlerItem;

	RPG::Class *m_currentClass;
	RPG::Database &m_data;
};

#endif // QDBPAGEPROFESSIONS_H
