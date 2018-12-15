#include "qdbpageskills.h"
#include "ui_qdbpageskills.h"

QDbPageSkills::QDbPageSkills(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageSkills),
	m_data(database)
{
	ui->setupUi(this);
}

QDbPageSkills::~QDbPageSkills()
{
	delete ui;
}
