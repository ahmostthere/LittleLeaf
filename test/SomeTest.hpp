#ifndef TESTING
#define TESTING

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Quad.hpp"
#include "DragSelect.hpp"
#include "Tile.hpp"
#include "TileBoard.hpp"
#include <iostream>
#include <cmath>
// #include "Button.hpp"

// #define WIN_WIDTH 480
// #define WIN_HEIGHT 270
// #define TILE_SIZE 30
#define WIN_WIDTH 900
#define WIN_HEIGHT 600
#define TILE_SIZE 300

class Testing
{
public:
    static TileBoard *t_gameBoard;
    static sf::CircleShape t_mouseCircle;
    static sf::RectangleShape t_rotateSquare;
    static sf::RectangleShape t_negativeSquare;
    static DragSelect t_dragSelect;

    static sf::Texture t_ButtonTexture;
    // static Button upBtn;
    // static Button downBtn;
    // static Button leftBtn;
    // static Button rightBtn;

    
    static sf::RenderWindow m_window;
    static bool m_isQuitting;
    static void load();

    static void handleInput();
    static void update();
    static void render();
    static bool quitting();
    static void quit();
};

TileBoard *Testing::t_gameBoard;
sf::CircleShape Testing::t_mouseCircle;
sf::RectangleShape Testing::t_rotateSquare;
sf::RectangleShape Testing::t_negativeSquare;

// sf::Texture Testing::t_ButtonTexture;
// Button Testing::upBtn;
// Button Testing::downBtn;
// Button Testing::leftBtn;
// Button Testing::rightBtn;

sf::RenderWindow Testing::m_window;
bool Testing::m_isQuitting;
DragSelect Testing::t_dragSelect(&m_window);

void Testing::load()
{
    // Load / initialize other static variables

    t_gameBoard = new TileBoard(WIN_WIDTH / TILE_SIZE, WIN_HEIGHT / TILE_SIZE, TILE_SIZE);

    t_mouseCircle.setFillColor(sf::Color(220, 0, 0, 55));
    t_mouseCircle.setRadius(100);
    t_mouseCircle.setOrigin(sf::Vector2f(t_mouseCircle.getRadius(), t_mouseCircle.getRadius()));

    t_rotateSquare.setFillColor(sf::Color::Green);
    t_rotateSquare.setPosition(200, 200);
    t_rotateSquare.setOrigin(t_rotateSquare.getSize().x / 2, t_rotateSquare.getSize().y / 2);
    t_rotateSquare.setSize(sf::Vector2f(120, 120));
    
    t_negativeSquare.setFillColor(sf::Color::Red);
    t_negativeSquare.setPosition(200, 200);
    t_negativeSquare.setOrigin(t_negativeSquare.getSize().x / 2, t_negativeSquare.getSize().y / 2);
    t_negativeSquare.setSize(sf::Vector2f(120, -120));

    // Button Testing
    // t_ButtonTexture.loadFromFile("assets/arrowButtons.png");
    // upBtn = Button(
    //     t_ButtonTexture, 
    //     sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(400, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(400, 0), sf::Vector2i(100, 100)));
    // upBtn.setPosition(400, 300);
    // downBtn = Button(
    //     t_ButtonTexture, 
    //     sf::IntRect(sf::Vector2i(100, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(500, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(500, 0), sf::Vector2i(100, 100)));
    // downBtn.setPosition(400, 450);
    // leftBtn = Button(
    //     t_ButtonTexture, 
    //     sf::IntRect(sf::Vector2i(200, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(600, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(600, 0), sf::Vector2i(100, 100)));
    // leftBtn.setPosition(250, 450);
    // rightBtn = Button(
    //     t_ButtonTexture, 
    //     sf::IntRect(sf::Vector2i(300, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(700, 0), sf::Vector2i(100, 100)), 
    //     sf::IntRect(sf::Vector2i(700, 0), sf::Vector2i(100, 100)));
    // rightBtn.setPosition(550, 450);

    // t_dragSelect.setWindow(&m_window);

    m_isQuitting = false;

    m_window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Close);
    m_window.setFramerateLimit(60);
}

