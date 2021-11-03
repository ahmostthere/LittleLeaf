/*
FILE
-----------------------------------------------------------------------------------------------
GameState.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

class GameState
{
public:
    enum State
    {
        Menu,
        Play,
        Pause
    };
    virtual ~GameState();
    virtual void onEnter() = 0;   // Enters Stack on State Push
    virtual void onReveal() = 0;  // Obtain Top position on State Pop
    virtual void onConseal() = 0; // Relieve Top position on State Push
    virtual void onExit() = 0;    // Exits Stack on State Pop
    virtual State getState() = 0;

    virtual void handleInputs() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    void close();
    void resetTimer();

    static bool quit;
    static State nextState;
    static sf::RenderWindow m_window;
    static sf::Clock m_clock;
    static sf::Time m_time;

    // friend std::ostream &operator<<(std::ostream &os, const GameState &_gs) {
    //     os << _gs.name;
    //     return os;
    // }
};

#endif //GAME_STATE