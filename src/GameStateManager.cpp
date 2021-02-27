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

GameStateManager::GameStateManager() { }

GameStateManager::~GameStateManager() { 
    m_GameStateStack.clear();
}

GameState* GameStateManager::currentState() {
    return m_GameStateStack.top();
}

void GameStateManager::pushState(GameState *newState) {
    if (!m_GameStateStack.empty()) {
        currentState()->onConseal();
    }
    m_GameStateStack.push(newState);
    currentState()->onEnter();
}

void GameStateManager::popState() {
    if (!empty()) {
        currentState()->onExit();
        m_GameStateStack.pop();
        if (!empty()) {
            currentState()->onReveal();
        }
    } 
}

void GameStateManager::switchState(GameState *newState) {
    currentState()->onConseal();

    m_GameStateStack.pop();
    m_GameStateStack.push(newState);

    currentState()->onReveal();
}

bool GameStateManager::empty() {
    return m_GameStateStack.empty();
}

void GameStateManager::printSize() {
    std::cout << m_GameStateStack.size() << std::endl;
}

void GameStateManager::printEmpty() {
    if (m_GameStateStack.empty()) {
        std::cout << "Stack Empty" << std::endl;
    } else {
        std::cout << "Stack Not Empty" << std::endl;
    }
}

NodeStack<GameState *> GameStateManager::m_GameStateStack;