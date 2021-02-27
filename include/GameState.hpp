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
#ifndef GAME_STATE
#define GAME_STATE

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState();
    virtual void onEnter() = 0; // Enters Stack on State Push
    virtual void onReveal() = 0; // Obtain Top position on State Pop
    virtual void onConseal() = 0; // Relieve Top position on State Push
    virtual void onExit() = 0;     // Exits Stack on State Pop

    virtual void handleInputs() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    friend std::ostream &operator<<(std::ostream &os, const GameState &_gs) {
        os << _gs.name;
        return os;
    }

    static bool quit;
    static std::string name;
    static sf::RenderWindow m_Window;
};

#endif //GAME_STATE