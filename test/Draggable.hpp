#ifndef DRAGGABLE_HPP
#define DRAGGABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Draggable : public sf::RectangleShape
{
public:
    explicit Draggable(const sf::Vector2f &size = sf::Vector2f(0, 0))
    {
        setSize(size);
        setFillColor(sf::Color::Blue);
    }

    bool isClicked() 
    {
        return m_isClicked;
    }

    void onClick(const sf::Vector2i &mousePos)
    {
        if (contains((sf::Vector2f)mousePos))
        {
            m_isClicked = true;
            m_relativePos = (sf::Vector2f)mousePos - getPosition();
        }
    }

    void onReleased()
    {
        m_isClicked = false;
    }

    void drag(const sf::Vector2i &mousePos)
    {
        if (m_isClicked)
        {
            setPosition((sf::Vector2f)mousePos - m_relativePos);
        }
    }

    const sf::Vector2f& getRelativePosition() const 
    {
        return m_relativePos;
    }

    bool contains(const sf::Vector2f &point)
    {
        return getGlobalBounds().contains(point);
    }

private:
    bool m_isClicked;
    sf::Vector2f m_relativePos;

};

#endif // DRAGGABLE