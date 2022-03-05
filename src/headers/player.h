#pragma once

#include <vector>
using std::vector;

class Pawn;
class Rook;
class Knight;
class Bishop;
class Queen;
class King;
struct Position;
class Player
{
public:
    bool is_white;
    vector<Pawn *> pawns;
    vector<Rook *> rooks;
    vector<Knight *> knights;
    vector<Bishop *> bishops;
    vector<Queen *> queens;
    King *king;

    Player(bool is_white);
    ~Player();

    bool remove_piece(Position pos);
    int total_value();
};