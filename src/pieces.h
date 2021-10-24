#ifndef PIECES_H
#define PIECES_H

#include <vector>
using namespace std;

class Position
{
private:
    int x;
    int y;

public:
    Position(int x, int y) : x(x), y(y){};
    int get_x() { return x; };
    int get_y() { return y; };
    bool is_equal(Position p) { return (x == p.get_x() && this->y == p.get_y()); };
    ~Position(){};
};

bool is_inside_board(Position p);
class Piece
{
protected:
    Position pos;
    std::vector<Position> prev_pos;
    int value;

public:
    std::vector<Position> possible_moves;
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
    virtual void generate_moves_from_pos(Position p, std::vector<Position> *moves){};
    bool confirm_position(Position p) { return (this->pos.is_equal(p)); };
    int get_value() { return this->value; };
};

class Pawn : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    Pawn(int x, int y) : Piece(x, y) { value = 1; };
    ~Pawn(){};
};

class Rook : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    Rook(int x, int y) : Piece(x, y) { value = 5; };
    ~Rook(){};
};

class Knight : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    Knight(int x, int y) : Piece(x, y) { value = 3; };
    ~Knight(){};
};

class Bishop : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    Bishop(int x, int y) : Piece(x, y) { value = 3; };
    ~Bishop(){};
};

class Queen : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    Queen(int x, int y) : Piece(x, y) { value = 9; };
    ~Queen(){};
};

class King : public Piece
{
    //private:

public:
    void generate_moves_from_pos(Position p, std::vector<Position> *moves);
    King(int x, int y) : Piece(x, y) { value = 1000; };
    ~King(){};
};

#endif