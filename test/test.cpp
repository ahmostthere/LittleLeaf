#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



namespace testing {


sf::ContextSettings m_Settings;
sf::RenderWindow m_Window;
sf::Clock m_Clock;
sf::Time m_Time;
bool t_Exiting;

void load() {
    t_Exiting = false;
    m_Settings.antialiasingLevel = 0;
    m_Window.create(sf::VideoMode(1080, 720), "TEST",
                    sf::Style::Default, m_Settings);
    m_Window.setFramerateLimit(60);
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

        default:
            break;
        }
    }
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

        default:
            break;
    }
}

void update() {

}

void render() {

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
        loop();
    }

    // exit
    m_Window.close();
}

} // namespace testing










int main() {
    testing::start();
    return 0;
}