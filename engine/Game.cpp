#include "Game.hpp"

Game::Game() :
	board(this)
{

}

void Game::Setup()
{
	// Put 8 cards on the table
	for (int i = 0; i < 8; i++)
		board.RevealCard();
}

void Game::Cleanup()
{
	stack = CardStack();
	board.Cleanup();
}
