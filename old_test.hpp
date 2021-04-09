#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "ArrowBtns.hpp"
// #include "TestQuads.hpp"

#define WIN_WIDTH 1080
#define WIN_HEIGHT 720

#define PI std::acos(-1)

int speed;
 
sf::ContextSettings m_Settings;
sf::RenderWindow m_Window;
sf::Clock m_Clock;
sf::Time m_Time;
bool t_Exiting;

// ArrowBtns t_ArrowBtns;

sf::RectangleShape t_Rect;
sf::CircleShape t_Circle;
// sf::CircleShape t_Circle2;
sf::CircleShape t_Circle3;
bool leftPressed, rightPressed;

sf::Time t_contTime;

float t_factor;

void oscillate() {
    
}


void load() {
    t_Exiting = false;

    // t_ArrowBtns.load();
    // t_ArrowBtns.setPosition(0, 0);

    t_factor = 1;
    t_Circle.setRadius(10);
    t_Circle.setPosition(400, 400);
    t_Circle.setFillColor(sf::Color::Blue);
    t_Circle.setOutlineThickness(0);

    
    t_Rect.setSize(sf::Vector2f(t_Circle.getLocalBounds().width, t_Circle.getLocalBounds().height));
    t_Rect.setPosition(450, 450);
    t_Rect.setFillColor(sf::Color((sf::Uint8)220U, (sf::Uint8)220U, (sf::Uint8)255U, (sf::Uint8)220U));

    std::cout << "localBound: " << t_Circle.getLocalBounds().top << "   " << t_Circle.getLocalBounds().left << std::endl;
    std::cout << "globalBound: " << t_Circle.getGlobalBounds().top << "   " << t_Circle.getGlobalBounds().left << std::endl;


    t_Circle3.setPosition(500, 500);
    t_Circle3.setFillColor(sf::Color::Green);

    speed = 100;
    leftPressed = false;
    rightPressed = false;

    m_Settings.antialiasingLevel = 0;
    m_Window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Default, m_Settings);
    m_Window.setFramerateLimit(60);
}

void handleKeyPress(sf::Keyboard::Key eventKey) {
    switch (eventKey) {
        case sf::Keyboard::Escape:
            t_Exiting = true;
            break;

        case sf::Keyboard::P:
            break;

        case sf::Keyboard::I:
            break;

        case sf::Keyboard::M:
            break;

        case sf::Keyboard::Space:
            oscillate();
            break;

        case sf::Keyboard::Up:
            // t_factor += .1;
            speed+=10;
            break;

        case sf::Keyboard::Down:
            // if (t_factor > 1)
                // t_factor -= .1;
            speed-=10;
            break;

        case sf::Keyboard::Left:
            leftPressed = true;
            break;

        case sf::Keyboard::Right:
            rightPressed = true;
            
            break;

        default:
            break;
    }
}

void handleContinuous() {
    // t_ArrowBtns.handleInput();
}

void handleInputs() {
    sf::Event currentEvent;
    while (m_Window.pollEvent(currentEvent)) {
        switch (currentEvent.type) {
            case sf::Event::Closed:
                t_Exiting = true;
                break;

            case sf::Event::KeyPressed:
                handleKeyPress(currentEvent.key.code);
                break;

            case sf::Event::KeyReleased:
                switch (currentEvent.key.code) {
                    case sf::Keyboard::Left:
                        leftPressed = false;
                        break;

                    case sf::Keyboard::Right:
                        rightPressed = false;
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void update() {
    // handleContinuous();
    
    

    // if (leftPressed) {
    //     t_Circle3.move(speed * m_Time.asSeconds() * -1, 0);
    // }
    // if (rightPressed) {
    //     t_Circle3.move(speed * m_Time.asSeconds(), 0);
    // }
}

void render() {
    m_Window.clear();
    /*
    // int i = t_contTime.asSeconds();
    // std::cout << "i::" << i << std::endl;
    // if (i % 2) {
    //     m_Window.draw(t_Circle);
    //     m_Window.draw(t_Circle2);
    // } else {
    //     m_Window.draw(t_Circle2);
    //     m_Window.draw(t_Circle);
    // }
    */
    
    m_Window.draw(t_Circle);
    // m_Window.draw(t_Circle2);
    m_Window.draw(t_Circle3);
    m_Window.draw(t_Rect);
    // m_Window.draw(t_ArrowBtns);

    m_Window.display();
}

void start() {
    // initialize / load
    load();
    
    // all game stuff
    while (!t_Exiting) {
        m_Time = m_Clock.restart();
        t_contTime += m_Time;
        // std::cout << t_factor << std::endl;

        // t_Circle.setPosition(400 + (60 * std::cos(PI * t_contTime.asSeconds() / t_factor)), 400);
        handleInputs();
        update();
        render();
    }

    // exit
    m_Window.close();
}



template <typename T, typename U>
class QuadNode {

    struct QuadLeaf {
        sf::Vector2<T> m_point;
        U m_data;
    };

    sf::Rect<T> m_quadRect;

    QuadLeaf* m_leaf = nullptr;

    QuadNode *topLeft;
    QuadNode *topRight;
    QuadNode *botLeft;
    QuadNode *botRight;

public:
    QuadNode() {
        m_quadRect = sf::Rect<T>(0,0,0,0);
        m_leaf = nullptr;
        topLeft = nullptr;
        topRight = nullptr;
        botLeft = nullptr;
        botRight = nullptr;
    }

    QuadNode(sf::Rect<T> rect) {
        m_quadRect = rect;
        m_leaf = nullptr;
        topLeft = nullptr;
        topRight = nullptr;
        botLeft = nullptr;
        botRight = nullptr;
    }

    bool contains(sf::Vector2f point) {
        return (point.x >= m_quadRect.left && point.x <= m_quadRect.left + m_quadRect.width &&
                point.y >= m_quadRect.top && point.y <= m_quadRect.top + m_quadRect.height)
    }

    bool contains(sf::Vector2f point) {
        return (point.x >= m_tl.x && point.x <= m_br.x &&
                point.y >= m_tl.y && point.y <= m_br.y)
    }

    void insert (QuadLeaf *leaf) {
        if (leaf == nullptr) return;



    }

};



int main() {
    start();

    return 0;

    sf::FloatRect FR = sf::FloatRect(0, 0, 10, 10);
 
}