#ifndef TEST
#define TEST
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <random>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

class Test
{
public:
    static sf::RenderWindow m_window;
    static sf::Time m_time;
    static sf::Clock m_clock;
    static sf::View m_view;
    static bool m_isQuitting;

    static void load();
    static void handleInput();
    static void update();
    static void render();
    static bool isQuitting();
    static void quit();
    static void resetTimer();
};

sf::RenderWindow Test::m_window;

sf::Time Test::m_time;

sf::Clock Test::m_clock;

sf::View Test::m_view;

bool Test::m_isQuitting;

void Test::load()
{
    m_isQuitting = false;

    m_window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Close);
    m_window.setFramerateLimit(60);
    m_view = m_window.getDefaultView();

}

void Test::handleInput()
{
    // sf::Event curEvent;
    // while (m_window.pollEvent(curEvent))
    // {
    //     switch (curEvent.type)
    //     {
    //     case sf::Event::Closed:
    //         m_isQuitting = true;
    //         break;

    //     case sf::Event::KeyPressed:
    //         switch (curEvent.key.code)
    //         {
    //         case sf::Keyboard::Escape:
    //             m_isQuitting = true;
    //             break;
    //         default:
    //             break;
    //         }
    //         break;
    //     default:
    //         break;
    //     }
    // }
}

void Test::update()
{
    m_window.setView(m_view);
}

void Test::render()
{
}

bool Test::isQuitting()
{
    return m_isQuitting;
}

void Test::quit()
{
    m_window.close();
}

void Test::resetTimer()
{
    m_time = m_clock.restart();
}

#endif