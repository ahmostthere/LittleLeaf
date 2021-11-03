/*
FILE
-----------------------------------------------------------------------------------------------
GameState.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "GameState.hpp"

GameState::~GameState() {}

void GameState::resetTimer()
{
    m_time = m_clock.restart();
}

void GameState::close()
{
    m_window.close();
}

bool GameState::quit = false;

GameState::State GameState::nextState;

sf::RenderWindow GameState::m_window;

sf::Clock GameState::m_clock;

sf::Time GameState::m_time;