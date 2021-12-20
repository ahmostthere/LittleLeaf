#ifndef TESTING
#define TESTING


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Test.hpp"

#include <iostream>
#include <cmath>
#include <random>

class Testing: public Test
{
public:
    static void load();
    static void handleInput();
    static void update();
    static void render();
public:
};

sf::VertexArray objects(sf::Quads);
sf::VertexArray objectLines(sf::Lines);
sf::VertexArray sight(sf::Lines);



// adds a quad to vertex array objectList
// 
//   a ---- b
//   |      |
//   |      |
//   c ---- d
//
void addObject(sf::VertexArray &objectList, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d, sf::Color color)
{
    objectList.append(sf::Vertex(a, color));
    objectList.append(sf::Vertex(b, color));
    objectList.append(sf::Vertex(c, color));
    objectList.append(sf::Vertex(d, color));
}

void addLine(sf::VertexArray &lineList, sf::Vector2f a, sf::Vector2f b, sf::Color color)
{
    lineList.append(sf::Vertex(a, color));
    lineList.append(sf::Vertex(b, color));
}

float getDistance(sf::Vector2f p1, sf::Vector2f p2)
{
    return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

float getSlope(sf::Vector2f p1, sf::Vector2f p2)
{
    return (p2.y - p1.y) / (p2.x - p1.x);
}

sf::Vector2f getIntersect(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q1 = sf::Vector2f(0,0), sf::Vector2f q2 = sf::Vector2f(0,0))
{
    float pm = getSlope(p1, p2);
    float qm = getSlope(q1, q2);
    float pb = p1.y - p1.x * pm;
    float qb = q1.y - q1.x * qm;
    float x = (pb - qb) / (qm - pm);
    float yp = pm * x + pb;
    float yq = qm * x + qb;
    std::cout << yp << "   " << yq << std::endl; 

    // y = pm * x + pb;
    // y = qm * x + qb;
    // pm * x + pb = qm * x + qb
    // pm * x + pb - qb = qm * x
    // qm * x - pm * x = pb - qb
    // x * (qm - pm) = pb - qb
    // x = (pb - qb) / (qm - pm)
    

    return p1;
}

bool onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
    
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool intersects(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}

void Testing::load()
{ Test::load();
    // obj1
    addObject(objects, sf::Vector2f(200, 200), sf::Vector2f(300, 200), sf::Vector2f(300, 400), sf::Vector2f(150, 450), sf::Color::Blue);
    // obj2
    addObject(objects, sf::Vector2f(830, 400), sf::Vector2f(850, 200), sf::Vector2f(900, 440), sf::Vector2f(840, 450), sf::Color::Red);
    // obj3
    addObject(objects, sf::Vector2f(600, 800), sf::Vector2f(770, 900), sf::Vector2f(700, 1000), sf::Vector2f(650, 950), sf::Color::Yellow);

    // add obj lines
    for (size_t i = 0; i < objects.getVertexCount(); i+=4)
    {
        for (size_t j = 0; j < 4; j++)
        {
            (j + 1 == 4) ? 
            addLine(objectLines, objects[i + j].position, objects[i + 0].position, sf::Color::White) : 
            addLine(objectLines, objects[i + j].position, objects[i + j + 1].position, sf::Color::White);
        }
    }

    sf::Vector2f pos(800, 800);

    for (size_t i = 0; i < objects.getVertexCount(); i++)
    {
        addLine(sight, pos, objects[i].position, sf::Color::Green);
    }
}

void Testing::handleInput()
{ Test::handleInput();
}

void Testing::update()
{ Test::update();

    for (size_t i = 0; i < sight.getVertexCount(); i+=2)
    {
        sight[i].position = Test::m_window.mapPixelToCoords(sf::Mouse::getPosition(Test::m_window));
    }

    for (size_t i = 0; i < sight.getVertexCount(); i+=2)
    {
        bool isintersects = false;
        sf::Vector2f closestIntersect;
        sf::Vector2f originalPoint = sight[i+1].position;
        for (size_t j = 0; j < objectLines.getVertexCount(); j+=2)
        {
            sf::Vector2f p1 = sight[i].position;
            sf::Vector2f p2 = sight[i + 1].position;

            sf::Vector2f q1 = objectLines[j].position;
            sf::Vector2f q2 = objectLines[(j + 1 == objectLines.getVertexCount()) ? 0 : j + 1].position;

            if (p2 != q1 && p2 != q2)
            {
                if (intersects(p1, p2, q1, q2)) 
                {
                    isintersects = true;
                    closestIntersect = getDistance(sight[i].position, getIntersect(p1, p2, q1, q2)) <= getDistance(sight[i].position, closestIntersect) ? getIntersect(p1, p2, q1, q2) : closestIntersect;
                }
            }
        }

        if (isintersects)
        {
            sight[i+1].color = sf::Color::Magenta;
            sight[i].color = sf::Color::Magenta;
        }
        else
        {
            sight[i+1].color = sf::Color::Green;
            sight[i].color = sf::Color::Green;
        }
    }
}

void Testing::render()
{
    m_window.clear();
    m_window.draw(objects);
    m_window.draw(sight);
    m_window.display();
}

#endif