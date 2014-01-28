#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QString>
#include <vector>

class GameMap
{
public:
    GameMap();

    int m_w;
    int m_h;
    std::vector<short> m_lowerLayer;
    std::vector<short> m_upperLayer;
    void setWidth(int w);
    void setHeight(int h);
    void setSize(int w, int h);
};

#endif // GAMEMAP_H
