#include "skill_widget.h"
#include "ui_skill_widget.h"

SkillWidget::SkillWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SkillWidget),
	m_data(database)
{
	ui->setupUi(this);
}

SkillWidget::~SkillWidget()
{
	delete ui;
}
