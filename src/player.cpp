#include "player.h"

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

bool Player::remove_piece(int x, int y)
{
    for (int i = 0; i < this->pawns.size(); ++i)
    {
        Pawn *p = this->pawns[i];

        if (p->confirm_position(x, y))
        {
            this->pawns.erase(this->pawns.begin() + i);
            delete p;
            return true;
        }
    }

    for (int i = 0; i < this->rooks.size(); ++i)
    {
        Rook *r = this->rooks[i];

        if (r->confirm_position(x, y))
        {
            this->rooks.erase(this->rooks.begin() + i);
            delete r;
            return true;
        }
    }

    for (int i = 0; i < this->knights.size(); ++i)
    {
        Knight *kn = this->knights[i];

        if (kn->confirm_position(x, y))
        {
            this->knights.erase(this->knights.begin() + i);
            delete kn;
            return true;
        }
    }

    for (int i = 0; i < this->bishops.size(); ++i)
    {
        Bishop *b = this->bishops[i];

        if (b->confirm_position(x, y))
        {
            this->bishops.erase(this->bishops.begin() + i);
            delete b;
            return true;
        }
    }

    for (int i = 0; i < this->queens.size(); ++i)
    {
        Queen *q = this->queens[i];

        if (q->confirm_position(x, y))
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

void Player::update_possible_moves(bool force_update)
{
    for(auto p : this->pawns)
    {
        if(force_update || p->moved_last_turn)
            p->generate_possible_moves();
    }

    for(auto p : this->rooks)
    {
        if(force_update || p->moved_last_turn)
            p->generate_possible_moves();
    }

    for(auto p : this->knights)
    {
        if(force_update || p->moved_last_turn)
            p->generate_possible_moves();
    }

    for(auto p : this->bishops)
    {
        if(force_update || p->moved_last_turn)
            p->generate_possible_moves();
    }

    for(auto p : this->queens)
    {
        if(force_update || p->moved_last_turn)
            p->generate_possible_moves();
    }

    if(force_update || this->king->moved_last_turn)
        this->king->generate_possible_moves();
}

