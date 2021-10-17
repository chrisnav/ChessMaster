#include <vector>
using namespace std;

class Piece
{
protected:
    int x;
    int y;
    std::vector<int> prev_x;
    std::vector<int> prev_y;
    bool moved_last_turn;
    bool has_moevd;

public:
    std::vector<int> possible_x;
    std::vector<int> possible_y;

    Piece(int x, int y) : x(x), y(y)
    {
        moved_last_turn = false;
        has_moevd = false;
    };
    
    bool move(int new_x, int new_y);
    void add_possible_move(int x, int y);
    virtual void generate_possible_moves(){};
    ~Piece(){};
};

class Pawn : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Pawn(int x, int y) : Piece(x, y){};
    ~Pawn(){};
};

class Rook : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Rook(int x, int y) : Piece(x, y){};
    ~Rook(){};
};

class Knight : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Knight(int x, int y) : Piece(x, y){};
    ~Knight(){};
};

class Bishop : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Bishop(int x, int y) : Piece(x, y){};
    ~Bishop(){};
};

class Queen : public Piece
{
    //private:

public:
    void generate_possible_moves();
    Queen(int x, int y) : Piece(x, y){};
    ~Queen(){};
};

class King : public Piece
{
    //private:

public:
    void generate_possible_moves();
    King(int x, int y) : Piece(x, y){};
    ~King(){};
};