/*
FILE
-----------------------------------------------------------------------------------------------
MenuState.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#include "MenuState.hpp"

MenuState::MenuState()
{
    if (!menuSplashTexture.loadFromFile("assets/menuSplash.png"))
    {
        return;
    }
    if (!playTexture.loadFromFile("assets/play.png"))
    {
        return;
    }
    if (!quitTexture.loadFromFile("assets/quit.png"))
    {
        return;
    }
    play = true;
    menuSplash.setTexture(menuSplashTexture);
    playSprite.setTexture(playTexture);
    quitSprite.setTexture(quitTexture);

    menuSplash.setPosition(0, 0);

    playSprite.setTextureRect(sf::IntRect(1, 0, 198, 150));
    playSprite.setPosition(((MENU_WIN_WIDTH * 1) / 3), ((MENU_WIN_HEIGHT * 7) / 9));
    playSprite.setOrigin(199 / 2, 150 / 2);

    quitSprite.setTextureRect(sf::IntRect(176, 0, 174, 143));
    quitSprite.setPosition(((MENU_WIN_WIDTH * 2) / 3), ((MENU_WIN_HEIGHT * 7) / 9));
    quitSprite.setOrigin(176 / 2, 143 / 2);
}

MenuState::~MenuState() {}

GameState::State MenuState::getState() { return Menu; }

void MenuState::onEnter()
{
    nextState = Menu;
    m_Window.create(sf::VideoMode(MENU_WIN_WIDTH, MENU_WIN_HEIGHT), "Main Menu");
    std::cout << "Enter Menu State" << std::endl;
}

void MenuState::onExit()
{
    m_Window.close();
    std::cout << "Exit Menu State" << std::endl;
}

void MenuState::onReveal()
{
    nextState = Menu;
    m_Window.create(sf::VideoMode(MENU_WIN_WIDTH, MENU_WIN_HEIGHT), "Main Menu");
    std::cout << "Reveal Menu State" << std::endl;
}

void MenuState::onConseal()
{
    m_Window.close();
    std::cout << "Conseal Menu State" << std::endl;
}

void MenuState::handleInputs()
{
    sf::Event currentEvent;
    while (m_Window.pollEvent(currentEvent))
    {
        switch (currentEvent.type)
        {
        case sf::Event::Closed:
            quit = true;
            break;

        case sf::Event::KeyPressed:
            switch (currentEvent.key.code)
            {
            case sf::Keyboard::Enter:
                if (play)
                {
                    nextState = Play;
                }
                else
                {
                    quit = true;
                }
                break;

            case sf::Keyboard::S:
                std::cout << "In Menu " << nextState << std::endl;
                break;

            case sf::Keyboard::Escape:
                quit = true;
                break;

            case sf::Keyboard::Left:
                if (!play)
                {
                    playSprite.setTextureRect(sf::IntRect(1, 0, 198, 150));
                    quitSprite.setTextureRect(sf::IntRect(176, 0, 174, 143));
                    play = !play;
                }
                break;

            case sf::Keyboard::Right:
                if (play)
                {
                    playSprite.setTextureRect(sf::IntRect(199, 0, 198, 150));
                    quitSprite.setTextureRect(sf::IntRect(1, 0, 174, 143));
                    play = !play;
                }
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

void MenuState::update()
{
}

void MenuState::render()
{
    m_Window.clear();
    m_Window.draw(menuSplash);
    m_Window.draw(playSprite);
    m_Window.draw(quitSprite);
    m_Window.display();
}
