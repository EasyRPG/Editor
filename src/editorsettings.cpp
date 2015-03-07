#include "editorsettings.h"

#include <QApplication>

EditorSettings *EditorSettings::m_instance = 0;

EditorSettings::EditorSettings() :
    QSettings(qApp->applicationDirPath()+"/Easy.cfg",
              QSettings::IniFormat,
              qApp)
{
}
