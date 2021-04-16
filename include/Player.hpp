#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

class Player : public Character
{
public:
    int m_speed;
    sf::Vector2f m_position;
    sf::CircleShape m_circle;
    sf::Uint8 m_direction;

    Player();
    ~Player();
    void init(const sf::Vector2f position);
    void handleMove(sf::Time _time, sf::Uint8 _dir);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_circle, states);
    }
};

#endif