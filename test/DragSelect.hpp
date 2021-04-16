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

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(m_highlight);
    }

public:

    DragSelect() 
    {
        load();
    }

    void load() 
    {
        m_isHighlighted = false;
        m_highlight.setSize(sf::Vector2f(0, 0));
        m_highlight.setFillColor(sf::Color::Transparent);
        m_startPos = sf::Vector2f(0, 0);
        m_endPos = sf::Vector2f(0, 0);
    }

    void start(const sf::Window &relativeTo) 
    {
        m_startPos = (sf::Vector2f)sf::Mouse::getPosition(relativeTo);
        m_isHighlighted = true;
    }

    void update(const sf::Window &relativeTo)
    {
        m_endPos = (sf::Vector2f)sf::Mouse::getPosition(relativeTo);
        m_highlight.setSize(m_isHighlighted ? sf::Vector2f(m_startPos.x >= m_endPos.x ? m_startPos.x - m_endPos.x : m_endPos.x - m_startPos.x, m_startPos.y >= m_endPos.y ? m_startPos.y - m_endPos.y : m_endPos.y - m_startPos.y) : sf::Vector2f(0, 0));
        m_highlight.setPosition(m_isHighlighted ? sf::Vector2f(m_startPos.x >= m_endPos.x ? m_endPos.x : m_startPos.x, m_startPos.y >= m_endPos.y ? m_endPos.y : m_startPos.y) : (sf::Vector2f)sf::Mouse::getPosition(relativeTo));
        m_highlight.setFillColor(m_isHighlighted ? sf::Color(20, 20, 140, 120) : sf::Color::Transparent);
    }

    void end() 
    {
        m_isHighlighted = false;
    }

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