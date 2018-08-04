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
#include <iostream>

GameState::~GameState() {

}
MenuState::~MenuState() {

}
PlayState::~PlayState() {
    
}
PauseState::~PauseState() {
    
}
OptionsState::~OptionsState() {
    
}

void MenuState::say() { 
    std::cout << "In Menu" << std::endl;
}

void PlayState::say() { 
    std::cout << "In Play" << std::endl; 
}

void PauseState::say() { 
    std::cout << "in Pause" << std::endl; 
}

void OptionsState::say() {
    std::cout << "in Options" << std::endl;
}