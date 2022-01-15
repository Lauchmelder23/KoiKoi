#pragma once

#include "CardStack.hpp"
#include "Board.hpp"

class Game
{
public:
	Game();
	~Game() {}

	void Setup();
	inline CardStack& GetStack() { return stack; }
	inline Board& GetBoard() { return board; }

private:
	CardStack stack;
	Board board;
};