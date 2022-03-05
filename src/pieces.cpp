#include <iostream>
#include <vector>
#include <string>
#include "headers\pieces.h"

bool Position::is_inside_board()
{
    return (this->x >= 0 && this->x <= 7 && this->y >= 0 && this->y <= 7);
}

bool Piece::move(Position new_pos)
{

    if (!new_pos.is_inside_board()) //Outside board
        return false;

    if (new_pos.is_equal(this->pos)) //Piece not moved
        return false;

    this->prev_pos.push_back(this->pos);

    this->pos = new_pos;

    this->moved_last_turn = true;
    this->has_moevd = true;
    return true;
}

void Piece::add_possible_move(int x, int y)
{
    Position p = Position(x, y);

    if (!p.is_inside_board()) //Outside board
        return;

    if (p.is_equal(this->pos)) //Piece not moved
        return;

    this->possible_moves.push_back(p);
}

void Pawn::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    //The pawn should have been transformed
    if (p.y == 7)
        return;

    //One step forward
    moves->push_back(Position(p.x, p.y + 1));

    //Two steps forward from initial position
    if (!this->has_moevd && p.y == 1)
        moves->push_back(Position(p.x, p.y + 2));

    //Captures
    moves->push_back(Position(p.x - 1, p.y + 1));
    moves->push_back(Position(p.x + 1, p.y + 1));
}

void Rook::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    for (int i = 0; i < 8; ++i)
    {
        if (i != p.x)
            moves->push_back(Position(i, p.y));

        if (i != p.y)
            moves->push_back(Position(p.x, i));
    }
}

void Knight::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    Position q = Position(p.x - 2, p.y - 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x - 2, p.y + 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x + 2, p.y - 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x + 2, p.y + 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x - 1, p.y - 2);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x - 1, p.y + 2);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x + 1, p.y - 2);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x + 1, p.y + 2);
    if (q.is_inside_board())
        moves->push_back(q);
}

void Bishop::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    for (int i = 0; i < 8; ++i)
    {
        Position q = Position(p.x + i, p.y + i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x + i, p.y - i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x - i, p.y + i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x - i, p.y - i);
        if (q.is_inside_board())
            moves->push_back(q);
    }
}

void Queen::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    for (int i = 0; i < 8; ++i)
    {
        //Diagonal
        Position q = Position(p.x + i, p.y + i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x + i, p.y - i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x - i, p.y + i);
        if (q.is_inside_board())
            moves->push_back(q);

        q = Position(p.x - i, p.y - i);
        if (q.is_inside_board())
            moves->push_back(q);

        //Horizontal and vertical
        if (i != p.x)
            moves->push_back(Position(i, p.y));

        if (i != p.y)
            moves->push_back(Position(p.x, i));
    }
}

void King::generate_moves_from_pos(Position p, vector<Position> *moves)
{
    Position q = Position(p.x - 1, p.y - 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x - 1, p.y);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x - 1, p.y + 1);
    if (q.is_inside_board())
        moves->push_back(q);

    q = Position(p.x, p.y + 1);
    if (q.is_inside_board())
        moves->push_back(q);  

    q = Position(p.x, p.y - 1);
    if (q.is_inside_board())
        moves->push_back(q);  

    q = Position(p.x + 1, p.y - 1);
    if (q.is_inside_board())
        moves->push_back(q);  

    q = Position(p.x + 1, p.y);
    if (q.is_inside_board())
        moves->push_back(q);  

    q = Position(p.x + 1, p.y + 1);
    if (q.is_inside_board())
        moves->push_back(q);                          

    //Castling
    if (!this->has_moevd && p.x == 4 && p.y == 0)
    {
        moves->push_back(Position(p.x + 2, p.y));
        moves->push_back(Position(p.x - 2, p.y));
    }
}