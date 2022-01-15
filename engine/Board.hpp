#pragma once

#include <functional>
#include <memory>
#include <vector>
#include "Card.hpp"

typedef std::function<void(std::shared_ptr<Card>)> RevealCallbackFunc;

class Game;

class Board
{
public:
	Board(Game* parent);

	void RevealCard();
	inline const std::vector<std::shared_ptr<Card>>& GetOpenCards() { return openCards; }

	void SetRevealCallback(RevealCallbackFunc callbackFunc);

private:
	std::vector<std::shared_ptr<Card>> openCards;

	RevealCallbackFunc callback;
	Game* parent;
};