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
    playButton = Button(
        playTexture,
        sf::IntRect(199, 0, 198, 150),
        sf::IntRect(1, 0, 198, 150),
        sf::IntRect(1, 0, 198, 150));
    quitButton = Button(
        quitTexture,
        sf::IntRect(176, 0, 174, 143),
        sf::IntRect(1, 0, 174, 143),
        sf::IntRect(1, 0, 174, 143));

    menuSplash.setPosition(0, 0);
    playButton.setPosition(((MENU_WIN_WIDTH * 1) / 3) - (199 / 2), ((MENU_WIN_HEIGHT * 7) / 9) - (150 / 2));
    quitButton.setPosition(((MENU_WIN_WIDTH * 2) / 3) - (176 / 2), ((MENU_WIN_HEIGHT * 7) / 9) - (143 / 2));
}

MenuState::~MenuState() {}

GameState::State MenuState::getState() 
{ 
    return Menu; 
}

void MenuState::onEnter()
{
    nextState = Menu;
    m_Window.create(sf::VideoMode(MENU_WIN_WIDTH, MENU_WIN_HEIGHT), "Main Menu");
    // std::cout << "Enter Menu State" << std::endl;
}

void MenuState::onExit()
{
    m_Window.close();
    // std::cout << "Exit Menu State" << std::endl;
}

void MenuState::onReveal()
{
    nextState = Menu;
    m_Window.create(sf::VideoMode(MENU_WIN_WIDTH, MENU_WIN_HEIGHT), "Main Menu");
    // std::cout << "Reveal Menu State" << std::endl;
}

void MenuState::onConseal()
{
    m_Window.close();
    // std::cout << "Conseal Menu State" << std::endl;
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
                    playButton.setButtonState(Button::SELECTED);
                    quitButton.setButtonState(Button::UNSELECTED);
                    play = !play;
                }
                break;

            case sf::Keyboard::Right:
                if (play)
                {
                    playButton.setButtonState(Button::UNSELECTED);
                    quitButton.setButtonState(Button::SELECTED);
                    play = !play;
                }
                break;

            default:
                break;
            };
            break;

        case sf::Event::MouseButtonPressed:
            if (playButton.contains(sf::Mouse::getPosition(m_Window)))
            {
                playButton.isPressed = true;
            }
            if (quitButton.contains(sf::Mouse::getPosition(m_Window)))
            {
                quitButton.isPressed = true;
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (playButton.contains(sf::Mouse::getPosition(m_Window)) && playButton.isPressed)
            {
                nextState = Play;
            }
            else
            {
                playButton.isPressed = false;
            }
            
            if (quitButton.contains(sf::Mouse::getPosition(m_Window)) && quitButton.isPressed)
            {
                quit = true;
            }
            else
            {
                quitButton.isPressed = false;
            }
            
            break;
        default:
            break;
        }
    }


}

void MenuState::update()
{
    // handle mouse hover
    if (playButton.contains(sf::Mouse::getPosition(m_Window)))
    {
        playButton.setButtonState(Button::HOVER);
        quitButton.setButtonState(Button::UNSELECTED);
        play = true;
    }

    if (quitButton.contains(sf::Mouse::getPosition(m_Window)))
    {
        playButton.setButtonState(Button::UNSELECTED);
        quitButton.setButtonState(Button::HOVER);
        play = false;
    }
}

void MenuState::render()
{
    m_Window.clear();
    m_Window.draw(menuSplash);
    m_Window.draw(playButton);
    m_Window.draw(quitButton);
    m_Window.display();
}
