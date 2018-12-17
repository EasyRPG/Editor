#include "dialogsplash.h"
#include "mainwindow.h"
#include "tools/qeventpagewidget.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("EasyRPG Editor");
	a.setOrganizationName("EasyRPG");
	a.setOrganizationDomain("easy-rpg.org");
	MainWindow w;
	DialogSplash s(&w);
	s.show();
	QTimer::singleShot(3000, &s, SLOT(hide()));
	QTimer::singleShot(3000, &w, SLOT(show()));

	w.LoadLastProject();

	return a.exec();
}
