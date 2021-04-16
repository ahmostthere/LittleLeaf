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

GameStateManager::GameStateManager() {}

GameStateManager::~GameStateManager()
{
    m_GameStateStack.clear();
}

GameState *GameStateManager::currentGameState()
{
    return m_GameStateStack.top();
}

void GameStateManager::pushState(GameState *newState)
{
    if (!m_GameStateStack.empty())
    {
        currentGameState()->onConseal();
    }
    m_GameStateStack.push(newState);
    currentGameState()->onEnter();
}

void GameStateManager::popState()
{
    if (!empty())
    {
        currentGameState()->onExit();
        m_GameStateStack.pop();
        if (!empty())
        {
            currentGameState()->onReveal();
        }
    }
}

void GameStateManager::switchState(GameState *newState)
{
    if (!empty())
    {
        currentGameState()->onConseal();
        m_GameStateStack.pop();
        m_GameStateStack.push(newState);
        currentGameState()->onReveal();
    }
    else
    {
        m_GameStateStack.push(newState);
        currentGameState()->onEnter();
    }
}

bool GameStateManager::empty()
{
    return m_GameStateStack.empty();
}

void GameStateManager::goToNextState()
{
    if (currentGameState()->getState() != currentGameState()->nextState)
    {
        switch (currentGameState()->nextState)
        {
        case GameState::Menu:
            break;

        case GameState::Pause:
            pushState(new PauseState);
            break;

        case GameState::Play:
            switchState(new PlayState);
            break;

        default:
            break;
        }
    }
}

NodeStack<GameState *> GameStateManager::m_GameStateStack;