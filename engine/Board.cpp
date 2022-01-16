#include "Board.hpp"

#include "Game.hpp"

Board::Board(Game* parent) :
	parent(parent)
{
	
}

void Board::RevealCard()
{
	openCards.push_back(parent->GetStack().DrawCard());
	if (revealCallback)
		revealCallback(openCards.back());
}

void Board::Cleanup()
{
	openCards.clear();
	if (cleanupCallback)
		cleanupCallback();
}

void Board::SetRevealCallback(RevealCallbackFunc callbackFunc)
{
	revealCallback = callbackFunc;
}

void Board::SetCleanupCallback(CleanupCallbackFunc callbackFunc)
{
	cleanupCallback = callbackFunc;
}
