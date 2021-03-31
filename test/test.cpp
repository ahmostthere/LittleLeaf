#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "ArrowBtns.hpp"

#define WIN_WIDTH 1080
#define WIN_HEIGHT 720

#define PI std::acos(-1)

int speed;
 
sf::ContextSettings m_Settings;
sf::RenderWindow m_Window;
sf::Clock m_Clock;
sf::Time m_Time;
bool t_Exiting;

ArrowBtns t_ArrowBtns;

sf::CircleShape t_Circle;
sf::CircleShape t_Circle2;
sf::CircleShape t_Circle3;
bool leftPressed, rightPressed;

sf::Time t_contTime;

float t_factor;

void oscillate() {
    
}


void load() {
    t_Exiting = false;

    t_ArrowBtns.load();
    t_ArrowBtns.setPosition(0, 0);

    t_factor = 1;
    t_Circle.setRadius(10);
    t_Circle.setPosition(400, 400);
    t_Circle.setFillColor(sf::Color::Blue);

    t_Circle2.setRadius(10);
    t_Circle2.setPosition(400, 400);
    t_Circle2.setFillColor(sf::Color::Red);

    t_Circle3.setRadius(10);
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
    t_ArrowBtns.handleInput();
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
    handleContinuous();
    
    

    if (leftPressed) {
        t_Circle3.move(speed * m_Time.asSeconds() * -1, 0);
    }
    if (rightPressed) {
        t_Circle3.move(speed * m_Time.asSeconds(), 0);
    }
}

void render() {
    m_Window.clear();
    int i = t_contTime.asSeconds();
    std::cout << "i::" << i << std::endl;
    if (i % 2) {
        m_Window.draw(t_Circle);
        m_Window.draw(t_Circle2);
    } else {
        m_Window.draw(t_Circle2);
        m_Window.draw(t_Circle);
    }
    
    m_Window.draw(t_Circle3);
    m_Window.draw(t_ArrowBtns);

    m_Window.display();
}

void loop() {
    handleInputs();
    update();
    render();
}

void start() {
    // initialize / load
    load();
    
    // all game stuff
    while (!t_Exiting) {
        m_Time = m_Clock.restart();
        t_contTime += m_Time;
        // std::cout << t_factor << std::endl;

        t_Circle.setPosition(400 + (60 * std::cos(PI * t_contTime.asSeconds() / t_factor)), 400);
        loop();
    }

    // exit
    m_Window.close();
}











int main() {
    start();

    return 0;
}