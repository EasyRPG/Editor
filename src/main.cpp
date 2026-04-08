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

#include "core.h"
#include "ui/main_window.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTranslator>
#include <QTimer>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QStyleHints>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	app.setApplicationName("EasyRPG Editor");
	app.setOrganizationName("EasyRPG");
	app.setOrganizationDomain("easyrpg.org");

	// show splash
	QPixmap logo(":/app/splash.png");
	QSplashScreen s(logo, Qt::WindowStaysOnTopHint);

	// Style setup
	bool force_dark = false;

	// Kirigami only loads a custom style when using a static build
	// Lets wait for upstream to improve this
#if defined(KIRIGAMI_STATIC)
    // Default to org.kde.breeze style (from qqc2-breeze style)
	if (qEnvironmentVariableIsEmpty("QT_QUICK_CONTROLS_STYLE")) {
		const char* fstyle = "KIRIGAMI_FORCE_STYLE";
		if (qEnvironmentVariableIsEmpty(fstyle) || qEnvironmentVariableIntValue(fstyle) > 0) {
			// Built in EasyRPG Style (Theme.qml)
			qputenv("KIRIGAMI_FORCE_STYLE", "1");
			force_dark = true;
		}
		QQuickStyle::setStyle(QStringLiteral("org.kde.breeze"));
	}
#endif

	auto hints = app.styleHints();
	auto scheme_changed = [=]() {
		if (!force_dark && hints->colorScheme() == Qt::ColorScheme::Light) {
			QIcon::setThemeName("ezbright");
		} else {
			QIcon::setThemeName("ezdark");
		}
	};
	scheme_changed();
	QObject::connect(hints, &QStyleHints::colorSchemeChanged, scheme_changed);

	s.showMessage("EasyRPG Editor");
	//s.show();

#ifdef NDEBUG
	// close splash after 3 seconds for release
	QTimer::singleShot(3000, &s, &QWidget::close);
#endif

	// setup qml engine
	auto engine = core().qmlEngine();

	/*engine->loadFromModule("org.easyrpg.editor", "MainWindow");
	if (engine->rootObjects().isEmpty()) {
		return -1;
	}*/

	// load translations
	s.showMessage("Loading translations...");
	app.processEvents();
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
		app.installTranslator(&t);
	else
		qDebug() << "No translation(s) available.";

	// main window and project
	s.showMessage("Loading main window...");
	app.processEvents();
	MainWindow w;
	s.showMessage("Loading last project...");
	app.processEvents();
	w.LoadLastProject();
	s.clearMessage();
	w.show();
#ifndef NDEBUG
	// close splash immediately in debug
	s.finish(&w);
#endif

	// into event loop
	return app.exec();
}
