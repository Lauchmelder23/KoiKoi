#pragma once

#include <functional>
#include <memory>
#include <vector>
#include "Card.hpp"

typedef std::function<void(std::shared_ptr<Card>)> RevealCallbackFunc;
typedef std::function<void(void)> CleanupCallbackFunc;

class Game;

enum class BoardState
{
	Empty,
	HasCards,
	C
};

class Board
{
public:
	Board(Game* parent);

	void RevealCard();
	void Cleanup();
	inline const std::vector<std::shared_ptr<Card>>& GetOpenCards() { return openCards; }

	void SetRevealCallback(RevealCallbackFunc callbackFunc);
	void SetCleanupCallback(CleanupCallbackFunc callbackFunc);

private:
	std::vector<std::shared_ptr<Card>> openCards;

	RevealCallbackFunc revealCallback;
	CleanupCallbackFunc cleanupCallback;
	Game* parent;
};