#include "dialogrungame.h"
#include "core.h"
#include <QLabel>
#include <QBoxLayout>

DialogRunGame::DialogRunGame(QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    QLabel *label = new QLabel(tr("Game is currently runing"), this);
    QFont font = label->font();
    font.setBold(true);
    font.setPixelSize(20);
    label->setFont(font);
    label->setFrameShape(QLabel::WinPanel);
    label->setFrameShadow(QLabel::Raised);
    m_process = new QProcess(this);
    this->setWindowFlags(Qt::SplashScreen);
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    layout->addWidget(label);
    layout->setMargin(0);
    this->setLayout(layout);
    this->adjustSize();
    this->move(parent->geometry().center().x() - this->width() / 2,
               parent->geometry().center().y() - this->height() / 2);
}

void DialogRunGame::run()
{
    m_process->setWorkingDirectory(mCore()->filePath(ROOT));
    m_process->start(mCore()->filePath(ROOT, PLAYER64), m_commands);
    connect(m_process, SIGNAL(finished(int)), this, SLOT(end()));
    exec();
}

void DialogRunGame::end()
{
    this->close();
}
QStringList DialogRunGame::commands() const
{
    return m_commands;
}

void DialogRunGame::setCommands(const QStringList &commands)
{
    m_commands = commands;
}

