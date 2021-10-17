#include <iostream>
#include <vector>
#include <string>
#include "pieces.h"

using namespace std;

bool Piece::move(int new_x, int new_y)
{

    if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7) //Outside board
        return false;

    if (new_x == this->x && new_y == this->y) //Piece not moved
        return false;

    this->prev_x.push_back(this->x);
    this->prev_y.push_back(this->y);

    this->x = new_x;
    this->y = new_y;

    this->moved_last_turn = true;
    this->has_moevd = true;
    return true;
}

void Piece::add_possible_move(int x, int y)
{
    if (x < 0 || x > 7 || y < 0 || y > 7) //Outside board
        return;

    if (x == this->x && y == this->y) //Piece not moved
        return;

    this->possible_x.push_back(x);
    this->possible_y.push_back(y);
}

void Pawn::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    //The pawn should have been transformed
    if (y == 7)
        return;

    //One step forward
    this->add_possible_move(x, y + 1);

    //Two steps forward from initial position
    if (!this->has_moevd && y == 1)
        this->add_possible_move(x, y + 2);

    //Captures
    this->add_possible_move(x - 1, y + 1);
    this->add_possible_move(x + 1, y + 1);
}

void Rook::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    for (int i = 0; i < 8; ++i)
    {
        this->add_possible_move(i, y);
        this->add_possible_move(x, i);
    }
}

void Knight::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    this->add_possible_move(x - 2, y - 1);
    this->add_possible_move(x - 2, y + 1);
    this->add_possible_move(x + 2, y - 1);
    this->add_possible_move(x + 2, y + 1);
    this->add_possible_move(x - 1, y - 2);
    this->add_possible_move(x - 1, y + 2);
    this->add_possible_move(x + 1, y - 2);
    this->add_possible_move(x + 1, y + 2);
}

void Bishop::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    for (int i = 0; i < 8; ++i)
    {
        this->add_possible_move(x + i, y + i);
        this->add_possible_move(x + i, y - i);
        this->add_possible_move(x - i, y + i);
        this->add_possible_move(x - i, y - i);
    }
}

void Queen::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    for (int i = 0; i < 8; ++i)
    {
        //Diagonal
        this->add_possible_move(x + i, y + i);
        this->add_possible_move(x + i, y - i);
        this->add_possible_move(x - i, y + i);
        this->add_possible_move(x - i, y - i);

        //Horizontal and vertical
        this->add_possible_move(i, y);
        this->add_possible_move(x, i);
    }
}

void King::generate_possible_moves()
{
    this->possible_x.clear();
    this->possible_y.clear();

    int x = this->x;
    int y = this->y;

    this->add_possible_move(x - 1, y - 1);
    this->add_possible_move(x - 1, y);
    this->add_possible_move(x - 1, y + 1);

    this->add_possible_move(x, y + 1);
    this->add_possible_move(x, y - 1);

    this->add_possible_move(x + 1, y - 1);
    this->add_possible_move(x + 1, y);
    this->add_possible_move(x + 1, y + 1);

    //Castling
    if (!this->has_moevd && x == 4 && y == 0)
    {
        this->add_possible_move(x + 2, y);
        this->add_possible_move(x - 2, y);
    }
}