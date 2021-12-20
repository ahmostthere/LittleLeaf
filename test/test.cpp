// #include "SomeTest.hpp"
// #include "Test2.hpp"
#include "SightTest.hpp"



void start() 
{
    Testing::load();

    while(!Testing::isQuitting()) 
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
