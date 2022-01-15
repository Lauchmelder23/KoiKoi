#pragma once

#include <memory>
#include <vector>

#include "Card.hpp"

class CardStack
{
public:
	CardStack();
	~CardStack();

	std::shared_ptr<Card> DrawCard();
	inline bool Empty() const { return stack.empty(); }

private:
	std::vector<std::shared_ptr<Card>> stack;
};