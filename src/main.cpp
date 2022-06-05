/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ui/other/splash_dialog.h"
#include "ui/main_window.h"
#include "ui/event/event_page_widget.h"
#include <QApplication>
#include <QTranslator>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("EasyRPG Editor");
	a.setOrganizationName("EasyRPG");
	a.setOrganizationDomain("easyrpg.org");

	// load translations
	QTranslator t;
	if(t.load(QLocale(), QLatin1String("easyrpg-editor"), QLatin1String("_"), QLatin1String(":/i18n"))) {
		a.installTranslator(&t);
	} else {
		qDebug() << "No translation(s) available.";
	}

	MainWindow w;
	// FIXME: SplashScreen disabled for now, this imposed a 6s startup delay due to timers...
	//SplashDialog s(&w);
	//s.show();
	//QTimer::singleShot(3000, &s, SLOT(hide()));
	//QTimer::singleShot(3000, &w, SLOT(show()));
	w.LoadLastProject();
	w.show();

	return a.exec();
}
