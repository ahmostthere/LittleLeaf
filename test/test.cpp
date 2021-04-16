#include "SomeTest.hpp"

void start() {
    Testing::load();

    while(!Testing::quitting()) {
        Testing::handleInput();
        Testing::update();
        Testing::render();
    }
    Testing::quit();
}


int main() {
    start();


    // sf::RectangleShape one;
    // sf::RectangleShape two;
    // one.setPosition(0, 0);
    // one.setPosition(3, 0);

    // Quad<sf::Transformable> *root = new Quad<sf::Transformable>(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(36, 24)));

    // root->insert(new Quad<sf::Transformable>::Node(one, one.getPosition()));
    // root->insert(new Quad<sf::Transformable>::Node(two, two.getPosition()));



    // root->printQuads();

    return 0;
}