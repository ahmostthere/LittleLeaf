/*
FILE
-----------------------------------------------------------------------------------------------
PlayState.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "PlayState.hpp"

PlayState::~PlayState() {}

GameState::State PlayState::getState() { return Play; }

void PlayState::onEnter() {
    nextState = Play;
    m_Window.create(sf::VideoMode(1920, 1080), "Play State");
    std::cout << "Enter Play State" << std::endl;
}

void PlayState::onExit() {
    m_Window.close();
    std::cout << "Exit Play State" << std::endl;
}

void PlayState::onReveal() {
    nextState = Play;
    m_Window.create(sf::VideoMode(1920, 1080), "Play State");
    std::cout << "Reveal Play State" << std::endl;
}

void PlayState::onConseal() {
    m_Window.close();
    std::cout << "Conseal Play State" << std::endl;
}

void PlayState::handleInputs() {
    sf::Event currentEvent;
    while (m_Window.pollEvent(currentEvent)) {
        switch (currentEvent.type) {
            case sf::Event::Closed:
                quit = true;
                break;

            case sf::Event::KeyPressed:
                switch (currentEvent.key.code) {
                    case sf::Keyboard::S:
                        std::cout << "In Play " << nextState << std::endl;
                        break;

                    case sf::Keyboard::Escape:
                        quit = true;
                        break;
                    default:
                        break;
                };
                break;

            default:
                break;
        }
    }
}

void PlayState::update() {

}

void PlayState::render() {
    m_Window.clear();

    m_Window.display();

}
