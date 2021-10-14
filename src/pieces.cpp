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

    if (!this->validate_move(new_x, new_y)) //This piece cannot move like this
        return false;

    this->prev_x.push_back(this->x);
    this->prev_y.push_back(this->y);

    this->x = new_x;
    this->y = new_y;

    return true;
}

void Piece::generate_possible_moves()
{
    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (x == this->x && y == this->y)
                continue;

            bool ok = this->validate_move(x, y);
            if (ok)
            {
                this->possible_x.push_back(x);
                this->possible_y.push_back(y);
            }
        }
    }
}

bool Pawn::validate_move(int new_x, int new_y)
{
    int abs_dx = abs(new_x - this->x);
    int dy = new_y - this->y;

    //Can only move 1 to the side (when capturing)
    if (abs_dx > 1)
        return false;

    //Can't move backwards or more than 2 spaces forwards
    if (dy <= 0 || dy > 2)
        return false;

    //Can only move 2 spaces when in the start row, and not when capturing
    if (dy == 2 && (this->y != 1 || abs_dx > 0))
        return false;

    return true;
}

bool Rook::validate_move(int new_x, int new_y)
{
    //Illegal to change both x and y cooridinates
    if (new_x != this->x && new_y != this->y)
        return false;

    return true;
}

bool Knight::validate_move(int new_x, int new_y)
{
    int abs_dx = abs(new_x - this->x);
    int abs_dy = abs(new_y - this->y);

    //Two to the side and 1 up or down is ok
    if (abs_dx == 2 && abs_dy == 1)
        return true;

    //One to the side and 2 up or down is ok
    if (abs_dx == 1 && abs_dy == 2)
        return true;

    return false;
}

bool Bishop::validate_move(int new_x, int new_y)
{
    int abs_dx = abs(new_x - this->x);
    int abs_dy = abs(new_y - this->y);

    //Diagonal move is ok
    if (abs_dx == abs_dy)
        return true;

    return false;
}

bool Queen::validate_move(int new_x, int new_y)
{
    int abs_dx = abs(new_x - this->x);
    int abs_dy = abs(new_y - this->y);

    //Diagonal move is ok
    if (abs_dx == abs_dy)
        return true;

    //Move up/down is ok
    if (abs_dx == 0 && abs_dy > 0)
        return true;

    //Move sideways is ok
    if (abs_dy == 0 && abs_dx > 0)
        return true;

    return false;
}

bool King::validate_move(int new_x, int new_y)
{
    int abs_dx = abs(new_x - this->x);
    int abs_dy = abs(new_y - this->y);

    //One step in any direction is ok
    if (abs_dx <= 1 && abs_dy <= 1)
        return true;

    //Castling is ok if the king has no previous moves
    if (abs_dy == 0 && abs_dx == 2 && this->prev_x.size() == 0)
        return true;

    return false;
}

int main()
{
    Knight p = Knight(1, 4);
    p.generate_possible_moves();

    int n = p.possible_x.size();
    for (int i = 0; i < n; ++i)
    {
        cout << p.possible_x[i] << "," << p.possible_y[i] << endl;
    }
}