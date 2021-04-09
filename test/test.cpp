#include "SomeTest.hpp"

// void start() {
//     Testing::load();

//     while(!Testing::quitting()) {
//         Testing::handleInput();
//         Testing::update();
//         Testing::render();
//     }
//     Testing::quit();
// }


int main() {
    // start();

    sf::CircleShape one;
    one.setPosition(15, 15);


    QuadNode n1(one);

    Quad *root = new Quad(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(640, 270)));

    root->insert(&n1);

    return 0;
}