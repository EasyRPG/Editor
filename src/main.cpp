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

#include "ui/main_window.h"
#include "ui/event/event_page_widget.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTranslator>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// show splash
	QPixmap logo(":/app/splash.png");
	QSplashScreen s(logo, Qt::WindowStaysOnTopHint);
	s.showMessage("EasyRPG Editor");
	s.show();
#ifdef NDEBUG
	// close splash after 3 seconds for release
	QTimer::singleShot(3000, &s, &QWidget::close);
#endif

	a.setApplicationName("EasyRPG Editor");
	a.setOrganizationName("EasyRPG");
	a.setOrganizationDomain("easyrpg.org");

	// load translations
	s.showMessage("Loading translations...");
	a.processEvents();
	QTranslator t;
	bool found = false;
#ifndef NDEBUG
	// allow overwriting in debug builds
	QString e = getenv("EASYRPG_EDITOR_LANG_FILE");
	if (!e.isEmpty())
		found = t.load(e);
#endif
	if (!found)
		found = t.load(QLocale(), QLatin1String("easyrpg-editor"), QLatin1String("_"), QLatin1String(":/i18n"));
	if (found)
		a.installTranslator(&t);
	else
		qDebug() << "No translation(s) available.";

	// main window and project
	s.showMessage("Loading main window...");
	a.processEvents();
	MainWindow w;
	s.showMessage("Loading last project...");
	a.processEvents();
	w.LoadLastProject();
	s.clearMessage();
	w.show();
#ifndef NDEBUG
	// close splash immediately in debug
	s.finish(&w);
#endif

	// into event loop
	return a.exec();
}
