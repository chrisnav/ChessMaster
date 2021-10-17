#ifndef PIECES_H
#define PIECES_H

#include <vector>
using namespace std;

class Piece
{
protected:
    int x;
    int y;
    std::vector<int> prev_x;
    std::vector<int> prev_y;
    int value;

public:
    std::vector<int> possible_x;
    std::vector<int> possible_y;
    bool moved_last_turn;
    bool has_moevd;    

    Piece(int x, int y) : x(x), y(y)
    {
        moved_last_turn = false;
        has_moevd = false;
        value = 0;
    };
    ~Piece(){};

    bool move(int new_x, int new_y);
    void add_possible_move(int x, int y);
    virtual void generate_possible_moves(){};
    bool confirm_position(int x, int y) { return (this->x == x && this->y == y); };
    int get_value() { return this->value; };
};

class Pawn : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Pawn(int x, int y) : Piece(x, y) { value = 1; };
    ~Pawn(){};
};

class Rook : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Rook(int x, int y) : Piece(x, y) { value = 5; };
    ~Rook(){};
};

class Knight : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Knight(int x, int y) : Piece(x, y) { value = 3; };
    ~Knight(){};
};

class Bishop : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Bishop(int x, int y) : Piece(x, y) { value = 3; };
    ~Bishop(){};
};

class Queen : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Queen(int x, int y) : Piece(x, y) { value = 9; };
    ~Queen(){};
};

class King : public Piece
{
    //private:

public:
    void generate_possible_moves();
    King(int x, int y) : Piece(x, y) { value = 1000; };
    ~King(){};
};

#endif