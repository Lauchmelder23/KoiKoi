#include "CardStack.hpp"

#include <algorithm>
#include <chrono>
#include <random>

CardStack::CardStack(lol::ObjectManager& manager)
{
	// Create a full stack of cards
	for (int month = 0; month < 11; month++)
	{
		for (int type = 0; type < 4; type++)
		{
			stack.push_back(std::make_shared<Card>(manager, static_cast<Month>(month), type));
		}
	}

	// Shuffle stack
	std::default_random_engine engine(time(0));
	std::shuffle(stack.begin(), stack.end(), engine);
}

CardStack::~CardStack()
{
}

std::shared_ptr<Card> CardStack::Draw()
{
	std::shared_ptr<Card> drawnCard = stack.back();
	stack.pop_back();
	return drawnCard;
}
