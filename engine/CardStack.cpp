#include "CardStack.hpp"

#include <algorithm>
#include <chrono>
#include <random>

CardStack::CardStack()
{
	// Create a full stack of cards
	for (int month = 0; month < 11; month++)
	{
		for (int type = 0; type < 4; type++)
		{
			stack.push_back(std::make_shared<Card>(static_cast<Month>(month), type));
		}
	}

	// Shuffle stack
	std::default_random_engine engine(std::chrono::steady_clock::now().time_since_epoch().count());
	std::shuffle(stack.begin(), stack.end(), engine);
}

CardStack::~CardStack()
{
}

std::shared_ptr<Card> CardStack::DrawCard()
{
	std::shared_ptr<Card> drawnCard = stack.back();
	stack.pop_back();
	return drawnCard;
}
