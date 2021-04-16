/*
FILE
-----------------------------------------------------------------------------------------------
PauseState.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2019-01-05

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef PAUSE_STATE
#define PAUSE_STATE

#include "PlayState.hpp"

class PauseState : public PlayState
{
public:
    ~PauseState();
    void onEnter();
    void onReveal();
    void onConseal();
    void onExit();
    void handleInputs();
    void update();
    void render();
    State getState();
};

#endif //PAUSE_STATE