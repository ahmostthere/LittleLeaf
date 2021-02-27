/*
FILE
-----------------------------------------------------------------------------------------------
GameStates.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-08-06

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef GAME_STATES
#define GAME_STATES

#include "GameState.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"

class GameStates {
public:
    GameStates();

    enum State {
        Menu,
        Play,
        Pause
    };
};

#endif //GAME_STATES