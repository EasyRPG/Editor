#include "terrain_widget.h"
#include "ui_terrain_widget.h"

TerrainWidget::TerrainWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TerrainWidget),
	m_data(database)
{
	ui->setupUi(this);
}

TerrainWidget::~TerrainWidget()
{
	delete ui;
}
