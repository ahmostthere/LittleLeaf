/*
FILE
-----------------------------------------------------------------------------------------------
Game.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "Game.hpp"
#include <iostream>

void Game::start()
{
    load();
    while (!GameStateManager::empty() && !GameStateManager::currentGameState()->quit)
    {
        GameStateManager::currentGameState()->resetTimer();
        // std::cout << GameStateManager::currentGameState()->m_Time.asSeconds() << std::endl;
        GameStateManager::currentGameState()->handleInputs();
        GameStateManager::currentGameState()->update();
        GameStateManager::currentGameState()->render();
        GameStateManager::goToNextState();
        // std::cout << GameStateManager::currentGameState()->m_Time.asSeconds() << std::endl;
    }
    GameStateManager::currentGameState()->close();
}

void Game::load()
{
    GameStateManager::pushState(new MenuState);
}