void Testing::handleInput()
{
    sf::Event curEvent;
    while (m_window.pollEvent(curEvent))
    {
        switch (curEvent.type)
        {
            case sf::Event::Closed:
                m_isQuitting = true;
                break;

            case sf::Event::KeyPressed:
            {
                switch (curEvent.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_isQuitting = true;
                        break;

                    case sf::Keyboard::Left:
                        // std::cout << "left Pressed" << std::endl;
                        // leftBtn.setButtonState(Button::SELECTED);
                        break;

                    case sf::Keyboard::Right:
                        // std::cout << "right Pressed" << std::endl;
                        // rightBtn.setButtonState(Button::SELECTED);
                        break;

                    case sf::Keyboard::Down:
                        // std::cout << "down Pressed" << std::endl;
                        // downBtn.setButtonState(Button::SELECTED);
                        break;

                    case sf::Keyboard::Up:
                        // upBtn.setButtonState(Button::SELECTED);
                        // std::cout << "up Pressed" << std::endl;
                        break;

                    case sf::Keyboard::R:
                        t_rotateSquare.setRotation(t_rotateSquare.getRotation() + 1);
                        break;

                    case sf::Keyboard::L:
                        std::cout << "local: ";
                        std::cout << t_rotateSquare.getLocalBounds().width << ", ";
                        std::cout << t_rotateSquare.getLocalBounds().height << std::endl;
                        break;

                    case sf::Keyboard::O:
                        std::cout << "global: ";
                        std::cout << t_rotateSquare.getGlobalBounds().width << ", ";
                        std::cout << t_rotateSquare.getGlobalBounds().height << std::endl;
                        break;

                    case sf::Keyboard::P:
                        // t_GameBoardQuad->printQuads();
                        break;

                    case sf::Keyboard::S:
                        break;

                    case sf::Keyboard::D:
                        break;

                    default:
                        break;
                }
                break;
            }

            case sf::Event::Resized:
                // m_window.setView();
                break;

            case sf::Event::MouseButtonPressed:
            {
                // t_dragSelect.start(m_window);
                t_dragSelect.start();
                if (!t_dragSelect.isHighlighted()) 
                    t_dragSelect.toggleHighlight();
                std::cout << "mouse pressed" << std::endl;
                
                break;
            }

            case sf::Event::MouseButtonReleased:
            {
                if (t_dragSelect.isHighlighted())
                    t_dragSelect.toggleHighlight();

                std::cout << "mouse released" << std::endl;

                // std::vector<Quad<Tile *>::Node *> them;    
                // them = qSearch(t_dragSelect.getPosition().x,
                //                 t_dragSelect.getPosition().y,
                //                 t_dragSelect.getPosition().x + t_dragSelect.getSize().x,
                //                 t_dragSelect.getPosition().y + t_dragSelect.getSize().y, 
                //                 somequad);


                // std::cout << them.size() << std::endl;
                // for (int i = 0; i < them.size(); i++)
                // {
                //     them[i]->data()->isSelected() ? them[i]->data()->deselect() : them[i]->data()->select();
                // }
                break;
            }

            case sf::Event::KeyReleased:
                switch (curEvent.key.code)
                {
                    case sf::Keyboard::Up:
                        // upBtn.setButtonState(Button::UNSELECTED);
                        // std::cout << "up Released" << std::endl;
                        break;
                    case sf::Keyboard::Left:
                        // leftBtn.setButtonState(Button::UNSELECTED);
                        // std::cout << "left Released" << std::endl;
                        break;
                    case sf::Keyboard::Right:
                        // rightBtn.setButtonState(Button::UNSELECTED);
                        // std::cout << "right Released" << std::endl;
                        break;
                    case sf::Keyboard::Down:
                        // downBtn.setButtonState(Button::UNSELECTED);
                        // std::cout << "down Released" << std::endl;
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Testing::update()
{
    //  Update stuff
    t_mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(m_window));

    t_dragSelect.update();
    t_gameBoard->update();

}

void Testing::render()
{
    m_window.clear();

    // Draw stuff
    // m_window.draw([somestuff])

    m_window.draw(*t_gameBoard);

    m_window.draw(t_rotateSquare);
    m_window.draw(t_negativeSquare);
    m_window.draw(t_mouseCircle);
    m_window.draw(t_dragSelect);
    // m_window.draw(upBtn);
    // m_window.draw(downBtn);
    // m_window.draw(leftBtn);
    // m_window.draw(rightBtn);

    m_window.display();
}

bool Testing::quitting()
{
    return m_isQuitting;
}

void Testing::quit()
{
    m_window.close();
}

#endif