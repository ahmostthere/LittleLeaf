/*
FILE
-----------------------------------------------------------------------------------------------
GameStates.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-08-06

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef GAME_STATES
#define GAME_STATES

#include "GameState.hpp"

class MenuState : public GameState
{
  public:
    ~MenuState();
    void onEnter();
    void onExit();
    void update();
    void render();
};

class PlayState : public GameState
{
  public:
    ~PlayState();
    void onEnter();
    void onExit();
    void update();
    void render();
};

class PauseState : public GameState
{
  public:
    ~PauseState();
    void onEnter();
    void onExit();
    void update();
    void render();
};

class OptionsState : public GameState
{
  public:
    ~OptionsState();
    void onEnter();
    void onExit();
    void update();
    void render();
};

#endif //GAME_STATES