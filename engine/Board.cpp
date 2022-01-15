#include "Board.hpp"

#include "Game.hpp"

Board::Board(Game* parent) :
	parent(parent)
{
	
}

void Board::RevealCard()
{
	openCards.push_back(parent->GetStack().DrawCard());
	if (callback)
		callback(openCards.back());
}

void Board::SetRevealCallback(RevealCallbackFunc callbackFunc)
{
	callback = callbackFunc;
}
