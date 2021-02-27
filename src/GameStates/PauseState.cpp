/*
FILE
-----------------------------------------------------------------------------------------------
PauseState.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "PauseState.hpp"


PauseState::~PauseState() {}

void PauseState::onEnter() {
    name = "Pause State";
    m_Window.create(sf::VideoMode(1080, 720), "Pause");
    std::cout << "Enter Pause State" << std::endl;
}

void PauseState::onExit() {
    m_Window.close();
    std::cout << "Exit Pause State" << std::endl;
}

void PauseState::onReveal() {
    name = "Pause State";
    m_Window.create(sf::VideoMode(1080, 720), "Pause");
    std::cout << "Reveal Pause State" << std::endl;
}

void PauseState::onConseal() {
    m_Window.close();
    std::cout << "Conseal Pause State" << std::endl;
}

void PauseState::handleInputs() {

}

void PauseState::update() {

}

void PauseState::render() {
    m_Window.clear();

    m_Window.display();
}