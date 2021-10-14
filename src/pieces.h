#include <vector>
using namespace std;

class Piece
{
protected:
    int x;
    int y;
    std::vector<int> prev_x;
    std::vector<int> prev_y;

public:

    std::vector<int> possible_x;
    std::vector<int> possible_y;

    Piece(int x, int y) : x(x), y(y){};
    bool move(int new_x, int new_y);
    virtual bool validate_move(int new_x, int new_y) = 0;
    void generate_possible_moves();
    ~Piece(){};
};

class Pawn : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);    
    Pawn(int x, int y) : Piece(x, y){};
    ~Pawn(){};
};

class Rook : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);
    Rook(int x, int y) : Piece(x, y){};
    ~Rook(){};
};

class Knight : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);
    Knight(int x, int y) : Piece(x, y){};
    ~Knight(){};
};

class Bishop : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);
    Bishop(int x, int y) : Piece(x, y){};
    ~Bishop(){};
};

class Queen : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);
    Queen(int x, int y) : Piece(x, y){};
    ~Queen(){};
};


class King : public Piece
{
    //private:

public:
    bool validate_move(int new_x, int new_y);
    King(int x, int y) : Piece(x, y){};
    ~King(){};
};