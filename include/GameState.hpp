/*
FILE
-----------------------------------------------------------------------------------------------
GameState.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-07-29

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef GAME_STATE
#define GAME_STATE

class GameState {
public:
    virtual ~GameState();
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif //GAME_STATE