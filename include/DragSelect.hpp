#ifndef DRAG_SELECT_HPP
#define DRAG_SELECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class DragSelect : public sf::Drawable
{
private:

    bool m_isHighlighted;
    sf::RectangleShape m_highlight;
    sf::Vector2f m_startPos;
    sf::Vector2f m_endPos;
    sf::Window *m_window;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_highlight);
    }

public:

    DragSelect();

    DragSelect(sf::Window *relativeTo);

    void setWindow(sf::Window *relativeTo);

    void start();

    void onPressed();

    void onReleased();

    void update();

    const sf::Vector2f &getSize() const;

    const sf::Vector2f &getPosition() const;
};

#endif