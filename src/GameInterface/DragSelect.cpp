#include "DragSelect.hpp"

DragSelect::DragSelect() : m_isHighlighted(false), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0))
{
    // load
    setSize(sf::Vector2f(0, 0));
    setFillColor(sf::Color::Transparent);
}

DragSelect::DragSelect(sf::Window *relativeTo) : m_isHighlighted(false), m_startPos(sf::Vector2f(0, 0)), m_endPos(sf::Vector2f(0, 0)), m_window(relativeTo)
{
    setSize(sf::Vector2f(0, 0));
    setFillColor(sf::Color::Transparent);
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
        setSize(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_startPos.x - m_endPos.x : m_endPos.x - m_startPos.x,
                                         m_startPos.y >= m_endPos.y ? m_startPos.y - m_endPos.y : m_endPos.y - m_startPos.y));
        setPosition(sf::Vector2f(m_startPos.x >= m_endPos.x ? m_endPos.x : m_startPos.x,
                                             m_startPos.y >= m_endPos.y ? m_endPos.y : m_startPos.y));


        setFillColor(sf::Color(20, 20, 140, 120));
        setOutlineColor(sf::Color(0, 255, 255, 220));
        setOutlineThickness(1);
    }
    else
    {
        setSize(sf::Vector2f(0, 0));
        setPosition(0, 0);
        setFillColor(sf::Color::Transparent);
    }
}