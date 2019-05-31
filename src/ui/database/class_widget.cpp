#include "class_widget.h"
#include "ui_class_widget.h"
#include <QTimer>

ClassWidget::ClassWidget(RPG::Database &database, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ClassWidget),
	m_data(database)
{
	ui->setupUi(this);

	m_currentClass = nullptr;

	m_battlerItem = new BattleAnimationItem();

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

void ClassWidget::UpdateModels()
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

void ClassWidget::on_currentClassChanged(RPG::Class *_class)
{
	/* TODO: Update Widgets */
	m_currentClass = _class;
	emit currentClassChanged(_class);
}

ClassWidget::~ClassWidget()
{
	delete ui;
}
