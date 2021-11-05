#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// class Tile : public sf::Drawable
class Tile : public sf::RectangleShape
{
private:
    sf::Vector2i m_index;
    bool m_isSelected;

    friend std::ostream &operator<<(std::ostream &os, const Tile &_tile)
    {
        os << "(" << _tile.m_index.x << ", " << _tile.m_index.y << ")";
        return os;
    }

public:
    explicit Tile(const sf::Vector2f &size = sf::Vector2f(0, 0))
    {
        setIndex(sf::Vector2i(0,0));
        m_isSelected = false;

        setSize(size);
        setFillColor(sf::Color::White);
        setOutlineColor(sf::Color::Black);
        setOutlineThickness(1);
    }

    void setIndex(const sf::Vector2i &index)
    {
        m_index = index;
    }

    const sf::Vector2i &getIndex() const
    {
        return m_index;
    }

    void hover(const sf::Vector2i& mousePos)
    {
        contains((sf::Vector2f)mousePos) ?
            setFillColor(sf::Color(255, 255, 0, 180)) :
            m_isSelected?
                setFillColor(sf::Color(0, 255, 255, 180)) :
                setFillColor(sf::Color::White);
    }

    void areaHover(const sf::FloatRect &rectangle)
    {
        intersects(rectangle) ? 
            setFillColor(sf::Color(255, 255, 0, 180)) : 
            m_isSelected ? 
                setFillColor(sf::Color(0, 255, 255, 180)) : 
                setFillColor(sf::Color::White);
    }

    void generalHover(const sf::Vector2i &mousePos, const sf::FloatRect &rectangle)
    {
        (contains((sf::Vector2f)mousePos) || intersects(rectangle)) ?
            setFillColor(sf::Color(255, 255, 0, 180)) :
            m_isSelected ? 
                setFillColor(sf::Color(0, 255, 255, 180)) : 
                setFillColor(sf::Color::White);
    }
    
    void select()
    {
        setFillColor(sf::Color(0, 255, 255, 180));
        m_isSelected = true;
    }

    void deselect()
    {
        setFillColor(sf::Color::White);
        m_isSelected = false;
    }

    bool isSelected() 
    {
        return m_isSelected;
    }

    void update()
    {
    }

    bool contains(const sf::Vector2f &point)
    {
        return getGlobalBounds().contains(point);
    }

    bool intersects(const sf::FloatRect &rectangle)
    {
        return getGlobalBounds().intersects(rectangle);
    }
};

#endif