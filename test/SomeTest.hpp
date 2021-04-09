#ifndef TESTING
#define TESTING

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

// #define WIN_WIDTH 480
// #define WIN_HEIGHT 270
// #define TILE_SIZE 30
#define WIN_WIDTH 640
#define WIN_HEIGHT 640
#define TILE_SIZE 160

// Quad Stuff
class QuadNode {
public:
    sf::Transformable obj;
    QuadNode(sf::Transformable _obj) {
        obj = _obj;
    }
};

class Quad {
public:
    sf::FloatRect quadRect;
    QuadNode *node;
    Quad *tLQuad, *tRQuad, *bLQuad, *bRQuad;
    sf::Vector2f minSz;

    Quad() {
        quadRect = sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        minSz = sf::Vector2f(TILE_SIZE, TILE_SIZE);
        node = nullptr;
        tLQuad = nullptr;
        tRQuad = nullptr;
        bLQuad = nullptr;
        bRQuad = nullptr;
    }
    
    Quad(sf::FloatRect _quadRect, sf::Vector2f _minSz = sf::Vector2f(TILE_SIZE, TILE_SIZE)) {
        quadRect = _quadRect;
        minSz = _minSz; 
        node = nullptr;
        tLQuad = nullptr;
        tRQuad = nullptr;
        bLQuad = nullptr;
        bRQuad = nullptr;
    }

    void insert(QuadNode *_node) {
        if (_node == nullptr) return;

        std::cout << _node->obj.getPosition().x << ", " << _node->obj.getPosition().y << std::endl;
        std::cout << "QUAD TL: " << quadRect.left << ", " << quadRect.top << std::endl;
        std::cout << "QUAD BR: " << quadRect.left + quadRect.width << ", " << quadRect.top + quadRect.height << std::endl;

        if (!quadRect.contains(_node->obj.getPosition())) return;
            
        
        if (quadRect.width <= 3 && quadRect.height <= 3) {
            if (node == nullptr) {
                node = _node;
                std::cout << "inserted" << std::endl;
            }
            return;
        }
        
        if (_node->obj.getPosition().y <= quadRect.top + (quadRect.height / 2)) { // T
            if (_node->obj.getPosition().x <= quadRect.left + (quadRect.width / 2)) { // L
                if (tLQuad == nullptr) {
                    tLQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(quadRect.left, quadRect.top),
                            sf::Vector2f(quadRect.width / 2, quadRect.height / 2)));
                    tLQuad->insert(_node);
                }
            } else { // R
                if (tRQuad == nullptr) {
                    tRQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(quadRect.left + (quadRect.width / 2), quadRect.top),
                            sf::Vector2f(quadRect.width / 2, quadRect.height / 2)));
                    tRQuad->insert(_node);
                }
            }
        } else { // B
            if (_node->obj.getPosition().x <= quadRect.left + (quadRect.width / 2))
            { // L
                if (bLQuad == nullptr) {
                    bLQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(quadRect.left, quadRect.top + (quadRect.height / 2)),
                            sf::Vector2f(quadRect.width / 2, quadRect.height / 2)));
                    bLQuad->insert(_node);
                }
            }
            else
            { // R
                if (bRQuad == nullptr) {
                    bRQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(quadRect.left + (quadRect.width / 2), quadRect.top + (quadRect.height / 2)),
                            sf::Vector2f(quadRect.width / 2, quadRect.height / 2)));
                    bRQuad->insert(_node);
                }
            }
        }
    }
};


class Testing {
public:
    static sf::RectangleShape gameBoard[WIN_WIDTH / TILE_SIZE][WIN_HEIGHT / TILE_SIZE];
    static sf::CircleShape mouseCircle;
    static sf::RenderWindow t_window;
    static bool t_isQuitting;
    static void load();
    static Quad *t_quad;

    static void handleInput();
    static void update();
    static void render();
    static bool quitting();
    static void quit();
};

sf::RectangleShape Testing::gameBoard[WIN_WIDTH / TILE_SIZE][WIN_HEIGHT / TILE_SIZE];
sf::CircleShape Testing::mouseCircle;
sf::RenderWindow Testing::t_window;
bool Testing::t_isQuitting;
Quad *Testing::t_quad = new Quad(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(WIN_WIDTH, WIN_HEIGHT)));

void Testing::load()
{
    // Load / initialize other static variables
    for (int i = 0; i < sizeof(gameBoard) / sizeof(gameBoard[0]); i++) {
        for (int j = 0; j < sizeof(gameBoard[0]) / sizeof(sf::RectangleShape); j++) {
            gameBoard[i][j].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            gameBoard[i][j].setPosition(sf::Vector2f((i * TILE_SIZE) + (TILE_SIZE / 2), (j * TILE_SIZE) + (TILE_SIZE / 2)));
            gameBoard[i][j].setOrigin(sf::Vector2f(TILE_SIZE/2, TILE_SIZE/2));
            gameBoard[i][j].setFillColor(
                (i % 2) ? ((j % 2) ? sf::Color::White : sf::Color(150, 150, 150)) : ((j % 2) ? sf::Color(150, 150, 150) : sf::Color::White));
            gameBoard[i][j].setOutlineColor(sf::Color::Black);
            gameBoard[i][j].setOutlineThickness(1);
            t_quad->insert(new QuadNode(gameBoard[i][j]));
        }
    }


    mouseCircle.setFillColor(sf::Color(220, 0, 0, 55));
    mouseCircle.setRadius(100);
    mouseCircle.setOrigin(sf::Vector2f(mouseCircle.getRadius(), mouseCircle.getRadius()));



    t_isQuitting = false;

    t_window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Close);
    t_window.setFramerateLimit(60);
}


void Testing::handleInput()
{
    sf::Event curEvent;
    while (t_window.pollEvent(curEvent)) {
        switch (curEvent.type) {
            case sf::Event::Closed:
                t_isQuitting = true;
                break;

            case sf::Event::KeyPressed:
                switch (curEvent.key.code) {
                    case sf::Keyboard::Escape:
                        t_isQuitting = true;
                        break;

                    default:
                        break;
                }
                break;
            
            case sf::Event::Resized:
                // t_window.setView();
                break;

            default:
                break;
        }
    }
}


void Testing::update()
{
    //  Update stuff
    mouseCircle.setPosition((sf::Vector2f)sf::Mouse::getPosition(t_window));

}


void Testing::render()
{
    t_window.clear();

    // Draw stuff
    // t_window.draw([somestuff])
    for (int i = 0; i < sizeof(gameBoard) / sizeof(gameBoard[0]); i++) {
        for (int j = 0; j < sizeof(gameBoard[0]) / sizeof(sf::RectangleShape); j++) {
            t_window.draw(gameBoard[i][j]);
        }
    }

    t_window.draw(mouseCircle);
    
    t_window.display();
}


bool Testing::quitting()
{
    return t_isQuitting;
}


void Testing::quit()
{
    t_window.close();
}

#endif