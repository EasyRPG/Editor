#include "dialogsplash.h"
#include "mainwindow.h"
#include "tools/qeventpagewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("EasyRPG Editor");
    a.setOrganizationName("EasyRPG");
    a.setOrganizationDomain("easy-rpg.org");
    MainWindow w;
    DialogSplash s(&w);
    w.show();
    s.show();
    QEventPageWidget::Init(&s, s.getProgressBar(), s.getLabel());
    w.LoadLastProject();
    return a.exec();
}
