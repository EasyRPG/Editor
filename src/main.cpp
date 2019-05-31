#include "splash_dialog.h"
#include "main_window.h"
#include "tools/event_page_widget.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("EasyRPG Editor");
	a.setOrganizationName("EasyRPG");
	a.setOrganizationDomain("easy-rpg.org");
	MainWindow w;
	SplashDialog s(&w);
	s.show();
	QTimer::singleShot(3000, &s, SLOT(hide()));
	QTimer::singleShot(3000, &w, SLOT(show()));

	w.LoadLastProject();

	return a.exec();
}
