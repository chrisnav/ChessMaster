#ifndef PIECES_H
#define PIECES_H

#include <vector>
using std::vector;

struct Position
{
    int x;
    int y;

    Position(int x, int y) : x(x), y(y){};
    bool is_equal(Position p) { return (x == p.x && this->y == p.y); };
    bool is_inside_board();
    ~Position(){};
};

class Piece
{
protected:
    Position pos;
    vector<Position> prev_pos;
    int value;

public:
    vector<Position> possible_moves;
    bool moved_last_turn;
    bool has_moevd;

    Piece(int x, int y) : pos(Position(x, y))
    {
        moved_last_turn = false;
        has_moevd = false;
        value = 0;
    };
    ~Piece(){};

    bool move(Position new_pos);
    void add_possible_move(int x, int y);
    virtual vector<Position> generate_moves(){};
    bool confirm_position(Position p) { return (this->pos.is_equal(p)); };
    int get_value() { return this->value; };
};

class Pawn : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    Pawn(int x, int y) : Piece(x, y) { value = 1; };
    ~Pawn(){};
};

class Rook : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    Rook(int x, int y) : Piece(x, y) { value = 5; };
    ~Rook(){};
};

class Knight : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    Knight(int x, int y) : Piece(x, y) { value = 3; };
    ~Knight(){};
};

class Bishop : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    Bishop(int x, int y) : Piece(x, y) { value = 3; };
    ~Bishop(){};
};

class Queen : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    Queen(int x, int y) : Piece(x, y) { value = 9; };
    ~Queen(){};
};

class King : public Piece
{
    //private:

public:
    vector<Position> generate_moves();
    King(int x, int y) : Piece(x, y) { value = 1000; };
    ~King(){};
};

#endif