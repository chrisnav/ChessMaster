#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "pieces.h"
using namespace std;

class Player
{
private:
    bool is_white;
    std::vector<Pawn *> pawns;
    std::vector<Rook *> rooks;
    std::vector<Knight *> knights;
    std::vector<Bishop *> bishops;
    std::vector<Queen *> queens;
    King *king;

public:
    Player(bool is_white);
    ~Player();

    bool remove_piece(int x, int y);
    int total_value();
    void update_possible_moves(bool force_update);
};

#endif