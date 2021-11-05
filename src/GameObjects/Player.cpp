#include <iostream>
#include "Player.hpp"
#include <cmath>
#define PI std::acos(-1)
#define DEFAULT_SPEED 500

Player::Player() : m_speed(DEFAULT_SPEED), m_player(sf::CircleShape(50)), m_direction(0b0000), isMoving(false)
{
    m_player.setFillColor(sf::Color::Blue);
    m_mouseMovePosition = m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius());
}

Player::Player(const sf::Vector2f &_position) : m_speed(DEFAULT_SPEED), m_player(sf::CircleShape(50)), m_direction(0b0000), isMoving(false)
{
    m_player.setFillColor(sf::Color::Blue);
    m_player.setPosition(_position);
    setPosition(_position);
    m_mouseMovePosition = m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius());
}

Player::~Player()
{
}

void Player::handleButtonPress(sf::Keyboard::Key _northKey, sf::Keyboard::Key _eastKey, sf::Keyboard::Key _southKey, sf::Keyboard::Key _westKey)
{
    if (sf::Keyboard::isKeyPressed(_northKey))
        m_direction |= N;
    else if (!sf::Keyboard::isKeyPressed(_northKey))
        m_direction &= ~N;

    if (sf::Keyboard::isKeyPressed(_eastKey))
        m_direction |= E;
    else if (!sf::Keyboard::isKeyPressed(_eastKey))
        m_direction &= ~E;

    if (sf::Keyboard::isKeyPressed(_southKey))
        m_direction |= S;
    else if (!sf::Keyboard::isKeyPressed(_southKey))
        m_direction &= ~S;

    if (sf::Keyboard::isKeyPressed(_westKey))
        m_direction |= W;
    else if (!sf::Keyboard::isKeyPressed(_westKey))
        m_direction &= ~W;
}

void Player::handleButtonMove(sf::Time _time)
{
    // default facing South
    float theta = PI * 1 / 2;

    switch (m_direction)
    {
        // N
        case N:
            std::cout << "N";
        case N | E | W:
            if (m_direction == (N | E | W))
                std::cout << "NEW";
            std::cout << std::endl;
            theta = PI * 3 / 2;
            isMoving = true;
            break;

        // E
        case E:
            std::cout << "E";
        case E | N | S:
            if (m_direction == (E | N | S))
                std::cout << "ENS";
            std::cout << std::endl;
            theta = PI * 2;
            isMoving = true;
            break;

        // S
        case S:
            std::cout << "S";
        case S | E | W:
            if (m_direction == (S | E | W))
                std::cout << "SEW";
            std::cout << std::endl;
            theta = PI * 1 / 2;
            isMoving = true;
            break;

        // W
        case W:
            std::cout << "W";
        case W | N | S:
            if (m_direction == (W | N | S))
                std::cout <<"WNS";
            std::cout << std::endl;
            theta = PI;
            isMoving = true;
            break;

        // NE
        case N | E:
            std::cout << "NE" << std::endl;
            theta = PI * 7 / 4;
            isMoving = true;
            break;

        // NW
        case N | W:
            std::cout << "NW"<< std::endl;
            theta = PI * 5 / 4;
            isMoving = true;
            break;

        // SE
        case S | E:
            std::cout << "SE"<< std::endl;
            theta = PI * 1 / 4;
            isMoving = true;
            break;

        // SW
        case S | W:
            std::cout << "SW"<< std::endl;
            theta = PI * 3 / 4;
            isMoving = true;
            break;

        // No Movement
        case 0b1111:
            if (m_direction == (N|E|S|W))
                std::cout << "NESW" <<std::endl;
        case 0b0000:
            if (m_direction == 0)
                std::cout << "~NESW" <<std::endl;
        case 0b1010:
            if (m_direction == (N|S))
                std::cout << "NS" <<std::endl;
        case 0b0101:
            if (m_direction == (E|W))
                std::cout << "EW" <<std::endl;

            isMoving = false;
            break;

        default:
            break;
    }

    if (isMoving) 
    {
        m_player.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        m_mouseMovePosition = m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius());
    }
}

void Player::handleMouseMove(sf::Time _time)
{
    sf::Vector2f posDif = m_mouseMovePosition - (m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius()));
    float theta = std::atan2(posDif.y, posDif.x);
    float distance = sqrt((posDif.x * posDif.x) + (posDif.y * posDif.y));
    if (distance > 2)
        m_player.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
    else
        m_mouseMovePosition = m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius());
}

void Player::setMouseMovePosition(const sf::Vector2i &_mousePosition)
{
    m_mouseMovePosition = sf::Vector2f(_mousePosition.x, _mousePosition.y);
}

void Player::resetMouseMovePosition()
{
    m_mouseMovePosition = m_player.getPosition() + sf::Vector2f(m_player.getRadius(), m_player.getRadius());
}