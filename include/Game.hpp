/*
FILE
-----------------------------------------------------------------------------------------------
Game.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef GAME
#define GAME

#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameStateManager.hpp"

// #include "DebugUtils.hpp"

#define WIN_WIDTH 1080
#define WIN_HEIGHT 720
#define MS_PER_UPDATE 0.011

class Game {
public:
    static void start();

private:
    static void load();
    // static void handleKeyPress(sf::Keyboard::Key eventKey);

    static sf::Clock m_Clock;
    static sf::Time m_Time;
};

#endif // GAME