#include "DragSelect.hpp"

DragSelect::DragSelect() : m_isHighlighted(false), m_highlight(sf::Vector2f(0, 0)), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0))
{
    // load
    m_highlight.setFillColor(sf::Color::Transparent);
}

DragSelect::DragSelect(sf::Window *relativeTo) : m_isHighlighted(false), m_highlight(sf::Vector2f(0, 0)), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0)), m_window(relativeTo)
{
    m_highlight.setFillColor(sf::Color::Transparent);
}

void DragSelect::setWindow(sf::Window *relativeTo)
{
    m_window = relativeTo;
}

void DragSelect::start()
{
    m_startPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
}

void DragSelect::onPressed()
{
    start();
    if (!m_isHighlighted)
        m_isHighlighted = !m_isHighlighted;
}

void DragSelect::onReleased()
{
    if (m_isHighlighted)
        m_isHighlighted = !m_isHighlighted;
}

void DragSelect::update()
{
    m_endPos = (sf::Vector2f)sf::Mouse::getPosition(*m_window);

    if (m_isHighlighted)
    {
        // keeps top left point as position
        m_highlight.setSize(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_startPos.x - m_endPos.x : m_endPos.x - m_startPos.x,
                                         m_startPos.y >= m_endPos.y ? m_startPos.y - m_endPos.y : m_endPos.y - m_startPos.y));
        m_highlight.setPosition(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_endPos.x : m_startPos.x,
                                             m_startPos.y >= m_endPos.y ? m_endPos.y : m_startPos.y));


        m_highlight.setFillColor(sf::Color(20, 20, 140, 120));
        m_highlight.setOutlineColor(sf::Color(0, 255, 255, 220));
        m_highlight.setOutlineThickness(1);
    }
    else
    {
        m_highlight.setSize(sf::Vector2f(0, 0));
        m_highlight.setPosition(0, 0);
        m_highlight.setFillColor(sf::Color::Transparent);
    }
}

const sf::Vector2f &DragSelect::getSize() const
{
    return m_highlight.getSize();
}

const sf::Vector2f &DragSelect::getPosition() const
{
    return m_highlight.getPosition();
}