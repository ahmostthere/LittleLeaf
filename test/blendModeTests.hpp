// #include "SomeTest.hpp"
// #include "Test2.hpp"

// void start() 
// {
//     Testing::load();

//     while(!Testing::quitting()) 
//     {
//         Testing::resetTimer();
//         Testing::handleInput();
//         Testing::update();
//         Testing::render();
//     }
//     Testing::quit();
// }

// int main() 
// {
//     start();
//     return 0;
// }

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

sf::VertexArray createVA(sf::Vector2f pos, float rad, sf::Color outerColor, sf::Color innerColor, int slices = 100, float percentage = .5 )
{
    sf::VertexArray retVal(sf::Quads);
    float pi = std::acos(-1);
    for (int i = 0; i < slices; i++)
    {
        // Q outer
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad, sin((2 * pi * (i) / slices) - pi / 2) * rad), outerColor));
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad, sin((2 * pi * (i + 1) / slices) - pi / 2) * rad), outerColor));
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage), innerColor));
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i) / slices) - pi / 2) * rad * percentage), innerColor));

        // Q inner
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i) / slices) - pi / 2) * rad * percentage), innerColor));
        retVal.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage), innerColor));
        retVal.append(sf::Vertex(pos, innerColor)); // center
        retVal.append(sf::Vertex(pos, innerColor)); // center
    }

    return retVal;
}

int main2()
{
    sf::RenderWindow app(sf::VideoMode(800u, 600u), "blending lights");
    app.setFramerateLimit(60u);

    sf::RenderTexture tex;
    tex.create(app.getSize().x, app.getSize().y);

    sf::Texture pic;
    pic.loadFromFile("assets/menuSplash.png");

    std::vector<sf::Vector2f> lights;

    const sf::Color colors[3] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};

    while (app.isOpen())
    {
        sf::Event eve;
        while (app.pollEvent(eve))
        {
            if (eve.type == sf::Event::Closed)
                app.close();

            if (eve.type == sf::Event::MouseButtonPressed)
                lights.push_back(app.mapPixelToCoords(sf::Vector2i(eve.mouseButton.x, eve.mouseButton.y)));

            if (eve.type == sf::Event::KeyPressed)
                if (eve.key.code == sf::Keyboard::Escape)
                    app.close();
        }

        app.clear();

        // start = no light
        tex.clear(sf::Color(80, 60, 120));

        
        
        

        // sf::VertexArray sha2(sf::Quads);
        // sf::Vector2f pos = app.mapPixelToCoords(sf::Mouse::getPosition(app));
        // float rad = 250.f;
        // int slices = 100;
        // float percentage = .5;
        // float pi = std::acos(-1);
        // for (int i = 0; i < slices; i++)
        // {
        //     // Q outer
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad, sin((2 * pi * (i) / slices) - pi/2) * rad), sf::Color::Transparent)); 
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad, sin((2 * pi * (i + 1) / slices) - pi/2) * rad), sf::Color::Transparent)); 
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i + 1) / slices) - pi/2) * rad * percentage), sf::Color::White)); 
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i) / slices) - pi/2) * rad * percentage), sf::Color::White)); 
            
        //     // Q inner
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i) / slices) - pi/2) * rad * percentage), sf::Color::White)); 
        //     sha2.append(sf::Vertex(pos + sf::Vector2f(cos((2 * pi * (i + 1) / slices) - pi / 2) * rad * percentage, sin((2 * pi * (i + 1) / slices) - pi/2) * rad * percentage), sf::Color::White)); 
        //     sha2.append(sf::Vertex(pos, sf::Color::White)); // center
        //     sha2.append(sf::Vertex(pos, sf::Color::White)); // center

        // }

        sf::VertexArray sha2 = createVA(app.mapPixelToCoords(sf::Mouse::getPosition(app)), 250.f, sf::Color::Transparent, sf::Color(0xc2, 0x7e, 0x00));

        tex.draw(sha2, sf::BlendAdd);



        // add the lights together
        for (int i = 0; i < lights.size(); ++i)
        {
            sha2 = createVA(lights[i], 250.f, sf::Color::Transparent, colors[i % 3]);
            tex.draw(sha2, sf::BlendAdd);
        }
        tex.display();


    





        // lit scene
        app.draw(sf::Sprite(pic));

        // multiply by light
        app.draw(sf::Sprite(tex.getTexture()), sf::BlendMultiply);
        app.display();
    }
    return 0;
}