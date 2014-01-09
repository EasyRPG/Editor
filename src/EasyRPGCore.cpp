#include "EasyRPGCore.h"
#include <QApplication>

//define static members
GameProject* EasyRPGCore::m_currentProject = 0;
QPixmap* EasyRPGCore::m_currentChipset = 0;
int EasyRPGCore::m_tileSize = 0;
QString EasyRPGCore::m_currentGameTitle = QString();
QString EasyRPGCore::m_currentProjectPath = QString();
EasyRPGCore::Layer EasyRPGCore::m_currentLayer = EasyRPGCore::LOWER;
EasyRPGCore::Tool EasyRPGCore::m_currentTool = EasyRPGCore::PENCIL;
EasyRPGCore::Zoom EasyRPGCore::m_currentZoom = EasyRPGCore::Z_11;


GameProject *EasyRPGCore::currentProject()
{
    return m_currentProject;
}

void EasyRPGCore::setCurrentProject(GameProject *current_project)
{
    if (m_currentProject)
        delete m_currentProject;
    m_currentProject = current_project;
}

void EasyRPGCore::LoadChipset(QString n_chipset)
{
    QPixmap * p_chipset = new QPixmap(111*tileSize(), tileSize());
}
int EasyRPGCore::tileSize()
{
    return m_tileSize;
}

void EasyRPGCore::setTileSize(int tile_size)
{
    m_tileSize = tile_size;
}
QString EasyRPGCore::currentProjectPath()
{
    return m_currentProjectPath;
}

void EasyRPGCore::setCurrentProjectPath(const QString &current_project_path)
{
    m_currentProjectPath = current_project_path;
}
EasyRPGCore::Layer EasyRPGCore::currentLayer()
{
    return m_currentLayer;
}

void EasyRPGCore::setCurrentLayer(const Layer &current_layer)
{
    m_currentLayer = current_layer;
}
EasyRPGCore::Tool EasyRPGCore::currentTool()
{
    return m_currentTool;
}

void EasyRPGCore::setCurrentTool(const Tool &current_tool)
{
    m_currentTool = current_tool;
}
EasyRPGCore::Zoom EasyRPGCore::currentZoom()
{
    return m_currentZoom;
}

void EasyRPGCore::setCurrentZoom(const Zoom &current_zoom)
{
    m_currentZoom = current_zoom;
}

QString EasyRPGCore::pathBackdrop(QString fileName) {return pathBackdrop()+fileName;}
QString EasyRPGCore::pathBattle(QString fileName) {return pathBattle()+fileName;}
QString EasyRPGCore::pathBattle2(QString fileName) {return pathBattle2()+fileName;}
QString EasyRPGCore::pathBattleCharSet(QString fileName) {return pathBattleCharSet()+fileName;}
QString EasyRPGCore::pathBattleWeapon(QString fileName) {return pathBattleWeapon()+fileName;}
QString EasyRPGCore::pathCharSet(QString fileName) {return pathCharSet()+fileName;}
QString EasyRPGCore::pathChipSet(QString fileName) {return pathChipSet()+fileName;}
QString EasyRPGCore::pathFaceSet(QString fileName) {return pathFaceSet()+fileName;}
QString EasyRPGCore::pathFrame(QString fileName) {return pathFrame()+fileName;}
QString EasyRPGCore::pathGameOver(QString fileName) {return pathGameOver()+fileName;}
QString EasyRPGCore::pathMonster(QString fileName) {return pathMonster()+fileName;}
QString EasyRPGCore::pathMovie(QString fileName) {return pathMovie()+fileName;}
QString EasyRPGCore::pathMusic(QString fileName) {return pathMusic()+fileName;}
QString EasyRPGCore::pathBackground(QString fileName) {return pathBackground()+fileName;}
QString EasyRPGCore::pathPicture(QString fileName) {return pathPicture()+fileName;}
QString EasyRPGCore::pathSound(QString fileName) {return pathSound()+fileName;}
QString EasyRPGCore::pathSystem(QString fileName) {return pathSystem()+fileName;}
QString EasyRPGCore::pathSystem2(QString fileName) {return pathSystem2()+fileName;}
QString EasyRPGCore::pathTitle(QString fileName) {return pathTitle()+fileName;}

QString EasyRPGCore::RtpPath()
{
    return (qApp->applicationDirPath() + "/RTP/");
}

QString EasyRPGCore::currentGameTitle()
{
    return m_currentGameTitle;
}

void EasyRPGCore::setCurrentGameTitle(const QString &currentGameTitle)
{
    m_currentGameTitle = currentGameTitle;
}


QString EasyRPGCore::pathTitle() {return m_currentProjectPath+"Title/";}
QString EasyRPGCore::pathSystem2() {return m_currentProjectPath+"System2/";}
QString EasyRPGCore::pathSystem() {return m_currentProjectPath+"System/";}
QString EasyRPGCore::pathSound() {return m_currentProjectPath+"Sound/";}
QString EasyRPGCore::pathPicture() {return m_currentProjectPath+"Picture/";}
QString EasyRPGCore::pathBackground() {return m_currentProjectPath+"Background/";}
QString EasyRPGCore::pathMusic() {return m_currentProjectPath+"Music/";}
QString EasyRPGCore::pathMovie() {return m_currentProjectPath+"Movie/";}
QString EasyRPGCore::pathMonster() {return m_currentProjectPath+"Monster/";}
QString EasyRPGCore::pathGameOver() {return m_currentProjectPath+"GameOver/";}
QString EasyRPGCore::pathFrame() {return m_currentProjectPath+"Frame/";}
QString EasyRPGCore::pathFaceSet() {return m_currentProjectPath+"FaceSet/";}
QString EasyRPGCore::pathChipSet() {return m_currentProjectPath+"ChipSet/";}
QString EasyRPGCore::pathCharSet() {return m_currentProjectPath+"CharSet/";}
QString EasyRPGCore::pathBattleWeapon() {return m_currentProjectPath+"BattleWeapon/";}
QString EasyRPGCore::pathBattleCharSet() {return m_currentProjectPath+"BattleCharSet/";}
QString EasyRPGCore::pathBattle2() {return m_currentProjectPath+"Battle2/";}
QString EasyRPGCore::pathBattle() {return m_currentProjectPath+"Battle/";}
QString EasyRPGCore::pathBackdrop() {return m_currentProjectPath+"Backdrop/";}



