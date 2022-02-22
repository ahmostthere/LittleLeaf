#ifndef TESTING
#define TESTING

#include "Test.hpp"

class Testing : public Test
{
public:
    static void load();
    static void handleInput();
    static void update();
    static void render();

public:
};

// Add Test objects here
// TODO

void Testing::load()
{
    Test::load();
    // Load
    // TODO
}

void Testing::handleInput()
{
    Test::handleInput();
    // Inputs
    // TODO
}

void Testing::update()
{
    Test::update();
    // Update
    // TODO
}

void Testing::render()
{
    m_window.clear();
    // Draw
    // TODO
    m_window.display();
}

#endif