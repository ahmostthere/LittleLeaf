#ifndef DEBUG_UTILS_HPP
#define DEBUG_UTILS_HPP
#include <iostream>

void logDebug(std::string message)
{
    std::cout << "~*~[DEBUG] " << message << " ~*~" << std::endl;
}

#endif // DEBUG_UTILS
