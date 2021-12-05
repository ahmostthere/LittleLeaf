// #include "SomeTest.hpp"
#include "Test2.hpp"

void start() 
{
    Testing::load();

    while(!Testing::quitting()) 
    {
        Testing::resetTimer();
        Testing::handleInput();
        Testing::update();
        Testing::render();
    }
    Testing::quit();
}

int main() 
{
    start();
    return 0;
}