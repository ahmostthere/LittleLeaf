#ifndef DEBUG_UTILS
#define DEBUG_UTILS
#include <iostream>

void logDebug(std::string message) {
    std::cout << "~*~[DEBUG] " << message << " ~*~" << std::endl;
}

#endif  // DEBUG_UTILS
