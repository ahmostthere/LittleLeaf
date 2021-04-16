/*
FILE
-----------------------------------------------------------------------------------------------
MenuState.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef MENU_STATE
#define MENU_STATE

#include "GameState.hpp"

#define MENU_WIN_WIDTH 1920
#define MENU_WIN_HEIGHT 1080

class MenuState : public GameState
{
public:
    MenuState();
    ~MenuState();
    void onEnter();
    void onReveal();
    void onConseal();
    void onExit();
    void handleInputs();
    void update();
    void render();
    State getState();

private:
    sf::Texture menuSplashTexture;
    sf::Texture playTexture;
    sf::Texture quitTexture;
    sf::Sprite menuSplash;
    sf::Sprite playSprite;
    sf::Sprite quitSprite;
    bool play;
};

#endif //MENU_STATE