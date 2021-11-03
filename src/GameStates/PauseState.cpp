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

GameState::State PauseState::getState() { return Pause; }

void PauseState::onEnter()
{
    nextState = Pause;
    m_window.create(sf::VideoMode(1080, 720), "Pause");
    std::cout << "Enter Pause State" << std::endl;
}

void PauseState::onExit()
{
    m_window.close();
    std::cout << "Exit Pause State" << std::endl;
}

void PauseState::onReveal()
{
    nextState = Pause;
    m_window.create(sf::VideoMode(1080, 720), "Pause");
    std::cout << "Reveal Pause State" << std::endl;
}

void PauseState::onConseal()
{
    m_window.close();
    std::cout << "Conseal Pause State" << std::endl;
}

void PauseState::handleInputs()
{
    sf::Event currentEvent;
    while (m_window.pollEvent(currentEvent))
    {
        switch (currentEvent.type)
        {
        case sf::Event::Closed:
            quit = true;
            break;

        case sf::Event::KeyPressed:
            switch (currentEvent.key.code)
            {
            case sf::Keyboard::S:
                std::cout << "In Pause " << nextState << std::endl;
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

void PauseState::update()
{
}

void PauseState::render()
{
    m_window.clear();

    m_window.display();
}
