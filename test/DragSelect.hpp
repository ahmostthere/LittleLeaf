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

    DragSelect() : m_isHighlighted(false), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0))
    {
        setSize(sf::Vector2f(0,0));
        setFillColor(sf::Color::Transparent);
    }

    DragSelect(sf::Window *relativeTo) : m_isHighlighted(false), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0)), m_window(relativeTo)
    {
        setSize(sf::Vector2f(0, 0));
        setFillColor(sf::Color::Transparent);
    }

    void setWindow(sf::Window *relativeTo) 
    {
        m_window = relativeTo;
    }

    void toggleHighlight() 
    {
        m_isHighlighted = !m_isHighlighted;
    }

    bool isHighlighted() 
    {
        return m_isHighlighted;
    }

    void start() 
    {
        m_startPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
    }

    void onPressed()
    {
        start();
        if (!m_isHighlighted)
            m_isHighlighted = !m_isHighlighted;
    }

    void onReleased()
    {
        if (m_isHighlighted)
            m_isHighlighted = !m_isHighlighted;
    }

    void update()
    {
        m_endPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);

        if (m_isHighlighted)
        {
            // keeps top left point as position
            setSize(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_startPos.x - m_endPos.x : m_endPos.x - m_startPos.x, 
                                             m_startPos.y >= m_endPos.y ? m_startPos.y - m_endPos.y : m_endPos.y - m_startPos.y));
            setPosition(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_endPos.x : m_startPos.x, 
                                                 m_startPos.y >= m_endPos.y ? m_endPos.y : m_startPos.y));

            setFillColor(sf::Color(20, 20, 140, 120));
        } 
        else 
        {
            setSize(sf::Vector2f(0, 0));
            setPosition(0, 0);
            setFillColor(sf::Color::Transparent);
        }
    }

};

#endif