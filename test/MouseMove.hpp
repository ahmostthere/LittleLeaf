#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>

class MouseMove 
{
private:
    sf::Vector2f m_mouseMovePosition;
    
public:
    friend class sf::Transformable;
    
    void initMouseMovePosition(const sf::Vector2f &position);

    void mouseMove(sf::Transformable &movable, float speed, const sf::Vector2f &offset = sf::Vector2f(0, 0), float minDistance = 2);

    void setMouseMovePosition(const sf::Vector2i &mousePosition);

    void resetMouseMovePosition(sf::Transformable &movable, const sf::Vector2f &offset = sf::Vector2f(0, 0));
};

void MouseMove::initMouseMovePosition(const sf::Vector2f &position)
{
    m_mouseMovePosition = position;
}

void MouseMove::mouseMove(sf::Transformable &movable, float speed, const sf::Vector2f &offset, float minDistance)
{
    sf::Vector2f positionDifference = m_mouseMovePosition - (movable.getPosition() + offset);
    float theta = std::atan2(positionDifference.y, positionDifference.x);
    float distance = std::sqrt((positionDifference.x * positionDifference.x) + (positionDifference.y * positionDifference.y));
    if (distance > minDistance)
    {
        movable.move(std::cos(theta) * speed, std::sin(theta) * speed);
    }
    else
    {
        m_mouseMovePosition = movable.getPosition() + offset;
    }
}

void MouseMove::setMouseMovePosition(const sf::Vector2i &mousePosition)
{
    m_mouseMovePosition = sf::Vector2f(mousePosition.x, mousePosition.y);
}

void MouseMove::resetMouseMovePosition(sf::Transformable &movable, const sf::Vector2f &offset)
{
    m_mouseMovePosition = movable.getPosition() + offset;
}