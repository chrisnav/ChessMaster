#include "game.h"

Game::Game()
{
    this->white = new Player(true);
    this->black = new Player(false);
    this->whites_turn = true;
    this->n_white_moves = 0;
    this->n_black_moves = 0;
}

Game::~Game()
{
    delete this->white;
    delete this->black;
}

void Game::move_white()
{
    Player* p = this->white;

    if(this->n_white_moves == 0)
        p->update_possible_moves(true);
    else
        p->update_possible_moves(false);

    
}