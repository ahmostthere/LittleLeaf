/*
FILE
-----------------------------------------------------------------------------------------------
PlayState.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef PLAY_STATE
#define PLAY_STATE

#include "GameState.hpp"
#include "Player.hpp"

#define PLAY_WIN_WIDTH 1920
#define PLAY_WIN_HEIGHT 1080

class PlayState : public GameState {
public:
    ~PlayState();
    void onEnter();
    void onReveal();
    void onConseal();
    void onExit();
    void handleInputs();
    void update();
    void render();
    State getState();
    Player m_player;
};

#endif //PLAY_STATE