#ifndef TESTING
#define TESTING

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Quad.hpp"
#include "DragSelect.hpp"
#include "Draggable.hpp"
#include "Stack.hpp"
#include "Tile.hpp"
#include "TileBoard.hpp"
#include <iostream>
#include <cmath>
#include <random>

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
    static Draggable t_drag;
    static sf::CircleShape t_player;
    static NodeStack<sf::Keyboard::Key> t_stack;
    
    static sf::RenderWindow m_window;
    static sf::Time m_time;
    static sf::Clock m_clock;
    static sf::View m_view;
    static bool m_isQuitting;
    static void load();

    static void handleInput();
    static void update();
    static void render();
    static bool quitting();
    static void quit();
    static void resetTimer();
    static void t_move(sf::Keyboard::Key _up, sf::Keyboard::Key _down, sf::Keyboard::Key _left, sf::Keyboard::Key _right, sf::Transformable movable);
};

TileBoard *Testing::t_gameBoard;
sf::CircleShape Testing::t_mouseCircle;
sf::CircleShape Testing::t_player(30);
NodeStack<sf::Keyboard::Key> Testing::t_stack;

sf::RenderWindow Testing::m_window;
sf::Time Testing::m_time;
sf::Clock Testing::m_clock;
sf::View Testing::m_view;
bool Testing::m_isQuitting;
DragSelect Testing::t_dragSelect(&m_window);
Draggable Testing::t_drag(sf::Vector2f(80, 80));

void Testing::load()
{
    // Load / initialize other static variables

    t_gameBoard = new TileBoard(WIN_WIDTH / TILE_SIZE, WIN_HEIGHT / TILE_SIZE, TILE_SIZE);

    t_mouseCircle.setRadius(10);
    t_mouseCircle.setFillColor(sf::Color(220, 0, 0, 55));
    t_mouseCircle.setOrigin(sf::Vector2f(t_mouseCircle.getRadius(), t_mouseCircle.getRadius()));


    t_player.setFillColor(sf::Color(0, 255, 255));
    t_player.setPosition(WIN_WIDTH/2, WIN_HEIGHT/2);

    t_drag.setPosition(200, 200);

    m_isQuitting = false;

    m_window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Close);
    m_window.setFramerateLimit(60);
    m_view = m_window.getDefaultView();    
    
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


            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    t_mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(m_window));
                    t_gameBoard->searchPoint(t_mouseCircle.getPosition())->isSelected() ? t_gameBoard->searchPoint(t_mouseCircle.getPosition())->deselect() : t_gameBoard->searchPoint(t_mouseCircle.getPosition())->select();
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    t_dragSelect.onPressed();
                    t_drag.onClick(sf::Mouse::getPosition(m_window));
                }
                break;

            case sf::Event::MouseButtonReleased:
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
                t_drag.onReleased();

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

            case sf::Event::KeyPressed:
                switch (curEvent.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_isQuitting = true;
                        break;

                    case sf::Keyboard::Up:
                        std::cout << "Up Pressed" << std::endl;
                        m_view.move(0, 5);
                        m_window.setView(m_view);
                        break;

                    default:
                        break;
                }
                if (!t_stack.contains(curEvent.key.code))
                {
                    t_stack.push(curEvent.key.code);
                }
                std::cout << "Key Pressed " << t_stack.size() << std::endl;
                std::cout << t_stack << std::endl;
                break;

            case sf::Event::KeyReleased:
                t_stack.remove(curEvent.key.code);
                std::cout << "Key Released " << t_stack.size() << std::endl;
                break;

            case sf::Event::Resized:
                // m_window.setView();
                break;

            default:
                break;
        }
    }

    // t_move(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, t_player);
    float vel = 500 * m_time.asSeconds();
    float pi = std::acos(-1);
    float dir;
    bool isMoving = false;
    // 1key
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 0 * pi / 4;
        isMoving = true;   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir = 2 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = 4 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir = 6 * pi / 4;
        isMoving = true;
    }
    // 2keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 1 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = 3 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = 5 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 7 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        isMoving = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        isMoving = false;
    }
    // 3keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir = 0 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 2 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir = 4 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 6 * pi / 4;
        isMoving = true;
    }

    if (isMoving)
    {
        t_player.move(sf::Vector2f(std::cos(dir) * vel, std::sin(dir) * vel));
    }
}

void Testing::update()
{
    //  Update stuff
    t_dragSelect.update();

    // combination of mouse hover and highlight hover
    t_gameBoard->generalHover(sf::Mouse::getPosition(m_window),t_dragSelect.getGlobalBounds());

    // t_drag.drag(sf::Mouse::getPosition(m_window));
    t_drag.drag(sf::Mouse::getPosition(m_window));

}

void Testing::render()
{
    m_window.clear();

    // Draw stuff

    m_window.draw(*t_gameBoard);

    m_window.draw(t_drag);
    m_window.draw(t_player);
    
    m_window.draw(t_mouseCircle);
    m_window.draw(t_dragSelect);


    m_window.display();
}

bool Testing::quitting() { return m_isQuitting; }

void Testing::quit() { m_window.close(); }

void Testing::resetTimer() { m_time = m_clock.restart(); }

void Testing::t_move(sf::Keyboard::Key _up, sf::Keyboard::Key _down, sf::Keyboard::Key _left, sf::Keyboard::Key _right, sf::Transformable movable)
{
    float vel = 500 * m_time.asSeconds();
    float pi = std::acos(-1);
    float dir;
    bool isMoving = false;
    // 1key
    if (sf::Keyboard::isKeyPressed(_right))
        dir = 0 * pi / 4;
    if (sf::Keyboard::isKeyPressed(_down))
        dir = 2 * pi / 4;
    if (sf::Keyboard::isKeyPressed(_left))
        dir = 4 * pi / 4;
    if (sf::Keyboard::isKeyPressed(_up))
        dir = 6 * pi / 4;
    // 2keys
    if (sf::Keyboard::isKeyPressed(_down) && sf::Keyboard::isKeyPressed(_right))
    {
        dir = 1 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_down) && sf::Keyboard::isKeyPressed(_left))
    {
        dir = 3 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_left))
    {
        dir = 5 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_right))
    {
        dir = 7 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_down))
        isMoving = false;
    if (sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_right))
        isMoving = false;

    // 3keys
    if (sf::Keyboard::isKeyPressed(_right) && sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_down))
    {
        dir = 0 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_down) && sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_right))
    {
        dir = 2 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_down))
    {
        dir = 4 * pi / 4;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(_up) && sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_right))
    {
        dir = 6 * pi / 4;
        isMoving = true;
    }

    if (isMoving) movable.move(sf::Vector2f(std::cos(dir) * vel, std::sin(dir) * vel));
}

#endif