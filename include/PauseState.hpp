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

class PauseState : public PlayState {
public:
    ~PauseState();
    void onEnter();
    void onReveal();
    void onConseal();
    void onExit();
    void handleInputs();
    void update();
    void render();
    
    friend std::ostream& operator<<(std::ostream& os, const PauseState& _gs) {
        os << _gs.name;
        return os;
    }

};

#endif //PAUSE_STATE