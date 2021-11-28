#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Collidable : public sf::Drawable, public sf::Transformable
{
public:
private:
    static std::vector<Collidable> Collidables;
};

#endif