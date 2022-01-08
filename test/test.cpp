// #include "SomeTest.hpp"
// #include "Test2.hpp"
#include "SightTest.hpp"
#include "blendModeTests.hpp"



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
    // start();
    main2();
    return 0;
}
