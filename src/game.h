#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
private:
    Player* white;
    Player* black;
    bool whites_turn;
    int n_white_moves;
    int n_black_moves;

public:
    Game();
    ~Game();

    void move_white();
    void move_black();

};


#endif