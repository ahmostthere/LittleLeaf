/*
FILE
-----------------------------------------------------------------------------------------------
GameStateManager.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "GameStateManager.hpp"

GameStateManager::GameStateManager() {
}

GameStateManager::~GameStateManager() {
}

GameState* GameStateManager::currentState() {
    return m_GameStateStack.top();
}

void GameStateManager::pushState(GameState *newState) {
    m_GameStateStack.push(newState);
}

void GameStateManager::popState() {
    m_GameStateStack.pop();
}

void GameStateManager::switchState(GameState *newState) {
    m_GameStateStack.pop();
    m_GameStateStack.push(newState);
}
