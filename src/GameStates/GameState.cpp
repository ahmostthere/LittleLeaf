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
#include "GameStateManager.hpp"

GameState::~GameState() { }

bool GameState::quit = false;

std::string GameState::name = "Game State";

sf::RenderWindow GameState::m_Window;