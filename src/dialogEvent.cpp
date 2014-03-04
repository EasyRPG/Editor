#include "DialogEvent.h"
#include "ui_dialogevent.h"
#include <QFileDialog>
#include <QSettings>
#include "tools/qeventwidget.h"
#include "core.h"

DialogEvent::DialogEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvent)
{
    ui->setupUi(this);
}

DialogEvent::~DialogEvent()
{
    delete ui;
}

void DialogEvent::edit(QWidget *parent, RPG::Event *event)
{
    DialogEvent dlg(parent);
    dlg.setEvent(*event);
    dlg.exec();

}
RPG::Event DialogEvent::event() const
{
    return m_event;
}

void DialogEvent::setEvent(const RPG::Event &event)
{
    m_event = event;
    ui->lineName->setText(QString::fromStdString(m_event.name));
    this->setWindowTitle(QString("EV: %1").arg(m_event.ID));
    ui->tabEventPages->clear();
    for (unsigned int i = 0; i < m_event.pages.size(); i++)
    {
        QEventWidget *tab = new QEventWidget(this);
        tab->setEventPage(&(m_event.pages[i]));
        ui->tabEventPages->addTab(tab,QString::number(i+1));
    }
}
