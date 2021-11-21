#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Stack.hpp"
#include <cmath>


class KeyMove 
{
public:
    friend class sf::Transformable;

    void keyMove(sf::Transformable &movable, Stack<sf::Keyboard::Key> keyStack, float speed, sf::Keyboard::Key _up = sf::Keyboard::W, sf::Keyboard::Key _down = sf::Keyboard::S, sf::Keyboard::Key _left = sf::Keyboard::A, sf::Keyboard::Key _right = sf::Keyboard::D);
};

void KeyMove::keyMove(sf::Transformable &movable, Stack<sf::Keyboard::Key> keyStack, float speed, sf::Keyboard::Key _up, sf::Keyboard::Key _down, sf::Keyboard::Key _left, sf::Keyboard::Key _right)
{
    float pi = std::acos(-1);
    float theta;
    bool isMoving = false, upPressed = keyStack.contains(_up), downPressed = keyStack.contains(_down), leftPressed = keyStack.contains(_left), rightPressed = keyStack.contains(_right);

    // 1key
    if (rightPressed)
    {
        theta = 0 * pi / 4;
        isMoving = true;
    }
    if (downPressed)
    {
        theta = 2 * pi / 4;
        isMoving = true;
    }
    if (leftPressed)
    {
        theta = 4 * pi / 4;
        isMoving = true;
    }
    if (upPressed)
    {
        theta = 6 * pi / 4;
        isMoving = true;
    }
    // 2keys
    if (downPressed && rightPressed)
    {
        theta = 1 * pi / 4;
        isMoving = true;
    }
    if (downPressed && leftPressed)
    {
        theta = 3 * pi / 4;
        isMoving = true;
    }
    if (upPressed && leftPressed)
    {
        theta = 5 * pi / 4;
        isMoving = true;
    }
    if (upPressed && rightPressed)
    {
        theta = 7 * pi / 4;
        isMoving = true;
    }
    if (upPressed && downPressed)
    {
        isMoving = false;
    }
    if (leftPressed && rightPressed)
    {
        isMoving = false;
    }
    // 3keys
    if (rightPressed && upPressed && downPressed)
    {
        theta = 0 * pi / 4;
        isMoving = true;
    }
    if (downPressed && leftPressed && rightPressed)
    {
        theta = 2 * pi / 4;
        isMoving = true;
    }
    if (leftPressed && upPressed && downPressed)
    {
        theta = 4 * pi / 4;
        isMoving = true;
    }
    if (upPressed && leftPressed && rightPressed)
    {
        theta = 6 * pi / 4;
        isMoving = true;
    }

    if (isMoving)
    {
        movable.move(sf::Vector2f(std::cos(theta) * speed, std::sin(theta) * speed));
    }
}