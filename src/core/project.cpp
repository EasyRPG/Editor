#include "project.h"

Project *Project::m_current = 0;

Project::Project(QObject *parent) :
QObject(parent)
{
    window = dynamic_cast<MainWindow *>(parent);
    if (!window)
        qDebug() << "ERROR: you must use the MainWindow as parent of the project";

    //Connect all signals.
    connect(this, &Project::gameTitleChanged, window, &MainWindow::on_gameTitleChanged);
}

void Project::Load(QString projectPath)
{
    if (!projectPath.endsWith('/'))
        projectPath.append("/");
    path = projectPath;

    //Throws exception
    settings = new ProjectSettings(this, filePath(ROOT, EASY_CFG));

    Data::Clear();
    if (!LDB_Reader::LoadXml(filePath(ROOT, EASY_DB).toStdString()))
    {
        Exception e;
        e.title = "Error loading project";
        e.description = "Could not load database file: " + filePath(ROOT, EASY_DB);
        e.code = Exception::FILE_NOT_FOUND;
        Data::Clear();
        throw (e);
    }
    if (!LMT_Reader::LoadXml(mCore->filePath(ROOT, EASY_MT).toStdString()))
    {
        Exception e;
        e.title = "Error loading project";
        e.description = "Could not load map tree file: " + filePath(ROOT, EASY_MT);
        Data::Clear();
        throw(e);
    }

    data = Data::data;

    if (!m_current)
        m_current = this;
}

QString Project::getGameTitle()
{
    return settings->getGameTitle();
}

void Project::setGameTitle(const QString &n_gameTitle)
{
    settings->setGameTitle(n_gameTitle);
    emit gameTitleChanged(n_gameTitle);
}

Layer Project::getEditionLayer() const
{
    return settings->getEditionLayer();
}

void Project::setEditionLayer(Layer layer)
{
    settings->setEditionLayer(layer);
    emit editionLayerChanged(layer);
}

void Project::setCurrent(Project *n_current)
{
    m_current = n_current;
    if (m_current)
        emit m_current->gameTitleChanged(m_current->getGameTitle());
}

QString Project::filePath(const QString &folder, const QString &filename)
{
    return path+folder+filename;
}
