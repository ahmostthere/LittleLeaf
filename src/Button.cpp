#include "Button.hpp"

Button::Button() : isPressed(false),
                   m_Sprite(),
                   m_UnselectedRect(),
                   m_SelectedRect(),
                   m_HoverRect(),
                   m_ButtonState(UNSELECTED)
{
}

Button::Button(const sf::Texture &texture) : isPressed(false),
                                             m_UnselectedRect(),
                                             m_SelectedRect(),
                                             m_HoverRect(),
                                             m_ButtonState(UNSELECTED)

{
    m_Sprite.setTexture(texture);
    m_UnselectedRect = m_Sprite.getTextureRect();
    m_SelectedRect = m_Sprite.getTextureRect();
    m_HoverRect = m_Sprite.getTextureRect();
}

Button::Button(const sf::Texture &texture, const sf::IntRect &unselectedRect) : isPressed(false),
                                                                                m_UnselectedRect(unselectedRect),
                                                                                m_SelectedRect(unselectedRect),
                                                                                m_HoverRect(unselectedRect),
                                                                                m_ButtonState(UNSELECTED)

{
    m_Sprite.setTexture(texture);
    m_Sprite.setTextureRect(unselectedRect);
}

Button::Button(const sf::Texture &texture, const sf::IntRect &unselectedRect, const sf::IntRect &selectedRect, const sf::IntRect &hoverRect) : isPressed(false),
                                                                                                                                               m_UnselectedRect(unselectedRect),
                                                                                                                                               m_SelectedRect(selectedRect),
                                                                                                                                               m_HoverRect(hoverRect),
                                                                                                                                               m_ButtonState(UNSELECTED)

{
    m_Sprite.setTexture(texture);
    m_Sprite.setTextureRect(unselectedRect);
}

void Button::setButtonState(ButtonState btnState)
{
    m_ButtonState = btnState;
    switch (m_ButtonState)
    {
    case UNSELECTED:
        m_Sprite.setTextureRect(m_UnselectedRect);
        break;

    case SELECTED:
        m_Sprite.setTextureRect(m_SelectedRect);
        break;

    case HOVER:
        m_Sprite.setTextureRect(m_HoverRect);
        break;
    }
}

void Button::setPosition(float x, float y)
{
    m_Sprite.setPosition(x, y);
}

void Button::setPosition(const sf::Vector2f &position)
{
    m_Sprite.setPosition(position);
}

const sf::Vector2f &Button::getPosition() const
{
    return m_Sprite.getPosition();
}

bool Button::contains(const sf::Vector2i &point) const
{
    sf::Vector2i spritePos = sf::Vector2i(m_Sprite.getPosition());
    sf::Vector2i spriteSize = sf::Vector2i(m_Sprite.getTextureRect().width, m_Sprite.getTextureRect().height);
    return sf::IntRect(spritePos, spriteSize).contains(point);
}

// bool Button::isPressed() const
// {
//     return m_Pressed;
// }