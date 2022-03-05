#include "headers\player.h"
#include "headers\pieces.h"

Player::Player(bool is_white)
{
    this->is_white = is_white;

    for (int i = 0; i < 8; ++i)
    {
        Pawn *p = new Pawn(i, 1);
        this->pawns.push_back(p);
    }

    Rook *r1 = new Rook(0, 0);
    Rook *r2 = new Rook(7, 0);
    this->rooks.push_back(r1);
    this->rooks.push_back(r2);

    Knight *kn1 = new Knight(1, 0);
    Knight *kn2 = new Knight(6, 0);
    this->knights.push_back(kn1);
    this->knights.push_back(kn2);

    Bishop *b1 = new Bishop(2, 0);
    Bishop *b2 = new Bishop(5, 0);
    this->bishops.push_back(b1);
    this->bishops.push_back(b2);

    Queen *q = new Queen(3, 0);
    this->queens.push_back(q);

    King *k = new King(4, 0);
    this->king = k;
}

Player::~Player()
{
    for (auto p : this->pawns)
        delete p;

    for (auto p : this->rooks)
        delete p;

    for (auto p : this->knights)
        delete p;

    for (auto p : this->bishops)
        delete p;

    for (auto p : this->queens)
        delete p;

    delete this->king;
}

bool Player::remove_piece(Position pos)
{
    for (int i = 0; i < this->pawns.size(); ++i)
    {
        Pawn *p = this->pawns[i];

        if (p->confirm_position(pos))
        {
            this->pawns.erase(this->pawns.begin() + i);
            delete p;
            return true;
        }
    }

    for (int i = 0; i < this->rooks.size(); ++i)
    {
        Rook *r = this->rooks[i];

        if (r->confirm_position(pos))
        {
            this->rooks.erase(this->rooks.begin() + i);
            delete r;
            return true;
        }
    }

    for (int i = 0; i < this->knights.size(); ++i)
    {
        Knight *kn = this->knights[i];

        if (kn->confirm_position(pos))
        {
            this->knights.erase(this->knights.begin() + i);
            delete kn;
            return true;
        }
    }

    for (int i = 0; i < this->bishops.size(); ++i)
    {
        Bishop *b = this->bishops[i];

        if (b->confirm_position(pos))
        {
            this->bishops.erase(this->bishops.begin() + i);
            delete b;
            return true;
        }
    }

    for (int i = 0; i < this->queens.size(); ++i)
    {
        Queen *q = this->queens[i];

        if (q->confirm_position(pos))
        {
            this->queens.erase(this->queens.begin() + i);
            delete q;
            return true;
        }
    }

    return false;
}

int Player::total_value()
{
    int value = 0;
    for (auto p : this->pawns)
        value += p->get_value();

    for (auto r : this->rooks)
        value += r->get_value();

    for (auto kn : this->knights)
        value += kn->get_value();        

    for (auto b : this->bishops)
        value += b->get_value();

    for (auto q : this->queens)
        value += q->get_value();

    return value;
}