#ifndef TESTING
#define TESTING

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#define WIN_WIDTH 900
#define WIN_HEIGHT 600
#define TILE_SIZE 30

class Testing
{
public:
    static sf::VertexArray t_vertexArray;
    static sf::VertexArray t_vectFog;
    static sf::VertexArray t_vectAbn;
    static sf::RectangleShape t_rectBG;


    static sf::RenderWindow m_window;
    static sf::Time m_time;
    static sf::Clock m_clock;
    static sf::View m_view;
    static bool m_isQuitting;
    static void load();

    static void handleInput();
    static void update();
    static void render();
    static bool quitting();
    static void quit();
    static void resetTimer();
};

sf::VertexArray Testing::t_vertexArray(sf::TriangleFan);
sf::RectangleShape Testing::t_rectBG(sf::Vector2f(WIN_WIDTH, WIN_HEIGHT));
sf::VertexArray Testing::t_vectAbn(sf::TriangleFan);
sf::VertexArray Testing::t_vectFog(sf::Quads);




sf::RenderWindow Testing::m_window;
sf::Time Testing::m_time;
sf::Clock Testing::m_clock;
sf::View Testing::m_view;
bool Testing::m_isQuitting;

namespace
{
    float pi = std::acos(-1);
};

// changes floatrect to vertex array
sf::VertexArray rectToVertexArray(const sf::FloatRect &rect)
{
    sf::VertexArray retVal;
    retVal.append(sf::Vertex(sf::Vector2f(rect.left, rect.top)));
    retVal.append(sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top)));
    retVal.append(sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top + rect.height)));
    retVal.append(sf::Vertex(sf::Vector2f(rect.left, rect.top + rect.height)));
    return retVal;
}

// get
sf::VertexArray getBoundsMultiple(std::vector<sf::VertexArray> vertexArrays)
{
    sf::VertexArray retVal;
    return retVal;
}



sf::VertexArray insideBoundBox(sf::VertexArray shape)
{
    sf::VertexArray retVal;
    sf::VertexArray shapeBounds = rectToVertexArray(shape.getBounds());
    struct vertexPair
    {
        sf::Vertex vertex;
        enum Intersects
        {
            NONE = 0b0000,
            TOP = 0b1000,
            RIGHT = 0b0100,
            BOTTOM = 0b0010,
            LEFT = 0b0001,
            TRCorner = 0b1100,
            TLCorner = 0b1001,
            BRCorner = 0b0110,
            BLCorner = 0b0011
        };
        Intersects placement;
        
        vertexPair(sf::Vertex _vertex) : vertex(_vertex)
        {

        }
    };

    std::map<std::size_t, vertexPair> borderVertices;
    std::map<std::size_t, vertexPair> containedVertices;

    // triangle case 
    // at least 1 vertex is a corner
    // all 3 vertices touch a side
    // if (shape.getVertexCount() == 3)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         vertexPair vp;
    //         vp.vertex = shape[j];
    //         for (int i = 0; i < 4; i++)
    //         {
    //             if (shapeBounds[i].position == shape[j].position)
    //             {
    //                 vp.placement = i;
    //             }
    //         }
    //         if ()
    //     }
    // } 
    // else 
    // {
    // }
    for (int i = 0; i < shape.getVertexCount(); i++)
    {
        vertexPair vp(shape[i]);
       
    }

    return retVal;
}

sf::VertexArray outsideBoundBox(sf::VertexArray fog, sf::VertexArray shape)
{
    sf::VertexArray shapeBounds = rectToVertexArray(shape.getBounds());
    sf::VertexArray retVal(sf::TriangleStrip);
    for (int i = 0; i < 4; i++)
    {
        retVal.append(fog[i]);
        retVal.append(shapeBounds[i]);
    }
    retVal.append(fog[0]);
    retVal.append(shapeBounds[0]);

    return retVal;
}

void Testing::load()
{
    // Load / initialize other static variables
    
    t_rectBG.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    t_rectBG.setPosition(0, 0);

    sf::Vector2f a(200, 200), b(250, 150), c(300, 250), d(250, 300);
    sf::Color fogColor = sf::Color(0x99, 0x99, 0xDD, 0xFF * 3/4);

    t_vertexArray.append(sf::Vertex(a, sf::Color(0x00, 0xFF, 0x00)));
    t_vertexArray.append(sf::Vertex(b, sf::Color(0x00, 0xFF, 0x00)));
    t_vertexArray.append(sf::Vertex(c, sf::Color(0x00, 0xFF, 0x00)));
    t_vertexArray.append(sf::Vertex(d, sf::Color(0x00, 0xFF, 0x00)));

    sf::FloatRect rectBound =  t_vertexArray.getBounds();
    sf::FloatRect rectFog(sf::Vector2f(25, 25), sf::Vector2f(850, 550));
    
    t_vectFog = rectToVertexArray(rectFog);
    t_vectFog = outsideBoundBox(t_vectFog, t_vertexArray);
    for (int i = 0; i < t_vectFog.getVertexCount(); i++) t_vectFog[i].color = fogColor;



    t_vectAbn.append(sf::Vertex(sf::Vector2f(100, 100), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(50, 50), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(150, 50), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(115, 100), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(150, 150), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(50, 150), sf::Color(0x33, 0x33, 0xFF)));
    t_vectAbn.append(sf::Vertex(sf::Vector2f(25, 125), sf::Color(0x33, 0x33, 0xFF)));

    // t_vectAbn.append(sf::Vertex(sf::Vector2f(85, 100), sf::Color(0x33, 0x33, 0xFF)));
    // t_vectAbn.append(sf::Vertex(sf::Vector2f(50, 50), sf::Color(0x33, 0x33, 0xFF)));



/// ====================================================================

    sf::ContextSettings settings; 
    settings.antialiasingLevel = 8;

    m_isQuitting = false;
    m_window.create(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TEST",
        sf::Style::Close, settings);
    m_window.setFramerateLimit(60);
    m_view = m_window.getDefaultView();
}

void Testing::handleInput()
{
    sf::Event curEvent;
    while (m_window.pollEvent(curEvent))
    {
        switch (curEvent.type)
        {
            case sf::Event::Closed:
                m_isQuitting = true;
                break;

            case sf::Event::KeyPressed:
                switch (curEvent.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_isQuitting = true;
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Testing::update()
{
    //  Update stuff
    m_window.setView(m_view);
}

void Testing::render()
{
    m_window.clear();

    // Draw stuff
    m_window.draw(t_rectBG);
    m_window.draw(t_vertexArray);
    m_window.draw(t_vectAbn);
    m_window.draw(t_vectFog);
    m_window.display();
}

bool Testing::quitting() { return m_isQuitting; }

void Testing::quit() { m_window.close(); }

void Testing::resetTimer() { m_time = m_clock.restart(); }

#endif