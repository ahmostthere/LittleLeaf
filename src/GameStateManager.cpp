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
    return m_currentState;
}

void GameStateManager::pushState(GameState *newState) {
    m_GameStateStack.push(newState);
    m_currentState = m_GameStateStack.top();
    m_currentState->onEnter();
}

void GameStateManager::popState() {
    m_currentState->onExit();
    m_GameStateStack.pop();
    m_currentState = m_GameStateStack.top();
}

void GameStateManager::switchState(GameState *newState) {
    m_GameStateStack.pop();
    m_GameStateStack.push(newState);
}
