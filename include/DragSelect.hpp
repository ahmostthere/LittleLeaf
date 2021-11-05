#ifndef DRAG_SELECT_HPP
#define DRAG_SELECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class DragSelect : public sf::RectangleShape
{
private:

    bool m_isHighlighted;
    sf::Vector2f m_startPos;
    sf::Vector2f m_endPos;
    sf::Window *m_window;

public:

    DragSelect();

    DragSelect(sf::Window *relativeTo);

    void setWindow(sf::Window *relativeTo);

    void start();

    void onPressed();

    void onReleased();

    void update();

};

#endif