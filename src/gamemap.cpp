#include "gamemap.h"
#include "EasyRPGCore.h"

GameMap::GameMap():
    m_w(0),
    m_h(0)
{
    setSize(20,15);
}

void GameMap::setWidth(int w)
{
    setSize(w, m_h);
}

void GameMap::setHeight(int h)
{
    setSize(m_w, h);
}

void GameMap::setSize(int w, int h)
{
    if (w == m_w && h == m_h)
        return;

    std::vector<short> n_lowerLayer;
    std::vector<short> n_upperLayer;

    int max_height = (h > m_h) ? h : m_h;
    int max_width = (w > m_w) ? w : m_w;
    for (int y = 0; y < max_height; y++)
        for (int x = 0; x < max_width; x++)
        {
            if (x > max_width-1 || y > max_height-1)
            {
                n_lowerLayer.push_back(0);
                n_upperLayer.push_back(0xFFFF);
            }
            else
            {
                n_lowerLayer.push_back(m_lowerLayer[x+y*m_w]);
                n_upperLayer.push_back(m_upperLayer[x+y*m_w]);
            }
        }
    m_w = w;
    m_h = h;
    m_lowerLayer = n_lowerLayer;
    m_upperLayer = n_upperLayer;
}
