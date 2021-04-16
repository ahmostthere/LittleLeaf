#ifndef TESTING
#define TESTING

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Quad.hpp"
#include "DragSelect.hpp"
#include "Tile.hpp"
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
    // static sf::RectangleShape t_gameBoard[WIN_WIDTH / TILE_SIZE][WIN_HEIGHT / TILE_SIZE];
    static Tile t_gameBoard[WIN_WIDTH / TILE_SIZE][WIN_HEIGHT / TILE_SIZE];
    static sf::CircleShape t_mouseCircle;
    static sf::RectangleShape t_rotateSquare;
    static DragSelect t_dragSelect;
    static Quad<Tile *> *t_GameBoardQuad;
    
    
    static sf::RenderWindow m_window;
    static bool m_isQuitting;
    static void load();

    static void handleInput();
    static void update();
    static void render();
    static bool quitting();
    static void quit();
};

Tile Testing::t_gameBoard[WIN_WIDTH / TILE_SIZE][WIN_HEIGHT / TILE_SIZE];
sf::CircleShape Testing::t_mouseCircle;
sf::RectangleShape Testing::t_rotateSquare;

DragSelect Testing::t_dragSelect;

sf::RenderWindow Testing::m_window;
bool Testing::m_isQuitting;
Quad<Tile *> *Testing::t_GameBoardQuad = new Quad<Tile *>(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(WIN_WIDTH, WIN_HEIGHT)));

void Testing::load()
{
    // Load / initialize other static variables
    for (int i = 0; i < sizeof(t_gameBoard) / sizeof(t_gameBoard[0]); i++)
    {
        for (int j = 0; j < sizeof(t_gameBoard[0]) / sizeof(Tile); j++)
        {
            t_gameBoard[i][j].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            t_gameBoard[i][j].setPosition(sf::Vector2f((i * TILE_SIZE) + (TILE_SIZE / 2), (j * TILE_SIZE) + (TILE_SIZE / 2)));
            t_gameBoard[i][j].setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));
            // t_gameBoard[i][j].setFillColor(
            //     // (i % 2) ? ((j % 2) ? sf::Color::White : sf::Color(150, 150, 150)) : ((j % 2) ? sf::Color(150, 150, 150) : sf::Color::White)
            //     sf::Color::White
            // );
            // t_gameBoard[i][j].setOutlineColor(sf::Color::Black);
            // t_gameBoard[i][j].setOutlineThickness(1);
            t_GameBoardQuad->insert(new Quad<Tile *>::Node(&t_gameBoard[i][j], t_gameBoard[i][j].getPosition()));
        }
    }

    t_mouseCircle.setFillColor(sf::Color(220, 0, 0, 55));
    t_mouseCircle.setRadius(100);
    t_mouseCircle.setOrigin(sf::Vector2f(t_mouseCircle.getRadius(), t_mouseCircle.getRadius()));

    t_rotateSquare.setFillColor(sf::Color::Green);
    t_rotateSquare.setPosition(100, 100);
    t_rotateSquare.setOrigin(t_rotateSquare.getSize().x / 2, t_rotateSquare.getSize().y / 2);
    t_rotateSquare.setSize(sf::Vector2f(120, 120));




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

                    case sf::Keyboard::Up:
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
                        t_GameBoardQuad->printQuads();

                    case sf::Keyboard::S:
                    {
                        int num = (sizeof(t_gameBoard) / sizeof(t_gameBoard[0])) / 3;
                        int num2 = (sizeof(t_gameBoard[0]) / sizeof(Tile)) / 3;
                        for (int i = num; i < num * 2; i++) 
                        {
                            for (int j = num2; j < num2 * 2; j++) 
                            {
                                t_gameBoard[i][j].select();
                            }
                        }
                        break;
                    }

                    case sf::Keyboard::D:
                    {
                        int num = (sizeof(t_gameBoard) / sizeof(t_gameBoard[0])) / 3;
                        int num2 = (sizeof(t_gameBoard[0]) / sizeof(Tile)) / 3;
                        for (int i = num; i < num * 2; i++) 
                        {
                            for (int j = num2; j < num2 * 2; j++) 
                            {
                                t_gameBoard[i][j].deselect();
                            }
                        }
                        break;
                    }

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
                t_dragSelect.start(m_window);
                std::cout << "mouse pressed" << std::endl;
                
                break;
            }

            case sf::Event::MouseButtonReleased:
            {
                std::vector<Quad<Tile *>::Node *>
                    them = t_GameBoardQuad->search(t_dragSelect.getPosition().x,
                                                   t_dragSelect.getPosition().y,
                                                   t_dragSelect.getPosition().x + t_dragSelect.getSize().x,
                                                   t_dragSelect.getPosition().y + t_dragSelect.getSize().y);

                std::cout << them.size() << std::endl;
                for (int i = 0; i < them.size(); i++)
                {
                    them[i]->data()->isSelected() ? them[i]->data()->deselect() : them[i]->data()->select();
                }
                t_dragSelect.end();

                break;
            }

            default:
                break;
        }
    }
}

void Testing::update()
{
    //  Update stuff
    t_mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(m_window));

    t_dragSelect.update(m_window);
    for (int i = 0; i < sizeof(t_gameBoard) / sizeof(t_gameBoard[0]); i++)
    {
        for (int j = 0; j < sizeof(t_gameBoard[0]) / sizeof(Tile); j++)
        {
            t_gameBoard[i][j].update();
        }
    }
}

void Testing::render()
{
    m_window.clear();

    // Draw stuff
    // m_window.draw([somestuff])
    for (int i = 0; i < sizeof(t_gameBoard) / sizeof(t_gameBoard[0]); i++)
    {
        for (int j = 0; j < sizeof(t_gameBoard[0]) / sizeof(Tile); j++)
        {
            m_window.draw(t_gameBoard[i][j]);
        }
    }

    m_window.draw(t_rotateSquare);
    m_window.draw(t_mouseCircle);
    m_window.draw(t_dragSelect);

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