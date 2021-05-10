#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
private:
    sf::Vector2i m_index;
    sf::RectangleShape m_tile;
    sf::RectangleShape m_highlight;
    bool m_isSelected;
    // sf::Sprite m_sprite;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_tile);
        target.draw(m_highlight);
    }

public:
    explicit Tile(const sf::Vector2f &size = sf::Vector2f(0, 0))
    {
        setSize(size);
        m_isSelected = false;
        m_tile.setFillColor(sf::Color::White);
        m_tile.setOutlineColor(sf::Color::Black);
        m_tile.setOutlineThickness(1);

        m_highlight.setFillColor(sf::Color::Transparent);
    }

    void setIndex(const sf::Vector2i &index)
    {
        m_index = index;
    }

    const sf::Vector2i &getIndex() const
    {
        return m_index;
    }

    void select()
    {
        m_isSelected = true;
    }

    void deselect()
    {
        m_isSelected = false;
    }

    bool isSelected() {
        return m_isSelected;
    }

    void update()
    {
        m_highlight.setFillColor(m_isSelected ? sf::Color(0, 200, 200) : sf::Color::Transparent);
    }

    void setPosition(const sf::Vector2f &position)
    {
        m_tile.setPosition(position);
        m_highlight.setPosition(position);
    }

    void setPosition(float x, float y)
    {
        m_tile.setPosition(x, y);
        m_highlight.setPosition(x, y);
    }

    const sf::Vector2f &getPosition() const
    {
        return m_tile.getPosition();
    }

    void setOrigin(float x, float y)
    {
        m_tile.setOrigin(x, y);
        m_highlight.setOrigin(x, y);
    }

    void setOrigin(const sf::Vector2f &origin)
    {
        m_tile.setOrigin(origin);
        m_highlight.setOrigin(origin);
    }

    void setSize(const sf::Vector2f &size)
    {
        m_tile.setSize(size);
        m_highlight.setSize(size);
    }

    bool contains(const sf::Vector2f &point)
    {
        return m_tile.getLocalBounds().contains(point);
    }

    bool intersects(const sf::FloatRect &rectangle)
    {
        return m_tile.getLocalBounds().intersects(rectangle);
    }
};

#endif