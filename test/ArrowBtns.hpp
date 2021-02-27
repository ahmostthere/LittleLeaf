#include <SFML/Graphics.hpp>
#include <iostream>


// Each button sprite is 100x100 px

#define NUM_BUTTONS 4
#define SPRITE_SZ 100

class ArrowBtns : public sf::Drawable {
private:
    sf::Texture m_Texture;
    sf::Sprite t_Sprites[NUM_BUTTONS * 2];
    sf::Sprite *t_DirSprites[NUM_BUTTONS];
    sf::Keyboard::Key t_DirBtns[NUM_BUTTONS];
    enum {
        UP = 0, 
        DOWN = 1, 
        LEFT = 2, 
        RIGHT = 3
    };

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(*t_DirSprites[UP]);
        target.draw(*t_DirSprites[DOWN]);
        target.draw(*t_DirSprites[LEFT]);
        target.draw(*t_DirSprites[RIGHT]);
    }

public:
    ArrowBtns(sf::Keyboard::Key up = sf::Keyboard::Up, sf::Keyboard::Key down = sf::Keyboard::Down, sf::Keyboard::Key left = sf::Keyboard::Left, sf::Keyboard::Key right = sf::Keyboard::Right) { 
        t_DirBtns[UP] = up; 
        t_DirBtns[DOWN] = down;
        t_DirBtns[LEFT] = left; 
        t_DirBtns[RIGHT] = right;
    }

    void load() {
        if (!m_Texture.loadFromFile("assets/arrowButtons.png")) {
            std::cout << "failed to load assets" << std::endl;
            return;
        } else {
            for (int i = 0; i < NUM_BUTTONS * 2; i++) {
                t_Sprites[i].setTexture(m_Texture);
                t_Sprites[i].setTextureRect(
                    sf::IntRect(sf::Vector2i(i * 100, 0), sf::Vector2i(100, 100)));
                if (i < NUM_BUTTONS) {
                    t_DirSprites[i] = &t_Sprites[i];
                }
            }
        }
    }    

    void setPosition(float x, float y) {
        t_Sprites[UP].setPosition(120 + x, 0 + y); // Up
        t_Sprites[LEFT].setPosition(0 + x, 120 + y); // Left
        t_Sprites[DOWN].setPosition(120 + x, 120 + y); // Down
        t_Sprites[RIGHT].setPosition(240 + x, 120 + y); // Right

        t_Sprites[UP + NUM_BUTTONS].setPosition(120 + x, 0 + y);    // Up
        t_Sprites[LEFT + NUM_BUTTONS].setPosition(0 + x, 120 + y);    // Left
        t_Sprites[DOWN + NUM_BUTTONS].setPosition(120 + x, 120 + y);  // Down
        t_Sprites[RIGHT + NUM_BUTTONS].setPosition(240 + x, 120 + y);  // Right
    }

    void setUpPressedEffect() {
        t_DirSprites[UP] = &t_Sprites[UP + NUM_BUTTONS];
    }
    void setDownPressedEffect() {
        t_DirSprites[DOWN] = &t_Sprites[DOWN + NUM_BUTTONS];
    }
    void setLeftPressedEffect() {
        t_DirSprites[LEFT] = &t_Sprites[LEFT + NUM_BUTTONS];
    }
    void setRightPressedEffect() {
        t_DirSprites[RIGHT] = &t_Sprites[RIGHT + NUM_BUTTONS];
    }

    void setUpReleasedEffect() {
      t_DirSprites[UP] = &t_Sprites[UP];
    }
    void setDownReleasedEffect() {
      t_DirSprites[DOWN] = &t_Sprites[DOWN];
    }
    void setLeftReleasedEffect() {
      t_DirSprites[LEFT] = &t_Sprites[LEFT];
    }
    void setRightReleasedEffect() {
      t_DirSprites[RIGHT] = &t_Sprites[RIGHT];
    }

    void handleInput() {
        for (int i = 0; i < NUM_BUTTONS; i++) {
            if (sf::Keyboard::isKeyPressed(t_DirBtns[i])) {
                t_DirSprites[i] = &t_Sprites[i + NUM_BUTTONS];
            } else {
                t_DirSprites[i] = &t_Sprites[i];
            }
        }
    }


};