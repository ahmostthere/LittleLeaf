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

sf::Clock Game::m_Clock;
sf::Time Game::m_Time;

void Game::start() {

    load();
    while (!GameStateManager::empty() && !GameStateManager::currentState()->quit) {
        m_Time = m_Clock.restart();
        handleInputs();
        update();
        render();
    }
    GameStateManager::currentState()->m_Window.close();
}

void Game::load() {
    GameStateManager::pushState(new MenuState);
}

void Game::handleInputs() {
    GameStateManager::currentState()->handleInputs();
}

void Game::update() {
    GameStateManager::currentState()->update();
}

void Game::render() {
    GameStateManager::currentState()->render();
}

/*
void Game::handleKeyPress(sf::Keyboard::Key eventKey) {
    switch (eventKey) {
        case sf::Keyboard::Escape:
            break;

        case sf::Keyboard::P:
            // m_GameStateManager.pushState(new PauseState);
            GameStateManager::pushState(new PauseState);
            break;

        case sf::Keyboard::Q:
            // m_GameStateManager.popState();
            GameStateManager::popState();
            std::cout << "POP" << std::endl;
            break;

        case sf::Keyboard::I:
            break;

        case sf::Keyboard::M:
            std::cout << "M pressed" << std::endl;
            break;

        case sf::Keyboard::E:
            // m_GameStateManager.printEmpty();
            GameStateManager::printEmpty();
            break;

        case sf::Keyboard::S:
            // m_GameStateManager.printSize();
            GameStateManager::printSize();
            std::cout << m_GameStateManager << std::endl;
            break;

        case sf::Keyboard::Up:
            break;

        case sf::Keyboard::Down:
            break;
        
        case sf::Keyboard::Left:
            break;
        
        case sf::Keyboard::Right:
            break;

        default:
            break;
    }
}
*/
