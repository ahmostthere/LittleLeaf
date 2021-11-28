/*
FILE
-----------------------------------------------------------------------------------------------
Button.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2021-11-02

DESCRIPTION
-----------------------------------------------------------------------------------------------
Button is for user interface buttons.
Each button has 3 states: Unselected, Hover, Selected.
Unselected is default state of each button.
Hover is state when mouse is moved over button. Can be visibly the same as Selected.
Selected is state when button is pressed or in focus. A button is in focus when it is tabbed or selected through with keyboard buttons.
Only a single button can be in focus.

*/
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
// #include <iostream>

class Button : public sf::Drawable
{
public:
    enum ButtonState
    {
        UNSELECTED,
        HOVER,
        SELECTED
    };
    Button();
    Button(const sf::Texture &texture, Button::ButtonState _buttonState = UNSELECTED);
    Button(const sf::Texture &texture, const sf::IntRect &unselectedRect, Button::ButtonState _buttonState = UNSELECTED);
    Button(const sf::Texture &texture, const sf::IntRect &unselectedRect, const sf::IntRect &selectedRect, const sf::IntRect &hoverRect, Button::ButtonState _buttonState = UNSELECTED);
    void setButtonState(ButtonState btnState);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    const sf::Vector2f &getPosition() const;
    bool contains(const sf::Vector2i &point) const;
    bool isPressed;
    // bool isPressed() const;

private:
    sf::Sprite m_Sprite;
    sf::IntRect m_UnselectedRect;
    sf::IntRect m_SelectedRect;
    sf::IntRect m_HoverRect;
    ButtonState m_ButtonState;
    // bool m_Pressed;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_Sprite);
    }
};

#endif 