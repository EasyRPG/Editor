#ifndef QDBPAGETERRAIN_H
#define QDBPAGETERRAIN_H

#include <QWidget>
#include <data.h>

namespace Ui {
class TerrainWidget;
}

class TerrainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TerrainWidget(RPG::Database &database, QWidget *parent = nullptr);
	~TerrainWidget();

private:
	Ui::TerrainWidget *ui;
	RPG::Database &m_data;
};

#endif // QDBPAGETERRAIN_H
