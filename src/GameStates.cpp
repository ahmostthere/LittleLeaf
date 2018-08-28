/*
FILE
-----------------------------------------------------------------------------------------------
GameStates.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-08-06

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "GameStates.hpp"
#include <iostream>

MenuState::~MenuState() {}
void MenuState::onEnter() {
    std::cout << "Enter Menu" << std::endl;
}
void MenuState::onExit() {
    std::cout << "Exit Menu" << std::endl;
}
void onReveal() {

}
void onConseal() {
    
}
void MenuState::handleInputs() {

}
void MenuState::update() {

}
void MenuState::render() {

}


PlayState::~PlayState() {}
void PlayState::onEnter() {
    std::cout << "Enter Play" << std::endl;
}
void PlayState::onExit() {
    std::cout << "Exit Play" << std::endl;
}
void onReveal() {

}
void onConseal() {
    
}
void PlayState::handleInputs() {

}
void PlayState::update() {

}
void PlayState::render() {

}

PauseState::~PauseState() {}
void PauseState::onEnter() {
    std::cout << "Enter Pause" << std::endl;
}
void PauseState::onExit() {
    std::cout << "Exit Pause" << std::endl;
}
void onReveal() {
    std::cout << "Reveal Pause" << std::endl;
}
void onConseal() {
    std::cout << "Conseal Pause" << std::endl;
}
void PauseState::handleInputs() {

}
void PauseState::update() {

}
void PauseState::render() {

}

OptionsState::~OptionsState() {}
void OptionsState::onEnter() {
    std::cout << "Enter Options" << std::endl;
}
void OptionsState::onExit() {
    std::cout << "Exit Options" << std::endl;
}
void onReveal() {

}
void onConseal() {
    
}
void OptionsState::handleInputs() {

}
void OptionsState::update() {

}
void OptionsState::render() {

}