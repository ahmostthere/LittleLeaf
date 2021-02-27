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

// #pragma once
#include "GameStates.hpp"
#include "NodeStack.hpp"

class GameStateManager {
private:
    static NodeStack<GameState *> m_GameStateStack;

public:
    GameStateManager();
    ~GameStateManager();
    static GameState *currentState();
    static void pushState(GameState *newState);
    static void popState();
    static void switchState(GameState *newState);
    static bool empty();

    static void printSize();
    static void printEmpty();

    friend std::ostream &operator<<(std::ostream &os, const GameStateManager &_gsm) {
        os << *(_gsm.m_GameStateStack.top());
        return os;
    }
};

#endif //GAME_STATE_MANAGER
