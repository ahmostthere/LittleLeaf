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
#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#pragma once
#include "NodeStack.hpp"
#include "GameStates.hpp"

class GameStateManager
{
private:
    static NodeStack<GameState *> m_GameStateStack;

public:
    GameStateManager();
    ~GameStateManager();
    static GameState *currentGameState();
    static void pushState(GameState *newState);
    static void popState();
    static void switchState(GameState *newState);

    static bool empty();
    static void goToNextState();

    // friend std::ostream & operator<<(std::ostream &os, const GameStateManager &_gsm) {
    //     os << *(_gsm.m_GameStateStack.top());
    //     return os;
    // }
};

#endif //GAME_STATE_MANAGER
