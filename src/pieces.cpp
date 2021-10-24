#include <iostream>
#include <vector>
#include <string>
#include "pieces.h"

using namespace std;

bool is_inside_board(Position p)
{
    int x = p.get_x();
    int y = p.get_y();

    return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

bool Piece::move(Position new_pos)
{

    if (!is_inside_board(new_pos)) //Outside board
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

    if (!is_inside_board(p)) //Outside board
        return;

    if (p.is_equal(this->pos)) //Piece not moved
        return;

    this->possible_moves.push_back(p);
}

void Pawn::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    //The pawn should have been transformed
    if (y == 7)
        return;

    //One step forward
    moves->push_back(Position(x, y + 1));

    //Two steps forward from initial position
    if (!this->has_moevd && y == 1)
        moves->push_back(Position(x, y + 2));

    //Captures
    moves->push_back(Position(x - 1, y + 1));
    moves->push_back(Position(x + 1, y + 1));
}

void Rook::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    for (int i = 0; i < 8; ++i)
    {
        if (i != x)
            moves->push_back(Position(i, y));

        if (i != y)
            moves->push_back(Position(x, i));
    }
}

void Knight::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    Position q = Position(x - 2, y - 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x - 2, y + 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x + 2, y - 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x + 2, y + 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x - 1, y - 2);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x - 1, y + 2);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x + 1, y - 2);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x + 1, y + 2);
    if (is_inside_board(q))
        moves->push_back(q);
}

void Bishop::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    for (int i = 0; i < 8; ++i)
    {
        Position q = Position(x + i, y + i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x + i, y - i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x - i, y + i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x - i, y - i);
        if (is_inside_board(q))
            moves->push_back(q);
    }
}

void Queen::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    for (int i = 0; i < 8; ++i)
    {
        //Diagonal
        Position q = Position(x + i, y + i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x + i, y - i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x - i, y + i);
        if (is_inside_board(q))
            moves->push_back(q);

        q = Position(x - i, y - i);
        if (is_inside_board(q))
            moves->push_back(q);

        //Horizontal and vertical
        if (i != x)
            moves->push_back(Position(i, y));

        if (i != y)
            moves->push_back(Position(x, i));
    }
}

void King::generate_moves_from_pos(Position p, std::vector<Position> *moves)
{
    int x = p.get_x();
    int y = p.get_y();

    Position q = Position(x - 1, y - 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x - 1, y);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x - 1, y + 1);
    if (is_inside_board(q))
        moves->push_back(q);

    q = Position(x, y + 1);
    if (is_inside_board(q))
        moves->push_back(q);  

    q = Position(x, y - 1);
    if (is_inside_board(q))
        moves->push_back(q);  

    q = Position(x + 1, y - 1);
    if (is_inside_board(q))
        moves->push_back(q);  

    q = Position(x + 1, y);
    if (is_inside_board(q))
        moves->push_back(q);  

    q = Position(x + 1, y + 1);
    if (is_inside_board(q))
        moves->push_back(q);                          

    //Castling
    if (!this->has_moevd && x == 4 && y == 0)
    {
        moves->push_back(Position(x + 2, y));
        moves->push_back(Position(x - 2, y));
    }
}