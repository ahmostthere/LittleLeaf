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
    m_Time = m_Clock.restart();
}

bool GameState::quit = false;

GameState::State GameState::nextState;

sf::RenderWindow GameState::m_Window;

sf::Clock GameState::m_Clock;

sf::Time GameState::m_Time;