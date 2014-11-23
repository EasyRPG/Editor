#ifndef EDITORSETTINGS_H
#define EDITORSETTINGS_H

#include <QSettings>

class EditorSettings : public QSettings
{
public:

    static EditorSettings *Instance()
    {
        if (m_instance == 0)
        {
            m_instance = new EditorSettings();
        }

        return m_instance;
    }

private:
    EditorSettings();

    static EditorSettings *m_instance;
};

#endif // EDITORSETTINGS_H
