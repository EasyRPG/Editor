#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("EasyRPG Editor");
    a.setOrganizationName("EasyRPG");
    a.setOrganizationDomain("easy-rpg.org");
    MainWindow w;
    w.show();
    
    return a.exec();
}
