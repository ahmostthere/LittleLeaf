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

sf::ContextSettings Game::m_Settings;
sf::RenderWindow Game::m_Window;
sf::Clock Game::m_Clock;
sf::Time Game::m_Time;

GameStateManager Game::t_GameStateManager;
bool Game::t_Exiting;

void Game::start() {

    load();
    
    while (!isExiting()) {
        m_Time = m_Clock.restart();

        handleInputs();
        update();
        render();
    }

    
    m_Window.close();
}

void Game::load() {
    t_Exiting = false; // initialize Exiting to false
    
    m_Settings.antialiasingLevel = 0;
    m_Window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Game Name", sf::Style::Default, m_Settings);
    m_Window.setFramerateLimit(60);


    t_GameStateManager.pushState(new MenuState);
}

void Game::handleInputs() {
    sf::Event currentEvent;
    while (m_Window.pollEvent(currentEvent)) {
        switch (currentEvent.type) {
        case sf::Event::Closed:
            t_Exiting = true;
            break;

        case sf::Event::KeyPressed:
            handleKeyPress(currentEvent.key.code);
            break;

        default:
            break;
        }
    }
}

void Game::handleKeyPress(sf::Keyboard::Key eventKey) {
    switch (eventKey) {
        case sf::Keyboard::Escape:
            t_Exiting = true;
            break;

        case sf::Keyboard::P:
            t_GameStateManager.pushState(new PauseState);
            break;

        case sf::Keyboard::I:
            break;

        case sf::Keyboard::M:
            break;

        default:
            break;
    }
}

void Game::update() {
    t_GameStateManager.currentState()->update();
}

void Game::render() {
    m_Window.clear();

    t_GameStateManager.currentState()->render();

    m_Window.display();
}

bool Game::isExiting() {
    return t_Exiting;   
}
