#ifndef QDBPAGESKILLS_H
#define QDBPAGESKILLS_H

#include <QWidget>
#include <data.h>

namespace Ui {
class SkillWidget;
}

class SkillWidget : public QWidget
{
	Q_OBJECT

public:
	explicit SkillWidget(RPG::Database &database, QWidget *parent = nullptr);
	~SkillWidget();

private:
	Ui::SkillWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGESKILLS_H
