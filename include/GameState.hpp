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
    virtual void say() = 0;
};

class MenuState: public GameState {
public:
    ~MenuState();
    void say();
};

class PlayState: public GameState {
public:
    ~PlayState();
    void say();
};

class PauseState: public GameState {
public:
    ~PauseState();
    void say();
};

class OptionsState: public GameState {
public:
    ~OptionsState();
    void say();
};

#endif //GAME_STATE