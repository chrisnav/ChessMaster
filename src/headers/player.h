#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "pieces.h"
using std::vector;

class Player
{
private:
    bool is_white;
    vector<Pawn *> pawns;
    vector<Rook *> rooks;
    vector<Knight *> knights;
    vector<Bishop *> bishops;
    vector<Queen *> queens;
    King *king;

public:
    Player(bool is_white);
    ~Player();

    bool remove_piece(Position pos);
    int total_value();
};

#endif