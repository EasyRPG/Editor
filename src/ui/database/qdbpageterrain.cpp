#include "qdbpageterrain.h"
#include "ui_qdbpageterrain.h"

QDbPageTerrain::QDbPageTerrain(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageTerrain),
	m_data(database)
{
	ui->setupUi(this);
}

QDbPageTerrain::~QDbPageTerrain()
{
	delete ui;
}
