#ifndef TILE_BOARD_HPP
#define TILE_BOARD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include "Tile.hpp"

class TileBoard : public sf::Drawable 
{
private:
    int row;
    int col;
    int tilesize;
    bool centered;

    Tile** m_tileboard;

public:
    TileBoard(int _row, int _col, int _tilesize, bool _centered = false) 
    {
        row = _row;
        col = _col;
        tilesize = _tilesize;
        centered = _centered;
        m_tileboard = new Tile*[_row];
        for (int r = 0; r < row; r++) 
        {
            m_tileboard[r] = new Tile[_col];
        }

    }

    ~TileBoard()
    {
        for (int i = 0; i < row; i++) 
            delete[] m_tileboard[i];
        delete[] m_tileboard;
    }

};

#endif