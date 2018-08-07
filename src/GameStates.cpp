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
void MenuState::onEnter()
{
    std::cout << "Enter Menu" << std::endl;
}
void MenuState::onExit()
{
    std::cout << "Exit Menu" << std::endl;
}

PlayState::~PlayState() {}
void PlayState::onEnter()
{
    std::cout << "Enter Play" << std::endl;
}
void PlayState::onExit()
{
    std::cout << "Exit Play" << std::endl;
}

PauseState::~PauseState() {}
void PauseState::onEnter()
{
    std::cout << "Enter Pause" << std::endl;
}
void PauseState::onExit()
{
    std::cout << "Exit Pause" << std::endl;
}

OptionsState::~OptionsState() {}
void OptionsState::onEnter()
{
    std::cout << "Enter Options" << std::endl;
}
void OptionsState::onExit()
{
    std::cout << "Exit Options" << std::endl;
}