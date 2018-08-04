/*
FILE
-----------------------------------------------------------------------------------------------
GameStateManager.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------
Game State Manager uses stack of Game States
*/
#ifndef GAME_STATE_MANAGER
#define GAME_STATE_MANAGER

#include "NodeStack.hpp"
#include "GameState.hpp"

class GameStateManager {
public:
    GameStateManager();
    ~GameStateManager();
    GameState *currentState();
    void pushState(GameState *newState);
    void popState();
    void switchState(GameState *newState);

private:
    NodeStack<GameState *> m_GameStateStack;
};

#endif //GAME_STATE_MANAGER
