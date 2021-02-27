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

void PlayState::onEnter() {
    name = "Play State";
    m_Window.create(sf::VideoMode(1920, 1080), "Play State");
    std::cout << "Enter Play State" << std::endl;
}

void PlayState::onExit() {
    std::cout << "Exit Play State" << std::endl;
}

void PlayState::onReveal() {
    name = "Play State";
    m_Window.create(sf::VideoMode(1920, 1080), "Play State");
    std::cout << "Reveal Play State" << std::endl;
}

void PlayState::onConseal() {
    std::cout << "Conseal Play State" << std::endl;
}

void PlayState::handleInputs() {
    
}

void PlayState::update() {

}

void PlayState::render() {

}