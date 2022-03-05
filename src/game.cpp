#include "headers\game.h"

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
  
}

void Game::move_black()
{
    Player* p = this->black;

}

bool Game::is_check()
{
    return false;
}