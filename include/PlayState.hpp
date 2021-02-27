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
    
    friend std::ostream& operator<<(std::ostream& os, const PlayState& _gs) {
        os << _gs.name;
        return os;
    }
    
};

#endif //PLAY_STATE