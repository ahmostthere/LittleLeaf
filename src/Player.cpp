#include "Player.hpp"
#include <iostream>
#include <cmath>
#define PI std::acos(-1)

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(sf::Vector2f position)
{
    m_position = position;
    m_circle.setFillColor(sf::Color::Blue);
    m_circle.setRadius(50);
    m_circle.setPosition(position);
    m_speed = 100;
}

void Player::handleMove(sf::Time _time, sf::Uint8 _dir)
{
    float theta = 0;
    switch (_dir)
    {
    // N
    case 0b1000:
    case 0b1101:
        theta = PI * 3 / 2;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // E
    case 0b0100:
    case 0b1110:
        theta = PI * 2;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // S
    case 0b0010:
    case 0b0111:
        theta = PI * 1 / 2;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // W
    case 0b0001:
    case 0b1011:
        theta = PI;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // NE
    case 0b1100:
        theta = PI * 7 / 4;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // NW
    case 0b1001:
        theta = PI * 5 / 4;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // SE
    case 0b0110:
        theta = PI * 1 / 4;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    // SW
    case 0b0011:
        theta = PI * 3 / 4;
        m_circle.move(std::cos(theta) * m_speed * _time.asSeconds(), std::sin(theta) * m_speed * _time.asSeconds());
        break;

    default:
        break;
    }
}