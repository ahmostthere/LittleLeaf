#include <iostream>

int callback(int num) 
{
    return num * 5;
}


void printCallback(int num, int (*func)(int)) 
{
    int printThis = func(num);
    std::cout << printThis << std::endl;
}