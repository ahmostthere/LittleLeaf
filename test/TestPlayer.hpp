#include <SFML/Graphics/CircleShape.hpp>
#include "KeyMove.hpp"
#include "MouseMove.hpp"

class TestPlayer : public KeyMove, public MouseMove, public sf::CircleShape
{
public:
    explicit TestPlayer(float radius = 0, std::size_t pointCount = 30) : sf::CircleShape(radius, pointCount)
    {

    }

    void keyMove(Stack<sf::Keyboard::Key> keyStack, float speed, sf::Keyboard::Key _up = sf::Keyboard::W, sf::Keyboard::Key _down = sf::Keyboard::S, sf::Keyboard::Key _left = sf::Keyboard::A, sf::Keyboard::Key _right = sf::Keyboard::D)
    {
        KeyMove::keyMove(*this, keyStack, speed, _up, _down, _left, _right);
    }

    void mouseMove(float speed, const sf::Vector2f &offset = sf::Vector2f(0, 0), float minDistance = 2) 
    {
        MouseMove::mouseMove(*this, speed, offset, minDistance);
    }

    void resetMouseMovePosition(const sf::Vector2f &offset = sf::Vector2f(0, 0))
    {
        MouseMove::resetMouseMovePosition(*this, offset);
    }
};