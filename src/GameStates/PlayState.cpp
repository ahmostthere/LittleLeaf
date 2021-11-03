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
    m_window.create(sf::VideoMode(PLAY_WIN_WIDTH, PLAY_WIN_HEIGHT), "Play State");
    std::cout << "Enter Play State" << std::endl;
    m_player = Player(sf::Vector2f(PLAY_WIN_WIDTH / 2, PLAY_WIN_HEIGHT / 2));

    m_dragSelect = DragSelect(&m_window);
}

void PlayState::onExit()
{
    m_window.close();
    std::cout << "Exit Play State" << std::endl;
}

void PlayState::onReveal()
{
    nextState = Play;
    m_window.create(sf::VideoMode(PLAY_WIN_WIDTH, PLAY_WIN_HEIGHT), "Play State");
    std::cout << "Reveal Play State" << std::endl;
    m_player = Player(sf::Vector2f(PLAY_WIN_WIDTH / 2, PLAY_WIN_HEIGHT / 2));

    m_dragSelect = DragSelect(&m_window);
}

void PlayState::onConseal()
{
    m_window.close();
    std::cout << "Conseal Play State" << std::endl;
}

void PlayState::handleInputs()
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
                    case (sf::Keyboard::Escape):
                        quit = true;
                        break;

                    case (sf::Keyboard::X):
                        m_player.resetMouseMovePosition();
                        break;

                    default:
                        break;
                }
                break;
                
            case sf::Event::KeyReleased:
                break;

            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) 
                {
                    m_player.setMouseMovePosition(sf::Mouse::getPosition(m_window));
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    m_dragSelect.onPressed();
                } 
                break;

            case sf::Event::MouseButtonReleased:
                m_dragSelect.onReleased();
                break;

            default:
                break;
        };
    }
}

void PlayState::update()
{
    m_player.handleButtonPress(sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::A);
    m_player.handleButtonMove(m_time);
    m_player.handleMouseMove(m_time);
    m_dragSelect.update();
}

void PlayState::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.draw(m_dragSelect);

    m_window.display();
}