#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

class Player : public Character
{
public:
    int m_speed;
    sf::CircleShape m_player;
    // sf::CircleShape m_mouseMove;
    sf::Vector2f m_mouseMovePosition;
    sf::Uint8 m_direction;
    float m_theta;

    Player();
    Player(const sf::Vector2f &_position);
    ~Player();
    void handleButtonPress(sf::Keyboard::Key _northKey, sf::Keyboard::Key _eastKey, sf::Keyboard::Key _southKey, sf::Keyboard::Key _westKey);
    void handleButtonMove(sf::Time _time);
    void handleMouseMove(sf::Time _time);
    void setMouseMovePosition(const sf::Vector2i &_mousePosition);
    void resetMouseMovePosition();
    void update();

private: 
    bool isMoving;
    
    enum Dir
    {
        N = 0b1000,
        E = 0b0100,
        S = 0b0010,
        W = 0b0001
    };

    Dir m_dir; 
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_player, states);
        // target.draw(m_mouseMove, states);
    }
};

#endif