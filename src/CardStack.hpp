#pragma once

#include "Card.hpp"

class CardStack
{
public:
	CardStack(lol::ObjectManager& manager);
	~CardStack();

	std::shared_ptr<Card> Draw();
	inline bool Empty() { return stack.empty(); }

private:
	std::vector<std::shared_ptr<Card>> stack;
};