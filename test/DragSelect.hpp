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

    DragSelect() : m_isHighlighted(false), m_highlight(sf::Vector2f(0, 0)), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0))
    {
        // load
        m_highlight.setFillColor(sf::Color::Transparent);
    }

    DragSelect(sf::Window *relativeTo) : m_isHighlighted(false), m_highlight(sf::Vector2f(0, 0)), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0)), m_window(relativeTo)
    {
        m_highlight.setFillColor(sf::Color::Transparent);
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

    // void start(const sf::Window &relativeTo) 
    // {
    //     m_startPos = (sf::Vector2f)sf::Mouse::getPosition(relativeTo);
    // }

    void start() 
    {
        m_startPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
    }

    void update()
    {
        // end()
        m_endPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);

        if (m_isHighlighted)
        {
            // keeps top left point as position
            m_highlight.setSize(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_startPos.x - m_endPos.x : m_endPos.x - m_startPos.x, 
                                             m_startPos.y >= m_endPos.y ? m_startPos.y - m_endPos.y : m_endPos.y - m_startPos.y));
            m_highlight.setPosition(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_endPos.x : m_startPos.x, 
                                                 m_startPos.y >= m_endPos.y ? m_endPos.y : m_startPos.y));

            // m_highlight.setSize(m_endPos - m_startPos);
            // m_highlight.setPosition(m_startPos);
            
            m_highlight.setFillColor(sf::Color(20, 20, 140, 120));
        } 
        else 
        {
            m_highlight.setSize(sf::Vector2f(0, 0));
            m_highlight.setPosition(0, 0);
            m_highlight.setFillColor(sf::Color::Transparent);
        }
    }

    // void end(const sf::Window &relativeTo)
    // {
    //     m_endPos = (sf::Vector2f)sf::Mouse::getPosition(relativeTo);
    // }

    const sf::Vector2f &getSize() const
    {
        return m_highlight.getSize();
    }

    const sf::Vector2f &getPosition() const
    {
        return m_highlight.getPosition();
    }
};

#endif