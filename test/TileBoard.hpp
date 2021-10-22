#ifndef TILE_BOARD_HPP
#define TILE_BOARD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include "Tile.hpp"
#include "Quad.hpp"
#include <iostream>
/*  
    _Tileboard A_
      c0  c1  c2
    +---+---+---+
  r0|0,0|1,0|2,0|
    +---+---+---+
  r1|0,1|1,1|2,1|
    +---+---+---+
  r2|0,2|1,2|2,2|
    +---+---+---+

    Tile (x, y) => A[c][r]
    Tile (0, 1) => A[0][1]
*/

typedef Quad<Tile *> QuadTile;

class TileBoard : public sf::Drawable 
{
private:
    int row;
    int col;
    int tilesize;
    bool centered;

    Tile** m_tileboard;
    QuadTile *m_tileboardQuad;
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for (int i = 0; i < col; i++) 
        {
            for (int j = 0; j < row; j++) 
            {
                target.draw(m_tileboard[i][j]);
            }
        }
    }

    

public:
    TileBoard(int _col, int _row, int _tilesize, bool _centered = false) 
    {
        row = _row;
        col = _col;
        tilesize = _tilesize;
        centered = _centered;
        m_tileboard = new Tile*[_col];
        sf::Vector2f tL(0,0);
        m_tileboardQuad = new Quad<Tile *>(sf::FloatRect(tL, sf::Vector2f(_col * tilesize, _row * tilesize)));
        for (int i = 0; i < col; i++) 
        {
            m_tileboard[i] = new Tile[_row];
        }

        for (int i = 0; i < col; i++) 
        {
            for (int j = 0; j < row; j++)
            {
                m_tileboard[i][j].setSize(sf::Vector2f(_tilesize, _tilesize));
                m_tileboard[i][j].setPosition(i * _tilesize + tL.x, j * _tilesize + tL.y);
                m_tileboardQuad->insert(new Quad<Tile *>::Node(&m_tileboard[i][j], m_tileboard[i][j].getPosition()));
            }
        }
    }

    ~TileBoard()
    {
        for (int i = 0; i < col; i++)
            delete[] m_tileboard[i];
        delete[] m_tileboard;
        delete m_tileboardQuad;
    }

    
    std::vector<QuadTile::Node *> qSearch(float _left, float _top, float _right, float _bottom, QuadTile *quad)
    {
        std::vector<QuadTile::Node *> results;
        if (_bottom < _top)
        {
            float t = _bottom;
            _bottom = _top;
            _top = t;
        }
        if (_right < _left)
        {
            float t = _left;
            _left = _right;
            _right = t;
        }

        if (_bottom < quad->top)
            return results;
        if (_top > quad->bottom)
            return results;
        if (_right < quad->left)
            return results;
        if (_left > quad->right)
            return results;

        if (_top <= quad->top)
            _top = quad->top;
        if (_left <= quad->left)
            _left = quad->left;
        if (_right >= quad->right)
            _right = quad->right;
        if (_bottom >= quad->bottom)
            _bottom = quad->bottom;

        if (quad->node == nullptr)
        {
            if (quad->tLQuad != nullptr)
            {
                std::vector<QuadTile::Node *> tLResults = qSearch(_left, _top, _right, _bottom, quad->tLQuad);
                results.insert(std::end(results), std::begin(tLResults), std::end(tLResults));
            }
            if (quad->tRQuad != nullptr)
            {
                std::vector<QuadTile::Node *> tRResults = qSearch(_left, _top, _right, _bottom, quad->tRQuad);
                results.insert(std::end(results), std::begin(tRResults), std::end(tRResults));
            }
            if (quad->bLQuad != nullptr)
            {
                std::vector<QuadTile::Node *> bLResults = qSearch(_left, _top, _right, _bottom, quad->bLQuad);
                results.insert(std::end(results), std::begin(bLResults), std::end(bLResults));
            }
            if (quad->bRQuad != nullptr)
            {
                std::vector<QuadTile::Node *> bRResults = qSearch(_left, _top, _right, _bottom, quad->bRQuad);
                results.insert(std::end(results), std::begin(bRResults), std::end(bRResults));
            }
        }
        else
        {
            if (quad->node->x >= _left &&
                quad->node->x <= _right &&
                quad->node->y >= _top &&
                quad->node->y <= _bottom)
            {
                results.push_back(quad->node);
            }
            if (quad->tLQuad != nullptr)
            {
                std::vector<QuadTile::Node *> tLResults = qSearch(_left, _top, _right, _bottom, quad->tLQuad);
                results.insert(std::end(results), std::begin(tLResults), std::end(tLResults));
            }
            if (quad->tRQuad != nullptr)
            {
                std::vector<QuadTile::Node *> tRResults = qSearch(_left, _top, _right, _bottom, quad->tRQuad);
                results.insert(std::end(results), std::begin(tRResults), std::end(tRResults));
            }
            if (quad->bLQuad != nullptr)
            {
                std::vector<QuadTile::Node *> bLResults = qSearch(_left, _top, _right, _bottom, quad->bLQuad);
                results.insert(std::end(results), std::begin(bLResults), std::end(bLResults));
            }
            if (quad->bRQuad != nullptr)
            {
                std::vector<QuadTile::Node *> bRResults = qSearch(_left, _top, _right, _bottom, quad->bRQuad);
                results.insert(std::end(results), std::begin(bRResults), std::end(bRResults));
                std::vector<int> inv;
            }
        }
        return results;
    }



    void update()
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                m_tileboard[i][j].update();
            }
        }
    }
};

#endif