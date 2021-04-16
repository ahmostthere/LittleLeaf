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

#define PI std::acos(-1)

PlayState::~PlayState() {}

GameState::State PlayState::getState() { return Play; }

void PlayState::onEnter()
{
    nextState = Play;
    m_Window.create(sf::VideoMode(PLAY_WIN_WIDTH, PLAY_WIN_HEIGHT), "Play State");
    std::cout << "Enter Play State" << std::endl;
    m_player.init(sf::Vector2f(PLAY_WIN_WIDTH / 2, PLAY_WIN_HEIGHT / 2));
}

void PlayState::onExit()
{
    m_Window.close();
    std::cout << "Exit Play State" << std::endl;
}

void PlayState::onReveal()
{
    nextState = Play;
    m_Window.create(sf::VideoMode(PLAY_WIN_WIDTH, PLAY_WIN_HEIGHT), "Play State");
    std::cout << "Reveal Play State" << std::endl;
    m_player.init(sf::Vector2f(PLAY_WIN_WIDTH / 2, PLAY_WIN_HEIGHT / 2));
}

void PlayState::onConseal()
{
    m_Window.close();
    std::cout << "Conseal Play State" << std::endl;
}

void PlayState::handleInputs()
{
    sf::Event currentEvent;
    while (m_Window.pollEvent(currentEvent))
    {
        switch (currentEvent.type)
        {
        case sf::Event::Closed:
            quit = true;
            break;

        case sf::Event::KeyReleased:
            switch (currentEvent.key.code)
            {
            case sf::Keyboard::W:
                std::cout << "Up Released " << std::endl;
                m_player.m_direction &= 0b0111;
                break;

            case sf::Keyboard::D:
                std::cout << "Right Released " << std::endl;
                m_player.m_direction &= 0b1011;
                break;

            case sf::Keyboard::S:
                std::cout << "Down Released " << std::endl;
                m_player.m_direction &= 0b1101;
                break;

            case sf::Keyboard::A:
                std::cout << "Left Released " << std::endl;
                m_player.m_direction &= 0b1110;
                break;

                ;
            };
            break;

        case sf::Event::KeyPressed:
            switch (currentEvent.key.code)
            {
            case sf::Keyboard::P:
                // std::cout << "In Play " << nextState << std::endl;
                std::cout << "Direction: " << m_player.m_direction << std::endl;
                break;

            case sf::Keyboard::Escape:
                quit = true;
                break;

            case sf::Keyboard::W:
                std::cout << "Up Pressed " << std::endl;
                m_player.m_direction |= 0b1000;
                break;

            case sf::Keyboard::D:
                std::cout << "Right Pressed " << std::endl;
                m_player.m_direction |= 0b0100;
                break;

            case sf::Keyboard::S:
                std::cout << "Down Pressed " << std::endl;
                m_player.m_direction |= 0b0010;
                break;

            case sf::Keyboard::A:
                std::cout << "Left Pressed " << std::endl;
                m_player.m_direction |= 0b0001;
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

void PlayState::update()
{
    m_player.handleMove(m_Time, m_player.m_direction);
}

void PlayState::render()
{
    m_Window.clear();
    m_Window.draw(m_player);

    m_Window.display();
}
