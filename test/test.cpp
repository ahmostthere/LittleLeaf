#include "SomeTest.hpp"

void start() 
{
    Testing::load();

    while(!Testing::quitting()) {
        Testing::handleInput();
        Testing::update();
        Testing::render();
    }
    Testing::quit();
}

class Something 
{
private: 
    int parts;
public:
    Something() 
    {
        parts = 0;    
    }

    Something(int _parts)
    {
        parts = _parts;
    }

    friend int show(Something);
};

int show(Something s) {
    return s.parts;
}


int main() 
{
    start();
    // Something s(5);
    // std::cout << show(s) << std::endl;


    // sf::RectangleShape one;
    // sf::RectangleShape two;
    // one.setPosition(0, 0);
    // one.setPosition(3, 0);

    // Quad<sf::Transformable> *root = new Quad<sf::Transformable>(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(36, 24)));

    // root->insert(new Quad<sf::Transformable>::Node(one, one.getPosition()));
    // root->insert(new Quad<sf::Transformable>::Node(two, two.getPosition()));


    // root->printQuads();
    // delete root;

    return 0;
}