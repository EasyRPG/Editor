#ifndef DIALOGRUNGAME_H
#define DIALOGRUNGAME_H

#include <QDialog>
#include <QProcess>

class DialogRunGame : public QDialog
{
    Q_OBJECT
public:
    explicit DialogRunGame(QWidget *parent = 0);

    QStringList commands() const;
    void setCommands(const QStringList &commands);

    void run();

signals:

private slots:
    void end();

private:
    QStringList m_commands;
    QProcess *m_process;
};

#endif // DIALOGRUNGAME_H
