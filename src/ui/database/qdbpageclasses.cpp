#include "qdbpageclasses.h"
#include "ui_qdbpageclasses.h"
#include <QTimer>

QDbPageClasses::QDbPageClasses(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QDbPageClasses),
	m_data(database)
{
	ui->setupUi(this);

	m_currentClass = nullptr;

	m_battlerItem = new QGraphicsBattleAnimationItem();

	ui->graphicsBattler->setScene(new QGraphicsScene(this));
	ui->graphicsBattler->scene()->addItem(m_battlerItem);
	ui->graphicsBattler->scene()->setSceneRect(0,0,48,48);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), ui->graphicsBattler->scene(), SLOT(advance()));
	timer->start(200);
	UpdateModels();
	if (ui->listClasses->count())
		ui->listClasses->setCurrentRow(0);
}

void QDbPageClasses::UpdateModels()
{
	/* Clear */
	ui->listClasses->clear();

	/* Fill */
	for (unsigned int i = 0; i < m_data.classes.size(); i++)
		ui->listClasses->addItem(QString("%1: %2")
							   .arg(QString::number(i+1), 4, QLatin1Char('0'))
							   .arg(m_data.classes[i].name.c_str()));

	/* TODO: Fill battle commands combos*/

	on_currentClassChanged(m_currentClass);
}

void QDbPageClasses::on_currentClassChanged(RPG::Class *_class)
{
	/* TODO: Update Widgets */
	m_currentClass = _class;
	emit currentClassChanged(_class);
}

QDbPageClasses::~QDbPageClasses()
{
	delete ui;
}
