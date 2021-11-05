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

// #define WIN_WIDTH 480
// #define WIN_HEIGHT 270
// #define TILE_SIZE 30
#define WIN_WIDTH 900
#define WIN_HEIGHT 600
#define TILE_SIZE 30

class Testing
{
public:
    static TileBoard *t_gameBoard;
    static sf::CircleShape t_mouseCircle;
    static sf::RectangleShape t_rotateSquare;
    static sf::RectangleShape t_negativeSquare;
    static DragSelect t_dragSelect;
    
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

sf::RenderWindow Testing::m_window;
bool Testing::m_isQuitting;
DragSelect Testing::t_dragSelect(&m_window);

void Testing::load()
{
    // Load / initialize other static variables

    t_gameBoard = new TileBoard(WIN_WIDTH / TILE_SIZE, WIN_HEIGHT / TILE_SIZE, TILE_SIZE);

    t_mouseCircle.setRadius(10);
    t_mouseCircle.setFillColor(sf::Color(220, 0, 0, 55));
    t_mouseCircle.setOrigin(sf::Vector2f(t_mouseCircle.getRadius(), t_mouseCircle.getRadius()));

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
                        break;

                    case sf::Keyboard::Right:
                        break;

                    case sf::Keyboard::Down:
                        break;

                    case sf::Keyboard::Up:
                        break;

                    case sf::Keyboard::R:
                        break;

                    case sf::Keyboard::L:
                        break;

                    case sf::Keyboard::O:
                        break;

                    case sf::Keyboard::P:
                        // t_gameBoard->printQuads();
                        break;

                    case sf::Keyboard::S:
                        t_gameBoard->changeColors();
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
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    t_mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(m_window));
                    t_gameBoard->searchPoint(t_mouseCircle.getPosition())->isSelected() ? t_gameBoard->searchPoint(t_mouseCircle.getPosition())->deselect() : t_gameBoard->searchPoint(t_mouseCircle.getPosition())->select();
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    t_dragSelect.onPressed();
                }

                break;
            }

            case sf::Event::MouseButtonReleased:
            {
                // select tiles that are highlighted
                if (t_dragSelect.isHighlighted())
                {
                    std::vector<Tile *> found = t_gameBoard->search(t_dragSelect.getGlobalBounds());
                    for (int i = 0; i < found.size(); i++)
                    {
                        found[i]->select();
                    }
                }

                // turn off dragselect highlight
                t_dragSelect.onReleased();

                // t_mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(m_window));

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
                break;

            default:
                break;
        }
    }
}

void Testing::update()
{
    //  Update stuff
    t_dragSelect.update();

    // combination of mouse hover and highlight hover
    t_gameBoard->generalHover(sf::Mouse::getPosition(m_window),t_dragSelect.getGlobalBounds());
}

void Testing::render()
{
    m_window.clear();

    // Draw stuff

    m_window.draw(*t_gameBoard);

    m_window.draw(t_mouseCircle);
    m_window.draw(t_dragSelect);

    m_window.display();
}

bool Testing::quitting() { return m_isQuitting; }

void Testing::quit() { m_window.close(); }

#endif