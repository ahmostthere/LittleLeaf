#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Collidable.hpp"
// Characters are collidable objects

class Character : public Collidable {
public:
    int health;
};

#endif